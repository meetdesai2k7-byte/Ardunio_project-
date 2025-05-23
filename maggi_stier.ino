// Pin definitions
const int motorPin = 9;     // PWM pin for controlling DC motor
const int buzzerPin = 10;   // Pin connected to buzzer

bool cooking = false;

void setup() {
  pinMode(motorPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  
  // Start cooking automatically
  startCooking();
}

void loop() {
  // This loop can be left empty since the operation is handled in startCooking function
}

void startCooking() {
  cooking = true;
  Serial.println("Cooking started.");

  // Start stirring for 8 minutes (480 seconds)
  unsigned long startTime = millis();
  unsigned long cookingDuration = 8 * 60 * 1000; // 8 minutes in milliseconds

  // Stirring while the cooking duration hasn't passed
  while (millis() - startTime < cookingDuration) {
    analogWrite(motorPin, 255); // Adjust PWM value for motor speed (0-255)
    delay(1000); // Stirring interval (adjust as needed)
  }

  // Stop the motor after cooking time
  analogWrite(motorPin, 0);

  // Cooking is done, activate the buzzer
  Serial.println("Your Maggi is ready!");
  tone(buzzerPin, 1000); // Set the frequency of the buzzer
  delay(2000); // Duration of the beep (2 seconds)
  noTone(buzzerPin); // Turn off the buzzer

  cooking = false;
}
