# Funcionalidades
* Casa
  - Rastrear pessoas e veículos;
  - Previsão do tempo;
  - Aviso do próximo compromisso no google agenda:
    - Alerta no celular avisando a hora de sair;
    - Maps e streetview do local.

* Quarto 1
  - Câmera ip;
  - Tempo até o hospital;
  - Temperatura, umidade e luminosidade:
    - Alerta no celular se temperatura menor que 24 e maior que 30 graus;
    - Alerta se umidade menor que 20%;
    - Alerta se luminosidade maior que 90% de dia e 20% a noite;
  - Alerta no celular se o bebê chorar.
  
* Quarto 2
  - Tv LG e Chromecast:
    - Controle e amostra do que está sendo visto;
    - Envio de notificações.

* Sala
  - Ligar ps4.
   
* Cozinha
  - Lista de compras:
    - Aviso no celular dos itens faltantes toda sexta pela manhã.
    
* Server
  - Links;
  - Estatisticas do servidor;
  - Nmap.

--------------------------------------------------------------------------------------
# MySensors

[The Radio Communication (MySensors)](https://www.mysensors.org/about/network)

[Gateway Raspberry (MySensors)](https://www.mysensors.org/build/raspberry)
```
git clone https://github.com/mysensors/MySensors.git --branch master
cd MySensors
./configure --my-transport=nrf24 --my-rf24-irq-pin=15 --my-gateway=ethernet --my-controller-url-address=YOUR-CONTROLLER-ADDRESS
make
sudo ./bin/mysgw -d
sudo make install
```
```
function detect_machine { ...
eval "grep sunxi_platform /sys/class/sunxi_info/sys_info 2>/dev/null | sed 's/^.*: \(.*\)$/\1/'"
...case $hardware in BCM*)...
...soc="BCM2835"...
```

[Arduino Linux 64bits](https://www.arduino.cc/en/Main/Software)
> RESOURCE_NAME=arduino-arduinoide

[Air Humidity Sensor (MySensors)](https://www.mysensors.org/build/humidity)
* https://github.com/henriquebol/Home-Assistant/blob/master/arduino/dht11/dht11.ino
![GitHub Logo](/arduino/dht11/arduino_nrf_dht11_ldr_battery.png)

----------------------------------------------------------------------------------
# Arduino pro mini
![GitHub Logo](http://svc.dxcdn.com/upload/reviewpicture/201601/2f9e6fbb-d550-41d1-aa3c-72cdf441b05f.jpg)
http://www.instructables.com/id/Uploading-sketch-to-Arduino-Pro-Mini-using-Arduino/

## babyBOX

* https://github.com/henriquebol/Home-Assistant/blob/master/arduino/babybox.fzz
![GitHub Logo](/arduino/babybox_Esquemático.png)

Arduino Pro Mini para (5V / 16MHz)
* 3.3V~12V DC
* 5mA

NRF24L01
* 1.9-3.6V
* As the transmit mode, the transmit power is 6dBm, the current is 9.0mA, the accepted mode current is 12.3mA, the current consumption of the power-down mode and standby mode are lower
* Pro Mini      NRF24L01+ Color
* GND	          GND	      Black
* 5VReg -> 3.3V	VCC	      Red
* 9	            CE	      Orange
* 10	          CSN/CS	  Yellow
* 13	          SCK	      Green
* 11	          MOSI	    Blue
* 12	          MISO	    Violet
* 2	            IRQ	      Gray

DHT11
* 3,0 a 5,0 VDC (5,5 Vdc máximo)
* 200uA a 500mA, em standby de 100uA a 150 uA
* Pin + to Arduino Vcc
* Pin - to Arduino Gnd
* Pin data to Arduino A3 (for analog program)

KY-037 
* 5v DC
* Pin + to Arduino Vcc
* Pin - to Arduino Gnd
* Pin A0 to Arduino A0 (for analog program)
* Pin D0 to Arduino 13 (for digital program)


Regulador de Tensão 3.3V AMS1117
* Entrada: DC 4.5~7V;
* Saída: DC 3.3V +/- 0.05V;
* Corrente máxima: 800mA;

LDR
* 5V or 3.3V
* 0.5 mA.
* Resistor 10k (+)
* Pino A1


Buzzer
* 5V or (3.3V)
* Pino D5 (PWM)
* Resistor 66 Ohm (+)
* https://github.com/keithgardner2/sweetChild
* https://www.youtube.com/watch?v=vJMvCEaOpyw
* http://www.instructables.com/id/How-to-easily-play-music-with-buzzer-on-arduino-Th/
----------------------------------------------------------------------------------
# Home-Assistant

Home: http://hbo.duckdns.org:1111/states

Components: https://home-assistant.io/components/

MySensors: https://www.mysensors.org/build/raspberry

CloudMQTT: https://cloudmqtt-api.herokuapp.com/sso/heroku/websocket

### Gateway
sudo systemctl start mysgw.service

### Home Assistant
sudo systemctl start home-assistant@homeassistant.service

----------------------------------------------------------------------------------
# HTTPS
* https://hbo.duckdns.org

## DuckDNS
```
mkdir duckdns
cd duckdns
vi duck.sh
echo url="https://www.duckdns.org/update?domains=exampledomain&token=a7c4d0ad-114e-40ef-ba1d-d217904a50f2&ip=" | curl -k -o ~/duckdns/duck.log -K -
chmod 700 duck.sh
crontab -e
*/5 * * * * ~/duckdns/duck.sh >/dev/null 2>&1
./duck.sh
cat duck.log
sudo service cron start
```
## LET’S ENCRYPT
* Forward port 80 to port 80
* Forward port 443 to port 443

http://www.bruhautomation.com/single-post/2016/07/17/Part-3-Encrypting-Home-Assistant-and-External-Access

```
git clone https://github.com/letsencrypt/letsencrypt
cd letsencrypt
./letsencrypt-auto certonly --email youremail@address.com -d example.duckdns.org
sudo chmod -R 777 /etc/letsencrypt

crontab -e:
40 11,23 * * * ~/certbot/certbot-auto renew --quiet --no-self-upgrade >> ~/certbot/certbot_renew.log,
```
## Home Assistant 
* Forward port 443 (https connections) to port 8123
* Home Assistant has read access to the folder that holds the certificates

```
http:
  api_password: YOUR_SECRET_PASSWORD
  ssl_certificate: /etc/letsencrypt/live/hass-example.duckdns.org/fullchain.pem
  ssl_key: /etc/letsencrypt/live/hass-example.duckdns.org/privkey.pem
```
----------------------------------------------------------------------------------
# GPS Tracker

## Pessoas
* https://play.google.com/store/apps/details?id=com.mendhak.gpslogger
* https://home-assistant.io/components/device_tracker.gpslogger/
```
# Example configuration.yaml entry
device_tracker:
  - platform: gpslogger

Android:
http://<ha_server>/api/gpslogger?latitude=%LAT&longitude=%LON&device=%SER&accuracy=%ACC&battery=%BATT&speed=%SPD&direction=%DIR&altitude=%ALT&provider=%PROV&activity=%ACT
```

## Carro (TK102)
* http://hbo.duckdns.org:8082/

* https://github.com/tananaev/traccar/issues/329

```
begin123456
apn123456 zap.vivo.com.br vivo vivo
adminip123456 serverip 5001
gprs123456
t030s***n123456
```

* https://www.traccar.org/
* Portas no router: 8082 e 5001

```
sudo ./traccar.run
Start service:
3.8 and later: sudo /opt/traccar/bin/startDaemon.sh

Uninstall service:
3.8 and later: sudo /opt/traccar/bin/uninstallDaemon.sh
sudo rm -R /opt/traccar
```

* https://community.home-assistant.io/t/traccar-org-gps-gprs-tracker-custom-platform/15447

```
device_tracker:
   platform: traccar
   username: traccar_user
   password: traccar_password
   host: traccar_host ip/name including port number
```

 home/user/.homeassistant/custom_components/device_tracker/traccar.py
 ```
 #-*- coding: utf-8 -*-
 ```
 https://github.com/koen01/hass/blob/cd55cd0bdb84ae680d88bd4c8a20792e4637b71d/custom_components/device_tracker/traccar.py
