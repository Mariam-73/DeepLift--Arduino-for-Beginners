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

void setup() {
  pinMode(Out1, INPUT);
  pinMode(Out2, INPUT);
  pinMode(Out3, INPUT);
  pinMode(Out4, INPUT);
  pinMode(Out5, INPUT);
  pinMode(OutF, INPUT);
  Serial.begin(9600);
}

void loop() {
  Sensor1 = analogRead(Out1);
  Sensor2 = analogRead(Out2);
  Sensor3 = analogRead(Out3);
  Sensor4 = analogRead(Out4);
  Sensor5 = analogRead(Out5);
  SensorF = analogRead(OutF);
  Serial.println("\nSensor1: "); Serial.println(Sensor1);
  Serial.println("\nSensor2: "); Serial.println(Sensor2);
  Serial.println("\nSensor3: "); Serial.println(Sensor3);
  Serial.println("\nSensor4: "); Serial.println(Sensor4);
  Serial.println("\nSensor5: "); Serial.println(Sensor5);
  Serial.println("\nSensorF: "); Serial.println(SensorF);
}
