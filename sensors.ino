const int echoPin1[] = {3, 5};
const int echoPin2[] = {6, 9};
const int echoPin3[] = {7, 8, 4};
const int trigPin1 = 10;
const int trigPin2 = 11;
const int trigPin3 = 12;

const int trigPins[] = {10, 11, 12};

int distances[7];
int curDistSize = 0;

void setup()
{
  for (int i = 0; i < 3; i++)
  {
    pinMode(trigPins[i], OUTPUT);
  }

  for (int i = 0; i < 2; i++)
  {
    pinMode(echoPin1[i], INPUT);
    pinMode(echoPin2[i], INPUT);
  }

  for (int i = 0; i < 3; i++)
  {
    pinMode(echoPin3[i], INPUT);
  }

  Serial.begin(9600);
}

void loop()
{
  // Measure distance from the first set of sensors (echoPin1 and trigPin1)
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(trigPin1, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin1, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin1, LOW);

    int duration = pulseIn(echoPin1[i], HIGH);
    int distance = duration * 0.034 / 2;

    distances[curDistSize] = distance;
    curDistSize++;
  }

  // Measure distance from the second set of sensors (echoPin2 and trigPin2)
  for (int i = 0; i < 2; i++)
  {
    digitalWrite(trigPin2, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin2, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin2, LOW);

    int duration = pulseIn(echoPin2[i], HIGH);
    int distance = duration * 0.034 / 2;

    distances[curDistSize] = distance;
    curDistSize++;
  }

  // Measure distance from the third set of sensors (echoPin3 and trigPin3)
  for (int i = 0; i < 3; i++)
  {
    digitalWrite(trigPin3, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin3, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin3, LOW);

    int duration = pulseIn(echoPin3[i], HIGH);
    int distance = duration * 0.034 / 2;

    distances[curDistSize] = distance;
    curDistSize++;
  }

  // Print the distance measurements
  for (int i = 0; i < 7; i++)
  {
    Serial.print("Distance ");
    Serial.print(i);
    Serial.print(": ");
    Serial.print(distances[i]);
    Serial.println(" cm");
  }

  curDistSize = 0;
  delay(50);
}
