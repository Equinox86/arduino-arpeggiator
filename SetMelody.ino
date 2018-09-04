void checkInputs(){ 
  // If a button was just pressed or released...
  if (trellis.readSwitches()) {
    // go through every button
    for (uint8_t i=0; i<numKeys; i++) {
      //button "i" was just pressed.
      if (trellis.justPressed(i)) {
        //keyCodes 0-11 are the 12 piano keys
        if(i <12) {
          if(i == keyCode){keyCode = -1;}
          else {keyCode =i;}
        }
        //Major Minor Flips
        else if(i ==12) { 
          minorKey=!minorKey;
          if(trellis.isLED(i)) {
              trellis.clrLED(i);
          }
          else{ 
              trellis.setLED(i);
          }
        }
       //Octave Up/Down
       else if(i==13){octave = octave +1;}
       else if(i==14){octave = octave -1;}
      }
        else { 
          if(i<12 ) { trellis.clrLED(i);}
        }
      trellis.setLED(keyCode);
    }
    trellis.writeDisplay();
  }
}
  

void setMelody () { 
 	//Major Keys
   Serial.println(minorKey);
 	if(minorKey == false) { 
 		switch(keyCode){
			case 0:setKeyArray(c,d,e,f,g,a,b);break;
			case 1:setKeyArray(cs,ds,f,fs,gs,as,c/2);break;
			case 2:setKeyArray(d,e,fs,g,a,b,cs/2);break;
      case 3:setKeyArray(ds,f,g,gs,as,c/2,d/2); break;
			case 4:setKeyArray(e,fs,gs,a,b,cs/2,ds/2);break;
			case 5:setKeyArray(f,g,a,as,c/2,d/2,e/2);break;
			case 6: setKeyArray(fs,gs,as,b,cs/2,ds/2,f/2);break;
			case 7:setKeyArray(g,a,b,c/2,d/2,e/2,fs/2);break;
			case 8:setKeyArray(gs,as,c/2,cs/2,ds/2,f/2,g/2);break;
			case 9:setKeyArray(a,b,cs/2,d/2,e/2,fs/2,gs/2);break;
			case 10:setKeyArray(as,c/2,d/2,ds/2,f/2,g/2,a/2);break;
			case 11:setKeyArray(b,cs/2,ds/2,e/2,fs/2,gs/2,as/2);break;
			}
 	} else { 
      switch(keyCode){
      case 0:setKeyArray(c,d,ds,f,g,gs,as);break;
      case 1:setKeyArray(cs,ds,e,fs,gs,a,b);break;
      case 2:setKeyArray(d,e,f,g,a,as,c);break;
      case 3:setKeyArray(ds,f,fs,gs,as,b,cs/2);break;
      case 4:setKeyArray(e,fs,g,a,b,c/2,d/2);break;
      case 5: setKeyArray(f,g,gs,as,c/2,cs/2,ds/2);break;
      case 6:setKeyArray(fs,gs,a,b,cs/2,d/2,e/2);break;
      case 7:setKeyArray(g,a,as,c/2,d/2,ds/2,f/2);break;
      case 8:setKeyArray(gs,as,b,cs/2,ds/2,e/2,fs/2);break;
      case 9:setKeyArray(a,b,c/2,d/2,e/2,f/2,g/2);break;
      case 10:setKeyArray(as,c/2,cs/2,ds/2,f/2,fs/2,gs/2);break;
      case 11:setKeyArray(b,cs/2,d/2,e/2,fs/2,g/2,a/2);break;
      }
}

	melody[0] = setKeys[0]*2;
	melody[1] = setKeys[1]*2;
  melody[2] = setKeys[2]*2;
  melody[3] = setKeys[4]*2;
  melody[4] = setKeys[0];
  melody[5] = setKeys[1];
  melody[6] = setKeys[2];
  melody[7] = setKeys[4];
  melody[8] = setKeys[0]/2;
  melody[9] = setKeys[1]/2;
  melody[10] = setKeys[2]/2;
  melody[11] = setKeys[4]/2;
  melody[12] = setKeys[0]/4;
  melody[13] = setKeys[1]/4;
  melody[14] = setKeys[2]/4;
  melody[15] = setKeys[4]/4;
  melody[16] = setKeys[0]/8;
  melody[17] = setKeys[4]/4;
  melody[18] = setKeys[2]/4;
  melody[19] = setKeys[1]/4;
  melody[20] = setKeys[0]/4;
  melody[21] = setKeys[4]/2;
  melody[22] = setKeys[2]/2;
  melody[23] = setKeys[1]/2;
  melody[24] = setKeys[0]/2;
  melody[25] = setKeys[4];
  melody[26] = setKeys[2];
  melody[27] = setKeys[1];
  melody[28] = setKeys[0];
  melody[29] = setKeys[4]*2;
  melody[30] = setKeys[2]*2;
  melody[31] = setKeys[1]*2;  

  for(int i =0; i< sizeof(melody)/sizeof(int); i++) {
    melody[i] = melody[i] * octave;
  }
}

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and Lw
    while (elapsed_time < duration){
      //UP
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_/2);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  else { // Rest beat; loop times delay
    for (int j = 0; j < rest_count; j++) { // See NOTE on rest_count
      delayMicroseconds(duration);  
    }                                
  }                                 
}
