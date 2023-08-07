
int fan_relay_pin = 11;
int override_switch_pin = 10;


bool fan_state = false;
int currentstate = 69;
int switch_override = 0;

int ghosted_counter = 0;

void setup()

{
pinMode(fan_relay_pin, OUTPUT);
pinMode(override_switch_pin, OUTPUT);
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
button_state =

if( (fan_state == true && ghosted_counter < 50 ) || switch_override == 1){
  digitalWrite(fan_relay_pin, HIGH);
}
else{
  digitalWrite(fan_relay_pin, LOW);
}
delay(100);
}

