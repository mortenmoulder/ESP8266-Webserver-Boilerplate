#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <DNSServer.h>
#include <WiFiManager.h>

MDNSResponder mdns;
ESP8266WebServer server(80);

void setup(void) {
  Serial.begin(115200);

  WiFiManager wifiManager;
  wifiManager.autoConnect("ESP8266 WiFi");

  server.on("/", handleRoot);

  server.begin();
}

void handleRoot() {
  if (server.args() > 0) {
    String arg1 = server.arg(0);
    Serial.println(arg1);
    
    server.send(200, "text/html", "Success!");
  }
}

void loop(void) {
  mdns.update();
  server.handleClient();
}
