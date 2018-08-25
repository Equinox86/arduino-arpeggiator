public String checkInputs(){ 
   String result = "";
   //determine which key is hit and put the result into result String (TODO: make a dimensional array instead of string)
   for( int i = 0; i < inputPins.size(); i++;) {
      if (inputPins[i] = 1) { 
      	result = result + i; 
      }
  }
   return result; 
}

public int[] setMelody (String inKey, int octave) { 
	// The number of notes in the arpeggiated string
	arp_size = 4; 
	//Keep track of Octave 
	octave = 1; 
	//Break string into Charactor Elements
	inKey.toCharArray(keyIns,2);
	//create an array to hold the key range
	int[] keyRange[7]; 
 	
 	//Set the key based on the input
 	//Major Keys
 	if(keyIns[1]="0") { 
 		switch(inKey){
			case(0):keyRange[7] = {c,d,e,f,g,a,b};
			case(1):keyRange[7] = {cs,ds,f,fs,gs,as,c};
			case(2):keyRange[7] = {d,e,fs,g,a,b,cs};
			case(3):keyRange[7] = {ds,f,g,gs,as,bs,cs};
			case(4):keyRange[7] = {ds,f,fs,gs,as,b,cs};
		}
	}

  	//now use the arp size to pick from the keyrange to construct the melody

}
