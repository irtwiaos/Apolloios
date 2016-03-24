#define Hor 2
#define Ver 3
#define zero 4
#define nine 5

#include <Servo.h>


int pos = 0;    // variable to store the servo position
int h;
int v;
int z;
int n;

char X;
 
Servo myservo;  // create servo object to control a servo 
                // twelve servo objects can be created on most boards



 
 
 
void setup() 
{ 
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
  pinMode(Hor, INPUT);
  pinMode(Ver, INPUT);
  pinMode(zero, INPUT);
  pinMode(nine, INPUT);
  Serial.begin(9600);
  
} 
 
void loop() 
{ 
   while(Serial.available())
  {
     X = Serial.read();
      h = digitalRead(Hor);
      v = digitalRead(Ver);
      z = digitalRead(zero);
      n = digitalRead(nine);
    Serial.print("While");
    if (X == '1')
    {
      while(!(h == HIGH && z == HIGH))
      {
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        Serial.println("here");
        h = digitalRead(Hor);
        Serial.println(h);
        v = digitalRead(Ver);
        z = digitalRead(zero);
        n = digitalRead(nine);
        delay(15);                      
      }
        myservo.write(90); 
    }
    else if (X == '2')
    {
      while(!(v == HIGH && n == HIGH))
      {
        myservo.write(pos);
        delay(15);
        h = digitalRead(Hor);
        v = digitalRead(Ver);
        z = digitalRead(zero);
        n = digitalRead(nine);
      }
        myservo.write(90);
    }
    else if (X == '3')
    {
      while(!(h == HIGH))
      {
        myservo.write(pos);
        delay(15);
        h = digitalRead(Hor);
        v = digitalRead(Ver);
        z = digitalRead(zero);
        n = digitalRead(nine);
      }
        myservo.write(90);
    }
    else if(X == '4')
    {
      while(!(v == HIGH))
      {
        myservo.write(pos);
        delay(15);
        h = digitalRead(Hor);
        v = digitalRead(Ver);
        z = digitalRead(zero);
        n = digitalRead(nine);
      }
        myservo.write(90);
    }
  }
}
