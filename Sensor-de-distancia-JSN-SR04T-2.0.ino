/*
  Created by TEOS
  Domotic with Arduino https://goo.gl/btZpjs
  YouTube https://goo.gl/k7TUSZ
  Instagram https://goo.gl/zEIjia
  Facebook https://goo.gl/eivraR
  Twitter https://goo.gl/du5Wgn
  Github https://goo.gl/Xl5IiS
  Google Plus https://goo.gl/gBnUdh
  WEB https://www.proyecto-teos.com/
*/

#include <NewPing.h> //https://bitbucket.org/teckel12/arduino-new-ping/wiki/Home
#include <medianFilter.h> //https://github.com/jeroendoggen/Arduino-signal-filtering-library

const uint8_t triggerPinT = 2, echoPinT = 3;
const uint16_t maxDistanceT = 500;
String resultSerialT;

NewPing sonarSensorT(triggerPinT, echoPinT, maxDistanceT);
medianFilter filterT;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  uint16_t distanceT = sonarSensorT.ping_cm(), distanceFilterT;

  if (distanceT >= 21 && distanceT < maxDistanceT) {
    distanceFilterT = filterT.run(distanceT);
    if (distanceT == distanceFilterT) {
      resultSerialT = "Distancia: " + String(distanceT) + "cm";
      Serial.println(resultSerialT);
    }
  }

  delay(500);
}
