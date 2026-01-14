/*
    UltrasonicDisplayOnTerm.ino
    Example sketch for ultrasonic ranger

    Copyright (c) 2012 seeed technology inc.
    Website    : www.seeed.cc
    Author     : LG, FrankieChu
    Create Time: Jan 17,2013
    Change Log :

    The MIT License (MIT)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in
    all copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
    THE SOFTWARE.
*/


/***************************************************************************/
//	Function: Measure the distance to obstacles in front and print the distance
//			  value to the serial terminal.The measured distance is from
//			  the range 0 to 400cm(157 inches).
//	Hardware: Grove - Ultrasonic Ranger
//	Arduino IDE: Arduino-1.0
/*****************************************************************************/

#include "Ultrasonic.h"

Ultrasonic ultrasonic(7);
void setup() {
    Serial.begin(9600);
}
void loop() {
     //const int initialvalue = 0; 
     const int minimumvalue = 20; // Minimum set of value in cm
     const int mediumvalue = 30; // medium setof value in cm
     const int maximumvalue = 50; // maximum set of value in cm
    //long RangeInInches;
    long RangeInCentimeters;

   // Serial.println("The distance to obstacles in front is: ");
   //RangeInInches = ultrasonic.MeasureInInches();
   //Serial.print(RangeInInches);//0~157 inches
   //Serial.println(" inch");
   // delay(250);

    RangeInCentimeters = ultrasonic.MeasureInCentimeters(); // two measurements should keep an interval
    if(RangeInCentimeters <= minimumvalue){
    Serial.print(RangeInCentimeters);//0~20cm
    Serial.println(" cm");
    Serial.print("Danger Level: WATER LEVEL IS LOW : ");
    delay(3000);
    }
    else if(RangeInCentimeters <= mediumvalue){
    Serial.print(RangeInCentimeters);//20~30cm
    Serial.println(" cm");
    Serial.print("Moderate level: WATER LVEL IS GOOD : ");
    delay(3000);
    }
    else if(RangeInCentimeters <= maximumvalue){
    Serial.print(RangeInCentimeters);//30~50cm
    Serial.println(" cm");
    Serial.print("Maximum Level: WATER LVEL IS FULL : ");
    delay(3000);
    }
    else{
    //Serial.println("Warning: WATER LEVEL IS OVERFLOW ");//above 50cm
    Serial.print(RangeInCentimeters);// above-50cm
    Serial.println(" cm");  
    Serial.print("Warning: WATER LEVEL IS OVERFLOW ");//above 50cm
    delay(3000);
    
    }
    
}
