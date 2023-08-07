
int fan_relay_pin = 11;
bool fan_state = false;
int currentstate = 69;
int ghosted_counter = 0;
void setup()

{
pinMode(fan_relay_pin, OUTPUT);
Serial.begin(9600);
}

void loop() {
  
if (Serial.available())
{
  ghosted_counter = 0;
  currentstate = Serial.parseInt();
  if(currentstate==420){
    fan_state = true;
  }
  else if (currentstate == 69){
    fan_state = false;
  }
}
else{
  if(ghosted_counter < 10){
    ghosted_counter += 1;
  } 
}

if(fan_state == true && ghosted_counter < 10){
  digitalWrite(fan_relay_pin, HIGH);

}
else{
  digitalWrite(fan_relay_pin, LOW);
}
delay(500);


}

