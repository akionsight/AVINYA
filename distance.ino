#define trigPin 2

const int echoPin[] = {3, 4, 5, 6, 7, 8, 9};
int numSensors = 8;

// Define variables:
long duration;
int distance;

void setup()
{
  // Define outputs: // trig pin is common
  pinMode(trigPin, OUTPUT);
  for (int i = 0; i < numSensors; i++)
  {
    pinMode(echoPin[i], INPUT);
  }

  Serial.begin(9600);
}

void loop()
{
  // clear trigpin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  // write to common trigPin, this may or may not be a good idea but we'll see
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  int distances[7]; // mount it clockwise

  for (int i = 0; i < numSensors; i++)
  {
    long duration;
    int distance;

    duration = pulseIn(echoPin[i], HIGH);

    distance = duration * 0.034 / 2;

    distances[i] = distance;
  }

  Serial.println(distances[0]);

  delay(50);
}
