#include <Arduino.h>
#include <Wire.h> // for I2C
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <RTClib.h>

Adafruit_MPU6050 accel;
RTC_DS3231 gyro;

void setup() 
{
  Serial.begin(115200);
  Serial.println("Tracker Started");

  Wire.begin(); // Add pins?

  if (accel.begin() == false)
  {
    Serial.println("MPU6050 Failed to Start");
    return;
  }
  Serial.println("MPU6050 Started");

  if (gyro.begin() == false)
  {
    Serial.println("DS3231 Failed to Start");
    return;
  }
  Serial.println("DS3231 Started");

  if (gyro.lostPower()) 
  {
    Serial.println("RTC lost power, setting the time.");
    gyro.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() 
{
  // Next Steps: ask for documentation on these libraries so that I can try to use the proper methods myself
  // Think about what data I want to collect and more importantly HOW TO DISPLAY IT on the phone
}
