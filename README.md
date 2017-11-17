# ESP8266-Webserver-Boilerplate
A boilerplate for an ESP8266 webserver. Use it for regular GET requests.

# How to use
Right now you can only send a request to / with one argument. Well, you can send multiple arguments, but only one is being handled. Here's an example:

    String arg1 = server.arg(0);
    Serial.println(arg1);
    
If you send a request to `http://192.168.1.123/?foo=bar` it will write `bar` in the Serial Monitor and respond with `Success!` on the page.
