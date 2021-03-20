 # define THRESHOLD 400

//Define Pins

//Motor Pins
//Enable Pin of the Right Motor (must be PWM)
#define LM1 2       // left motor
#define LM2 3       // left motor
#define ENA 9
#define RM1 4       // right motor
#define RM2 5       // right motor
#define ENB 10

//Sensors Pins
int Out1 = A0;
int Out2 = A1;
int Out3 = A2;
int Out4 = A3;
int Out5 = A4;
int OutF = A5;

//Sensor values initialization
int Sensor1 = 0;
int Sensor2 = 0;
int Sensor3 = 0;
int Sensor4 = 0;
int Sensor5 = 0;
int SensorF = 0;

//Funtion Declerations
void MoveForward(void);
void MoveRight(void);
void MoveLeft(void);
void MoveBack(void);
void MoveSRight(void);
void MoveSLeft(void);
void Stop (void);


void setup() {

  pinMode(LM1, OUTPUT);
  pinMode(LM2, OUTPUT);
  pinMode(RM1, OUTPUT);
  pinMode(RM2, OUTPUT);
  
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(Out1, INPUT);
  pinMode(Out2, INPUT);
  pinMode(Out3, INPUT);
  pinMode(Out4, INPUT);
  pinMode(Out5, INPUT);
  pinMode(OutF, INPUT);
  Serial.begin(9600); 
  
}

void loop(){
  //Use analogWrite to run motor at adjusted speed
    analogWrite(ENA, 100);
    analogWrite(ENB, 100);
  Sensor1 = analogRead(Out1);
  Sensor2 = analogRead(Out2);
  Sensor3 = analogRead(Out3);
  Sensor4 = analogRead(Out4);
  Sensor5 = analogRead(Out5);
  SensorF = analogRead(OutF);

  // White = 0
  // Black = 1
  
  Sensor1 = Sensor1 > THRESHOLD? 0:1;
  Sensor2 = Sensor2 > THRESHOLD? 0:1;
  Sensor3 = Sensor3 > THRESHOLD? 0:1;
  Sensor4 = Sensor4 > THRESHOLD? 0:1;
  Sensor5 = Sensor5 > THRESHOLD? 0:1;
  SensorF = SensorF < THRESHOLD? 0:1;


if (!Sensor1 && !Sensor5) //  2 sensor work
 {
   if(!SensorF && !Sensor2 && !Sensor3 && !Sensor4)
   MoveBack();
  else{
   if (SensorF || Sensor3)
    MoveForward();
  else if (Sensor2 && !Sensor4) 
    MoveLeft();
  else if (!Sensor2 && Sensor4)
    MoveRight();
  else
    Stop();
 }
 
 }
else {
  if ((Sensor2 || Sensor1)) 
    MoveSLeft();  //for checkpoints
    
  else if ((Sensor4 || Sensor5)) 
    MoveSRight();
  else
    Stop();
 }
delay(5);

}

void MoveForward(void)
{

    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
    delay(35);
}

void MoveBack(void)
{

    
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, HIGH);
    digitalWrite(RM2, LOW);
    delay(40);
}

void MoveSRight(void)
{
    digitalWrite(LM1, HIGH);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
delay(110);
}

void MoveSLeft(void)
{
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, HIGH); 
    digitalWrite(RM2, LOW);
delay(110);
}

void MoveRight(void)
{
     
    
    digitalWrite(LM1, LOW); 
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, HIGH);
   
}

void MoveLeft(void)
{
     
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, HIGH);
    digitalWrite(RM1, LOW); 
    digitalWrite(RM2, LOW);
}

void Stop(void)
{
       
    analogWrite(ENA, 0);
    analogWrite(ENB, 0);
    
    digitalWrite(LM1, LOW);
    digitalWrite(LM2, LOW);
    digitalWrite(RM1, LOW);
    digitalWrite(RM2, LOW);
}
