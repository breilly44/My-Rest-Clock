
const int note = 330;           // Note frequency
const int note_time = 3000;     // three seconds
const int threshold = 500;      // Analog read threshold
const int debounce_delay = 50;  // Debounce delay

unsigned long rest_time = 45000;    // 45 seconds

void setup() {
  Serial.begin(9600);
  pinMode(8, OUTPUT);
}

void loop() {
  int keyVal = analogRead(A0);

  if (keyVal > threshold) {
    delay(debounce_delay);      // Debounce delay
    delay(rest_time);           // Wait for rest time
    tone(8, note);              // Send note to piezo
    delay(note_time);           // Hold note for note_time duration
    noTone(8);                  // Stop note
  } else {
    noTone(8);
  }
}
