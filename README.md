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

# Home-Assistant

Home: http://hbo.duckdns.org:1111/states

Components: https://home-assistant.io/components/

MySensors: https://www.mysensors.org/build/raspberry

CloudMQTT: https://cloudmqtt-api.herokuapp.com/sso/heroku/websocket

# Components

Organization
* https://home-assistant.io/components/group/
* https://home-assistant.io/components/zone/
* https://home-assistant.io/components/scene/
* https://home-assistant.io/docs/configuration/devices/
* https://home-assistant.io/docs/configuration/customizing-devices/
* https://home-assistant.io/docs/configuration/troubleshooting/

Hub
* https://home-assistant.io/components/mqtt/
* https://home-assistant.io/components/mysensors/
* https://home-assistant.io/components/zoneminder/

Automation/Input
* https://home-assistant.io/components/script/
* https://home-assistant.io/components/proximity/
* https://home-assistant.io/components/device_sun_light_trigger/
* https://home-assistant.io/components/input_slider/
* https://home-assistant.io/components/input_select/
* https://home-assistant.io/components/input_boolean/
* https://home-assistant.io/components/ifttt/
* https://home-assistant.io/components/arduino/
* https://home-assistant.io/components/automation/
* https://home-assistant.io/components/lirc/
* https://home-assistant.io/components/shell_command/
* https://home-assistant.io/components/sensor.onewire/

Text-to-speech
* https://home-assistant.io/components/tts.google/

Front end
* https://home-assistant.io/components/panel_custom/
* https://home-assistant.io/components/panel_iframe/
* https://home-assistant.io/components/weblink/

Transport
* https://home-assistant.io/components/sensor.google_travel_time/
* https://home-assistant.io/components/sensor.torque/
* https://home-assistant.io/components/sensor.uber/

Media Player
* https://home-assistant.io/components/media_player.cast/
* https://home-assistant.io/components/media_player.gpmdp/
* https://home-assistant.io/components/media_player.kodi/
* https://home-assistant.io/components/media_player.plex/
* https://home-assistant.io/components/media_player.lg_netcast/
* https://home-assistant.io/components/media_player.webostv/
* https://home-assistant.io/components/media_player.universal/
* https://home-assistant.io/components/media_player.mpd/
http://www.pimusicbox.com/

Presence Detection
* https://home-assistant.io/components/device_tracker.nmap_tracker/
* https://home-assistant.io/components/device_tracker.owntracks/
* https://home-assistant.io/components/device_tracker.ping/

Input/Command/Binary Sensor/switch
* https://home-assistant.io/components/conversation/
* https://home-assistant.io/components/switch.command_line/ (SHUTDOWN YOUR LOCAL HOST, CONTROL YOUR VLC PLAYER, CONTROL FOSCAM MOTION SENSOR)
* https://home-assistant.io/components/binary_sensor.command_line/
* https://home-assistant.io/components/binary_sensor.http/
* https://home-assistant.io/components/binary_sensor.iss/
* https://home-assistant.io/components/binary_sensor.template/
* https://home-assistant.io/components/switch.template/
* https://home-assistant.io/components/binary_sensor.threshold/
* https://home-assistant.io/components/binary_sensor.trend/
* https://home-assistant.io/components/switch.wake_on_lan/
* https://github.com/dhleong/ps4-waker

Sensor/status
* https://home-assistant.io/components/sensor.min_max/
* https://home-assistant.io/components/sensor.moldindicator/
* https://home-assistant.io/components/sensor.dht/
* https://home-assistant.io/components/sensor.random/
* https://home-assistant.io/components/sensor.command_line/ (HARD DRIVE TEMPERATURE, CPU TEMPERATURE, MONITORING FAILED LOGIN ATTEMPTS ON HOME ASSISTANT, READ VALUE OUT OF A REMOTE TEXT FILE)
* https://home-assistant.io/components/sensor.http/
* https://home-assistant.io/components/sensor.speedtest/
* https://home-assistant.io/components/sensor.template/

Monitor
* https://home-assistant.io/components/sensor.systemmonitor/
* https://home-assistant.io/components/sensor.statistics/

Notifications
* https://home-assistant.io/components/notify/
* https://home-assistant.io/components/notify.facebook/
* https://home-assistant.io/components/notify.twitter/
* https://home-assistant.io/components/notify.webostv/
* https://home-assistant.io/components/notify.kodi/
* https://home-assistant.io/components/notify.group/
* https://home-assistant.io/components/notify.pushbullet/
* https://home-assistant.io/components/notify.html5/
* https://home-assistant.io/components/notify.telegram/
* https://home-assistant.io/components/persistent_notification/
* https://home-assistant.io/components/notify.rest/

Downloading
* https://home-assistant.io/components/sensor.transmission/
* https://home-assistant.io/components/switch.transmission/
* https://home-assistant.io/components/sensor.scrape/

DIY
* https://home-assistant.io/components/sensor.serial_pm/ (Particulate matter sensors)
* https://www.open-homeautomation.com/2016/07/19/measuring-air-quality/
* https://home-assistant.io/components/sensor.miflora/

Outers
* https://home-assistant.io/components/browser/
* https://home-assistant.io/components/feedreader/
* https://home-assistant.io/components/discovery/
* https://home-assistant.io/components/frontend/
* https://home-assistant.io/components/http/
* https://home-assistant.io/components/logger/

Camera
* https://home-assistant.io/components/camera.ffmpeg/
* https://home-assistant.io/components/camera.foscam/
* https://home-assistant.io/components/camera.generic/

Image Processing
* https://home-assistant.io/components/image_processing.microsoft_face_detect/
* https://home-assistant.io/components/image_processing.microsoft_face_identify/

Alarm
* https://home-assistant.io/components/alarm_control_panel.manual/

Calendar
* https://home-assistant.io/components/calendar.google/
* https://home-assistant.io/components/sensor.time_date/
* https://home-assistant.io/components/binary_sensor.workday/

History
* https://home-assistant.io/components/history/
* https://home-assistant.io/components/sensor.history_stats/
* https://home-assistant.io/components/recorder/

Finance
* https://home-assistant.io/components/sensor.fixer/
* https://home-assistant.io/components/sensor.yahoo_finance/

Weather
* https://home-assistant.io/components/sensor.moon/
* https://home-assistant.io/components/weather.openweathermap/
* https://home-assistant.io/components/sun/
* https://home-assistant.io/components/sensor.openweathermap/
* https://home-assistant.io/components/sensor.waqi/
* https://home-assistant.io/components/sensor.yweather/
* https://home-assistant.io/components/sensor.yr/
