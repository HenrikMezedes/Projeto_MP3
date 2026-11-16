// Músicas armazenadas na memória FLASH (PROGMEM) para não gastar os 2 KB de RAM.
// Formato A (pares): um vetor só, com {nota, duração, nota, duração, ...}
// Formato B (dois vetores): um vetor com as notas e outro com as durações, na mesma ordem
//   duração: 1 = semibreve, 2 = mínima, 4 = semínima, 8 = colcheia, 16 = semicolcheia
//   duração negativa = nota pontuada (vale 1,5x)
#pragma once
#include <avr/pgmspace.h>

#define REST     0
#define NO_SOUND 0   // mesmo que REST (nome usado em outros códigos)

// Tabela de frequências (Hz) das notas, de C3 a C7
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093

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

// ---------- Músicas no formato B (dois vetores) ----------
// Para adicionar uma música que vem de outro código (ex.: melodia[] e tempoNotas[]):
//   1. Cole as notas num vetor e as durações em outro, assim:
//        const int16_t minhaMusicaNotas[]   PROGMEM = { ...notas... };
//        const int16_t minhaMusicaFiguras[] PROGMEM = { ...durações... };
//   2. Acrescente uma linha em musicas[] (mais abaixo):
//        {"Nome (max 16)", minhaMusicaNotas, minhaMusicaFiguras, QTD1(minhaMusicaNotas), BPM},
//   3. Se o outro código usa "compasso" (ms da semibreve), o BPM é 240000 / compasso.
//      Ex.: compasso = 1500  ->  BPM = 160.

struct Musica {
  const char *nome;        // até 16 caracteres (largura do LCD)
  const int16_t *notas;    // formato A: pares nota/duração | formato B: só as notas
  const int16_t *figuras;  // formato A: nullptr            | formato B: só as durações
  uint8_t qtdNotas;
  uint8_t tempo;           // BPM
};

#define QTD(v)  (sizeof(v) / sizeof(v[0]) / 2)   // formato A: cada nota ocupa 2 posições
#define QTD1(v) (sizeof(v) / sizeof(v[0]))       // formato B: cada nota ocupa 1 posição

const Musica musicas[] = {
  {"Ode a Alegria",  odeAlegria,   nullptr, QTD(odeAlegria),   120},
  {"Brilha Brilha",  brilhaBrilha, nullptr, QTD(brilhaBrilha), 100},
  {"Parabens",       parabens,     nullptr, QTD(parabens),     120},
  {"Jingle Bells",   jingleBells,  nullptr, QTD(jingleBells),  160},
  {"Fur Elise",      furElise,     nullptr, QTD(furElise),      80},
  {"Tetris",         tetris,       nullptr, QTD(tetris),       144},
  // {"Nome",        minhaMusicaNotas, minhaMusicaFiguras, QTD1(minhaMusicaNotas), 160},
};

const uint8_t TOTAL_MUSICAS = sizeof(musicas) / sizeof(musicas[0]);
