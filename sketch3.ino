const int ledPin = 13;       // المنفذ الموصل به LED
const int buttonPin = 7;     // المنفذ الموصل به الزر

bool ledState = false;       // حالة LED (ON/OFF)
bool lastButtonState = HIGH; // تخزين الحالة السابقة للزر

void setup() {
  pinMode(ledPin, OUTPUT);        // تحديد LED كمخرج
  pinMode(buttonPin, INPUT_PULLUP); // تحديد الزر كمدخل مع مقاومة داخلية
}

void loop() {
  bool currentButtonState = digitalRead(buttonPin); // قراءة حالة الزر

  // التحقق من الضغط على الزر
  if (currentButtonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState; // تبديل حالة LED
    digitalWrite(ledPin, ledState); // تشغيل أو إطفاء LED
    delay(200); // تأخير بسيط لمنع الاهتزاز (debounce)
  }

  lastButtonState = currentButtonState; // تحديث الحالة السابقة للزر
}