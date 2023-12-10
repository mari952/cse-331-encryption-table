// pin assignment
int O0 = 10; 
int O1 = 11;
int O2 = 12;
int O3 = 13;

int I0 = 2;
int I1 = 3;
int I2 = 4;
int I3 = 5;


void setup() {
  
  //input output initialization
  pinMode(I0,INPUT);
  pinMode(I1,INPUT);
  pinMode(I2,INPUT);
  pinMode(I3,INPUT);
  pinMode(O0,OUTPUT);
  pinMode(O1,OUTPUT);
  pinMode(O2,OUTPUT);
  pinMode(O3,OUTPUT);
}

void loop() {

  // to read boolean states from input pins
  boolean I0State = digitalRead(I0);
  boolean I1State = digitalRead(I1);
  boolean I2State = digitalRead(I2);
  boolean I3State = digitalRead(I3);
  boolean O0State;
  boolean O1State;
  boolean O2State;
  boolean O3State;

  O0State= ((!I1State && !I0State)||(!I3State && I2State && !I0State)||(I2State && !I1State)||(I3State && !I1State)||(I3State && I2State && I0State));
  O1State= ((!I2State && I1State && !I0State)||(I2State && !I1State && I0State)||(I3State && I1State));
  O2State= ((!I2State && !I1State && I0State)||(!I3State && I2State && !I0State)||(I2State && !I1State && !I0State)||(I3State && !I2State && I0State));
  O3State= ((!I3State && !I1State)||(!I3State && !I0State)||(I2State && !I0State)||(I3State && !I2State && I0State));

  digitalWrite(O0,O0State);
  digitalWrite(O1,O1State);
  digitalWrite(O2,O2State);
  digitalWrite(O3,O3State);

}
