int sensorPin = A0;    // select the input pin for the potentiometer
int sensorValue = 0;  // variable to store the value coming from the sensor
char trans[20];
 
void setup() {
  // declare the ledPin as an OUTPUT:
   Serial.begin(9600);  
}
 
void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);  

    
  delay(1000); 

  //シリアルからのデータ送信する
  memset(trans,0,20);
  char *json = &trans[0];

  
  //送信用のJSONデータの作成を行う
  sprintf(json, "{\"moisture\":%d}", sensorValue);                                
  Serial.println(json);                   
}
