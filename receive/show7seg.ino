// Pinos do display 7 segmentos 
int segA = 49;
int segB = 48;
int segC = 50;
int segD = 2;
int segE = 3;
int segF = 5;
int segG = 4;

int segs[] = {49, 48, 50, 2, 3, 4, 5}; // Para otimizar setup, on, off

// Mostra números de 0-9 no display
void show7Seg(int n) {
    int A=LOW, B=LOW, C=LOW, D=LOW, E=LOW, F=LOW, G=LOW;
  
    // Configura cada numero de acordo com o parametro
    switch(n) {
        case 0: A=HIGH; B=HIGH; C=HIGH; D=HIGH; E=HIGH; F=HIGH; break;
        case 1: B=HIGH; C=HIGH; break;
        case 2: A=HIGH; B=HIGH; D=HIGH; E=HIGH; G=HIGH; break;
        case 3: A=HIGH; B=HIGH; C=HIGH; D=HIGH; G=HIGH; break;
        case 4: B=HIGH; C=HIGH; F=HIGH; G=HIGH; break;
        case 5: A=HIGH; C=HIGH; D=HIGH; F=HIGH; G=HIGH; break;
        case 6: A=HIGH; C=HIGH; D=HIGH; E=HIGH; F=HIGH; G=HIGH; break;
        case 7: A=HIGH; B=HIGH; C=HIGH; break;
        case 8: A=HIGH; B=HIGH; C=HIGH; D=HIGH; E=HIGH; F=HIGH; G=HIGH; break;
        case 9: A=HIGH; B=HIGH; C=HIGH; D=HIGH; F=HIGH; G=HIGH; break;
        default: break;
    }

    digitalWrite(segA, A);
    digitalWrite(segB, B);
    digitalWrite(segC, C);
    digitalWrite(segD, D);
    digitalWrite(segE, E);
    digitalWrite(segF, F);
    digitalWrite(segG, G);
}

// Exibe a letra 'E' sinalizando erro 
void showDisplayError()
{
  digitalWrite(segA, HIGH);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

// Liga todos os segmentos
void onDisplay(){
  for(auto seg: segs)
    digitalWrite(seg, HIGH);
}

// Desliga todos os segmentos
void offDisplay(){
  for(auto seg: segs)
    digitalWrite(seg, LOW);
}

// Configura todos os pinos como saida
void setupOUT(){
  for(auto seg: segs)
    pinMode(seg, OUTPUT);
}

void setup() {
  	// Habilita os pinos do display como output  
    setupOUT();
    offDisplay();
    Serial.begin(9600);
}
void loop() {
  if(Serial.available())
  {
    String data = Serial.readString();
    int letter = (int) data.charAt(0);

    Serial.print("Valor recebido: ");
    Serial.println(letter);

    if(letter >= 48 && letter <= 57)
      show7Seg(letter - 48);
    else{
      showDisplayError();
    }
  }
}