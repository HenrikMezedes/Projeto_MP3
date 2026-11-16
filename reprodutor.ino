// CCP020 - Reprodutor de músicas no Arduino UNO
// Menu no LCD 16x2, 4 botões (UP, DOWN, PLAY/PAUSE, STOP),
// LED verde = tocando, LED vermelho = pausado, LED azul pisca no ritmo, música no buzzer.

#include <LiquidCrystal.h>
#include "musicas.h"

// ---------- Pinos ----------
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);   // RS, E, D4, D5, D6, D7
const uint8_t PINO_BUZZER   = 8;
const uint8_t LED_VERDE     = 6;
const uint8_t LED_VERMELHO  = 7;
const uint8_t LED_RITMO     = 9;
const uint8_t BTN_UP        = A0;
const uint8_t BTN_DOWN      = A1;
const uint8_t BTN_PLAY      = A2;
const uint8_t BTN_STOP      = A3;

// ---------- Estado ----------
enum Estado { MENU, TOCANDO, PAUSADO };
Estado estado = MENU;

uint8_t selecionada = 0;       // índice da música no menu
uint8_t notaAtual = 0;         // índice da nota em reprodução
unsigned long inicioNota = 0;  // millis() em que a nota começou
unsigned int duracaoNota = 0;  // duração total da nota (ms)
int16_t freqAtual = 0;         // frequência da nota atual (0 = pausa)
unsigned long tempoPausado = 0;// quanto da nota já tinha tocado ao pausar

// ---------- Botões (detecção de borda com debounce) ----------
const uint8_t botoes[4] = {BTN_UP, BTN_DOWN, BTN_PLAY, BTN_STOP};
bool ultimoEstado[4] = {HIGH, HIGH, HIGH, HIGH};
unsigned long ultimaMudanca[4] = {0, 0, 0, 0};

// Retorna true uma única vez quando o botão é pressionado
bool apertou(uint8_t i) {
  bool leitura = digitalRead(botoes[i]);
  if (leitura != ultimoEstado[i] && millis() - ultimaMudanca[i] > 30) {
    ultimaMudanca[i] = millis();
    ultimoEstado[i] = leitura;
    return leitura == LOW;   // INPUT_PULLUP: pressionado = LOW
  }
  return false;
}

// ---------- LEDs ----------
void atualizaLeds() {
  digitalWrite(LED_VERDE,    estado == TOCANDO);
  digitalWrite(LED_VERMELHO, estado == PAUSADO);
  if (estado != TOCANDO) digitalWrite(LED_RITMO, LOW);
}

// ---------- Tela (LCD + Monitor Serial) ----------
// Escreve as 2 linhas no LCD e desenha a mesma "tela" no Monitor Serial do PC.
// Assim o projeto funciona mesmo antes de encaixar o LCD.
void tela(const char *linha1, const char *linha2) {
  lcd.clear();
  lcd.print(linha1);
  lcd.setCursor(0, 1);
  lcd.print(linha2);

  char l1[17], l2[17];
  snprintf(l1, sizeof(l1), "%-16s", linha1);
  snprintf(l2, sizeof(l2), "%-16s", linha2);
  Serial.println(F("+----------------+"));
  Serial.print('|'); Serial.print(l1); Serial.println('|');
  Serial.print('|'); Serial.print(l2); Serial.println('|');
  Serial.println(F("+----------------+"));
}

void mostraMenu() {
  char l1[17], l2[17];
  uint8_t proxima = (selecionada + 1) % TOTAL_MUSICAS;
  snprintf(l1, sizeof(l1), ">%s", musicas[selecionada].nome);
  snprintf(l2, sizeof(l2), " %s", musicas[proxima].nome);
  tela(l1, l2);
}

void mostraReproducao() {
  tela(musicas[selecionada].nome, estado == TOCANDO ? "> Tocando" : "|| Pausado");
}

void mostraProgresso() {
  // Só no LCD (no Monitor Serial encheria a tela a cada nota)
  // Mostra "nota/total" no canto direito da 2ª linha
  char txt[8];
  snprintf(txt, sizeof(txt), "%2d/%-2d", notaAtual + 1, musicas[selecionada].qtdNotas);
  lcd.setCursor(11, 1);
  lcd.print(txt);
}

// ---------- Reprodução ----------
// Lê a nota i da FLASH, calcula a duração e começa a tocar
void tocaNota(uint8_t i) {
  const Musica &m = musicas[selecionada];
  int16_t freq    = pgm_read_word(&m.notas[i * 2]);
  freqAtual = freq;
  int16_t divisor = pgm_read_word(&m.notas[i * 2 + 1]);

  unsigned long semibreve = (60000UL * 4) / m.tempo;
  if (divisor > 0) {
    duracaoNota = semibreve / divisor;
  } else {
    duracaoNota = (semibreve / -divisor) * 3 / 2;  // nota pontuada
  }

  if (freq != REST) {
    tone(PINO_BUZZER, freq, duracaoNota * 9 / 10);  // 10% de silêncio separa as notas
  }
  inicioNota = millis();
  mostraProgresso();
}

void iniciaMusica() {
  estado = TOCANDO;
  notaAtual = 0;
  atualizaLeds();
  mostraReproducao();
  tocaNota(0);
}

void pausa() {
  estado = PAUSADO;
  tempoPausado = millis() - inicioNota;
  noTone(PINO_BUZZER);
  atualizaLeds();
  mostraReproducao();
  mostraProgresso();
}

void continua() {
  estado = TOCANDO;
  atualizaLeds();
  mostraReproducao();
  mostraProgresso();

  // Toca o restante da nota interrompida
  inicioNota = millis() - tempoPausado;
  int16_t freq = pgm_read_word(&musicas[selecionada].notas[notaAtual * 2]);
  unsigned int somRestante = duracaoNota * 9 / 10;
  if (freq != REST && tempoPausado < somRestante) {
    tone(PINO_BUZZER, freq, somRestante - tempoPausado);
  }
}

void paraMusica() {
  noTone(PINO_BUZZER);
  estado = MENU;
  atualizaLeds();
  mostraMenu();
}

// Avança para a próxima nota quando a atual termina (sem delay)
void atualizaReproducao() {
  unsigned long passou = millis() - inicioNota;

  // LED do ritmo: aceso enquanto a nota soa, apagado no silêncio entre notas
  digitalWrite(LED_RITMO, freqAtual != REST && passou < duracaoNota * 9UL / 10);

  if (passou < duracaoNota) return;

  notaAtual++;
  if (notaAtual >= musicas[selecionada].qtdNotas) {
    paraMusica();  // fim da música -> volta ao menu
  } else {
    tocaNota(notaAtual);
  }
}

// ---------- Arduino ----------
void setup() {
  for (uint8_t i = 0; i < 4; i++) pinMode(botoes[i], INPUT_PULLUP);
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_RITMO, OUTPUT);
  pinMode(PINO_BUZZER, OUTPUT);

  Serial.begin(9600);
  lcd.begin(16, 2);
  tela("Reprodutor", "CCP020");
  delay(1500);
  mostraMenu();
}

void loop() {
  bool up   = apertou(0);
  bool down = apertou(1);
  bool play = apertou(2);
  bool stop = apertou(3);

  switch (estado) {
    case MENU:
      if (up) {
        selecionada = (selecionada == 0) ? TOTAL_MUSICAS - 1 : selecionada - 1;
        mostraMenu();
      }
      if (down) {
        selecionada = (selecionada + 1) % TOTAL_MUSICAS;
        mostraMenu();
      }
      if (play) iniciaMusica();
      break;

    case TOCANDO:
      if (play) pausa();
      else if (stop) paraMusica();
      else atualizaReproducao();
      break;

    case PAUSADO:
      if (play) continua();
      else if (stop) paraMusica();
      break;
  }
}
