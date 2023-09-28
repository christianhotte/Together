
//SETTINGS:
const int baudRate = 9600;           //Serial port speed
const unsigned int updateSpeed = 20; //Rate at which program will check status of sensors (in updates per second)
const float sensorThresh = 500;      //Range: 0 - 1024. Value below which sensors will register as detecting an obstacle

//SENSORS--------------| A | B | C |
const int IRPins[3] =  { A0, A1, A2}; //Analog input pins for IR sensors (analog values vary but are essentially digital HIGH/LOW)
const int LEDPins[3] = { 2,  3,  4 }; //Digital output pins for activation indicator lights
bool IRValues[3];                     //Stored values for sensor outputs (can only be high or low)

//RUNTIME VARIABLES:
unsigned long interval;           //Number of milliseconds in each update interval (will be calculated in setup)
unsigned long lastUpdateTime = 0; //Millis timestamp at which program was last updated

//RUNTIME METHODS:
void setup() {
  //INITIAL CALCULATIONS:
  interval = 1000 / updateSpeed; //Calucluate update interval
  
  //PIN SETUP:
  for (int i = 0; i < 3; i++) {
    pinMode(LEDPins[i], OUTPUT);   //Set each LED pin as an output
    digitalWrite(LEDPins[i], LOW); //Set each LED's initial state to off
  }

  //FINAL INITIALIZATION:
  Serial.begin(baudRate); //Initialize serial communications
}

void loop() {
  unsigned long currentTime = millis(); //Get current time (in milliseconds) program has been running for
  
  if (currentTime >= lastUpdateTime + interval) { //Enough time has passed for program to process the next update
    lastUpdateTime = currentTime; //Update stored time value

    //Record sensor data:
    bool prevIRValues[3] = {IRValues[0], IRValues[1], IRValues[2]}; //Store IR values before check
    for (int i = 0; i < 3; i++) {
      IRValues[i] = (analogRead(IRPins[i]) < sensorThresh) ? true : false; //Determine boolean value for each sensor
      if (IRValues[i] != prevIRValues[i]){ //Value has changed

        // Print message
        Serial.print(i);
        Serial.print(" ");
        Serial.print(IRValues[i]);
        Serial.println();                                                                   //Print message on serial monitor
        digitalWrite(LEDPins[i], IRValues[i] ? HIGH : LOW);                                                         //Change LED status


//         //Compose serial message:
//         byte message = i;                       //Initialize message with first two bits indicating sensor number
//         if (IRValues[i]) message = message | 4; //Use third bit to indicate sensor activation
//         Serial.write(message);                  //Send message with serial bus
        
//         digitalWrite(LEDPins[i], IRValues[i] ? HIGH : LOW); //Change LED status
      }
    }
  }
}
