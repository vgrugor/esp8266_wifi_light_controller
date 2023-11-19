// MarToStringConverter.h
#ifndef MAPTOSTRINGCONVERTER_H
    #define MAPTOSTRINGCONVERTER_H

    #include <string>
    #include <map>
    #include <Arduino.h>

    class MarToStringConverter {
        public:
            MarToStringConverter();
            String printMap(const std::map<String, String>& myMap);
    };

#endif
