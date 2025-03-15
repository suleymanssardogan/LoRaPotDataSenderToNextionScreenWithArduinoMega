#include <Nextion.h>

#define FixSerial Serial1  // Arduino Mega için Serial1 (18-TX, 19-RX)

NexGauge gauge = NexGauge(0, 4, "z0");

void sendNextionCommand(String command) {
    FixSerial.print(command);
    FixSerial.write(0xFF);
    FixSerial.write(0xFF);
    FixSerial.write(0xFF);
}

void setup() {
    Serial.begin(9600);
    FixSerial.begin(9600);
    
    nexInit();
    delay(500);  // Nextion başlatmak için bekleme

    sendNextionCommand("baud=9600");  // Nextion’ın baud rate'ini 9600 yap
    delay(100);
    
    Serial.println("Setup Completed");
}

void loop() {
    if (FixSerial.available()) {
        byte value = FixSerial.read();
        int gauge_value = constrain(value, 0, 255);
        
        sendNextionCommand("z0.val=" + String(gauge_value));
        
        Serial.print("Gelen Değer: ");
        Serial.println(gauge_value);
    }
}
