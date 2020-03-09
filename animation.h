ANIMATION (test)
{
    DO_START()
    // Step One - fires once and waits 300ms before advancing
    //DO_SEQUENCE(SeqPanelAllOpenLong, DOME_PANELS_MASK)
    // Step Two - fires once
    //DO_COMMAND_AND_WAIT("HPF0026|20", 100)
    // Step Three - fires repeatedly for 200ms
    /*
    DO_DURATION(200, {
        Serial.println(elapsedMillis);
        //rotateR(200);
    })*/
    // Step Four
      DO_ONCE_AND_WAIT({ 
      Serial.println("Rechts");
      rotateR(1500);
      },1500)

      DO_ONCE_AND_WAIT({ 
      Serial.println("Motor Aus");
      resetM();
      },1000)
      
      DO_ONCE_AND_WAIT({ 
      Serial.println("Links");
      rotateL(2500);
      },2500)

      DO_ONCE_AND_WAIT({ 
      Serial.println("Fertig;-)");
      resetM();
      },1000)
      
       
    //DO_COMMAND("HPF0026|20")
    // Step Six - repeat this step until "num" reaches 100 then rewind the animation
    /*
    DO_FOREVER({
        Serial.println(num);
        if (num == 1000)
           animation.rewind();
    })*/
    DO_END()
}

ANIMATION (nono)
{
    DO_START()
   
    DO_ONCE_AND_WAIT({ 
      //Serial.println("Rechts");
      rotateR(500);
      },500)

      DO_ONCE_AND_WAIT({ 
      //Serial.println("Motor Aus");
      resetM();
      },100)
      
      DO_ONCE_AND_WAIT({ 
      //Serial.println("Links");
      rotateL(500);
      },500)

      DO_ONCE_AND_WAIT({ 
      //Serial.println("Motor Aus");
      resetM();
      },100)

      DO_ONCE_AND_WAIT({ 
      //Serial.println("Rechts");
      rotateR(500);
      },500)
      
      DO_ONCE_AND_WAIT({ 
      Serial.println("center");
      center("L");
      },500)
      
      DO_ONCE_AND_WAIT({ 
      //Serial.println("Fertig;-)");
      resetM();
      },100)
   
    DO_END()
}

ANIMATION(stopnow)  {
      DO_START()   
      DO_ONCE(
        {
          resetM();
          })  
      DO_END()
  
}


ANIMATION(toUSB)  {
      DO_START()   
      DO_ONCE_AND_WAIT({ 
      //Serial.println("To USB");
      rotateL(Rpos*80);
      },Rpos*80)
      DO_ONCE_AND_WAIT({ 
      //Serial.println("Fertig;-)");
      resetM();
      },100)
        
      DO_END()
  
}


ANIMATION(p1)  {
      DO_START()   
      DO_ONCE_AND_WAIT({ 
      //Serial.println("To USB");
      rotateL(Rpos*80);
      },Rpos*80)
      DO_ONCE_AND_WAIT({ 
      //Serial.println("Fertig;-)");
      resetM();
      },100)      
      DO_END()
}

ANIMATION(p2)  {
      DO_START()   
      DO_ONCE_AND_WAIT({ 
       rotateL(Rpos*100);
      },Rpos*100)
      DO_ONCE_AND_WAIT({ 
      resetM();
      },100)      
      DO_END()
}

ANIMATION(p3)  {
      DO_START()   
      DO_ONCE_AND_WAIT({ 
       rotateL(Rpos*130);
      },Rpos*130)
      DO_ONCE_AND_WAIT({ 
      resetM();
      },100)      
      DO_END()
}


ANIMATION(p4)  {
      DO_START()   
      DO_ONCE_AND_WAIT({ 
       rotateL(Rpos*180);
      },Rpos*180)
      DO_ONCE_AND_WAIT({ 
      resetM();
      },100)      
      DO_END()
}

ANIMATION (dance)
{
    DO_START()

      DO_ONCE_AND_WAIT({ 
      Serial.println("Rechts1");
      rotateR(1500);
      },1500)

      DO_ONCE_AND_WAIT({ 
      Serial.println("Motor Aus");
      resetM();
      },100)
      
      DO_ONCE_AND_WAIT({ 
      Serial.println("Links1");
      rotateL(1500);
      },1500)

      DO_ONCE_AND_WAIT({ 
      Serial.println("Motor Aus");
      resetM();
      },100)

      DO_ONCE_AND_WAIT({ 
      Serial.println("Rechts2");
      rotateR(1500);
      },1500)

      DO_ONCE_AND_WAIT({ 
      Serial.println("Motor Aus");
      resetM();
      },100)
      
      DO_ONCE_AND_WAIT({ 
      Serial.println("Links2");
      rotateL(1500);
      },1500)
     
      DO_FOREVER({
        DEBUG_PRINTLN(num);
        if (num == 100)
           animation.rewind();
       })
    
    DO_END()
}
