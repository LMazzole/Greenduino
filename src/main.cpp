#define MYDEBUG
#include <Arduino.h>
#include "debug.h"
#include "pinmapping.h"

void setup() {
    // put your setup code here, to run once:

    // declare relay as output
    pinMode(relay1, OUTPUT);
    pinMode(relay2, OUTPUT);
    pinMode(relay3, OUTPUT);
    pinMode(relay4, OUTPUT);
    // declare pump as output
    pinMode(pump, OUTPUT);
    // declare the ledPin as an OUTPUT:
    Serial.begin(9600);
}

void loop() {
    // put your main code here, to run repeatedly:

     // read the value from the moisture sensors:
     moisture1_value = analogRead(moisture1);
     moisture2_value = analogRead(moisture2);
     moisture3_value = analogRead(moisture3);
     moisture4_value = analogRead(moisture4);

     // check which plant need water
     // and open the switch for that specific plant

     if(moisture1_value<=450){
      digitalWrite(relay1, HIGH);
     }
     if(moisture2_value<=450){
      digitalWrite(relay2, HIGH);
     }
     if(moisture3_value<=450){
      digitalWrite(relay3, HIGH);
     }
     if(moisture4_value<=450){
      digitalWrite(relay4, HIGH);
     }

     // make sure there is at least one plant that needs water
     // if there is, open the motor
     if(moisture1_value<=450 || moisture2_value<=450 || moisture3_value<=450 || moisture4_value<=450){
       digitalWrite(pump, HIGH);
     }

     // let it water the plant for 5 seconds
     delay(5000);

     // turn the pump off
     digitalWrite(pump, LOW);

     // go each switch and turn them off
     digitalWrite(relay1, LOW);
     digitalWrite(relay2, LOW);
     digitalWrite(relay3, LOW);
     digitalWrite(relay4, LOW);

     // wait 5 minutes and repeat the process
     delay(300000);
}
