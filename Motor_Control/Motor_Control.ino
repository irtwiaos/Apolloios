#define EN 2
//#define SLP 4
#define stp 3
#define dir 5
//#define RST 6
#define CNT_0 7
#define CNT_1 8
#define CNT_2 9


//Declare variables for functions
int pills;
int x;
byte temp_num;
int count;


void setup() {
  pinMode(EN, OUTPUT);
  //pinMode(SLP, OUTPUT);
  pinMode(stp, OUTPUT);
  pinMode(dir, OUTPUT);
  //pinMode(RST, OUTPUT);
  pinMode(CNT_0, INPUT);
  pinMode(CNT_1, INPUT);
  pinMode(CNT_2, INPUT);
  resetPins(); //Set step, direction, microstep and enable pins to default states
  Serial.begin(9600); //Open Serial connection for debugging
  Serial.println("Begin motor control");
  Serial.println();
  //Print function list for user selection
  Serial.println("Enter number of pills to be dispensed");
  Serial.println();
}


//Main loop
void loop() {
  while(Serial.available()){
      Serial.println("Test");
      pills = Serial.parseInt(); 
      //digitalWrite(SLP, HIGH);
      digitalWrite(EN, LOW);
//      count = 0;
//      temp_num = digitalRead(CNT_2);
//      count = temp_num << 2;
//      temp_num = digitalRead(CNT_1);
//      count = count + (temp_num << 1);
//      temp_num = digitalRead(CNT_0);
//      count = count + temp_num;
//      Serial.println(count);
//      delay (500); 
//
//      if (pills > count)
//
//      {
        StepForwardDefault();
//}

//      else
//
//      {
        Serial.println("Pills Dispensed");
        resetPins();
//      }

  }

}


//Reset Big Easy Driver pins to default states
void resetPins()
{
  digitalWrite(EN, HIGH);
  //digitalWrite(SLP, LOW);
  digitalWrite(stp, LOW);
  digitalWrite(dir, LOW);
  //digitalWrite(RST, LOW);
}


//Default microstep mode function
void StepForwardDefault()
{
  Serial.println("Dispensing Pills");
  digitalWrite(dir, LOW); //Pull direction pin low to move "forward"
  for(x= 1; x<1000000000000000000000; x++)  //Loop the forward stepping enough times for motion to be visible
  {
    digitalWrite(stp,HIGH); //Trigger one step forward

      count = 0;
      temp_num = digitalRead(CNT_2);
      count = temp_num << 2;
      temp_num = digitalRead(CNT_1);
      count = count + (temp_num << 1);
      temp_num = digitalRead(CNT_0);
      count = count + temp_num;
      delay(20);
      Serial.println(count);
      delay (10); 

      if (pills <= count)
      {
        break;
      }
      
    digitalWrite(stp,LOW); //Pull step pin low so it can be triggered again
    delay(10);
  }
  //Serial.println("Enter new option");
  //Serial.println();
}
