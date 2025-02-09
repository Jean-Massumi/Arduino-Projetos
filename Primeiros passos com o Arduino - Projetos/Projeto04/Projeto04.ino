// Exemplo 05: Acende o LED enquanto o botão estiver pressionado,
// mantendo-o acesso mesmo depois que deixamos de pressionar o botão
// Inclui recurso simples de de-bouncing.
// Agora com uma nova implementação!

const int LED = 9;     //  pino para o LED
const int BUTTON = 7;   // pino da entrada na qual o botão de pressão está conectado

int val = 0;            // val será utilizada para armazenar o estado do pino de entrada

int old_val = 0;        // esta variável armazena o valor anterior de "val"

int state = 0;          // 0 = LED apagado, 1 = LED aceso

int brightness = 128;   // Armazena o valor do brilho
unsigned long  startTime = 0;   // quando começamos a pressionar o botão?

void setup() {
  pinMode(LED, OUTPUT);   // avisa o Arduino que LED é uma saída
  pinMode(BUTTON, INPUT); // e que BUTTON é uma entrada
}


void loop() {
  val = digitalRead(BUTTON);    // lê e armazena o valor da entrada

  // verifica se houve uma transição
  if ((val == HIGH) && (old_val == LOW)){
    
    state = 1 - state;    // altera o estado, de apagado para aceso ou vice-versa

    startTime = millis();   // millis() é o relógio do Arduino ela retorna quantos 
                            // milissegundos passaram desde que a placa foi reinicializada.
  
    // (esta linha recorda quand o botão foi pressionado pela última vez)
    delay(10);
  }

  // Verifica se estamos segurando o botão pressionado
  if ((val == HIGH) && (old_val == HIGH)){

    // Se o botão for segurado por mais de 500ms
    if (state == 1 && (millis() - startTime) > 500){
      
      brightness++;   // aumenta o brilho em 1
      delay(10);      // Intervalo para evitar que o brilho aumente rápido demais

      if (brightness > 255){    // 255 é o briho máximo

        brightness = 0;   // Se passarmos de 255 devemos retornar a 0.
      }

    }

  } 

  old_val = val;    // val agora está velha, vamos armazená-la

  if (state == 1){
    analogWrite(LED, brightness);   // acende o LED utilizando o nível atual do brilho
  
  } else {
    analogWrite(LED, 0);    // Apaga o LED
    
  }

}
