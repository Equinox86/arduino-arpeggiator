/* Play Melody
 * -----------
 *
 * Program to play a simple melody
 *
 * Tones are created by quickly pulsing a speaker on and off 
 *   using PWM, to create signature frequencies.
 *
 * Each note has a frequency, created by varying the period of 
 *  vibration, measured in microseconds. We'll use pulse-width
 *  modulation (PWM) to create that vibration.

 * We calculate the pulse-width to be half the period; we pulse 
 *  the speaker HIGH for 'pulse-width' microseconds, then LOW 
 *  for 'pulse-width' microseconds.
 *  This pulsing creates a vibration of the desired frequency.
 *
 * (cleft) 2005 D. Cuartielles for K3
 * Refactoring and comments 2006 clay.shirky@nyu.edu
 * See NOTES in comments at end for possible improvements
 */

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

// MELODY and TIMING  =======================================
//  melody[] is an array of notes, accompanied by beats[], 
//  which sets each note's relative length (higher #, longer note) 
int currMelody[] = {  c, d};
int currBeats[]  = { 16, 16}; 
int nextMelody[] = {  c, d};
int nextBeats[]  = { 16, 16};
int MAX_COUNT = sizeof(currMelody) / 2; // Melody length, for looping.

// Set overall tempo
long tempo = 10000;
// Set length of pause between notes
int pause = 1000;
// Loop variable to increase Rest length
int rest_count = 100; //<-BLETCHEROUS HACK; See NOTES

// Initialize core variables
int tone_ = 0; 
int beat = 0;
long duration  = 0;
boolean playpause = false;


// LET THE WILD RUMPUS BEGIN =============================
void loop() {
  // We are going to loop through the 2-state machine
  //State 1 - Set the Key while the major/minor key button is pressed. 
  //State 2 - play 1 loop
    for (int i=0; i<MAX_COUNT; i++) {
      tone_ = currMelody[i];
      beat = currBeats[i];
      duration = beat * tempo; // Set up timing
      playTone();
      // A pause between notes...
      delayMicroseconds(pause);
      if (DEBUG) { // If debugging, report loop, tone, beat, and duration
        //Serial.print(digitalRead(playButt));
       // Serial.print(i);
       // Serial.print(":");
       // Serial.print(beat);
       // Serial.print(" ");    
        //Serial.print(tone_);
        //Serial.print(" ");
        //Serial.println(duration);
      }
    }
  }

/*
 * NOTES
 * The program purports to hold a tone for 'duration' microseconds.
 *  Lies lies lies! It holds for at least 'duration' microseconds, _plus_
 *  any overhead created by incremeting elapsed_time (could be in excess of 
 *  3K microseconds) _plus_ overhead of looping and two digitalWrites()
 *  
 * As a result, a tone of 'duration' plays much more slowly than a rest
 *  of 'duration.' rest_count creates a loop variable to bring 'rest' beats 
 *  in line with 'tone' beats of the same length. 
 * 
 * rest_count will be affected by chip architecture and speed, as well as 
 *  overhead from any program mods. Past behavior is no guarantee of future 
 *  performance. Your mileage may vary. Light fuse and get away.
 *  
 * This could use a number of enhancements:
 * ADD code to let the programmer specify how many times the melody should
 *     loop before stopping
 * ADD another octave
 * MOVE tempo, pause, and rest_count to #define statements
 * RE-WRITE to include volume, using analogWrite, as with the second program at
 *          http://www.arduino.cc/en/Tutorial/PlayMelody
 * ADD code to make the tempo settable by pot or other input device
 * ADD code to take tempo or volume settable by serial communication 
 *          (Requires 0005 or higher.)
 * ADD code to create a tone offset (higer or lower) through pot etc
 * REPLACE random melody with opening bars to 'Smoke on the Water'
 */
