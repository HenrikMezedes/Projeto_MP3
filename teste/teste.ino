// Programa de TESTE do hardware do reprodutor.
// Procura o LCD I2C, acende cada LED, toca o buzzer e mostra os botões no Monitor Serial (9600).

#include <Wire.h>

const uint8_t LEDS[3]       = {6, 7, 9};
const char *NOMES_LEDS[3]   = {"LED VERDE (pino 6)", "LED VERMELHO (pino 7)", "LED AZUL (pino 9)"};
const uint8_t BUZZER        = 8;
const uint8_t BOTOES[4]     = {A0, A1, A2, A3};
const char *NOMES_BOTOES[4] = {"UP (A0)", "DOWN (A1)", "PLAY (A2)", "STOP (A3)"};
bool ultimo[4] = {HIGH, HIGH, HIGH, HIGH};

void setup() {
  Serial.begin(9600);
  for (uint8_t i = 0; i < 3; i++) pinMode(LEDS[i], OUTPUT);
  for (uint8_t i = 0; i < 4; i++) pinMode(BOTOES[i], INPUT_PULLUP);

  Serial.println(F("===== TESTE DE HARDWARE ====="));

  // Procura dispositivos I2C (o LCD costuma responder em 0x27 ou 0x3F)
  Wire.begin();
  bool achou = false;
  for (uint8_t end = 1; end < 127; end++) {
    Wire.beginTransmission(end);
    if (Wire.endTransmission() == 0) {
      Serial.print(F("LCD I2C encontrado no endereco 0x"));
      Serial.println(end, HEX);
      achou = true;
    }
  }
  if (!achou) Serial.println(F("Nenhum LCD I2C encontrado (confira SDA no A4 e SCL no A5)"));

  for (uint8_t i = 0; i < 3; i++) {
    Serial.print(F("Acendendo ")); Serial.println(NOMES_LEDS[i]);
    digitalWrite(LEDS[i], HIGH);
    delay(1500);
    digitalWrite(LEDS[i], LOW);
  }
  Serial.println(F("Tocando BUZZER (pino 8)..."));
  tone(BUZZER, 440, 1000);
  delay(1500);

  Serial.println(F("Agora aperte os botoes, um de cada vez:"));
  for (uint8_t i = 0; i < 4; i++) {
    if (digitalRead(BOTOES[i]) == LOW) {
      Serial.print(F("ATENCAO: ")); Serial.print(NOMES_BOTOES[i]);
      Serial.println(F(" ja comeca APERTADO (gire o botao 90 graus)"));
    }
  }
}

void loop() {
  for (uint8_t i = 0; i < 4; i++) {
    bool agora = digitalRead(BOTOES[i]);
    if (agora != ultimo[i]) {
      Serial.print(NOMES_BOTOES[i]);
      Serial.println(agora == LOW ? F(" apertado") : F(" solto"));
      ultimo[i] = agora;
      delay(30);
    }
  }
}
