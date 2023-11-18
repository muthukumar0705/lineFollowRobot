#include <math.h>

#define ir1 8
#define ir2 9
#define enA 2
#define in1 3
#define in2 4
#define enB 5
#define in3 6
#define in4 7
#define buttonPin 10

#define fastA 255
#define fastB 255
#define turnTimer 125

int currentButton;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  analogWrite(enA, fastA);
  analogWrite(enB, fastB);
}

void loop() {
  bool irSensor1 = digitalRead(ir1);
  bool irSensor2 = digitalRead(ir2);
  int prevButton = currentButton;
  currentButton = digitalRead(buttonPin);

  if (irSensor1 == 1 && irSensor2 == 1) {
    pause();
  } else if (irSensor1 == 1) {
      left();
      delay(turnTimer);
  } else if (irSensor2 == 1) {
    right();
    delay(turnTimer);
  }
  if(currentButton != prevButton && currentButton == LOW) {
    delay(5000);
    forward();
    delay(700);
  }
  
  if (irSensor1 == 0 && irSensor2 == 0) {
      forward();
  }
  delay(10);
}

void forward() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void pause() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
