#include <Arduino.h>

#include <WiFi.h>
#include <FirebaseESP32.h>
#define _DISABLE_TLS

//WIFI CREDENTIALS
#define WIFI_SSID "IZZI-1947"
#define WIFI_PASSWORD "AcirK4HK"

//FIREBASE CREDENTIALS
#define FIREBASE_HOST "https://iotapp-5608d-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "AIzaSyAcQny59ysfpBkhQ3xGjyztIeDJcFo0G4o"

//DEFINE FIREBASE DATA OBJECTS
FirebaseData fbdo;
FirebaseData firebaseData;
FirebaseJson updateSensorValue;
FirebaseJson json;

int gpioVal = 0;
#define LED 13

String pathled = "/ESP32IotAPP/GPIO/";

void setup() 
{
  Serial.begin(9600);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  pinMode(LED, OUTPUT);
  digitalWrite(LED, LOW);
}

void loop() {
  Serial.println("Funcionando");
  gpioVal =! gpioVal;
  digitalWrite(LED, gpioVal);
  delay(1000);

  updateSensorValue.add("GPIO", gpioVal);

  updateSensorValue.add("ESP32IotAPP", json);
  Firebase.RTDB.updateNode(&fbdo, "/ESP32IotAPP", &updateSensorValue);
}

