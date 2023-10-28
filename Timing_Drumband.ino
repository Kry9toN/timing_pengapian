//  Feel free to use this code
//  Visit for more details :
//  https://youtu.be/oYhfEQR9Az4
//  Consider to support DBOSS Project youtube channel :
//  https://www.youtube.com/c/DBOSSproject?sub_confirmation=1
// 
//  ADJUSTABLE RELAY RUMBLE IDLE / DRUMBAND IDLE / TIMING DRUMBAND RELAY
//  Features :  1.  3 Pre-set mode
//              2.  Customizable beats
//              3.  Adjustable speed

#define trimpot A0
#define relay D2
#define modeSelect_A D5
#define modeSelect_COM D6
#define modeSelect_B D7

//----------------[1] *  *  * [2] *  *  * [3] *  *  * [4] *  *  * ----------------// CUSTOMIZE YOUR BEATS HERE //----------------//
bool beat_A[16] = {1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0};         
bool beat_B[16] = {1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0};         
bool beat_C[16] = {1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 0};         
//----------------[1] *  *  * [2] *  *  * [3] *  *  * [4] *  *  * ----------------// ATUR IRAMA DRUMBAND SESUKA HATI //----------------//

bool selectorA;
bool selectorB;
const int numReadings = 8;
int readings[numReadings];
int readIndex = 0;
int total = 0;
int average = 0;
int interval = 0;
int count = 1;
unsigned long timeNow = 0;
unsigned long timeBefore = 0;

void setup() {
  pinMode(relay, OUTPUT);
  pinMode(modeSelect_COM, OUTPUT);
  pinMode(modeSelect_A, INPUT_PULLUP);
  pinMode(modeSelect_B, INPUT_PULLUP);
  digitalWrite(relay, LOW);
  digitalWrite(modeSelect_COM, LOW);
  for (int i = 0; i < numReadings; i++) {
    readings[i] = 0;
  }
}

void loop() {
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(trimpot);
  total = total + readings[readIndex];
  readIndex = (readIndex + 1) % numReadings;
  average = total / numReadings;
  interval = map(average, 0, 1023, 200, 50);

  timeNow = millis();
  if (timeNow - timeBefore >= interval) {
    timeBefore = timeNow;
    count = (count % 16) + 1;
  }

  selectorA = digitalRead(modeSelect_A);
  selectorB = digitalRead(modeSelect_B);

  int beatIndex = selectorA ? (selectorB ? 1 : 2) : 0;

  digitalWrite(relay, beats[beatIndex][count - 1]);
}
