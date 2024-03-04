// C++ code
//
int red_led = 2;
int green_led = 3;
int blue_led = 4;
int temp = 0;
void setup()
{
  pinMode(A1, INPUT);
  Serial.begin(9600);
  pinMode(red_led, OUTPUT);
  pinMode(green_led, OUTPUT);
  pinMode(blue_led, OUTPUT);
}

void loop()
{
  temp = map(((analogRead(A1) - 20) * 3.04), 0, 1023, -40, 125);
  Serial.print("Temperature in Celsius is ");
  Serial.println(temp);
    
  if (temp < 27){
    digitalWrite(red_led, HIGH);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, LOW);
  }
  else if (temp >= 27 && temp < 50){
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, HIGH);
    digitalWrite(blue_led, LOW);
  }
  else if(temp >= 50){
    digitalWrite(red_led, LOW);
    digitalWrite(green_led, LOW);
    digitalWrite(blue_led, HIGH);
  }
  delay(100);
}
