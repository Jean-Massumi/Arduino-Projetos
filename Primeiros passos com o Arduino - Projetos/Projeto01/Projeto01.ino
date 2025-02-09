// Exemplo 01: LED pisca-pisca

const int LED = 13;  // LED conectado ao pino digital 13

void setup() {
  pinMode(LED, OUTPUT);     // define o pino digital como saída
}

void loop() {
  digitalWrite(LED, HIGH);    // acende o LED
  delay(1000);                // aguarda um segundo
  digitalWrite(LED, LOW);     // apaga o LED
  delay(1000);                // aguarda um segundo
}
