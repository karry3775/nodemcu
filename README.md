# nodemcu_server.ino
This file creates a web server from ESP8266 NodeMCU microcontroller, which is monitored over a local network (Mobile Hotspot).
The NodeMCU is connected to a LED which is wirelessly controlled.
# python_client.py
This file use POST requests to the same server, to reach a specific page, which essentially ends up in toggling a LED.
