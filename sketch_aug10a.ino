const int FSR_PIN = A0;          // Analog pin connected to FSR
const int SPEAKER_PIN = 2;       // Digital pin connected to Grove Speaker
const int VIBRATION_PIN = 3;     // Digital pin connected to Vibration Motor

const int FSR_THRESHOLD = 100;   // Threshold value for FSR to detect high pressure
const int FEEDBACK_DURATION = 100; // Short duration for ping sound and vibration in milliseconds

void setup() {
  pinMode(FSR_PIN, INPUT);
  pinMode(SPEAKER_PIN, OUTPUT);
  pinMode(VIBRATION_PIN, OUTPUT);
  Serial.begin(9600);  // Initialize serial communication for debugging
}

void loop() {
  int fsrValue = analogRead(FSR_PIN);  // Read the FSR value
  Serial.println(fsrValue);            // Print the FSR value for debugging

  if (fsrValue > FSR_THRESHOLD) {
    // If the FSR value exceeds the threshold, provide feedback
    providePingFeedback();
  }

  delay(100);  // Small delay to avoid flooding the serial monitor
}

void providePingFeedback() {
  tone(SPEAKER_PIN, 1500, FEEDBACK_DURATION);  // Generate a "ping" sound at 1500 Hz for 100ms
  digitalWrite(VIBRATION_PIN, HIGH);           // Turn on the vibration motor
  delay(FEEDBACK_DURATION);                    // Wait for the duration of the ping
  digitalWrite(VIBRATION_PIN, LOW);            // Turn off the vibration motor
}
