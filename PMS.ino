/* Libraries */
#include "ADS1X15.h"
#include <WiFi.h>
#include <HTTPClient.h>

/* Communication */
String apiKey = "CU52P30JDUUVEJ3W";     // Enter your Write API key from ThingSpeak
const char *ssid =  "freewifi";           // replace with your wifi ssid and wpa2 key
const char *pass =  "1sampai8";
String serverName = "https://api.thingspeak.com/update";

/* ADC */
int16_t val0[4] = { 0, 0, 0, 0 };
int16_t val1[4] = { 0, 0, 0, 0 };
int     idx = 0;
uint32_t lastTime = 0;

/* LED */
const int PIN_RED   = 15;
const int PIN_GREEN = 2;
const int PIN_BLUE  = 4;

/* Classes */
ADS1115 ADS0(0x49);
ADS1115 ADS1(0x48);
WiFiClient client;

void setup()
{
  Serial.begin(115200);
  initLED();
  fail();
  initADC();
  initWifi();
}

void loop()
{
  // wait until all the adc values are read
  while (ADS_read_all());
  sendtoServer();
  delay(1000);
  //request all the adc values
  ADS_request_all();
}