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
  
  //Output set pins 10 - 13 as outputs
  DDRB |= B00111100;

  //Input set pins 2 - 5 as inputs
  DDRD &= B11000011;

}

void loop() {
  
  // to read boolean states from input pins
  //Pin 2 read
  boolean I0State = PIND & B00000100;
  //Pin 3 read
  boolean I1State = PIND & B00001000;
  //Pin 4 read
  boolean I2State = PIND & B00010000;
  //Pin 5 read
  boolean I3State = PIND & B00100000;

  //Output states
  boolean O0State;
  boolean O1State;
  boolean O2State;
  boolean O3State;

  //Logic
  O0State= ((!I1State && !I0State)||(!I3State && I2State && !I0State)||(I2State && !I1State)||(I3State && !I1State)||(I3State && I2State && I0State));
  O1State= ((!I2State && I1State && !I0State)||(I2State && !I1State && I0State)||(I3State && I1State));
  O2State= ((!I2State && !I1State && I0State)||(!I3State && I2State && !I0State)||(I2State && !I1State && !I0State)||(I3State && !I2State && I0State));
  O3State= ((!I3State && !I1State)||(!I3State && !I0State)||(I2State && !I0State)||(I3State && !I2State && I0State));

  //Pin 10 write
  if(O0State)
  {
    PORTB |= B00000100; //pin 10 high
  }
  else
  {
    PORTB &= B11111011; //pin 10 low
  }

  //Pin 11 write
  if(O1State)
  {
    PORTB |= B00001000; //pin 11 high
  }
  else
  {
    PORTB &= B11110111; //pin 11 low
  }

  //Pin 12 write
  if(O2State)
  {
    PORTB |= B00010000; //pin 12 high
  }
  else
  {
    PORTB &= B11101111; //pin 12 low
  }

  //Pin 13 write
  if(O3State)
  {
    PORTB |= B00100000; //pin 13 high
  }
  else
  {
    PORTB &= B11011111; //pin 13 low
  }

}
