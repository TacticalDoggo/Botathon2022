 // put your main code here, to run repeatedly:
#include <ArduinoJson.h>

StaticJsonDocument<200> doc;

// Motor A connections
int enA = 8; //9
int in1 = 2; //8
int in2 = 3; //7
// Motor B connections
int enB = 9; //3
int in3 = 4; //5
int in4 = 5; //4
//motor c
int in5 = 6;
int in6 = 7;

//motor d
int in7 = 8;
int in8 = 9;

String incomingByte = "";

void setup() {
  Serial.begin(115200);
  Serial.setTimeout(100);
  
  // Set all the motor control pins to outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(in5, OUTPUT);
  pinMode(in6, OUTPUT);
  pinMode(in7, OUTPUT);
  pinMode(in8, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
  
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  Serial.println("Started");
}

bool A_BUTTON_PRESSED = false;

void loop() {
  //if (Serial.available() > 0) {
    // read the incoming byte:
    incomingByte = Serial.readString();

    // say what you got:
    Serial.print("I received: ");
    Serial.print(incomingByte);

    DeserializationError error = deserializeJson(doc, incomingByte);

    if (error) {
      Serial.print(F("deserializeJson() failed: "));
      Serial.println(error.f_str());
      return;
    }

    String key = doc["input"]["key"];
    float value = doc["input"]["value"].as<float>();

    
    int x = doc["input"]["value"]["x"].as<int>();
    
    Serial.print("KEY:");
    Serial.print(key);
    Serial.print(", VAL:");
    Serial.println(value);

    if (key == "A_BUTTON" && value == true) {
      backwards();
    }
    else if (key == "A_BUTTON" && value == false){
      halt();
    }
    if (key == "Y_BUTTON" && value == true) {
      forwards();
    }
    else if (key == "Y_BUTTON" && value == false){
      halt();
    }
    if (key == "X_BUTTON" && value == true) {
      right_forwards();
    }
    else if (key == "X_BUTTON" && value == false){
      halt();
    }
    if (key == "B_BUTTON" && value == true) {
      left_forwards();
    }
    else if (key == "B_BUTTON" && value == false){
      halt();
    }    

    



  //}
  
  //directionControl();
  //delay(1000);
  //speedControl();
  //delay(1000);
}

void forwards() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
  
}
void backwards() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  digitalWrite(in5, HIGH);
  digitalWrite(in6, LOW);
  digitalWrite(in7, HIGH);
  digitalWrite(in8, LOW);
}

void left_forwards() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
}
void right_forwards() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}
void left_backwards() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in5, LOW);
  digitalWrite(in6, HIGH);
}
void right_backwards() {
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  digitalWrite(in7, LOW);
  digitalWrite(in8, HIGH);
}

void halt() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(in5, LOW);
  digitalWrite(in6, LOW);
  digitalWrite(in7, LOW);
  digitalWrite(in8, LOW);
}

















//void setup() {
//  // put your setup code here, to run once:
//  pinMode(motor1pin1, OUTPUT);
//  pinMode(motor1pin2, OUTPUT);
//  pinMode(motor2pin1, OUTPUT);
//  pinMode(motor2pin2, OUTPUT);
//}

//void loop() {
//  // put your main code here, to run repeatedly:   
//  delay(5000);
//  digitalWrite(motor1pin1, HIGH);
//  digitalWrite(motor1pin2, LOW);
//
//  digitalWrite(motor2pin1, HIGH);
//  digitalWrite(motor2pin2, LOW);
//  delay(1000);
//
//  digitalWrite(motor1pin1, LOW);
//  digitalWrite(motor1pin2, HIGH);
//
//  digitalWrite(motor2pin1, LOW);
//  digitalWrite(motor2pin2, HIGH);
//  delay(1000);
//}
