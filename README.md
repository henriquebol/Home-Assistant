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
# Carro (TK102)

* http://gpsbo.com.br/TK103-2_Portugues_user_manual.pdf

```
begin123456
apn123456 zap.vivo.com.br vivo vivo
adminip123456 serverip 5002
gprs123456
t030s***n123456
```

* https://www.traccar.org/
* Traccar is a free and open source GPS tracking system for hardware and software GPS trackers.

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
