//declaração de pinos e variaveis
int redled = 2;
int greenled = 3;
int blueled = 4;

int value = A0;

int red;
int blue;
int green;


void setup() {
    //define quais são as saídas
    pinMode(redled, OUTPUT);
    pinMode(greenled, OUTPUT);
    pinMode(blueled, OUTPUT);

    //define a entrada de valores da porta analógica
    pinMode(value, INPUT);

    //inicia o monitor serial
    Serial.begin(9600);

}

void loop() {
    //liga o led vermelho
    digitalWrite(redled, HIGH);
    delay(40);
    /*o valor lido na porta analógica
    no momento que o led está ligado
    é guardado na variável red*/
    red = analogRead(value);
    delay(100);
    //mostra no monitor serial o valor lido
    Serial.print("R=");
    Serial.println(red);
    //desliga o led vermelho
    digitalWrite(redled, LOW);

    //liga o led verde
    digitalWrite(greenled, HIGH);
    delay(40);
    /*o valor lido na porta analógica
    no momento que o led está ligado
    é guardado na variável green*/
    green = analogRead(value);
    delay(100);
    //mostra no monitor serial o valor lido
    Serial.print("G=");
    Serial.println(green);
    //desliga o led verde
    digitalWrite(greenled, LOW);

    //liga o led azul
    digitalWrite(blueled, HIGH);
    delay(40);
    /*o valor lido na porta analógica
    no momento que o led está ligado
    é guardado na variável blue*/
    blue = analogRead(value);
    delay(100);
    //mostra no monitor serial o valor lido
    Serial.print("B=");
    Serial.println(blue);
    //desliga o led azul
    digitalWrite(blueled, LOW);

    /*Caso os valores de red, blue e green forem parecidos e altos
    demonstra que nenhum valor está sendo mostrado*/
    if (red > 100 && blue > 150 && green > 150)
        Serial.println("Unknown");
    else {
      
        /* Caso os valores de red for maior que blue e green
         * significa que a cor é vermelho*/
        if (red > blue && red > green) {
            Serial.println("*** Red ***");
      }

        if (green > blue && green > red) {
            /* Caso os valores de green for maior que blue e red.
            * E que green e red são maiores que blue
            * significa que a cor é amarelo*/
            if (green > blue && red > blue) {
                Serial.println("*** Yellow ***");
            } 
            else
                /*Caso os valores de green for maior que blue e red
                significa que a cor é verde*/
                Serial.println("*** Green ***");
        }

        if (blue > red && blue > green) {
            /* Caso os valores de blue for maior que greeb e red.
            * Que blue é maior que red,
            * Que green é maior que 100,
            * E que red é menor que 70,
            * significa que a cor é ciano.*/
            if (blue > red && green > 100 && red < 70) {
                Serial.println("*** Cyan ***");
            }
            /* Caso os valores de red for maior que 70,
            * E que blue é maior que green,
            * significa que a cor é magenta*/            
            else if (red > 70 && blue > green) {
                Serial.println("*** Magent ***");
            }
            else
                /*Caso os valores de blue for maior que green e red
                significa que a cor é azul*/
                Serial.println("*** Blue ***");
        }
    }
}
