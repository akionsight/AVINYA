const int echoPin1[] = {3, 5};
const int echoPin2[] = {6, 9};
const int echoPin3[] = {7, 8, 4};
const int trigPin1 = 10;
const int trigPin2 = 11;
const int trigPin3 = 12;

const int trigPins[] = {10, 11, 12};


// Define variables:

int distances[7];
int curDistSize = 0;

void setup()
{
  // Define outputs

  for (int i = 0; i < 3; i++)
  {
    digitalWrite(trigPins[i], LOW);
  }

  for (int i = 0; i < 3; i++)
  {
    for (i = 0; i < 2; i++)
    {
      pinMode(echoPin1[i], OUTPUT);
      pinMode(echoPin2[i], OUTPUT);
    }

    for (int i = 0; i < 3; i++)
    {
      pinMode(echoPin3[i], OUTPUT);
    }

    pinMode(13, OUTPUT);
  }

  Serial.begin(9600);

  pinMode(13, OUTPUT)
}

void loop()
{
  // clear trigpin

  digitalWrite(trigPin1, LOW);
  digitalWrite(trigPin2, LOW);
  digitalWrite(trigPin3, LOW);

  delayMicroseconds(7);
  ///////////////////////////////////////

  digitalWrite(trigPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin1, LOW);

  for (int i = 0; i < 2; i++)
  {

    int duration = pulseIn(echoPin1[i], HIGH);

    int distance = duration * 0.034 / 2;

    distances[curDistSize] = distance;
    curDistSize++;
  }

  ////////////////////////////////////

  digitalWrite(trigPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin2, LOW);

  for (int i = 0; i < 2; i++)
  {

    int duration = pulseIn(echoPin2[i], HIGH);

    int distance = duration * 0.034 / 2;

    distances[curDistSize] = distance;
    curDistSize++;
  }

  ////////////////////////////////////

  digitalWrite(trigPin3, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin3, LOW);

  for (int i = 0; i < 3; i++)
  {

    int duration = pulseIn(echoPin2[i], HIGH);

    int distance = duration * 0.034 / 2;

    distances[curDistSize] = distance;
    curDistSize++;
  }

  for (int i = 0; i < 7; i++) {
    if (distances[i] < 15 && distances[i] > 0 ) {
      digitalWrite(13, HIGH);
    }

  }

  curDistSize = 0;
  delay(50);

}
