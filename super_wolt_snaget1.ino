#this is a code for Arduino for detecting animals in the farm lands and issue an alert to the farmer

#define trigPin  13
#define echoPin 12


int buzzer = 11; // Buzzer is connected to pin 8
int ledPin= 10;  //LED is connected to pin 6
int duration, distance; /*Measure the distance and time taken by the Animal to reach the Field*/ 

void setup() {
        Serial.begin (9600); 
        /*Define the output and input object devices*/
        pinMode(trigPin, OUTPUT); 
        pinMode(echoPin, INPUT);
        pinMode(buzzer, OUTPUT);
        pinMode(ledPin, OUTPUT);
}

void loop() {

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration/2) / 29.1;
    //when distance is greater than or equal to 60 OR less than or equal to 0,the buzzer and LED are off
  if (distance >= 60 || distance <= 0) 
        {
        Serial.println("No Animal Detected");
        digitalWrite(buzzer,LOW);
        digitalWrite(ledPin,LOW);
        }
  else {
        Serial.println("metres");
        Serial.print("The animal is at a distance of = ");              
        Serial.print(distance);        //prints the distance if it is between the range 0 to 60
        tone(buzzer,400);              // play tone of 400Hz for 500 ms
        digitalWrite(ledPin,HIGH);
  }
}
