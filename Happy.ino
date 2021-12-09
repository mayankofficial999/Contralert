#include <ESP8266WiFi.h>
#include "Adafruit_MQTT.h"
#include "Adafruit_MQTT_Client.h"

#define WLAN_SSID       "Home_Router"
#define WLAN_PASS       "DkSharma@1294"

#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "mayankOnAdafruit"
#define AIO_KEY         "aio_VeKp00mS8RJjJvuWzGdJMy08Lqf0"

WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_USERNAME, AIO_KEY);
Adafruit_MQTT_Subscribe issue_open = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/issue", MQTT_QOS_1);
Adafruit_MQTT_Subscribe pr_open = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/pr-open", MQTT_QOS_1);
Adafruit_MQTT_Subscribe pr_close = Adafruit_MQTT_Subscribe(&mqtt, AIO_USERNAME "/feeds/pr-close", MQTT_QOS_1);

int piezoPin = 12;

void issue_open_callback(char *data, uint16_t len) {
  Serial.print("New Issue status: ");
  Serial.println(data);
  if(strcmp (data, "true") == 0)
  tone1();
}

void pr_open_callback(char *data, uint16_t len) {
  Serial.print("PR Open : ");
  Serial.println(data);
  if(strcmp (data, "true") == 0)
  tone2();
}

void pr_close_callback(char *data, uint16_t len) {
  Serial.print("PR Close : ");
  Serial.println(data);
  if(strcmp (data, "true") == 0)
  tone3();
}

void MQTT_connect() {
  int8_t ret;

  // Stop if already connected.
  if (mqtt.connected()) {
    return;
  }

  Serial.print("Connecting to MQTT... ");

  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) { // connect will return 0 for connected
       Serial.println(mqtt.connectErrorString(ret));
       Serial.println("Retrying MQTT connection in 5 seconds...");
       mqtt.disconnect();
       delay(5000);  // wait 5 seconds
       retries--;
       if (retries == 0) {
         // basically die and wait for WDT to reset me
         while (1);
       }
  }
  Serial.println("MQTT Connected!");
}

void setup() {
  Serial.begin(115200);
  delay(10);

  Serial.println(F("Adafruit MQTT demo"));

  // Connect to WiFi access point.
  Serial.println(); Serial.println();
  Serial.print("Connecting to ");
  Serial.println(WLAN_SSID);

  WiFi.begin(WLAN_SSID, WLAN_PASS);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.println("WiFi connected");
  Serial.println("IP address: "); 
  Serial.println(WiFi.localIP());
  
  issue_open.setCallback(issue_open_callback);
  mqtt.subscribe(&issue_open);
  pr_open.setCallback(pr_open_callback);
  mqtt.subscribe(&pr_open);
  pr_close.setCallback(pr_close_callback);
  mqtt.subscribe(&pr_close);
  
}

void tone1() {
  tone(piezoPin, 1000, 500);
  delay(1000);
  tone(piezoPin,2000,500);
  delay(1000);
}

void tone2() {
  tone(piezoPin, 500, 500);
  delay(1000);
  tone(piezoPin,800,500);
  delay(1000);
}

void tone3(){
  tone(piezoPin, 3000, 500);
  delay(1500);
  tone(piezoPin,5000,500);
  delay(1500);
}

void loop() {
  MQTT_connect();
  mqtt.processPackets(10000);
  if(! mqtt.ping()) {
    mqtt.disconnect();
  }
  //tone1();
  //delay(2000);
  //tone2();

}
#Testing Change
