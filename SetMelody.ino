void checkInputs(){ 
   //determine which key is held and put the result into result String (TODO: make a dimensional array instead of string)
   for( int i = 0; i < 11; i++) {
      if (digitalRead(inputPins[i]) == 1) {keyCode = i+1;}
  }
  if(digitalRead(majMin) == 1){
    minorKey=true;
  }
  else{
    minorKey=false;
  }
}

void setMelody () { 
 	//Major Keys
   Serial.println(minorKey);
 	if(minorKey == false) { 
 		switch(keyCode){
			case 1:setKeyArray(c,d,e,f,g,a,b);break;
			case 2:setKeyArray(cs,ds,f,fs,gs,as,c);break;
			case 3:setKeyArray(d,e,fs,g,a,b,cs);break;
			//case '4':setKeyArray(e,fs,gs,a,b,cs,ds);break;
			//case '5':setKeyArray(f,g,a,as,c,d,e);break;
			//case '6'setKeyArray(f,g,a,as,c,d,e);break;
			//case '7':setKeyArray(fs,gs,as,b,cs,ds,f);break;
			//case '8':setKeyArray(g,a,b,c,d,e,fs);break;
			//case '9':setKeyArray(gs,as,c,cs,ds,f,g);break;
			//case '10':setKeyArray(a,b,cs,d,e,fs,gs);break;
			//case '11':setKeyArray(as,c,d,ds,f,g,a);break;
			}
 	} else { 
      switch(keyCode){
      case 1:setKeyArray(c,d,ds,f,g,gs,as);break;
      case 2:setKeyArray(cs,ds,f,fs,gs,as,c);break;
      case 3:setKeyArray(d,e,fs,g,a,b,cs);break;
      //case '4':setKeyArray(e,fs,gs,a,b,cs,ds);break;
      //case '5':setKeyArray(f,g,a,as,c,d,e);break;
      //case '6'setKeyArray(f,g,a,as,c,d,e);break;
      //case '7':setKeyArray(fs,gs,as,b,cs,ds,f);break;
      //case '8':setKeyArray(g,a,b,c,d,e,fs);break;
      //case '9':setKeyArray(gs,as,c,cs,ds,f,g);break;
      //case '10':setKeyArray(a,b,cs,d,e,fs,gs);break;
      //case '11':setKeyArray(as,c,d,ds,f,g,a);break;
      }
}

	  //Assuming 4 key loop
	melody[0] = setKeys[0];
	melody[1] = setKeys[2];
  melody[2] = setKeys[4];
  melody[3] = setKeys[0]/2;
  melody[4] = setKeys[2]/2;
  melody[5] = setKeys[0]/2;
  melody[6] = setKeys[4];
  melody[7] = setKeys[2];
  
}

// PLAY TONE  ==============================================
// Pulse the speaker to play a tone for a particular duration
void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) { // if this isn't a Rest beat, while the tone has 
    //  played less long than 'duration', pulse speaker HIGH and LOW
    while (elapsed_time < duration) {

      //UP
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

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
