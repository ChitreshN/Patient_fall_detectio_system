#include <VirtualWire.h>
#define rxpin 11
void setup() {
  pinMode(13,OUTPUT);
  Serial.begin(9600);
  vw_set_rx_inverted(true); // Required for DR3100
  vw_setup(2000);      // Bits per sec
  vw_rx_start(); 
}
  

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
    if (vw_get_message(buf, &buflen)){
        digitalWrite(13, HIGH);
        
        Serial.println("patient detected");
    }
    else{
      
      Serial.println("patient not detected");
    }
    delay(3000);
}
