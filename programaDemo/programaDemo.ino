int tiempo=500,informar=100;
int valor[]={0b00111111,0b00000110,0b01011011,0b01001111,0b01100110,0b01101101,0b01111100,0b00000111,0b01111111,0b01100111,0b00000000};
int letras[]={0b11110111,0b0111000,0b01011100,0b01110110};//ALOH
int Umil,Cent,Dec,Uni,temperatura,suma,cantidadDeValores=0;
void setup() {
  DDRD=0xFF;
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);

}

void loop() {
    tiempo=analogRead(A0)+2;
    if(cantidadDeValores<13){
      suma=suma+analogRead(A1);
      cantidadDeValores++;
    }
    else{
      temperatura=suma/(cantidadDeValores);
      cantidadDeValores=0;
      temperatura =map(temperatura,455,340,0,100);
      toBCD(temperatura);
      suma=0;
    }
 delay(tiempo);
  digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  PORTD=valor[Uni];
  delay(tiempo);
    digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  PORTD=valor[Dec];
  delay(tiempo);
    digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  PORTD=valor[Cent];
  delay(tiempo);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  PORTD=valor[Umil];
    delay(tiempo);
  digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  delay(tiempo);  
  
  //mandar la info por puerto serie
  /*if(informar>0)informar--;
  else{
    Serial.begin(9600);
    informar=500;
    Serial.println(temperatura);
    Serial.end();
  }*/
  
}
void toBCD(int dato){
  Umil = dato/1000;
  Cent = dato%1000/100;
  Dec = dato%100/10;
  Uni = dato%10;
}

void hola(void){
   digitalWrite(11,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
    PORTD=letras[0];
delay(tiempo);
    digitalWrite(11,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(8,HIGH);
  PORTD=letras[1];
delay(tiempo);
    digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(8,HIGH);
  PORTD=letras[2];
delay(tiempo);
    digitalWrite(11,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(8,LOW);
  PORTD=letras[3];
}


