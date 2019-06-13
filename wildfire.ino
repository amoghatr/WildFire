#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESPDash.h>

AsyncWebServer server(80);

const char* ssid = ""; // WiFi SSID
const char* password = ""; //WiFi Password

int indicator = ; //ESP8266 GPIO No.


void buttonClicked(const char* id)
{
   if(digitalRead(indicator)== LOW)
   {
   digitalWrite(indicator, HIGH);
   Serial.printf("Light Is Glowing!");
   }
   else if (digitalRead(indicator)==HIGH)
   { 
   digitalWrite(indicator, LOW);
   Serial.printf("Light is Off");
   }
}


void setup()
{
    Serial.begin(9600);
    pinMode(indicator, OUTPUT);
    digitalWrite(indicator, LOW);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
    
    ESPDash.init(server);   // Initiate ESPDash and attach your Async webserver instance
    // Add Respective Cards and attach Button Click Function
    ESPDash.addButtonCard("btn1", "Switch");
    ESPDash.attachButtonClick(buttonClicked);

    server.begin();
}

void loop() {

}
