#define cKey    2
#define csKey   3
#define dKey    4
#define dsKey   5
#define eKey    6
#define fKey    7
#define fsKey   8
#define gKey   10
#define gsKey  11
#define aKey   12
#define asKey  A0
#define bKey   A1
#define majMin A2

// TONES  ==========================================
// Start by defining the relationship between
//       note, period, &  frequency.
int c   =  3831;    // 261 Hz
int cs  =  3610;    // 
int d   =  3401;    //  
int ds  =  3215;    // 
int e   =  3040;    //  
int f   =  2865;    //  
int fs  =  2703;    //
int g   =  2558;    // 
int gs  =  2410;    //
int a   =  2273;    //  
int as  =  2146;    // 
int b   =  2024;    //  

// Define a special note, 'R', to represent a restb
#define  R     0

// SETUP ============================================
int octave = 1;
int speakerOut = 9;
int inputPins [] = {cKey, csKey, dKey, dsKey, eKey, fKey, fsKey, gKey, gsKey, aKey, asKey, bKey, majMin} ;
int melody[8];
//keyCode = activated Pin nbf
int keyCode;
//setKeys = 7 notes in a key for selection
int setKeys[7];
int keySet = 0;
bool minorKey=false;

void setup() {
  pinMode(speakerOut, OUTPUT);
  for(int i = 0; i<13; i++){
    pinMode(inputPins[i], INPUT);
  }
//input array for processing
    Serial.begin(9600); // Set serial out if we want debugging
}

//For the state machine
int state = 0; 
// Set overall tempo
long tempo = 10000;
long rest_count = 100;
long duration = 0;
int tone_ = 0;
// Set length of pause between notes
int pause = 1000;

//Boolean to validate the input

void loop() {

  // We are going to loop through the 3-state machine
  //State 1 - Wait for valid input
  //State 2 - Set the Key
  //State 2 - play 1 loop
  switch(state){ 
    //waiting for valid input 
    case 0: 
      //set the encoded string based on the current keypresses
      checkInputs();
      if(keyCode == 0 ){ 
        //Do Nothing
      }
      else {state+=1;}
      break;
     
     //Set the Melody
    case 1: 
      setMelody();
      state+=1;
      Serial.println(melody[3]);
    break;
    
    //Play 1 Arpegiator Loop
    case 2:
      for(int i= 0; i<8; i++){
        duration = tempo*16;
        tone_ = melody[i];
        playTone();
        delayMicroseconds(pause);
      }
      keyCode=0;
      state=0;
    break;
  }
}
