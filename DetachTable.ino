#include <Servo.h>
#include <SoftwareSerial.h>   
Servo servo_a, servo_b
int bluetooth_Rx = 11;
int bluetooth_Tx = 10; 
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
  servo_a.attach(9); 
  servo_b.attach(5);
  servo_a.write(90);  
  servo_b.write(90);
}

void loop()
{
  //Read from bluetooth and write to usb serial
  if(bluetooth.available()>= 2 )
  {
    unsigned int servo = bluetooth.read();
    unsigned int servo_1 = bluetooth.read();
    unsigned int servo_rot = servo + (servo_1 *256);
    
    if (servo_rot >= 1000 && servo_rot <1180) {
      int x = servo_rot;
      x = map(x, 1000, 1180, 0, 180);
      myservo1.write(x);
      myservo2.write(x);
      delay(10);
    }
  }
}
