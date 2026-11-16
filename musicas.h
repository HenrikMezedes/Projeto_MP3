// Músicas armazenadas na memória FLASH (PROGMEM) para não gastar os 2 KB de RAM.
// Formato de cada música: pares {nota, duração}
//   duração: 1 = semibreve, 2 = mínima, 4 = semínima, 8 = colcheia, 16 = semicolcheia
//   duração negativa = nota pontuada (vale 1,5x)
#pragma once
#include <avr/pgmspace.h>

#define REST 0
#define NOTE_C4  262
#define NOTE_D4  294
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_G5  784
#define NOTE_A5  880

const int16_t odeAlegria[] PROGMEM = {
  NOTE_E4,4, NOTE_E4,4, NOTE_F4,4, NOTE_G4,4,  NOTE_G4,4, NOTE_F4,4, NOTE_E4,4, NOTE_D4,4,
  NOTE_C4,4, NOTE_C4,4, NOTE_D4,4, NOTE_E4,4,  NOTE_E4,-4, NOTE_D4,8, NOTE_D4,2,
  NOTE_E4,4, NOTE_E4,4, NOTE_F4,4, NOTE_G4,4,  NOTE_G4,4, NOTE_F4,4, NOTE_E4,4, NOTE_D4,4,
  NOTE_C4,4, NOTE_C4,4, NOTE_D4,4, NOTE_E4,4,  NOTE_D4,-4, NOTE_C4,8, NOTE_C4,2
};

const int16_t brilhaBrilha[] PROGMEM = {
  NOTE_C4,4, NOTE_C4,4, NOTE_G4,4, NOTE_G4,4, NOTE_A4,4, NOTE_A4,4, NOTE_G4,2,
  NOTE_F4,4, NOTE_F4,4, NOTE_E4,4, NOTE_E4,4, NOTE_D4,4, NOTE_D4,4, NOTE_C4,2,
  NOTE_G4,4, NOTE_G4,4, NOTE_F4,4, NOTE_F4,4, NOTE_E4,4, NOTE_E4,4, NOTE_D4,2,
  NOTE_G4,4, NOTE_G4,4, NOTE_F4,4, NOTE_F4,4, NOTE_E4,4, NOTE_E4,4, NOTE_D4,2,
  NOTE_C4,4, NOTE_C4,4, NOTE_G4,4, NOTE_G4,4, NOTE_A4,4, NOTE_A4,4, NOTE_G4,2,
  NOTE_F4,4, NOTE_F4,4, NOTE_E4,4, NOTE_E4,4, NOTE_D4,4, NOTE_D4,4, NOTE_C4,2
};

const int16_t parabens[] PROGMEM = {
  NOTE_G4,-8, NOTE_G4,16, NOTE_A4,4, NOTE_G4,4, NOTE_C5,4, NOTE_B4,2,
  NOTE_G4,-8, NOTE_G4,16, NOTE_A4,4, NOTE_G4,4, NOTE_D5,4, NOTE_C5,2,
  NOTE_G4,-8, NOTE_G4,16, NOTE_G5,4, NOTE_E5,4, NOTE_C5,4, NOTE_B4,4, NOTE_A4,4,
  NOTE_F5,-8, NOTE_F5,16, NOTE_E5,4, NOTE_C5,4, NOTE_D5,4, NOTE_C5,2
};

const int16_t jingleBells[] PROGMEM = {
  NOTE_E4,4, NOTE_E4,4, NOTE_E4,2,  NOTE_E4,4, NOTE_E4,4, NOTE_E4,2,
  NOTE_E4,4, NOTE_G4,4, NOTE_C4,-4, NOTE_D4,8, NOTE_E4,1,
  NOTE_F4,4, NOTE_F4,4, NOTE_F4,-4, NOTE_F4,8, NOTE_F4,4, NOTE_E4,4, NOTE_E4,4, NOTE_E4,8, NOTE_E4,8,
  NOTE_E4,4, NOTE_D4,4, NOTE_D4,4, NOTE_E4,4, NOTE_D4,2, NOTE_G4,2,
  NOTE_E4,4, NOTE_E4,4, NOTE_E4,2,  NOTE_E4,4, NOTE_E4,4, NOTE_E4,2,
  NOTE_E4,4, NOTE_G4,4, NOTE_C4,-4, NOTE_D4,8, NOTE_E4,1,
  NOTE_F4,4, NOTE_F4,4, NOTE_F4,-4, NOTE_F4,8, NOTE_F4,4, NOTE_E4,4, NOTE_E4,4, NOTE_E4,8, NOTE_E4,8,
  NOTE_G4,4, NOTE_G4,4, NOTE_F4,4, NOTE_D4,4, NOTE_C4,1
};

const int16_t furElise[] PROGMEM = {
  NOTE_E5,16, NOTE_DS5,16, NOTE_E5,16, NOTE_DS5,16, NOTE_E5,16, NOTE_B4,16, NOTE_D5,16, NOTE_C5,16,
  NOTE_A4,-8, NOTE_C4,16, NOTE_E4,16, NOTE_A4,16, NOTE_B4,-8, NOTE_E4,16, NOTE_GS4,16, NOTE_B4,16,
  NOTE_C5,-8, NOTE_E4,16,
  NOTE_E5,16, NOTE_DS5,16, NOTE_E5,16, NOTE_DS5,16, NOTE_E5,16, NOTE_B4,16, NOTE_D5,16, NOTE_C5,16,
  NOTE_A4,-8, NOTE_C4,16, NOTE_E4,16, NOTE_A4,16, NOTE_B4,-8, NOTE_E4,16, NOTE_C5,16, NOTE_B4,16,
  NOTE_A4,4
};

const int16_t tetris[] PROGMEM = {
  NOTE_E5,4, NOTE_B4,8, NOTE_C5,8, NOTE_D5,4, NOTE_C5,8, NOTE_B4,8,
  NOTE_A4,4, NOTE_A4,8, NOTE_C5,8, NOTE_E5,4, NOTE_D5,8, NOTE_C5,8,
  NOTE_B4,-4, NOTE_C5,8, NOTE_D5,4, NOTE_E5,4,
  NOTE_C5,4, NOTE_A4,4, NOTE_A4,4, REST,4,
  NOTE_D5,-4, NOTE_F5,8, NOTE_A5,4, NOTE_G5,8, NOTE_F5,8,
  NOTE_E5,-4, NOTE_C5,8, NOTE_E5,4, NOTE_D5,8, NOTE_C5,8,
  NOTE_B4,4, NOTE_B4,8, NOTE_C5,8, NOTE_D5,4, NOTE_E5,4,
  NOTE_C5,4, NOTE_A4,4, NOTE_A4,4, REST,4
};

struct Musica {
  const char *nome;        // até 16 caracteres (largura do LCD)
  const int16_t *notas;    // ponteiro para a FLASH
  uint8_t qtdNotas;
  uint8_t tempo;           // BPM
};

#define QTD(v) (sizeof(v) / sizeof(v[0]) / 2)

const Musica musicas[] = {
  {"Ode a Alegria",  odeAlegria,   QTD(odeAlegria),   120},
  {"Brilha Brilha",  brilhaBrilha, QTD(brilhaBrilha), 100},
  {"Parabens",       parabens,     QTD(parabens),     120},
  {"Jingle Bells",   jingleBells,  QTD(jingleBells),  160},
  {"Fur Elise",      furElise,     QTD(furElise),      80},
  {"Tetris",         tetris,       QTD(tetris),       144},
};

const uint8_t TOTAL_MUSICAS = sizeof(musicas) / sizeof(musicas[0]);
