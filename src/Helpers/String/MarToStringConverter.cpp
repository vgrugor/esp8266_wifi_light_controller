#include "Helpers/String/MarToStringConverter.h"

MarToStringConverter::MarToStringConverter()
{
}

String MarToStringConverter::printMap(const std::map<String, String>& myMap)
{
     String kayValueString;

    for (const auto& entry : myMap) {
        kayValueString += entry.first + ": " + entry.second + "\n";
    }

    return kayValueString;
}
