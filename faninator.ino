
int fan_relay_pin = 11;
int override_switch_pin = 10;
bool fan_state = false;
int currentstate = 69;
int ghosted_counter = 0;
bool switch_override = false;

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
  if(ghosted_counter < 50){
    ghosted_counter += 1;
  } 
}

if( (fan_state == true && ghosted_counter < 50 ) || switch_override){
  digitalWrite(fan_relay_pin, HIGH);
}
else{
  digitalWrite(fan_relay_pin, LOW);
}
delay(100);
}

