#include <OpenHABClient.h>


#define WIFI_SSID "WIFI_SSID"
#define WIFI_PASS "WIFI_PASS"
#define OH_TOKEN "your-token-here"
#define OH_HOST "https://openhab.server:9090"

OpenHABClient *ohclient;

void connectToWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Connecting to WiFi...");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("\nConnected to WiFi!");
}

void initOH() {
  ohclient = new OpenHABClient(OH_HOST);
  ohclient->setBearerToken(OH_TOKEN);
}


void setup() {
    Serial.begin(115200);
    connectToWiFi();
    initOH();
}

void loop() {
  String item1 = ohclient->getItemState("item_1");
  bool item2 = ohclient->getItemStateBoolean("item_2");
  long item3 = ohclient->getItemStateLong("item_3");
  Serial.printf("item1: %s, item2: %d, item3: %.2f\n", item1, item2, item3);
  ohclient->updateItemState("item_3", ++item3);
  ohclient->sendCommand("item_2", "TOGGLE");
  delay(10000);
}
