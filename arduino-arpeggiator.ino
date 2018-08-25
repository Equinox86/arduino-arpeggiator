
// TONES  ==========================================
// Start by defining the relationship between
//       note, period, &  frequency.
#define  c     3831    // 523 Hz 
#define  cs    3610     // 554 Hz
#define  d     3401    // 587 Hz 
#define  ds    3215    // 622 Hz
#define  e     3040    // 329 Hz 
#define  f     2865    // 349 Hz 
#define  fs    2703
#define  g     2558    // 392 Hz 
#define  gs    2410
#define  a     2273    // 440 Hz 
#define  as    2146    // 466 Hz
#define  b     2024    // 493 Hz 

#define cKey = 2;
#define csKey = 3;
#define dKey = 4;
#define dsKey = 5;
#define eKey = 6;
#define fKey = 7;
#define fsKey = 8;
#define gKey = 10;
#define gsKey = 11;
#define aKey = 12;
#define asKey = A0;
#define bKey = A1;
#define majMin = A2;
// Define a special note, 'R', to represent a rest
#define  R     0

// SETUP ============================================
// Set up speaker on a PWM pin (digital 9, 10 or 11)
int octave = 1;
int speakerOut = 9;
//Setup all of the base keys - we will need to use two of the analog inputs as digital inputs


//input array for processing
int[] inputPins = {cKey, csKey, dKey, dsKey, eKey, fKey, fsKey, gKey, gsKey, aKey, asKey, bKey, majMin} ;
// Do we want debugging on serial out? 1 for yes, 0 for no
int DEBUG = 1;

void setup() {
  pinMode(speakerOut, OUTPUT);
  for(int i = 0; inputPins.size()){
    pinMode(inputPins[i], INPUT);
  }
  if (DEBUG) {
    Serial.begin(9600); // Set serial out if we want debugging
  }
}

//For the state machine
int state = 0; 
// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
//Boolean to validate the input
String checkIn = "0000000000000";


void loop() {
  // We are going to loop through the 3-state machine
  //State 1 - Wait for valid input
  //State 2 - Set the Key
  //State 2 - play 1 loop
  switch(state){ 
    
    //waiting for valid input 
    case 0: 
      //set the encoded string based on the current keypresses
      checkIn = checkInputs();
      if(checkIn = "000000000000" || checkIn = "000000000001" ){ 
        //Do Nothing
      }
      else {state+=1;}
      break;
     
     //Set the Melody
     case 1: 
        playMelody = setMelody(checkIn);
        state+=1;
     break;
    
    //Play 1 Arpegiator Loop
     case 2: 
        state=0;
     break;
  }
}
