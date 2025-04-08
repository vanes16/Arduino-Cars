  #define ENA_R 14
  #define ENA_L 12           
  #define MR_1  15       
  #define MR_2  13   
  #define MR_3  2     
  #define MR_4  0            
  #define TRIGGER_PIN  5  
  #define ECHO_PIN     4  
  #define MAX_DISTANCE 250
  
  #include <NewPing.h> 
  #include <ESP8266WiFi.h>
  NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); 

  
  void setup() {

   pinMode(ENA_R, OUTPUT);
   pinMode(MR_1, OUTPUT);
   pinMode(MR_2, OUTPUT);
   pinMode(ENA_L, OUTPUT);
   pinMode(MR_3, OUTPUT);
   pinMode(MR_4, OUTPUT);

  
  Serial.begin(115200);

   
  }

void goAhead(int t){ 
      
      digitalWrite(MR_1, LOW);
      digitalWrite(MR_2, HIGH);
      analogWrite(ENA_R, 150);
      delay(t);

  }

void brake(int t){  
   
      digitalWrite(MR_1, LOW);
      digitalWrite(MR_2, LOW);
      analogWrite(ENA_R, 0);
      delay(t);
 }

void loop() {
  int distance = sonar.ping_cm();
  if(distance >=20){
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.print(" cm");
    delay(1000);
    }
  if(distance<20){
    Serial.print("Careful!!!");
    delay(1000);
    }
}
