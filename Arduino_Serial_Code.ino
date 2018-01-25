#include <Adafruit_INA219.h>

Adafruit_INA219 sensor219;

void setup() {
  /* Set the baud rate for the software serial port */
  Serial.begin(9600); // Initialise Serial
  delay(1000);
  Serial.print("PV Device: ");
  delay(1000);
  sensor219.begin(); // Initialize voltage/current Sensor
}
void loop() {
  // Take readings

  float busVoltage = 5;
  float current = 5;
  float power = 0;


  busVoltage = sensor219.getBusVoltage_V();
  //Record the voltage
  current = sensor219.getCurrent_mA();
  //Record the current
  power = busVoltage * (current);
  //Power is equal to voltage * current

  Serial.print("Power");
  //Send data over serial

  Serial.println(power);
  Serial.println("mW")
  Serial.print("\n");
  delay(500);
  //Send 2 samples per second
}

