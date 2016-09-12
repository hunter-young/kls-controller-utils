/*
KLS series brushless motor controller serial communication emulator
Use an arduino with this code to emulate the aforementioned controller for testing purposes
Note: this is very, very primitive - it only supplies fixed data
don't expect it to work very well
*/

#define SERIAL_TIMEOUT 1000

byte packet_a[] = {0x3A, 0x10, 0x2D, 0x05, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x3B, 0x00, 0x0E, 0x00, 0x00, 0x00, 0x00, 0xC6};
byte packet_b[] = {0x3B, 0x10, 0x00, 0x00, 0x03, 0xC0, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x15};

byte command_a[] = {0x3A, 0x00, 0x3A};
byte command_b[] = {0x3B, 0x00, 0x3B};

byte incomingPacket[3];

unsigned long starttime;

void setup() {
  Serial.begin(19200);
  Serial1.begin(19200); // remove and change all instances of Serial1 to Serial if not using Arduino MEGA
}

void loop() {
  starttime = millis();

  while ( (Serial1.available() < 3) && ((millis() - starttime) < SERIAL_TIMEOUT) ) {}
  if (Serial1.available() < 3) {
    Serial.println("Error reading packet"); // remove if not using Arduino MEGA
    Serial1.flush();
  } else {
    for (int i = 0; i < 3; i++) {
      incomingPacket[i] = Serial1.read();
    }
  }

  Serial1.flush();

  if (incomingPacket[0] == command_a[0]) { //only compares first byte of each bytearray
    sendpacket_a();
  }
  else if (incomingPacket[0] == command_b[0]) {
    sendpacket_b();
  }
  else {
    Serial.println("Unknown packet type"); // remove if not using Arduino MEGA
  }

}

void sendpacket_a() {
  Serial.write(packet_a, sizeof(packet_a)); // remove if not using Arduino MEGA
  Serial1.write(packet_a, sizeof(packet_a));
}

void sendpacket_b() {
  Serial.write(packet_b, sizeof(packet_b)); // remove if not using Arduino MEGA
  Serial1.write(packet_b, sizeof(packet_b));
}
