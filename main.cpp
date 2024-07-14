// ===========================================
// Weather Tester
// ===========================================

#include <dht11.h>
#define DHT11PIN 4

dht11 DHT11;

bool flag_shownMessage = false;

const int LED_PIN_PLS_WORK = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN_PLS_WORK, OUTPUT);
}

void loop()
{
  Serial.println();

  while (Serial.available() == 0) {
  }

  String valueOfSerialMonitor = Serial.readString(); 
  valueOfSerialMonitor.trim();

  if (valueOfSerialMonitor == "kairos") {
      int chk = DHT11.read(DHT11PIN);

      Serial.print("Humidity (%): ");
      Serial.println((float)DHT11.humidity, 2);

      Serial.print("Temperature   (C): ");
      Serial.println((float)DHT11.temperature, 2);


      if ((float)DHT11.humidity >= 60.0) {
        digitalWrite(LED_PIN_PLS_WORK, HIGH);

        if (!flag_shownMessage) {
          Serial.println("Weather is rainy!");
          flag_shownMessage = true;
        }
      }

      else {
        digitalWrite(LED_PIN_PLS_WORK, LOW);
        if (!flag_shownMessage) {
          Serial.println("Weather is sunny!");
          flag_shownMessage = true;
        }
    }
  
    resetFlagOfMessage();
}

  delay(2000);
}

void resetFlagOfMessage() {
  delay(3000);
  flag_shownMessage = false;
  //clearSerialMonitor();
}

/*void clearSerialMonitor() {
  for (int i = 0; i < 30; i++) {
    Serial.println();
  }
}*/
