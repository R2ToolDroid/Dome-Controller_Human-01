#include <Arduino.h>       

void resetM(){
   digitalWrite(ledPin1, LOW); 
   digitalWrite(ledPin2, LOW); 
   ledState1 = LOW;
   ledState2 = LOW;
   digitalWrite(links, 0);  
   digitalWrite(rechts, 0);  
}

int center(String dir) {
    /// Fuert den Dome in die Ausgangsposition //
   centerState = digitalRead(sensorCenter);  
   if (debug) {   
    Serial.print(F("CenterMode "));
    Serial.println(centerState);
   }
    digitalWrite(rechts, 0); 
    digitalWrite(links, 0); 
      
      while ( centerState == 0){

                 centerState = digitalRead(sensorCenter);  
                
                if (dir == "L" ) {
                  digitalWrite(links, 50); 
                  digitalWrite(ledPin2, HIGH);                  
                } 
                
                if (dir == "R") {
                  digitalWrite(rechts, 50); 
                  digitalWrite(ledPin1, HIGH); 
                }
                
                if (debug){Serial.println(F("try to get center"));Serial.print(sensorCenter);}
              
 
      }
   digitalWrite(ledPin1, LOW); 
   digitalWrite(ledPin2, LOW); 
   digitalWrite(links, 0);  
   digitalWrite(rechts, 0);  
   
   delay(200);
   durchlauf = 0;
   
   //Mode = 0; 
}

void FindRoTime(){
    //int rotime;
    center("L");
    if (debug){Serial.println(F("Dome ist Center"));}  
    delay(1000);
    zeit1 = millis();
    center("L");
    zeit2 = millis();
    if (debug){Serial.print(F("Zeit1_"));Serial.println(zeit1); Serial.print(F("Zeit2_")); Serial.println(zeit2);}
    rotime = zeit2-zeit1;
    if (debug){Serial.print(F("rotime_")); Serial.println(rotime);}
    Rpos = rotime/360; ///Rpos ist dann Winkel in Zeit Variable  90° also SUM*90;
    center("R");
    if (debug){Serial.print(F("Rpos_")); Serial.println(Rpos);}
}


void rotateR( int Rpos) {
     if (debug){Serial.println(Rpos);}
     unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= Rpos) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // if the LED is off turn it on and vice-versa:
    if (ledState1 == LOW) {
      ledState1 = HIGH;
    } else {
      ledState1 = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin1, ledState1);
    digitalWrite(rechts, ledState1);  
  } //END IF
          
}

void rotateL( int Rpos) {
     
    if (debug){Serial.println(Rpos);}
     unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= Rpos) {
    // save the last time you blinked the LED
    previousMillis = currentMillis;
    // if the LED is off turn it on and vice-versa:
    if (ledState2 == LOW) {
      ledState2 = HIGH;
    } else {
      ledState2 = LOW;
    }
    // set the LED with the ledState of the variable:
    digitalWrite(ledPin2, ledState2);
    digitalWrite(links, ledState2); 
    
  } //END IF
}


int rcMove() {

    int sensorValue = pulseIn(sensorRC,HIGH);
    
    if (sensorValue >=800){ ///Check if Sensor is Connectet an RC on

    
    if (sensorValue < 1250){
      if (debug){ 
        Serial.println(F("Links"));
      }
          // set the LED with the ledState of the variable:
     //digitalWrite(ledPin2, HIGH);
     //tempo = sensorValue /4;
     //tempo = tempo *-1; 
     //tempo = tempo +500;

      tempo = map (sensorValue, 1250, 1015,50,255);
     
     
    //Drehung Rechts

    
     analogWrite(ledPin2, HIGH); 
     analogWrite(links, 0); 
     analogWrite(rechts, tempo); 
    
    } else if (sensorValue > 1650) {
      if (debug) {
      Serial.println(F("rechts"));
      }     
     // set the LED with the ledState of the variable:
      analogWrite(ledPin1, HIGH); 
      //tempo = sensorValue ;////6;
      tempo = map(sensorValue, 1650,2020,50,255);
      //tempo = tempo /5;
      
      analogWrite(rechts, 0);  
      analogWrite(links, tempo); 
     
    }  else {
      analogWrite(links, 0);  
      analogWrite(ledPin1, LOW); 
      analogWrite(rechts, 0); 
      analogWrite(ledPin2, LOW);     
      //delay (zeit);    
    }

    }///End Sensor Check
    
  if (debug) { 
    Serial.print(F("Tempo "));Serial.println(tempo);
    Serial.print(F("Value "));Serial.println(sensorValue);
    }
  
}

void randomMove() {
 
   // print a random number from 0 to 299
  zeit = random(3000, 6000)+(temp-20)*faktor;
  
  // print a random number from 10 to 19
  randNumber = random(10, 40);
  //Speed
  tempo = random(80,100);
  //Moving länge
  moving = random(500,1500);
 
  if (randNumber < 20){     ///Drehung Links
    if (debug){
    Serial.println(F("Links"));
     Serial.println(randNumber);
    }
     // set the LED with the ledState of the variable:
     analogWrite(ledPin2, HIGH);
     analogWrite(links, tempo);  
     delay(moving);
     analogWrite(links, 0);  
     analogWrite(ledPin2, LOW);
     delay(500);
    
    } else if (randNumber > 20 && randNumber <= 30) {  ///Rechts Drehung

     if (debug) {
      Serial.println(F("rechts"));
      Serial.println(randNumber);
     }
     // set the LED with the ledState of the variable:
      analogWrite(ledPin1, HIGH);   
      analogWrite(rechts, tempo); 
      delay(moving);      
      analogWrite(ledPin1, LOW); 
      analogWrite(rechts, 0); 
      delay(500);
      
    }  else {
      
      analogWrite(links, 0);  
      analogWrite(rechts, 0); 
      analogWrite(ledPin1, LOW); 
      analogWrite(ledPin2, LOW); 
      delay (zeit);  
    }

  if (debug) {
      Serial.print(F("Zeit "));
      Serial.println(zeit);
      Serial.print(F("Druchlauf "));
      Serial.println(durchlauf);
      Serial.print(F("Temp0 "));
      Serial.println(tempo);
      Serial.print(F("Temp "));
      Serial.println(temp);
      Serial.print(F("Faktor "));
      Serial.println(temp*faktor);
  }
 
}


void human(){
     if (movementSensor.dataReady()) {
        ir1 = movementSensor.getRawIR1();
        ir2 = movementSensor.getRawIR2();
        ir3 = movementSensor.getRawIR3();
        ir4 = movementSensor.getRawIR4();
        temp = movementSensor.getTMP();
        movementSensor.startNextSample();
        Sdiff = ir2 - ir4 ; ///Differenz

        int gap = 250;  /// Lücke wo nichts verfolgt wird

        int range = ir2+ir4;  /// Abstand

        if (range < 0 ) {
            gap = 200;
            } else {
              gap = 500;
            }

       
        
        if (debug)
        {  
        //Serial.print(F("1:BOT["));
        //Serial.print(ir1);
        Serial.print(F(" 2:RH["));
        Serial.print(ir2);
        //Serial.print(F("], 3:TOP["));
        //Serial.print(ir3);
        Serial.print(F("], 4:LH["));
        Serial.print(ir4);
        //Serial.print(F("], temp["));
        //Serial.print(temp);
        Serial.print(F("], diff["));
        Serial.print(Sdiff);    
        Serial.print(F("]"));
        //Serial.print(F("], millis["));
        //Serial.print(millis());
        //Serial.print(F("]"));

        Serial.print("----range");
        Serial.print(range);
        Serial.print("----gap");
        Serial.print(gap);
        Serial.println();
        }        
        ///////////////////////////////////////
        //Bewegungs Kalkulation
        ///////////////////////////////////////
        //Bei RH Impulse nach rechts drehen bis LH Impuls gleich ist
           
        byte diff = false;

        

        

        if ((Sdiff >= gap)||(Sdiff <= -gap)){ diff = true;}

        if (diff){

           if (ir4 > ir2){ ////turn right
                //Serial.print("Dreh nach Rechts");
                analogWrite(ledPin2, Htempo);  //Dreh nach R
                analogWrite(links,Htempo); 
           }
           
            if (ir2 > ir4){ ////turn left
                //Serial.print("Dreh nach links");
                analogWrite(ledPin1, Htempo);  //Dreh nach L
                analogWrite(rechts,Htempo); 
           } 
        } else {
          analogWrite(rechts, LOW); 
          analogWrite(links, LOW); 
          analogWrite(ledPin2, LOW);  //Dreh nach L
          analogWrite(ledPin1, LOW);  //Dreh nach R
        }

      
    }
    
  
}
