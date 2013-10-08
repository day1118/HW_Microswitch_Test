/*
  Hockey Warrior - Encoder Test
  Tests the Encoder Sensors & prints the results. Can also run the motors.
 */
 
 #include "config.h"

int MICRO_FRONT_Left;
int MICRO_FRONT_Right;
int MICRO_BACK_Left;
int MICRO_BACK_Right;

int averageCount = 1;

void setup() {
  Serial.begin(115200);      // open the serial port at 9600 bps:

  DEBUG_PRINT("Starting...");
}

void loop() {
	// Read each sensor in a loop
  MICRO_FRONT_Left = readSensor(FRONT_LEFT_TOUCH_SENSOR, averageCount);
  MICRO_FRONT_Right = readSensor(FRONT_RIGHT_TOUCH_SENSOR, averageCount);

  MICRO_BACK_Left = readSensor(BACK_LEFT_TOUCH_SENSOR, averageCount);
  MICRO_BACK_Right = readSensor(BACK_RIGHT_TOUCH_SENSOR, averageCount);
  
  PLOT("MICRO_FRONT_Left", MICRO_FRONT_Left);
  PLOT("MICRO_FRONT_Right", MICRO_FRONT_Right);

  PLOT("MICRO_BACK_Left", MICRO_BACK_Left);
  PLOT("MICRO_BACK_Right", MICRO_BACK_Right);

  delay(10);
}


int readSensor(int pin, int averageCount)
{
  int value = 0;
  int i = 0;
  for(i = 0; i < averageCount; i++)
      value += digitalRead(pin);
  return value/averageCount;
}
