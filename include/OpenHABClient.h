#ifndef OPENHAB_CLIENT_H
#define OPENHAB_CLIENT_H

#include <Arduino.h>
#include <HTTPClient.h>

class OpenHABClient {
public:
    OpenHABClient(const char* server);
    String getItemState(const String& item);
    bool sendCommand(const String& item, const String& command);
    bool updateItemState(const String& item, const String& state);

private:
    String openhabServer;
};

#endif
