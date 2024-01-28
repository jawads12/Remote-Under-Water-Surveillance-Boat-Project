#include <Servo.h>


int interrupt[] = {0,21,20,0,0,19,0,0,0};
int chVal[] =     {0,0,0,0,0,0,0,0,0};
volatile long StartTime[] = {0,0,0,0,0,0,0};
volatile long CurrentTime[] = {0,0,0,0,0,0,0};
volatile long Pulses[] = {0,0,0,0,0,0,0};
int PulseWidth[] = {0,0,0,0,0,0,0};

Servo servo;
Servo esc,esc1; 

void setup(){
  Serial.begin(9600);
 // Serial3.begin(9600);
  
  interruptConfig();
  servo.attach(11);
  esc.attach(10);  // Attach the ESC signal wire to pin 9
  esc1.attach(9);
  esc.writeMicroseconds(1000);  // Send minimum throttle signal
  esc1.writeMicroseconds(1000);
  delay(2000);

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  digitalWrite(13, LOW);
  digitalWrite(12,HIGH);
  //servo.write(90);
 // multStpr();
 // setSp(Max_sp);
}

// takeInterruptSignals();

void takeInterruptSignals(){
    if(Pulses[1] < 2100)chVal[1] = Pulses[1];
    if(Pulses[2] < 2100)chVal[2] = Pulses[2];
    if(Pulses[5] < 2100)chVal[5] = Pulses[5];
    // if(Pulses[4] < 2100)chVal[4] = Pulses[4];
    // if(Pulses[5] < 2100)chVal[5] = Pulses[5];
    // if(Pulses[6] < 2100)chVal[6] = Pulses[6];
}
void printChValues(){
  Serial.print(chVal[1]);Serial.print(" ");
  Serial.print(chVal[2]);Serial.print(" ");
  Serial.print(chVal[5]);Serial.print(" ");
  // Serial.print(chVal[4]);Serial.print(" ");
  // Serial.print(chVal[5]);Serial.print(" ");
  // Serial.print(chVal[6]);Serial.print(" ");
  //delay(100);
}
void interruptConfig(){
  pinMode(interrupt[1],INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt[1]),PulseTimerA,CHANGE);
  pinMode(interrupt[2],INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt[2]),PulseTimerB,CHANGE);
  pinMode(interrupt[5],INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(interrupt[5]),PulseTimerC,CHANGE);
  // pinMode(interrupt[4],INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(interrupt[4]),PulseTimerD,CHANGE);
  // pinMode(interrupt[5],INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(interrupt[5]),PulseTimerE,CHANGE);
  // pinMode(interrupt[6],INPUT_PULLUP);
  // attachInterrupt(digitalPinToInterrupt(interrupt[6]),PulseTimerF,CHANGE);
}

void PulseTimerA(){
  int i = 1;
  CurrentTime[i] = micros();
  if(CurrentTime[i] > StartTime[i]){
    Pulses[i] = CurrentTime[i] - StartTime[i];
    StartTime[i] = CurrentTime[i];
  }
}
void PulseTimerB(){
  int i = 2;
  CurrentTime[i] = micros();
  if(CurrentTime[i] > StartTime[i]){
    Pulses[i] = CurrentTime[i] - StartTime[i];
    StartTime[i] = CurrentTime[i];
  }
}
void PulseTimerC(){
  int i = 5;
  CurrentTime[i] = micros();
  if(CurrentTime[i] > StartTime[i]){
    Pulses[i] = CurrentTime[i] - StartTime[i];
    StartTime[i] = CurrentTime[i];
  }
}
// void PulseTimerD(){
//   int i = 4;
//   CurrentTime[i] = micros();
//   if(CurrentTime[i] > StartTime[i]){
//     Pulses[i] = CurrentTime[i] - StartTime[i];
//     StartTime[i] = CurrentTime[i];
//   }
// }
// void PulseTimerE(){
//   int i = 5;
//   CurrentTime[i] = micros();
//   if(CurrentTime[i] > StartTime[i]){
//     Pulses[i] = CurrentTime[i] - StartTime[i];
//     StartTime[i] = CurrentTime[i];
//   }
// }
// void PulseTimerF(){
//   int i = 6;
//   CurrentTime[i] = micros();
//   if(CurrentTime[i] > StartTime[i]){
//     Pulses[i] = CurrentTime[i] - StartTime[i];
//     StartTime[i] = CurrentTime[i];
//   }
// }


void loop()
{

  takeInterruptSignals();
  printChValues();
  Serial.println(map(chVal[5],972,1972, 0,180));
  int a = map(chVal[5],1000,2000, 0,720);
  servo.write(a/4);
 // delay(1000);

 

  if(chVal[2]>1600){ 
     esc.writeMicroseconds(chVal[2]);  // Send neutral throttle signal (stop)
  
   esc1.writeMicroseconds(chVal[2]);  // Send neutral throttle signal (stop)
    }
 

  else if(chVal[1]>1600){ 
     esc.writeMicroseconds(1500);  // Send neutral throttle signal (stop)
  
   esc1.writeMicroseconds(1000);  // Send neutral throttle signal (stop)
    }
  else if ((chVal[1]<1300))  {
     esc.writeMicroseconds(1000);  // Send neutral throttle signal (stop)
  
   esc1.writeMicroseconds(1500);  // Send neutral throttle signal (stop)
  }
   else  {
     esc.writeMicroseconds(1000);  // Send neutral throttle signal (stop)
  
   esc1.writeMicroseconds(1000);  // Send neutral throttle signal (stop)
  }
  




} 



