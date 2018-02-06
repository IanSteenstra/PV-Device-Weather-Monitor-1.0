#include <Adafruit_INA219.h>

// BT Data Logger
 // BlueTooth Configuration
 /* Include the software serial port library */
 #include <SoftwareSerial.h>
 /* to communicate with the Bluetooth module's TXD pin */
 #define BT_SERIAL_TX 11
 /* to communicate with the Bluetooth module's RXD pin */
 #define BT_SERIAL_RX 10
 /* Initialise the software serial port */
 SoftwareSerial BluetoothSerial(BT_SERIAL_TX, BT_SERIAL_RX); 

Adafruit_INA219 sensor219;

 void setup() {
 /* Set the baud rate for the software serial port */
 BluetoothSerial.begin(38400); // Initialise BlueTooth
 delay(1000);
 BluetoothSerial.print("PV Device: ");
 delay(1000); 
 sensor219.begin(); // Initialize voltage/current Sensor
 }
void loop() {
 // Take readings
 
  float busVoltage = 0;                  
  float current = 0;
  float power= 0;

  
  busVoltage = sensor219.getBusVoltage_V();             
  //Record the voltage
  current = sensor219.getCurrent_mA();
  //Record the current
  power= busVoltage * (current) ;
  //Power is equal to voltage * current

 BluetoothSerial.print("Power: "); 
 //Send data over bluetooth  
 // YELLOW Power will be displayed on the table//

 BluetoothSerial.println(power); 
 BluetoothSerial.println("mW");  BluetoothSerial.print("\n");
 delay(500);
 //Send 2 samples per second
 }
 
 

