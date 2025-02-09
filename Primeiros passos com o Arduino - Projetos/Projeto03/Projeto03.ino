// Exemplo 04: Acenda e apague um LED gradualmente, produzindo um efeito
// como aquele que vemos em um computador Apple em suspensão

const int LED = 9;    // pino para o LED
int i = 0;            // Utilizaremos essa variável para contagem

void setup() {
  pinMode(LED, OUTPUT);   // diz ao Arduino que LED é uma saída

}

void loop() {

  for (i = 0; i < 255; i++){    // faz um loop loop de 0 a 254 (acende gradualmente)
    analogWrite(LED, i);        // define o brilho do LED
    delay(10);                  // Espera 10ms, pois analogWrite é instantâneo e
                                // e não veríamos nenhuma alteração
  }

  for (i = 255; i > 0; i--){    // faz um loop de 255 a 1 (apaga gradualmente)
    analogWrite(LED, i);        // define o brilho do LED
    delay(10);                  // Aguarda 10ms
  }
}
