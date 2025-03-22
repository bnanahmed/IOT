void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // تعيين LED كمخرج
}

void loop() {
  digitalWrite(LED_BUILTIN, HIGH); // تشغيل LED
  delay(2000); // الانتظار لمدة ثانيتين
  digitalWrite(LED_BUILTIN, LOW);  // إطفاء LED
  delay(2000); // الانتظار لمدة ثانيتين أخرى
} 