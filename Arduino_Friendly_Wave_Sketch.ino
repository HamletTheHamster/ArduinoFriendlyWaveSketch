/* This program uses a motion sensor to activate a servo motor to "wave" when somebody walks by.
   Connect the motion sensor to pin 12, 5V, and GRND.
   Connect the servo motor to pin 10, 5V, and GRND.
   LED is build in to arduino board, tethered to pin 13

    9-19-2016
    Code by: Joel N. Johnson    
*/


#include <Servo.h>

// Creates servo object
Servo friendlyWave;                  

// Variable declaration
int pos;                        // Servo position
int motionSensor = LOW;         // Motion sensor
int val = 0;                    // For motion sensor status reading

// Initiates pin communication
void setup()                        
{
  friendlyWave.attach(10);        // Servo is attached to pin 10
  pinMode(12, INPUT);           // Motion sensor is attached to pin 12
  pinMode(13, OUTPUT);          // LED for motion sensitivity testing 
}

// Main
void loop()
{
  val = digitalRead(12);        // Read motion sensor status
  if (val == HIGH)
  {
    for(pos = 0; pos <= 45; pos += 1)
    {
      friendlyWave.write(pos);
      delay(25);
    }
    for(pos = 45; pos >= 0; pos -= 1)
    {
      friendlyWave.write(pos);
      delay(25);
    }
    digitalWrite(13, HIGH);
  }
  else
  {
    friendlyWave.write(0);
    digitalWrite(13, LOW);
  }
}
  
  
