iCS6814 sensor;
bool sensorConnected;
void setup() {
    // Initialize serial connection
    Serial.begin(115200);
    // Conecte ao sensor usando I2C address (0x04)
    // Alternatively the address can be passed to begin(addr)
    sensorConnected = sensor.begin();
    if (sensorConnected == true) {
        // Print status message
        Serial.println("Connected to MiCS-6814 sensor");
        // ligue o sensor
        sensor.powerOn();
        // Aparecer valores de concentrações de ar
        Serial.println("Current concentrations:");
        Serial.println("CO\tNO2\tNH3\tC3H8\tC4H10\tCH4\tH2\tC2H5OH");
    } else {
        // Print error message on failed connection
        Serial.println("Couldn’t connect to MiCS-6814 sensor");
    }
}
void loop() {
if (sensorConnected) {
    // Colocar valores
    Serial.print(sensor.measureCO());
    Serial.print("\t");
    Serial.print(sensor.measureNO2());
    Serial.print("\t");
    Serial.print(sensor.measureNH3());
    Serial.print("\t");
    Serial.print(sensor.measureC3H8());
    Serial.print("\t");
    Serial.print(sensor.measureC4H10());
    Serial.print("\t");
    Serial.print(sensor.measureCH4());
    Serial.print("\t");
    Serial.print(sensor.measureH2());
    Serial.print("\t");
    Serial.println(sensor.measureC2H5OH());
}
    // Wait a small amount of time
    delay(1000);
}