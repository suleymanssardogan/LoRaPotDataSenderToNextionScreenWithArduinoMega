#include <SoftwareSerial.h>
//RX,TX
SoftwareSerial FixSerial(52,53);

#define pot A2

void setup() {
  // put y>our setup code here, to run once:

  Serial.begin(9600);
  FixSerial.begin(9600);


}

byte pot_deger=0;
void loop() {
 

byte pot_deger = map(analogRead(A2),0,1024,0,255);

  

  FixSerial.write((byte)0x00);
  FixSerial.write(0x3f);
  FixSerial.write(0x17);
  FixSerial.write(pot_deger); 
  Serial.println(pot_deger);
  delay(20);

  /*for(int i=0;i<2;i++){
    FixSerial.write(a[i]);
  }*/
 
  
  

}
