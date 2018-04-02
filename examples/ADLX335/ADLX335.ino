#define x A2
#define y A1
#define z A0

int Cx;
int Cy;
int Cz;

void readsensor()
{
  Cx = analogRead(x);
  Cy = analogRead(y);
  Cz = analogRead(z);

  Cx = map(Cx, 250, 380 , -1, 1);
  Cy = map(Cy, 250, 380 , -1, 1);
  Cz = map(Cz, 250, 380 , -1, 1);
  
  Serial.print("Cx = ");
  Serial.print(Cx);
  Serial.print(" --- ");
  Serial.print("Cy = ");
  Serial.print(Cy);
  Serial.print(" --- ");
  Serial.print("Cz = ");
  Serial.println(Cz);
  delay(300);
}
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  readsensor();
}

