
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
// Define a special note, 'R', to represent a rest
#define  R     0

// SETUP ============================================
// Set up speaker on a PWM pin (digital 9, 10 or 11)
int octave = 1;
int speakerOut = 9;
//Setup all of the base keys - we will need to use two of the analog inputs as digital inputs
int cKey = 2;
int csKey = 3;
int dKey = 4;
int dsKey = 5;
int eKey = 6;
int fKey = 7;
int fsKey = 8;
int gKey = 10;
int gsKey = 11;
int aKey = 12;
int asKey = A0;
int bKey = A1;
int majMin = A2;

// Do we want debugging on serial out? 1 for yes, 0 for no
int DEBUG = 1;

void setup() {
  pinMode(speakerOut, OUTPUT);
  pinMode(cKey, INPUT);
  pinMode(csKey, INPUT);
  pinMode(dKey, INPUT);
  pinMode(dsKey, INPUT);
  pinMode(eKey, INPUT);
  pinMode(fKey, INPUT);
  pinMode(fsKey, INPUT);
  pinMode(gKey, INPUT);
  pinMode(gsKey, INPUT);
  pinMode(aKey, INPUT);
  pinMode(asKey, INPUT);
  pinMode(bKey, INPUT);
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
String checkIn = "0000000000000" 


void loop() {
  // We are going to loop through the 3-state machine
  //State 1 - Wait for valid input
  //State 2 - Set the Key
  //State 2 - play 1 loop
  switch(state){ 
    case 0: //waiting for valid input 
      if(CheckIn = "000000000000" || CheckIn = "100000000000" ){ 
        //Do Nothing
      }
      else {
        state+=1; 
        break;
      }
     case 1: //Set the Melody
     
     break;
  }
}
