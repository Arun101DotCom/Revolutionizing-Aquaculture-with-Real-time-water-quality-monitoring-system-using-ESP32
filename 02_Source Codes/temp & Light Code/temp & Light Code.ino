#define TempPin 8 //GPIO pin, check the pin number and function of your board
#define LightPin 9
// the setup routine runs once when you press reset:
void setup() {
// initialize serial communication at 9600 bits per second:
Serial.begin(9600);
pinMode(TempPin,INPUT);
pinMode(LightPin,INPUT);
}

// the loop routine runs over and over again forever:
void loop() {
// read the input on analog pin 0:
int sensorValue_tm = analogRead(TempPin);
int sensorValue_op = analogRead(LightPin);
// Convert the analog reading ADC:12bit (which goes from 0 - 4095) to a voltage (0 - 5V):
float voltage_tm = sensorValue_tm * (3.3 / 4096.0);
float voltage_op = sensorValue_op * (3.3 / 4096.0);
//float Light_Lux = 107.12* pow(voltage_op,2) - 190.78 * voltage_op + 68.724;
//float Temp_Celsius = -21.774 * sensorValue_tm + 52.739;
//float Light_Lux = (84.344*sensorValue_op)-53.911;
float Temp_Celsius = (-27.751 * voltage_tm) + 59.277;
float Light_Lux = (84.344*voltage_op)+53.911;
//float Temp_Celsius = (-0.0411*sensorValue_tm)+2.2768;
//float Light_Lux = (0.0049*sensorValue_op)+ 1.2923;
//float Temp_Celsius = (-33.55*sensorValue_tm)+66.417;
//loat Temp_Celsius = -34.246 * pow(sensorValue_tm,2)+47.149*sensorValue_tm+18.747;
// print out the value you read:
Serial.print(" Temperature :");
Serial.print(Temp_Celsius);
Serial.println(" Celsius ");
Serial.print("Light :");
Serial.print(Light_Lux);
Serial.print(" LUX ");
delay(2000);
}
