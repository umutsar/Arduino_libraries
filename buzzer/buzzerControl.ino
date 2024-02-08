
int buzzer = A1;
uint8_t ledPin = 3;
// notaların frekans değerleri
int DO = 262;  // DO
int re = 294;  // re
int mi = 330;  // mi
int fa = 349;  // fa
int sol = 392; // sol
int la = 440;  // la
int si = 493;  // si
int DOince = 523;  // DO (ince)
// notalar adında bir dizi oluşturalım
int notalar1[] = {re, re, re, re, mi, fa};
int notalar2[] = {fa,mi,re,mi,re,DO,DO};
int notalar3[] = {mi,re,DO,mi,re,DO,fa,mi,re,DO};
int notalar4[] = {si,si,si,si,DO,re,re,DO,re,DO,si};
int notalar5[] = {re,DO,si,re,DO,si,mi,re,DO,si,la};

void Tone(int a, int b, int c) {
  tone(a,b);
  digitalWrite(ledPin, HIGH);
  delay(c);
  digitalWrite(ledPin, LOW);
  noTone(a);
  delay(20);
}

void setup()
{
    
    for (int i = 0; i < 6; i++)
    {
      if(i == 3) {
        Tone(buzzer, notalar1[i], 400);
      }
      else if(i == 5) {
        Tone(buzzer, notalar1[i], 300);
      }
      else {
        Tone(buzzer, notalar1[i], 200);
      }
    }

    delay(200);

    for (int i = 0; i < 7; i++)
    {
        Tone(buzzer, notalar2[i], 200);
    }
    delay(200);

    for (int i = 0; i < 10; i++)
    {
        Tone(buzzer, notalar3[i], 200);
    }
    delay(200);
    
    for (int i = 0; i < 11; i++)
    {
        Tone(buzzer, notalar4[i], 200);
    }
    delay(200);

    for (int i = 0; i < 11; i++)
    {
        Tone(buzzer, notalar5[i], 200);
    }
    delay(200);
}
void loop()
{
}
