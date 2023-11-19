// StringToIPParser.h
#ifndef STRINGTOIPPARSER_H
    #define STRINGTOIPPARSER_H

    #include <Arduino.h>
    #include <ESP8266WiFi.h>

    class StringToIPParser {
        public:
            StringToIPParser();
            IPAddress parse(const char* ip);

        private:

    };

#endif
