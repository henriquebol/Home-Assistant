#define MY_DEBUG // Enable debug prints
#define MY_RADIO_NRF24 // Enable and select radio type attached 

#include <SPI.h>
#include <MySensors.h>
#include <DHT.h>
#include <Bounce2.h>
#include "pitches.h"

//pins
#define DHT_DATA_PIN A3 // Set this to the pin you connected the DHT's data pin to
#define LDR_DATA_PIN A6
#define SOUND_DATA_PIN A0
#define BUTTON_PIN 3 // Arduino Digital I/O pin for button/reed switch
#define BUZZER_PIN 5
#define LED 13

#define SENSOR_TEMP_OFFSET 0 // Set this offset if the sensor has a permanent small offset to the real temperatures

//Constants
static const uint64_t UPDATE_INTERVAL = 2000; // Sleep time between sensor updates (in milliseconds) // Must be >1000ms for DHT22 and >2000ms for DHT11

// Force sending an update of the temperature after n sensor reads, so a controller showing the
// timestamp of the last update doesn't show something like 3 hours in the unlikely case, that
// the value didn't change since;
// i.e. the sensor would force sending an update every UPDATE_INTERVAL*FORCE_UPDATE_N_READS [ms]
static const uint8_t FORCE_UPDATE_N_READS = 10;

bool initialValueSent = false; // Init Homeassistant

//Childs
#define CHILD_ID_HUM 0
#define CHILD_ID_TEMP 1
#define CHILD_ID_LIGHT 2
#define CHILD_ID_SOUND 3
#define CHILD_ID_BUTTON 4
#define CHILD_ID_BUZZER 6

//Variables
//Temp e Hum
float lastTemp = 0;
float lastHum = 0;
uint8_t nNoUpdatesTemp;
uint8_t nNoUpdatesHum;
bool metric = true;
MyMessage msgHum(CHILD_ID_HUM, V_HUM);
MyMessage msgTemp(CHILD_ID_TEMP, V_TEMP);
DHT dht;

//Light
MyMessage msgLight(CHILD_ID_LIGHT, V_LIGHT_LEVEL);
int lastLightLevel = 0;

//Microphone
MyMessage msgSound(CHILD_ID_SOUND, V_LEVEL);
int lastSoundLevel = 0;

//Button
Bounce debouncer = Bounce();
int oldValue = -1;
MyMessage msgButton(CHILD_ID_BUTTON, V_TRIPPED);

//Buzzer
MyMessage textMsg(CHILD_ID_BUZZER, V_TEXT);
int lastSong = 0;

void presentation()
{
  sendSketchInfo("BabyBox", "1.2");   // Send the sketch version information to the gateway

  // Register all sensors to gw (they will be created as child devices)
  present(CHILD_ID_HUM, S_HUM);
  present(CHILD_ID_TEMP, S_TEMP);
  present(CHILD_ID_LIGHT, S_LIGHT_LEVEL);
  present(CHILD_ID_SOUND, S_SOUND);
  present(CHILD_ID_BUTTON, S_DOOR);
  present(CHILD_ID_BUZZER, S_INFO);
  
  metric = getControllerConfig().isMetric;
}

void setup()
{  
  dht.setup(DHT_DATA_PIN); // set data pin of DHT sensor
  if (UPDATE_INTERVAL <= dht.getMinimumSamplingPeriod()) {
    Serial.println("Warning: UPDATE_INTERVAL is smaller than supported by the sensor!");
  }
  // Sleep for the time of the minimum sampling period to give the sensor time to power up
  // (otherwise, timeout errors might occure for the first reading)
  sleep(dht.getMinimumSamplingPeriod());

  // Setup the button
//  attachInterrupt(0, button_pressed, RISING); //Configurando a interrupção
  pinMode(LED, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  // Activate internal pull-up
  digitalWrite(BUTTON_PIN, HIGH);

  // After setting up the button, setup debouncer
  debouncer.attach(BUTTON_PIN);
  debouncer.interval(5);

  //Buzzer
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop()
{  
  if (!initialValueSent) {

    Serial.println("Sending initial value");
    send(msgHum.set((int) lastHum));
    send(msgTemp.set((int) lastTemp));
    send(msgLight.set((int) lastLightLevel));
    send(msgSound.set((int) lastSoundLevel));
    send(msgButton.set(0));
    send(textMsg.set("0"));

    Serial.println("Requesting initial value from controller");
    request(CHILD_ID_HUM, V_HUM);
    wait(2000, C_SET, V_HUM);
    request(CHILD_ID_TEMP, V_TEMP);
    wait(2000, C_SET, V_TEMP);
    request(CHILD_ID_LIGHT, V_LIGHT_LEVEL);
    wait(2000, C_SET, V_LIGHT_LEVEL);
    request(CHILD_ID_SOUND, V_LEVEL);
    wait(2000, C_SET, V_LEVEL);
    request(CHILD_ID_BUTTON, V_TRIPPED);
    wait(2000, C_SET, V_TRIPPED);
    request(CHILD_ID_BUZZER, V_TEXT);
    wait(2000, C_SET, V_TEXT);
  }

  // Force reading sensor, so it works also after sleep()
  dht.readSensor(true);

  // Get temperature from DHT library
  float temperature = dht.getTemperature();
  if (isnan(temperature)) {
    Serial.println("Failed reading temperature from DHT!");
  } else if (temperature != lastTemp || nNoUpdatesTemp == FORCE_UPDATE_N_READS) {
    // Only send temperature if it changed since the last measurement or if we didn't send an update for n times
    lastTemp = temperature;
    if (!metric) {
      temperature = dht.toFahrenheit(temperature);
    }
    // Reset no updates counter
    nNoUpdatesTemp = 0;
    temperature += SENSOR_TEMP_OFFSET;
    send(msgTemp.set(temperature, 1));
  } else {
    // Increase no update counter if the temperature stayed the same
    nNoUpdatesTemp++;
  }

  // Get humidity from DHT library
  float humidity = dht.getHumidity();
  if (isnan(humidity)) {
    Serial.println("Failed reading humidity from DHT");
  } else if (humidity != lastHum || nNoUpdatesHum == FORCE_UPDATE_N_READS) {
    // Only send humidity if it changed since the last measurement or if we didn't send an update for n times
    lastHum = humidity;
    // Reset no updates counter
    nNoUpdatesHum = 0;
    send(msgHum.set(humidity, 1));
  } else {
    // Increase no update counter if the humidity stayed the same
    nNoUpdatesHum++;
  }

  // Light level
  int16_t lightLevel = (1023 - analogRead(LDR_DATA_PIN)) / 10.23;
  if (lightLevel != lastLightLevel) {
    send(msgLight.set(lightLevel));
    lastLightLevel = lightLevel;
  }

  // Sound level
  int16_t soundLevel = (analogRead(SOUND_DATA_PIN));
  if (soundLevel != lastSoundLevel) {
    send(msgSound.set(soundLevel));
    lastSoundLevel = soundLevel;
  }

  //PRINT
#ifdef MY_DEBUG
  Serial.print("lastTemp: ");
  Serial.println(lastTemp);
  Serial.print("lastHum: ");
  Serial.println(lastHum);
  Serial.print("lastLightLevel: ");
  Serial.println(lastLightLevel);
  Serial.print("lastSoundLevel: ");
  Serial.println(lastSoundLevel);
  Serial.print("lastSong: ");
  Serial.println(lastSong);
#endif

  button_pressed();
  
  // Sleep for a while to save energy
  sleep(UPDATE_INTERVAL);

  request(CHILD_ID_BUZZER, V_TEXT);
  wait(1000, C_SET, V_TEXT);

}

void button_pressed() {
  debouncer.update();
  // Get the update value
  int value = debouncer.read();
  if (value != oldValue) {
    // Send in the new value
    send(msgButton.set(value == HIGH ? 1 : 0));
    oldValue = value;
    if (value == LOW) {
      tone(BUZZER_PIN,1500);   
      delay(100);
      //Desligando o buzzer.
      noTone(BUZZER_PIN);
    }
  }
}

void receive(const MyMessage &message) {
  if (message.type == V_TEXT) {
    if (!initialValueSent) {
      Serial.println("Receiving initial value from controller");
      initialValueSent = true;
    }
    int song = message.getInt();
    send(textMsg.set("0"));
    lastSong = song;
    switch (song) {
    case 1:
      imperial_song();
      break;
    case 2:
      elfen_song();      
      break;
    case 3:
      sweet_song();
      break;
//    case 4:
//      lullaby_song();
//      break;
    case 5:
      twinkle_song();
      twinkle_song();
      break;
    case 6:
      zelda_song();
      break;
    default:
      // default is optional
    break;
    }
  }
}

