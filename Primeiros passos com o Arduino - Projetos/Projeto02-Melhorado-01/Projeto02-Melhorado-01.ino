// Exemplo 03A: Acende o LED enquanto o botão estiver pressionado,
// mantendo-o acesso mesmo depois que deixamos de pressionar o botão

const int LED = 13;     //  pino para o LED
const int BUTTON = 7;   // pino da entrada na qual o botão de pressão está conectado

int val = 0;            // val será utilizada para armazenar o estado do pino de entrada

int state = 0;          // 0 = LED apagado, 1 = LED aceso

void setup() {
  pinMode(LED, OUTPUT);   // avisa o Arduino que LED é uma saída
  pinMode(BUTTON, INPUT); // e que BUTTON é uma entrada
}


void loop() {
  val = digitalRead(BUTTON);    // lê e armazena o valor da entrada

  // verifica se a saída está HIGH (botão pressionado) e altera o estado
  if (val == HIGH){
    state = 1 - state;
  }

  if (state == 1){
    digitalWrite(LED, HIGH);   // acende o LED
  
  } else {
    digitalWrite(LED, LOW);

  }

}
