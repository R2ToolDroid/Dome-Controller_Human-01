///Automatische Domebewegung Steuerung
///Doc Snyder Tool Droid DomeController
///für Arduino pro mini

#include "ReelTwo.h"
#include "core/Animation.h"
#include "core/DelayCall.h"
#include "ServoDispatchDirect.h"
#include "ServoSequencer.h"

#include <SoftwareSerial.h>        // Durch diesen Include können wir die Funktionen 

#include <Wire.h>  
#include "Grove_Human_Presence_Sensor.h" // der SoftwareSerial Bibliothek nutzen.
SoftwareSerial MainInput(14, 15); // Pin D14 ist RX, Pin D15 ist TX.
                                   // Die Funktion softSerial() kann nun wie Serial() genutzt werden.                                                                
#include "vars.h"

AK9753 movementSensor;

int ir1, ir2, ir3, ir4;
float temp = 24;

#include "Mdriver.h"
#include "animation.h"

ServoDispatchDirect<SizeOfArray(servoSettings)> servoDispatch(servoSettings);
ServoSequencer servoSequencer(servoDispatch);
AnimationPlayer player(servoSequencer);

#include "command.h"

void setup(){
  Serial.begin(9600);
  MainInput.begin(9600);
   // set the digital pin as output:
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPinC, OUTPUT);

  pinMode(links, OUTPUT);
  pinMode(rechts, OUTPUT);

  pinMode(SendStatus,INPUT);
  pinMode(sensorCenter,INPUT);

  digitalWrite(links, 0);  
  digitalWrite(rechts, 0); 
 
  // if analog input pin 0 is unconnected, random analog
  // noise will cause the call to randomSeed() to generateB
  // different seed numbers each time the sketch runs.
  // randomSeed() will then shuffle the random function.
  randomSeed(analogRead(0));
  //delay(2000);
  //Serial.println("DomeController_ Doc Tooldroide");
  //Serial.println("...ready for Command_");
  
  //startseq();

   REELTWO_READY();
   SetupEvent::ready();
   Wire.begin();

   //Turn on sensor
    if (movementSensor.initialize() == false) {
        Serial.println("Device not found. Check wiring.");
        //while (1);
        delay(3000);
    }
   //last_time = millis();
   
}


void loop() {

    Comand();
    AnimatedEvent::process();

  if (Mode == 0){
     randomMove();
     durchlauf = durchlauf+1;
  }

  if (Mode == 1  ){
      rcMove();
  }

  if (Mode == 2  ){
     human(); 
  }

  if (durchlauf == 10 ) {
    center("L");
    } 
    
  //Serial.println(durchlauf);
    stat = digitalRead(SendStatus);

    //Serial.print(stat);

    if (stat == 0) {
      Mode++;
      digitalWrite(ledPinC, HIGH);  
      delay(1000);
      digitalWrite(ledPinC, LOW);  
      }
     if (Mode >= 3){Mode=0;}
    
}
