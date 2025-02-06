#include "OpenHABClient.h"
#include <base64.h> 

OpenHABClient::OpenHABClient(const String& server) {
    _server = server;
}

void OpenHABClient::setAuth(const String& username, const String& password) {
    String credentials = username + ":" + password;
    _authHeader = "Basic " + base64::encode(credentials);
}

void OpenHABClient::setBearerToken(const String& token) {
    _authHeader = "Bearer " + String(token);
}

String OpenHABClient::getItemState(const String& item) {
    if (WiFi.status() != WL_CONNECTED) return "WiFi not connected";
    
    HTTPClient http;
    String url = _server + "/rest/items/" + item + "/state";
    http.begin(url);
    if (!_authHeader.isEmpty()) http.addHeader("Authorization", _authHeader);

    int httpCode = http.GET();

    String payload = (httpCode == 200) ? http.getString() : "Error: " + String(httpCode);
    http.end();
    return payload;
}

bool OpenHABClient::sendCommand(const String& item, const String& command) {
    if (WiFi.status() != WL_CONNECTED) return false;
    
    HTTPClient http;
    String url = _server + "/rest/items/" + item;
    http.begin(url);
    if (!_authHeader.isEmpty()) http.addHeader("Authorization", _authHeader);
    http.addHeader("Content-Type", "text/plain");

    int httpCode = http.POST(command);
    http.end();
    
    return httpCode == 200 || httpCode == 202;
}

bool OpenHABClient::updateItemState(const String& item, const String& state) {
    if (WiFi.status() != WL_CONNECTED) return false;
    
    HTTPClient http;
    String url = _server + "/rest/items/" + item + "/state";
    http.begin(url);
    if (!_authHeader.isEmpty()) http.addHeader("Authorization", _authHeader);
    http.addHeader("Content-Type", "text/plain");

    int httpCode = http.PUT(state);
    http.end();
    
    return httpCode == 200 || httpCode == 202;
}
