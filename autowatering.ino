/* Garden Module
 *  Developed by Paula Costa do Valle Gondim
 *  Last updated: 10/09/2020
 *  This is a generic code. If there are any issues, contact at paulavallerobotics@gmail.com 
*/


//Libraries

#include <math.h>

//Analog Pins
int soilPin1 = 1;//A1
int soilPin2 = 2;//A2
int soilPin3 = 3;//A2
int soilPin4 = 4;//A2

//variables
int soilRead1 = 0;
int soilRead2 = 0;
int soilRead3 = 0;
int soilRead4 = 0;

int waterlevel = 0; //A0 //lets make water level digital input

void setup() {

  //set-up pins
  pinMode(2, OUTPUT); //INT1
  pinMode(3, OUTPUT); //INT2
  pinMode(4, OUTPUT); //INT3
  pinMode(5, OUTPUT); //INT4

  pinMode(7, INPUT); //water level

  pinMode(9, OUTPUT); //low water level warning
  
  Serial.begin(9600);

}

void loop() {

  delay(100);

  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);
  digitalWrite(9,LOW);
  delay (1000);
  
  soilRead1 = analogRead(soilPin1);
  soilRead2 = analogRead(soilPin2);
  soilRead3 = analogRead(soilPin3);
  soilRead4 = analogRead(soilPin4);


  waterlevel = digitalRead(7); 
  
  if(waterlevel == HIGH){
    Serial.println(" NO WATER! ");
    digitalWrite(9,HIGH);
    delay(1000);
    }
    else {
      Serial.println(" Water level is acceptable.");
    }

  
  Serial.print(soilRead1);
  Serial.print(" / ");
  Serial.print(soilRead2);
  Serial.print(" / ");
  Serial.print(soilRead3);
  Serial.print(" / ");
  Serial.print(soilRead4);
  Serial.print(" / ");
  
  Serial.println("");
  delay(100);


//only works if it has water on the tank

  if(waterlevel == LOW){
  
    //pump1 //INT1
    if (soilRead1 > 400){
      Serial.print("dry / ");
      digitalWrite(2,LOW);
      delay (60000); //pump is on for 1min
      digitalWrite(2,HIGH);
    }
     else {
      digitalWrite(2,HIGH);
      Serial.print("wet / ");
     }
     
    //pump2 //INT2 
    if (soilRead2 > 500){
      Serial.print("dry / ");
      digitalWrite(3,LOW);
      delay (40000);
      digitalWrite(3,HIGH);
    }
     else {
      digitalWrite(3,HIGH);
      Serial.print("wet / ");
     }
  
    //pump3 //INT3
     if (soilRead2 > 500){
      Serial.print("dry / ");
      digitalWrite(4,LOW);
      delay (60000);
      digitalWrite(4,HIGH);
    }
     else {
      digitalWrite(4,HIGH);
      Serial.print("wet / ");
     }
  
    //pump4 //INT4
     if (soilRead2 > 500){
      Serial.print("dry / ");
      digitalWrite(5,LOW);
      delay (60000);
      digitalWrite(5,HIGH);
    }
     else {
      digitalWrite(5,HIGH);
      Serial.print("wet / ");
     }
     
  }
  else {
    digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    
    digitalWrite(9,LOW);
  }

  Serial.println(""); 

  digitalWrite(9,LOW);

  delay(60000); //wait 1min until next cycle
  

  //with this battery setup, if the arduino goes idle the battery turns off forever
  //make sure to check your relay logic for digital outputs HIGH or LOW
}
