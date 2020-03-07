ANIMATION (nono)
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
      Serial.println("To USB");
      rotateL(Rpos*80);
      },Rpos*80)
      DO_ONCE_AND_WAIT({ 
      Serial.println("Fertig;-)");
      resetM();
      },1000)
        
      DO_END()
  
}
