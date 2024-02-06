const char* mode[7] = {"rgb", "rb", "rg", "gb", "r", "g", "b"};
int i = 0;

void setup() {
  class Waiter
{
private:
  int time = 3600000;
public:
  void timer()
  {
    while (time != 0)
    {
      time--;
    }
    digitalWrite(9, LOW);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
  Waiter()
  {
    timer();
  }
};
  pinMode(9, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(7, INPUT_PULLUP);
  digitalWrite(4, HIGH);
  Waiter wait = Waiter();
}

void setLights()
{
  if (mode[i] == "rgb")
  {
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, HIGH);
  }
  else if (mode[i] == "rg") 
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(9, LOW);
  }
  else if (mode[i] == "rb")
  {
    digitalWrite(5, HIGH);
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
  }
  else if (mode[i] == "gb")
  {
    digitalWrite(9, HIGH);
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
  else if (mode[i] == "r")
  {
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(9, LOW);
  }
  else if (mode[i] == "g")
  {
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
  }
  else if (mode[i] == "b")
  {
    digitalWrite(9, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(5, LOW);
  }
}

void loop() {
  if (digitalRead(7) == LOW)
  {
    if (i == 7)
    {
      i = 0;
      setLights();
    }
    else {
      i++;
      setLights();
    }
    delay(1000);
  }
}