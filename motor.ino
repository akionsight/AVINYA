/*
  L298N HW-094 DC MOTOR DRIVER MODULE
  modified on 25 Sep 2020
  by Saeed Olfat @ Electropeak
  Home
*/

void setup() {
  pinMode(12, OUTPUT); //IN2
  pinMode(11, OUTPUT); //IN1
  pinMode(10, OUTPUT); //Enable Pin
  pinMode(5, OUTPUT); // enable 2
  pinMode(6, OUTPUT); // IN4
  pinMode(7, OUTPUT); // IN3

  pinMode (13, INPUT) // CHEKKKKKK
}
void loop() {

  if (!digitalRead(13)) {

// Full speed forward
  digitalWrite(12, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(10, HIGH);
  
  digitalWrite(7, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(5, HIGH);
  
  delay(3000);

// Full speed backward
  digitalWrite(12, LOW);
  digitalWrite(11, HIGH);
  digitalWrite(10, HIGH);
  
  digitalWrite(7, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(5, HIGH);

  delay(3000);

  }

// 0 to 100% speed in forward mode
  // for (int i=0;i<256;i++)
  // {   digitalWrite(12, HIGH);
  //     digitalWrite(11, LOW);
  //     analogWrite(10, i);
  //     delay(20);      
  //     }

  // delay(50);

  // // 0 to 100% speed in backward mode
  //       for (int i=0;i<256;i++)
  // {   digitalWrite(8, LOW);
  //     digitalWrite(9, HIGH);
  //     analogWrite(10, i);
  //     delay(20);      
  //     }

  //       delay(50);
}
