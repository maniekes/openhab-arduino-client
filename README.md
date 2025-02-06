# OpenHABClient

OpenHABClient is a simple Arduino library for interacting with an OpenHAB server via its REST API.

## Features

- Get the state of an item
- Send commands to items
- Update the state of items
- Supports basic and bearer token authentication

## Installation

1. Download the library from the [repository](https://github.com/maniekes/openhab-arduino-client).
2. Extract the library to your Arduino libraries folder.

## Usage

### Include the library

```cpp
#include <OpenHABClient.h>
```

### Initialize the client

```cpp
OpenHABClient client("http://your-openhab-server-address");
```

### Set authentication

#### Basic Authentication

```cpp
client.setAuth("username", "password");
```

#### Bearer Token

```cpp
client.setBearerToken("your-bearer-token");
```

### Get item state

```cpp
String state = client.getItemState("itemName");
```

### Send command to item

```cpp
bool success = client.sendCommand("itemName", "command");
```

### Update item state

```cpp
bool success = client.updateItemState("itemName", "newState");
```

## License

This library is licensed under the MIT License. See the [LICENSE](https://github.com/maniekes/openhab-arduino-client/blob/main/LICENSE) file for more details.

## Authors

- Rafal Klimonda (maniekes@gmail.com)

For more information, visit the [homepage](https://github.com/maniekes/openhab-arduino-client).