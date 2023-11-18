// IPParser.h
#ifndef IPPARSER_H
#define IPPARSER_H

#include <ESP8266WiFi.h>

class IPParser {
public:
  IPParser();
  IPAddress parse(const char* ip);

private:

};

#endif