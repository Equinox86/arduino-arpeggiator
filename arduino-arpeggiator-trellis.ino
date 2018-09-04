#include <Adafruit_Trellis.h>
#include <SD.h>
#include <Wire.h>
//Trellis Setup
Adafruit_Trellis matrix0 = Adafruit_Trellis();
Adafruit_TrellisSet trellis =  Adafruit_TrellisSet(&matrix0);
#define NUMTRELLIS 1
#define numKeys (NUMTRELLIS * 16)
#define INTPIN A2

//Set the Tones for all keys
#define c     3831    // 261 Hz
#define cs    3610    // 
#define d     3401    //  
#define ds    3215    // 
#define e     3040    //  
#define f     2865    //  
#define fs    2703    //
#define g     2558    // 
#define gs    2410    //
#define a     2273    //  
#define as    2146    // 
#define b     2024    //  
#define tempoIn  A3

// Define a special note, 'R', to represent a restb
#define  R     0

// SETUP ============================================
int octave = 1;
int speakerOut = 9;
int melody[8];
//keyCode = activated Pin nbf
int keyCode;
//setKeys = 7 notes in a key for selection
int setKeys[7];
int keySet = 0;
bool minorKey=false;

void setup() {
  
  pinMode(INTPIN, INPUT);
  digitalWrite(INTPIN, HIGH);
  trellis.begin(0x70); 
  
  pinMode(speakerOut, OUTPUT);
  Serial.begin(9600); // Set serial out if we want debugging
}

//For the state machine
int state = 0; 
// Set overall tempo
double tempo;
long rest_count = 100;
double duration = 0;
int tone_ = 0;
int looper = 0; 
// Set length of pause between notes
int pause = 1000;

//Boolean to validate the input

void loop() {

  // We are going to loop through the 3-state machine
  //State 1 - Wait for valid input
  //State 2 - Set the Key
  //State 3 - play 1 loop
  switch(state){ 
//waiting for valid input 
    case 0: 
      Serial.println("Listening");
      checkInputs();
      delay(30);
      break;
//Set the Melody
    case 1: 
      setMelody();
      state+=1;
      //Serial.println(melody[3]);
    break;
    
//Play 1 Arpegiator Loop3
    case 2:
      for(int i= 0; i<8; i++){
        //SetTempo - Max of 50000
        //tempo = (1-((double)analogRead(tempoIn)/700))*50000;
        tempo = 10000;
        Serial.println(tone_);
        duration = tempo*16;
        tone_ = melody[i];
        playTone();
       // delayMicroseconds(pause);
      }
      trellis.clrLED(keyCode);
      trellis.writeDisplay();
      //Reset State and KeyCode
     state=0;  
    break;
  }
}
