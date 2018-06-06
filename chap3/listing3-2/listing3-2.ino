int count; 
const int LED = 13; //assigning the variable “LED” to pin 13 

void setup() { 
pinMode (LED, OUTPUT); 
} 

void loop() { 
while (count < 7){ 
digitalWrite (LED, HIGH); 
delay(500); 
digitalWrite (LED, LOW); 
delay(500); 
count = count + 1; 
} 
}
