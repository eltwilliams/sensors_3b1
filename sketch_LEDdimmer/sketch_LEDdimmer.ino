// sketch_LEDdimmer-begin
// upload
// arduino:avr:uno
// /dev/ttyS0
// sketch_LEDdimmer-end

/*
   RGB Light Dimmer
*/
int redPin = 9;                // R – digital 9    
int greenPin = 10;             // G – digital 10
int bluePin = 11;              // B – digital 11
int potRedPin = 0;             // potentiometer 1 – analog 0
int potGreenPin = 1;           // potentiometer 2 – analog 1
int potBluePin = 2;            // potentiometer 3 – analog 2

void setup(){
   pinMode(redPin,OUTPUT);
   pinMode(greenPin,OUTPUT);
   pinMode(bluePin,OUTPUT);
   Serial.begin(9600);   
   Serial.println("<Arduino is ready>");       
}

void loop(){
   int potRed = analogRead(potRedPin);     
   int potGreen = analogRead(potGreenPin); 
   int potBlue = analogRead(potBluePin);  
 
   int val1 = map(potRed,0,1023,0,255);     
   int val2 = map(potGreen,0,1023,0,255);
   int val3 = map(potBlue,0,1023,0,255);

   Serial.print(val1);
   Serial.print(" ");
   Serial.print(val2);
   Serial.print(" ");
   Serial.print(val3);
   Serial.print("\n");
  
   colorRGB(val1,val2,val3);      
}

void colorRGB(int red, int green, int blue){     
   analogWrite(redPin,constrain(red,0,255));
   analogWrite(greenPin,constrain(green,0,255));
   analogWrite(bluePin,constrain(blue,0,255));
}
