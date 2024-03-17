#include<TimeInterval.h>  //include the TimeInterval library
TimeInterval blink;       //created the object blink 
int baselineTemp = 0;  //initialization
int celsius = 0;
void setup()
{
  pinMode(A0, INPUT);  //sensor's input pin
  Serial.begin(9600);
  pinMode(2, OUTPUT);  // led output pin
  digitalWrite(2, LOW);  //initial state
}
void loop()
{
  baselineTemp =30;
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125); // conversion of fahrenheit to celsius
  Serial.print(celsius); //print output
  Serial.println("C ");
  //conditions as given
  if (celsius < baselineTemp) {
    if(blink.intervalMillis(250))  //function from TimeInterval library used for Time in milliseconds of the interval
    { 
       digitalWrite(2,HIGH);
       digitalWrite(2,LOW);
      }
  }
  else{
if(blink.intervalMillis(500))   //function from TimeInterval library used for Time in milliseconds of the interval
{ 
       digitalWrite(2,HIGH);
       digitalWrite(2,LOW);
      }
  }
}
