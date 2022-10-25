// Defines pins numbers
const int stepPin = 3;
const int dirPin = 4;

const int ms2Pin = 5;
const int forwardReversePin = 6;
int customDelay,customDelayMapped; // Defines variables
 
void setup() {
  // Sets the four pins as Outputs
  pinMode(stepPin,OUTPUT);
  pinMode(dirPin,OUTPUT);
  pinMode(ms2Pin,OUTPUT);
  pinMode(forwardReversePin,OUTPUT);
 
  digitalWrite(dirPin,HIGH); //Enables the motor to move in a particular direction

  digitalWrite(ms2Pin,HIGH); // set it to 1/4 speed
}
void loop() {
  digitalWrite(dirPin,digitalRead(forwardReversePin));
  customDelayMapped = speedUp(); // Gets custom delay values from the custom speedUp function
  // Makes pules with custom delay, depending on the Potentiometer, from which the speed of the motor depends
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(customDelayMapped);
  digitalWrite(stepPin, LOW);
  delayMicroseconds(customDelayMapped);
}
// Function for reading the Potentiometer
int speedUp() {
  int customDelay = analogRead(A0); // Reads the potentiometer
  int newCustom = map(customDelay, 0, 1023, 300,10000); // Convrests the read values of the potentiometer from 0 to 1023 into desireded delay values (300 to 4000)
  return newCustom;  
}
