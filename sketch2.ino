const int redLed = 12;   // تعريف المنفذ الخاص بـ LED الأحمر
const int greenLed = 11; // تعريف المنفذ الخاص بـ LED الأخضر

void setup() {
  pinMode(redLed, OUTPUT);   // تعيين LED الأحمر كمخرج
  pinMode(greenLed, OUTPUT); // تعيين LED الأخضر كمخرج
}

void loop() {
  digitalWrite(redLed, HIGH);  // تشغيل LED الأحمر
  delay(500);
  digitalWrite(redLed, LOW);   // إطفاء LED الأحمر
  delay(500);

  digitalWrite(greenLed, HIGH); // تشغيل LED الأخضر
  delay(250);
  digitalWrite(greenLed, LOW);  // إطفاء LED الأخضر
  delay(250);
}


