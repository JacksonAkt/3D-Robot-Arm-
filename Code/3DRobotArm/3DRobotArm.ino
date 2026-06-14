#include <Servo.h>
#include <IRremote.hpp>



//Remote Control 
#define IR_RECEIVE_PIN 22



//Servo
Servo myServo;
const int servoPin = 6;
int recentAngle = 0;
bool ServoState = false; 



//X,Y,Z
const int XSTEP = A0;
const int XDIR = A1;
const int YSTEP = A6;
const int YDIR = A7;
const int ZSTEP = 46;
const int ZDIR = 48;

//A,B,C
const int ASTEP = 26;
const int ADIR = 28;
const int BSTEP = 36;
const int BDIR = 34;
const int CSTEP = 49;
const int CDIR = 51;



int XNsensor = A9;
int XSsensor = A8; 
int YNsensor = A11;
int YSsensor = A10; 
int ZNsensor = 53;
int ZSsensor = 50; 

int ANsensor = 43;
int ASsensor = 41; 
int BNsensor = 39;
int BSsensor = 37; 
int CNsensor = 35;
int CSsensor = 33; 


//Variables to control motors 
char selectedAxis = 'X'; // Choose the motor to control

bool motorRunning = false; //the state of motors (run/stay)

//multi-purpose variables to use between motors 
int currentStepPin = XSTEP; 
int currentDirPin = XDIR; 

unsigned long lastIRTime = 0; //the time when the most recent ID signal was received
const unsigned long IR_TIMEOUT = 150; //the last period of disconnection before the command stops

//variables corresponding to the address of turn buttons
uint8_t CMD_LEFT = 0x8;
uint8_t CMD_RIGHT = 0x5A;

uint8_t CMD_SERVO = 0x1C;

void setup() {
  Serial.begin(9600);

pinMode(XSTEP, OUTPUT);
pinMode(XDIR, OUTPUT);
pinMode(YSTEP, OUTPUT);
pinMode(YDIR, OUTPUT);
pinMode(ZSTEP, OUTPUT);
pinMode(ZDIR, OUTPUT);

pinMode(ASTEP, OUTPUT);
pinMode(ADIR, OUTPUT);
pinMode(BSTEP, OUTPUT);
pinMode(BDIR, OUTPUT);
pinMode(CSTEP, OUTPUT);
pinMode(CDIR, OUTPUT);


pinMode(XNsensor, INPUT);
pinMode(XSsensor, INPUT);
pinMode(YNsensor, INPUT);
pinMode(YSsensor, INPUT);
pinMode(ZNsensor, INPUT);
pinMode(ZSsensor, INPUT);

pinMode(ANsensor, INPUT);
pinMode(ASsensor, INPUT);
pinMode(BNsensor, INPUT);
pinMode(BSsensor, INPUT);
pinMode(CNsensor, INPUT);
pinMode(CSsensor, INPUT);

//Servo Motor
  myServo.attach(servoPin);
  myServo.write(recentAngle);

//Remote
  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);
  Serial.println("Press buttons on the IR remote...");

}

void loop() {
  


//To run motor only, comment out the whole code before run
/* 
digitalWrite(XDIR, HIGH);
rotateX();

delay(2000);

digitalWrite(XDIR, LOW);
rotateX();

delay(2000);
*/


if (IrReceiver.decode()) { //start the game once a button is pressed 

    uint8_t cmd = IrReceiver.decodedIRData.command; 

    Serial.print("Command: 0x"); //print the address of recent button
    Serial.println(cmd, HEX);

    switch(cmd) {
      case 0x45: // X-axis command is 0x45
          selectAxis('X');
          motorRunning = false;
          Serial.print("Motor X has been chosen and is moving"); 
          break;
      case 0x46: // Y-axis command is 0x45
          selectAxis('Y');
          motorRunning = false;
          Serial.println("Motor Y has been chosen and is moving"); 
          break;
      case 0x47: // Z-axis command is 0x45
          selectAxis('Z');
          motorRunning = false;
          Serial.println("Motor Z has been chosen and is moving"); 
          break;
      case 0x44: // A-axis command is 0x45
          selectAxis('A');
          motorRunning = false;
          Serial.println("Motor A has been chosen and is moving"); 
          break;
      case 0x40: // B-axis command is 0x45
          selectAxis('B');
          motorRunning = false;
          Serial.println("Motor B has been chosen and is moving"); 
          break;
      case 0x43: // C-axis command is 0x45
          selectAxis('C');
          motorRunning = false;
          Serial.println("Motor C has been chosen and is moving"); 
          break;
    }

    //control the motor to turn left/right
    if (cmd == CMD_LEFT) {
      digitalWrite(currentDirPin, LOW);
      motorRunning = true;
      lastIRTime = millis();
      Serial.println("to the left");
    }

    if (cmd == CMD_RIGHT) {
      digitalWrite(currentDirPin, HIGH);
      motorRunning = true;
      lastIRTime = millis();
      Serial.println("to the right");
    }

    if(cmd == CMD_SERVO) {
      toggleServo(); 
      delay(250);
    }

   //detect if the command is repeated (button is held)
    if (IrReceiver.decodedIRData.flags & IRDATA_FLAGS_IS_REPEAT) {
      Serial.println("Repeat signal detected");
      lastIRTime = millis();
    }
    IrReceiver.resume(); // Receive the next value
  }

  // Stop motor after button release
  if (millis() - lastIRTime > IR_TIMEOUT) {
    motorRunning = false;
  }

  if (motorRunning) {
    StepMotor(currentStepPin);
  }
}

//choose a motor to control 
void selectAxis(char axis) {
 selectedAxis = axis; 
 switch(axis) {
  case 'X': 
      currentStepPin = XSTEP; 
      currentDirPin = XDIR; 
      break; 
  case 'Y': 
      currentStepPin = YSTEP; 
      currentDirPin = YDIR; 
      break; 
  case 'Z': 
      currentStepPin = ZSTEP; 
      currentDirPin = ZDIR; 
      break; 
  case 'A': 
      currentStepPin = ASTEP; 
      currentDirPin = ADIR; 
      break; 
  case 'B': 
      currentStepPin = BSTEP; 
      currentDirPin = BDIR; 
      break; 
  case 'C': 
      currentStepPin = CSTEP; 
      currentDirPin = CDIR;   
      break; 
 }
  Serial.print("Selected axis: ");
  Serial.println(selectedAxis);
}

//enable the step motor to move 
/* Stepper Motor reaches to change in state, not the state itself) */ 
void StepMotor(int StepPin) {
    digitalWrite(StepPin, HIGH);
    delayMicroseconds(800);
    digitalWrite(StepPin, LOW);
    delayMicroseconds(800);
}

void toggleServo() {
  ServoState = !ServoState; 

  if(ServoState) {
    myServo.write(0);
  } else {
    myServo.write(180);
  }
}

//Motor test only
/*
void rotateX() {
  for (int x = 0; x < 800; x++) {
    digitalWrite(XSTEP, HIGH);
    delayMicroseconds(1000);

    digitalWrite(XSTEP, LOW);
    delayMicroseconds(1000);
  }
}
*/

-