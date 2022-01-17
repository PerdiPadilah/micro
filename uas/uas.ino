#include <MD_Parola.h>
#include <MD_MAX72xx.h>
#include <SPI.h>

// Define hardware type, size, and output pins:
#define HARDWARE_TYPE MD_MAX72XX::FC16_HW
#define MAX_DEVICES 4
#define CS_PIN 8

const int trigPin = 2;
const int echoPin = 3;
const int buzzer = 6;
const int ledPin = 5;
const int Button = 7;
int mulai = 1;


// defines variables
long duration;
int distance;
int safetyDistance;

MD_Parola myDisplay = MD_Parola(HARDWARE_TYPE, CS_PIN, MAX_DEVICES);

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication

 // Intialize the object:
  myDisplay.begin();
  // Set the intensity (brightness) of the display (0-15):
  myDisplay.setIntensity(0);  
  // Clear the display:
  myDisplay.displayClear();
  digitalWrite(Button, HIGH);
}


void loop() {
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
safetyDistance = distance;

        if (safetyDistance <= 30){

             myDisplay.setTextAlignment(PA_CENTER);
             myDisplay.print("AWAS");
             digitalWrite(buzzer, HIGH);
             digitalWrite(ledPin, HIGH);
        }
        else{
          myDisplay.setTextAlignment(PA_CENTER);
          myDisplay.print("AMAN");
          digitalWrite(buzzer, LOW);
          digitalWrite(ledPin, LOW);
        }

        // Prints the distance on the Serial Monitor
        Serial.print("Distance: ");
        Serial.println(distance);
      
}
