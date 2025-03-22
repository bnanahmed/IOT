
 #include <DHT.h>
#include <Servo.h>

// تعريف المداخل والمخارج
#define DHTPIN 3         // المستشعر متصل بـ Pin 3
#define DHTTYPE DHT22    // نوع المستشعر
#define HEATER_LED 11    // LED الأحمر (السخان)
#define PUMP_LED 12      // LED الأزرق (المضخة)
#define SERVO_PIN 9      // منفذ محرك السيرفو

// تهيئة المستشعر
DHT dht(DHTPIN, DHTTYPE);
Servo vent;  // إنشاء كائن لمحرك السيرفو

void setup() {
    // إعداد Serial للمراقبة
    Serial.begin(9600);
    Serial.println("Initializing System...");

    // تهيئة المستشعر
    dht.begin();

    // إعداد المخرجات
    pinMode(HEATER_LED, OUTPUT);
    pinMode(PUMP_LED, OUTPUT);

    // ربط محرك السيرفو بالمنفذ
    vent.attach(SERVO_PIN);

    // إطفاء جميع الأجهزة عند البداية
    digitalWrite(HEATER_LED, LOW);
    digitalWrite(PUMP_LED, LOW);
    vent.write(0); // إغلاق التهوية عند البداية

    Serial.println("System Ready.");
}

void loop() {
    // قراءة درجة الحرارة والرطوبة
    float temperature = dht.readTemperature();
    float humidity = dht.readHumidity();

    // التحقق من قراءة المستشعر
    if (isnan(temperature) || isnan(humidity)) {
        Serial.println("Error: Failed to read from DHT22 sensor!");
        delay(2000);
        return;
    }

    // طباعة القيم على Serial
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
    Serial.print("Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    // 🔹 التحكم في التهوية باستخدام السيرفو
    if (temperature > 30) {
        vent.write(90); // فتح التهوية (90°)
        Serial.println("Vent Opened (90°)");
    } else {
        vent.write(0); // إغلاق التهوية (0°)
        Serial.println("Vent Closed (0°)");
    }

    // 🔥 التحكم في السخان
    if (temperature < 20) {
        digitalWrite(HEATER_LED, HIGH); // تشغيل السخان
        Serial.println("Heater ON (Low Temperature).");
    } else {
        digitalWrite(HEATER_LED, LOW); // إطفاء السخان
        Serial.println("Heater OFF.");
    }

    // 💧 التحكم في المضخة بناءً على الرطوبة
    if (humidity < 50) {
        digitalWrite(PUMP_LED, HIGH); // تشغيل المضخة
        Serial.println("Pump ON (Low Humidity).");
    } else {
        digitalWrite(PUMP_LED, LOW); // إطفاء المضخة
        Serial.println("Pump OFF.");
    }

    // تأخير قبل القراءة التالية
    delay(2000);
}
