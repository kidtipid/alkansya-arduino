// Connections:
const int IR = 6; // IR Output to MCU pin 12
const int IR2 = 7; // IR Output to MCU pin 12
const int LED = 13; // Default MCU LED
// Connect Long Range IR GND pin to MCU GND
// Supply at least 5V on the (+) and (‐) pin
//of the long range sensor
// Initialize:
void setup()
{
Serial.begin(9600); // Begin serial communication
pinMode(LED,OUTPUT);
pinMode(IR,INPUT);
pinMode(IR2,INPUT);
}
void loop()
{
int IR_READ = digitalRead(IR); // Set a variable for IR output
int IR_READ2 = digitalRead(IR2);

// If an object is detected,
if(IR_READ == 1 || IR_READ2 == 1)
{
  if(IR_READ == 0 && IR_READ2 == 1){    
    Serial.println("COIN 1");
    digitalWrite(LED,HIGH);
    delayMicroseconds(100);
    digitalWrite(LED,LOW);
    delayMicroseconds(100);
    delay(3000);
  }

  if(IR_READ == 1 && IR_READ2 == 0){    
    Serial.println("COIN 2");
    digitalWrite(LED,HIGH);
    delayMicroseconds(100);
    digitalWrite(LED,LOW);
    delayMicroseconds(100);
    delay(3000);
  }
}




else
{
  digitalWrite(LED,LOW);
}


delay(50);
}
