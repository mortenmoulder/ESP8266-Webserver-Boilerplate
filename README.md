# ESP8266-Webserver-Boilerplate
A boilerplate for an ESP8266 webserver. Use it for regular GET requests.

# How to use
Right now you can only send a request to / with one argument. Well, you can send multiple arguments, but only one is being handled. Here's an example:

    String arg1 = server.arg(0);
    Serial.println(arg1);
    
If you send a request to `http://192.168.1.123/?foo=bar` it will write `bar` in the Serial Monitor and respond with `Success!` on the page.

# WiFi Manager
You might have noticed the ESP8266 doesn't include any hardcoded WiFi credentials. There's a reason for that. I use [WiFiManager](https://github.com/tzapu/WiFiManager) and it automatically creates a hotspot for your ESP8266. Once you're connected to its WiFi, you should be able to open any website and it will automatically redirect you to its WiFi manager. If not, try to visit a website without SSL (such as [nossl.net](http://nossl.net/)).

If you don't want to use the WiFi Manager, you can still do it yourself. Just make sure to include the `WiFi.h` library. 

    #include <WiFi.h>
    
    const char* ssid = "SSID";
    const char* password = "PASSWORD";
    void setup() {
        WiFi.begin(ssid, password);
        
        Serial.println("Connected to: " + ssid);
        
        Serial.print("IP address of ESP8266: ");
        Serial.println(WiFi.localIP()); //localIP() doesn't return a string, so we can't be arsed to convert it
    }
