#include <Arduino.h>    

//// Commandos ///////
void ProzessComando() {

    if (data == "hi-r2" )
      {             
       Serial.println("test gefunden");
       ANIMATION_PLAY_ONCE(player, test);    
      }
      
    if (data == "stop" )
      {         
       Serial.println("reset player");
       ANIMATION_PLAY_ONCE(player, stopnow);  
      }

    if (data == "find")
    {
      FindRoTime();
    }
    
    if (data == "debug on")
      {
        Serial.println("Debug Mode ON");
        debug = true;      
      }

    if (data == "debug off")
      {
        Serial.println("Debug Mode off");
        debug = false;
      }
    if (data == "vers")   
      {
        Serial.println(F("-----   Versionnsnummer   -----"));
        Serial.println(VERSION);     
        /*
         * Vorher 73% 77%
         */
        Serial.println(F("|    Komandoreferenz"));
        Serial.println(F("| debug on"));
        Serial.println(F("| debug off"));
        Serial.println(F("| stop  : resetAll"));
        Serial.println(F("| hi-r2 : test"));
        Serial.println(F("| vers  : Print Info"));
        Serial.println(F("| find  : calc Position"));      
        Serial.println(F("| mode0 : RAND Move"));
        Serial.println(F("| mode1 : RC Move"));
        Serial.println(F("| mode2 : Human detect"));
        Serial.println(F("| mode3 : Service"));    
        Serial.println(F("| usb  : Turn to USB"));
        Serial.println(F("| p1  : Turn to Panel 1"));
        Serial.println(F("| p2  : Turn to Panel 2"));
        Serial.println(F("| p3  : Turn to Panel 3"));
        Serial.println(F("| p4  : Turn to Panel 4"));
        Serial.println(F("tool1"));
        Serial.println(F("tool2"));
        Serial.println(F("tool3")); 
        Serial.println(F("nono"));
        Serial.println(F("yea"));
        Serial.println(F("dance"));
        Serial.println(F("| center: Turn Dome to Center"));
        Serial.println(F("---Rpos---"));
        Serial.println(Rpos);
        Serial.println(F("---Temparatur---"));
        Serial.println(temp);
        Serial.print("#___Actual Mode:");
        Serial.println(Mode);
        Serial.println(F("...ready for Command_"));

      }

    if (data == "mode1"){Serial.println(F("Mode 1 RC"));Mode = 1;}
    if (data == "mode0"){Serial.println(F("Mode 0 Random"));Mode = 0;}
    if (data == "mode3"){Serial.println(F("Mode 3 Service"));Mode = 3;}
    if (data == "mode2"){Serial.println(F("Mode 2 Human"));Mode = 2;}  
     
    if (data == "usb"){Serial.println(F("Rotation zu Position USB"));ANIMATION_PLAY_ONCE(player, toUSB);}
    if (data == "CB0"){Serial.println(F("Rotation zu Position USB"));ANIMATION_PLAY_ONCE(player, toUSB);}
    if (data == "p1"){Serial.println(F("Rotation zu Position P1"));ANIMATION_PLAY_ONCE(player, p1);}
    if (data == "p2"){Serial.println(F("Rotation zu Position P2"));ANIMATION_PLAY_ONCE(player, p2);}
    if (data == "p3"){Serial.println(F("Rotation zu Position P3"));ANIMATION_PLAY_ONCE(player, p3);}
    if (data == "p4"){Serial.println(F("Rotation zu Position P4"));ANIMATION_PLAY_ONCE(player, p4);}
    
    if (data == "tool1"){Serial.println(F("Rotation zu Position tool1"));ANIMATION_PLAY_ONCE(player, p2);}
    if (data == "tool2"){Serial.println(F("Rotation zu Position tool2"));ANIMATION_PLAY_ONCE(player, p3);}
    if (data == "tool3"){Serial.println(F("Rotation zu Position tool3"));ANIMATION_PLAY_ONCE(player, p4);}  
    if (data == "nono"){Serial.println(F("Rotation nono"));ANIMATION_PLAY_ONCE(player, nono);}
    
    if (data == "yea"){Serial.println("Rotation yea");}

    if (data =="dance") { ANIMATION_PLAY_ONCE(player, dance);   }

    if (data =="center") {center("L");}
    data = "";
}



void Comand() {
///Comando Pruefung////
   if(Serial.available() > 0)
    {
        data = Serial.readStringUntil('\n');
        ProzessComando();
    }
  ////Prüfung 2///
  MainInput.listen();
  
   if (MainInput.available() > 0)
    {
        data = MainInput.readStringUntil('\r');
        Serial.println(MainInput);
        Serial.println(data);
        ProzessComando();
    }
}
