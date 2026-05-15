#include <Servo.h>
#include <SPI.h>
#include <MFRC522.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
Servo puerta;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();
  puerta.attach(3);
  puerta.write(0);
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent() || !rfid.PICC_ReadCardSerial()) return;

  String uid = "";
  for (byte i = 0; i < rfid.uid.size; i++) {
    uid += String(rfid.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  Serial.println(uid);
  delay(1000);

  while (Serial.available()) {
    char comando = Serial.read();
    if (comando == 'A') {
      puerta.write(90);
      delay(3000);
      puerta.write(0);
    }
  }

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();
}
