#include "Helpers/String/StringToIPParser.h"

StringToIPParser::StringToIPParser()
{
}

IPAddress StringToIPParser::parse(const char* ip) 
{
    char copy[16];
    strncpy(copy, ip, sizeof(copy));

    char* token = strtok(copy, ".");
    int octet1 = atoi(token);

    token = strtok(nullptr, ".");
    int octet2 = atoi(token);

    token = strtok(nullptr, ".");
    int octet3 = atoi(token);

    token = strtok(nullptr, ".");
    int octet4 = atoi(token);

    return IPAddress(octet1, octet2, octet3, octet4);
}
