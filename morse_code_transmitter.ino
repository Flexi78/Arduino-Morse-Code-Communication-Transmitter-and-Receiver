int laser = 1;
char texte[] = "the quick brown fox jumps over the lazy dog"; //message a envoyer
char texteAenvoyer[4];
static String tabAlphabet[] = {"a","b", "c", "d", "e", "f", "g", "h",
                                "i", "j", "k", "l", "m", "n", "o", "p", "q",
                                 "r", "s", "t", "u", "v", "w", "x", "y", "z", " "
                             };
static String tabMorse[] = {"._!!","_...", "_._.", "_..!", ".!!!", ".._.", "__.!", "....",
                             "..!!", ".___", "_._!", "._..", "__!!", "_.!!", "___!", ".__.", "__._",
                             "._.!", "...!", "_!!!", ".._!", "..._", ".__!", "_.._", "_.__", "__..", "!!!!"
                             };
void setup() {
  // put your setup code here, to run once:
 pinMode(laser,OUTPUT);
 digitalWrite(laser,LOW);
 delay(6000);
}
void loop() {
  // put your main code here, to run repeatedly:
int i; 
int y;
String texteMorse;
int taille=((sizeof(texte))/(sizeof(char)));
 
for (i=0;i<taille;i++)
{
  texteMorse=morseOutput(texte[i]);
 
  for(y=0;y<4;y++)
  {
  texteAenvoyer[y]=texteMorse.charAt(y);
  envoi(texteAenvoyer[y]);
  }
}
delay(10000); //fin de transmission
}
void envoi(char carac)
{
  int i;
  Serial.println("fonction envoi");
    if(carac=='.')
    {
       digitalWrite(laser,HIGH);
       Serial.println('.');
       delay(300);
       digitalWrite(laser,LOW);
       delay(200);
    }
    if(carac=='_')
    {
       digitalWrite(laser,HIGH);
       Serial.println('_');
       delay(700);
       digitalWrite(laser,LOW);
       delay(200);
    }
    if(carac=='!')
    {
       digitalWrite(laser,LOW);
       Serial.println('!');
       delay(1000);
    }
 }
String morseOutput(char myMessage){
  int j = 0;
  
  while (tabAlphabet[j] != " ")
  {
    if (tabAlphabet[j].charAt(0) == myMessage)
    {
      return tabMorse[j];
    }
    j++;
    if (tabAlphabet[j] == " ")
    {
      //Serial.print("!!!!");
      return("!!!!");
    }
  }
}
