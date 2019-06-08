#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ArduinoJson.h>

//wifi credentials
const char* ssid = "*****";
const char* password = "******";

int led = 5;

//begin instance of the webserver on port 80
ESP8266WebServer server(80);

void setup(){
  pinMode(led,OUTPUT);
  digitalWrite(led,LOW);
  WiFi.begin(ssid,password);
  Serial.begin(115200);
  while(WiFi.status()!=WL_CONNECTED){
    Serial.print(". ");
    delay(10);    
    }
  Serial.println("");
  Serial.print("IP ADDRESS: \t");
  Serial.println(WiFi.localIP());

  server.on("/",[](){server.send(200,"text/plain","welcome to the nodemcu webserver");});
  server.on("/toggle",handletoggle);
  server.on("/jblink",jblinkfunction);
  server.begin();
  }

 void loop(){
  server.handleClient();
  }

 void handletoggle(){
  digitalWrite(led,!digitalRead(led));
//  char string1 = digitalRead(led).to_Str();
  server.send(200,"text/plain","led toggled"); //204 is used for empty responses
  }
  void jblinkfunction(){
    String data = server.arg("plain");
    //step 1 is create a json buffer instance
    StaticJsonDocument<200> doc;
    deserializeJson(doc,data);
    
    String n = doc["times"];
    String t = doc["delay"];

    for(int i=0;i<=n.toInt();i++){
      digitalWrite(led,!digitalRead(led));
      delay(t.toInt());
      server.send(204,"");
      }
    
    }
