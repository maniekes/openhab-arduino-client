#ifndef OPENHAB_CLIENT_H
#define OPENHAB_CLIENT_H

#include <Arduino.h>
#include <HTTPClient.h>

/**
 * @class OpenHABClient
 * @brief A client for interacting with an OpenHAB server.
 */
class OpenHABClient {
 public:
  /**
   * @brief Constructs an OpenHABClient with the specified server address.
   * @param server The address of the OpenHAB server including http:// or
   * https:// and without trailing slash.
   */
  OpenHABClient(const String& server);

  /**
   * @brief Sets the basic authentication credentials.
   * @param username The username for authentication.
   * @param password The password for authentication.
   */
  void setAuth(const String& username, const String& password);

  /**
   * @brief Sets the bearer token for authentication.
   * @param token The bearer token.
   */
  void setBearerToken(const String& token);

  /**
   * @brief Gets the state of the specified item.
   * @param item The name of the item.
   * @return The state of the item as a String.
   */
  String getItemState(const String& item);

  /**
   * @brief Gets the state of the specified item as a boolean.
   * @param item The name of the item.
   * @return True if the item state is "ON" or "OPEN", false otherwise.
   */
  bool getItemStateBoolean(const String& item) {
    auto state = getItemState(item);
    return state == "ON" || state == "OPEN";
  }

  /**
   * @brief Gets the state of the specified item as a long integer.
   * @param item The name of the item.
   * @return The state of the item as a long integer.
   */
  long getItemStateLong(const String& item) {
    return getItemState(item).toInt();
  }

  /**
   * @brief Gets the state of the specified item as a float.
   * @param item The name of the item.
   * @return The state of the item as a float.
   */
  float getItemStateFloat(const String& item) {
    return getItemState(item).toFloat();
  }

  /**
   * @brief Sends a command to the specified item.
   * @param item The name of the item.
   * @param command The command to send.
   * @return True if the command was sent successfully, false otherwise.
   */
  bool sendCommand(const String& item, const String& command);

  /**
   * @brief Updates the state of the specified item.
   * @param item The name of the item.
   * @param state The new state of the item as a String.
   * @return True if the state was updated successfully, false otherwise.
   */
  bool updateItemState(const String& item, const String& state);

  /**
   * @brief Updates the state of the specified item.
   * @param item The name of the item.
   * @param state The new state of the item as a long integer.
   * @return True if the state was updated successfully, false otherwise.
   */
  bool updateItemState(const String& item, const long state) {
    return updateItemState(item, String(state));
  };

  /**
   * @brief Updates the state of the specified item.
   * @param item The name of the item.
   * @param state The new state of the item as a float.
   * @return True if the state was updated successfully, false otherwise.
   */
  bool updateItemState(const String& item, const float state) {
    return updateItemState(item, String(state));
  };

  /**
   * @brief Updates the state of the specified item.
   * @param item The name of the item.
   * @param state The new state of the item as a boolean.
   * @param isContact Whether the item is a contact sensor. for contact sensors,
   * the state is "OPEN" or "CLOSED", otherwise it is "ON" or "OFF".
   * @return True if the state was updated successfully, false otherwise.
   */
  bool updateItemState(const String& item, const bool state,
                       const bool isContact = false) {
    return isContact ? updateItemState(item, state ? "OPEN" : "CLOSED")
                     : updateItemState(item, state ? "ON" : "OFF");
  };

 protected:
  String _server;
  String _authHeader;
};

#endif
