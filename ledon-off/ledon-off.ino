/* LED qui cliniote (HELLO WORD)
   by: Giaccone.R
   date: September 07, 2018
   license: Public Domain - please use this code however you'd like.
   environement:IDE Arduino.

   le script permet de faire clinoté une LED sur le arduino MEGA 2560
   2 constante est utilisé pour personalisé la sortie et le temp des cliniotement
*/

// liste des constantes ( #define ou const )
#define LED 4  // la led qui sera utilisé
#define BUTON 7 // le button gauche
#define BUTON2 5 // le button milieux
#define BUTON3 6 // le button droite
#define BUZ 3

//liste de variable
int NbrClignot = 0;
int valb1 = 0;
int valb2 = 0;
int valb3 = 0;
int temp = 500;
int eta = 0;
int msg = 0;


// debut des fonction
// mise en place
void setup()
{
  //mise en place entré sortie
 pinMode(LED, OUTPUT);  // Met la LED en sortie/Set LED as an output
 pinMode(BUZ, OUTPUT);  // Met la LED en sortie/Set LED as an output
 pinMode(BUTON, INPUT);  // Met la le button en entré
 pinMode(BUTON2, INPUT);  // Met la le button en entré
 pinMode(BUTON3, INPUT);  // Met la le button en entré
 //welcome terminal
 Serial.begin(2400);
 Serial.println ("BONJOUR JE SUIS CONNECTER \n");
 delay(1000);
 Serial.println ("je commence le loop \n");
 //son de confirmation alumé
 digitalWrite(BUZ, HIGH);   // alume le buze
 delay(20);
 digitalWrite(BUZ, LOW);    // etint la le buze
 delay(20);
 digitalWrite(BUZ, HIGH);   // alume le buze
 delay(20);
 digitalWrite(BUZ, LOW);    // etint la le buze
 delay(20);
}

//programe principale
void loop()
{
  //prépare les button
  valb1 = digitalRead(BUTON);     // read the input pin
  valb2 = digitalRead(BUTON2);     // read the input pin
  valb3 = digitalRead(BUTON3);     // read the input pin

//on-off
  if (valb2 == 0 ){
    //cette zone alterne entre étint et allumé
    //confirmation sonore+terminal
    if (msg == 1){Serial.println ("\n  led off");}
    else{Serial.println ("\n  led on");}
    digitalWrite(BUZ, HIGH);   // alume le buze
    delay(1);
    digitalWrite(BUZ, LOW);    // etint la le buze
    //met etat sur 1
    eta = !eta;
    delay(1000);
    //chagment du message
    msg = !msg;
  }
  if (eta ==1) {
  digitalWrite(LED, HIGH);   // alume la led (LED)
  delay(temp);
  digitalWrite(LED, LOW);    // etint la led (LED) 
  delay(temp); 
  }

//les temps
//temps-
if (valb1 == 0 ){
   Serial.println ("-50 au temps \n");
   temp = temp-50;
 digitalWrite(BUZ, HIGH);   // alume le buze
 delay(20);
 digitalWrite(BUZ, LOW);    // etint la le buze
   delay(1000);
}

//temps+
if (valb3 == 0 ){
   Serial.println ("+50 au temps \n");
    digitalWrite(BUZ, HIGH);   // alume le buze
     delay(20);
    digitalWrite(BUZ, LOW);    // etint la le buze
    delay(20);
     digitalWrite(BUZ, HIGH);   // alume le buze
     delay(20);
    digitalWrite(BUZ, LOW);    // etint la le buze
   temp = temp+50;
   delay(1000);
}


//fin affichage du temps en MS actuel
Serial.println ("\n\n");
delay(1000); //evite les erreur de loop
Serial.println ("le temps actuel est ");
Serial.println (temp);
Serial.println (" ms");
//fix le temp négatif
if (temp < 0 ){
   Serial.println ("ERREUR\n");
       digitalWrite(BUZ, HIGH);   // alume le buze
     delay(500);
    digitalWrite(BUZ, LOW);    // etint la le buze
   temp = 500;
   Serial.println ("temp negatif retour a 500 \n");
   Serial.println ("faite attention\n");
   delay(1000);
}
}//end

















