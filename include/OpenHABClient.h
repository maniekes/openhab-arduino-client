#ifndef OPENHAB_CLIENT_H
#define OPENHAB_CLIENT_H

#include <Arduino.h>
#include <HTTPClient.h>

class OpenHABClient {
public:
    OpenHABClient(const String& server);
    void setAuth(const String& username, const String& password);
    void setBearerToken(const String& token);

    String getItemState(const String& item);
    bool getItemStateBoolean(const String& item) {
        auto state = getItemState(item);
        return state == "ON" || state == "OPEN";
    }
    long getItemStateLong(const String& item) {
        return getItemState(item).toInt();
    }
    float getItemStateFloat(const String& item) {
        return getItemState(item).toFloat();
    }
    

    bool sendCommand(const String& item, const String& command);

    bool updateItemState(const String& item, const String& state);
    bool updateItemState(const String& item, const long state) {
        return updateItemState(item, String(state));
    };
    bool updateItemState(const String& item, const float state) {
        return updateItemState(item, String(state));
    };
    bool updateItemState(const String& item, const bool state, const bool isContact = false) {
        return isContact ?
            updateItemState(item, state ? "OPEN":"CLOSED")
            :
            updateItemState(item, state ? "ON":"OFF");
    };

protected:
    String _server;
    String _authHeader;
};

#endif
