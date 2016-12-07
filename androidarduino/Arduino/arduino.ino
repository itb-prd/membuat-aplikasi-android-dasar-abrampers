
const int led = 12;

const int tempSensor = A0;


float sensorValue = 0;
char serialByte = 0;

void setup() {
 
  Serial.begin(9600);

  pinMode(led, OUTPUT);
 
  digitalWrite(led, LOW);
}

void loop() {
  readSensorTemp();
  sendDataAndroid();
  
  
  if(Serial.available() > 0) {
    serialByte = Serial.read();
    
    if(serialByte == '0') {
      digitalWrite(led, LOW);
    }
    if(serialByte == '1') {
      
      digitalWrite(led, HIGH);
    }
  }
  
  
  delay(2000);
}

void readSensorTemp() {
  sensorValue = (5.0 * analogRead(tempSensor) * 100.0) / 1024;
}

void sendDataAndroid() {
  Serial.print(sensorValue);
  Serial.print('\n');
  delay(10);
}
