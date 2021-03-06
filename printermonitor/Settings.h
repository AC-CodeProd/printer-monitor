/** The MIT License (MIT)

Copyright (c) 2018 David Payne

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

/******************************************************************************
 * Printer Monitor is designed for the Wemos D1 ESP8266
 * Wemos D1 Mini:  https://amzn.to/2qLyKJd
 * 0.96" OLED I2C 128x64 Display (12864) SSD1306
 * OLED Display:  https://amzn.to/2JDEAUF
 ******************************************************************************/
/******************************************************************************
 * NOTE: The settings here are the default settings for the first loading.  
 * After loading you will manage changes to the settings via the Web Interface.  
 * If you want to change settings again in the settings.h, you will need to 
 * erase the file system on the Wemos or use the “Reset Settings” option in 
 * the Web Interface.
 ******************************************************************************/

#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>
#include <ESP8266mDNS.h>
#include <ArduinoOTA.h>
#include "TimeClient.h"
#include "OctoPrintClient.h"
#include "FS.h"
#include "SSD1306Wire.h"
#include "OLEDDisplayUi.h"

//******************************
// Start Settings
//******************************

// OctoPrint Monitoring -- Monitor your 3D printer OctoPrint Server
String OctoPrintApiKey = "";  // ApiKey from your User Account on OctoPrint
String OctoPrintServer = ""; // IP or Address of your OctoPrint Server (DO NOT include http://)
int OctoPrintPort = 80; // the port you are running your OctoPrint server on (usually 80);

const int WEBSERVER_PORT = 80; // The port you can access this device on over HTTP
const boolean WEBSERVER_ENABLED = true;  // Device will provide a web interface via http://[ip]:[port]/
char* www_username = "admin";  // User account for the Web Interface
char* www_password = "password";  // Password for the Web Interface
float UtcOffset = -7; // Hour offset from GMT for your timezone
int minutesBetweenDataRefresh = 60;

// Display Settings
const int I2C_DISPLAY_ADDRESS = 0x3c; // I2C Address of your Display (usually 0x3c or 0x3d)
const int SDA_PIN = D2;
const int SCL_PIN = D5;

boolean ENABLE_OTA = true;  // this will allow you to load firmware to the device over WiFi (see OTA for ESP8266)

//******************************
// End Settings
//******************************

String themeColor = "light-green"; // this can be changed later in the web interface.
