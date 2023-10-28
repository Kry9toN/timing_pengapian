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




void setup()
{
  pinMode(relay, OUTPUT);
  pinMode(modeSelect_COM, OUTPUT);
  pinMode(modeSelect_A, INPUT_PULLUP);
  pinMode(modeSelect_B, INPUT_PULLUP);
  digitalWrite(relay, 0);
  digitalWrite(modeSelect_COM, 0);
  for (int i = 0; i < numReadings; i++){
    readings[i] = 0;
  }
}

void loop()
{
  total = total - readings[readIndex];
  readings[readIndex] = analogRead(trimpot);
  total = total + readings[readIndex];
  readIndex = readIndex + 1;
  if (readIndex >= numReadings){
    readIndex = 0;
  }
  average = total / numReadings;
  interval = map(average, 0, 1023, 200, 50);
  
  timeNow = millis();
  if (timeNow - timeBefore >= interval){
    timeBefore = timeNow;
    count++;
    if (count > 16){
      count = 1; 
    }  
  }
  
  selectorA = digitalRead(modeSelect_A);
  selectorB = digitalRead(modeSelect_B);
  
  if (selectorA == 0 && selectorB == 1){
    if (count == 1){
      digitalWrite(relay, beat_A[1]);
    }
    if (count == 2){
      digitalWrite(relay, beat_A[2]);
    }
    if (count == 3){
      digitalWrite(relay, beat_A[3]);
    }
    if (count == 4){
      digitalWrite(relay, beat_A[4]);
    }
    if (count == 5){
      digitalWrite(relay, beat_A[5]);
    }
    if (count == 6){
      digitalWrite(relay, beat_A[6]);
    }
    if (count == 7){
      digitalWrite(relay, beat_A[7]);
    }
    if (count == 8){
      digitalWrite(relay, beat_A[8]);
    }
    if (count == 9){
      digitalWrite(relay, beat_A[9]);
    }
    if (count == 10){
      digitalWrite(relay, beat_A[10]);
    }
    if (count == 11){
      digitalWrite(relay, beat_A[11]);
    }
    if (count == 12){
      digitalWrite(relay, beat_A[12]);
    }
    if (count == 13){
      digitalWrite(relay, beat_A[13]);
    }
    if (count == 14){
      digitalWrite(relay, beat_A[14]);
    }
    if (count == 15){
      digitalWrite(relay, beat_A[15]);
    }
    if (count == 16){
      digitalWrite(relay, beat_A[16]);
    }
  }else if (selectorA == 1 && selectorB == 1){
    if (count == 1){
      digitalWrite(relay, beat_B[1]);
    }
    if (count == 2){
      digitalWrite(relay, beat_B[2]);
    }
    if (count == 3){
      digitalWrite(relay, beat_B[3]);
    }
    if (count == 4){
      digitalWrite(relay, beat_B[4]);
    }
    if (count == 5){
      digitalWrite(relay, beat_B[5]);
    }
    if (count == 6){
      digitalWrite(relay, beat_B[6]);
    }
    if (count == 7){
      digitalWrite(relay, beat_B[7]);
    }
    if (count == 8){
      digitalWrite(relay, beat_B[8]);
    }
    if (count == 9){
      digitalWrite(relay, beat_B[9]);
    }
    if (count == 10){
      digitalWrite(relay, beat_B[10]);
    }
    if (count == 11){
      digitalWrite(relay, beat_B[11]);
    }
    if (count == 12){
      digitalWrite(relay, beat_B[12]);
    }
    if (count == 13){
      digitalWrite(relay, beat_B[13]);
    }
    if (count == 14){
      digitalWrite(relay, beat_B[14]);
    }
    if (count == 15){
      digitalWrite(relay, beat_B[15]);
    }
    if (count == 16){
      digitalWrite(relay, beat_B[16]);
    }
  }else{
    if (count == 1){
      digitalWrite(relay, beat_C[1]);
    }
    if (count == 2){
      digitalWrite(relay, beat_C[2]);
    }
    if (count == 3){
      digitalWrite(relay, beat_C[3]);
    }
    if (count == 4){
      digitalWrite(relay, beat_C[4]);
    }
    if (count == 5){
      digitalWrite(relay, beat_C[5]);
    }
    if (count == 6){
      digitalWrite(relay, beat_C[6]);
    }
    if (count == 7){
      digitalWrite(relay, beat_C[7]);
    }
    if (count == 8){
      digitalWrite(relay, beat_C[8]);
    }
    if (count == 9){
      digitalWrite(relay, beat_C[9]);
    }
    if (count == 10){
      digitalWrite(relay, beat_C[10]);
    }
    if (count == 11){
      digitalWrite(relay, beat_C[11]);
    }
    if (count == 12){
      digitalWrite(relay, beat_C[12]);
    }
    if (count == 13){
      digitalWrite(relay, beat_C[13]);
    }
    if (count == 14){
      digitalWrite(relay, beat_C[14]);
    }
    if (count == 15){
      digitalWrite(relay, beat_C[15]);
    }
    if (count == 16){
      digitalWrite(relay, beat_C[16]);
    }
  }
}
