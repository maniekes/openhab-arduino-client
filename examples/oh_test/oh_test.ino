#include <OHClient.h>

const char* ssid = "YourWiFiSSID";
const char* password = "YourWiFiPassword";
OpenHABClient openhab("192.168.1.100");  // Replace with your OpenHAB server IP

void setup() {
    Serial.begin(115200);

    Serial.println("Getting OpenHAB item state...");
    String state = openhab.getItemState("LivingRoom_Light");
    Serial.println("LivingRoom_Light state: " + state);

    Serial.println("Sending command to turn ON light...");
    if (openhab.sendCommand("LivingRoom_Light", "ON")) {
        Serial.println("Light turned ON!");
    } else {
        Serial.println("Failed to send command.");
    }
}

void loop() {
    // Nothing needed here for this example
}
