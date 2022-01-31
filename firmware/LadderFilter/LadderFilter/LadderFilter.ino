/*
 * A simple hardware test which receives audio from the audio shield
 * Line-In pins and send it to the Line-Out pins and headphone jack.
 *
 * This example code is in the public domain.
 */

 #include "physicalLayer.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=478,230
AudioFilterLadder        ladder1;        //xy=639,244
AudioOutputI2S           i2s2;           //xy=803,233
AudioConnection          patchCord1(i2s1, 1, ladder1, 0);
AudioConnection          patchCord2(ladder1, 0, i2s2, 0);
AudioConnection          patchCord3(ladder1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=514,415
// GUItool: end automatically generated code





const int myInput = AUDIO_INPUT_LINEIN;
//const int myInput = AUDIO_INPUT_MIC;


void setup() {
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(24);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(1);

  ladder1.resonance(0.1);    // 
  ladder1.frequency(2000);     // 
  ladder1.octaveControl(5); // up 5 octaves (4850 Hz) & down 2.6 octaves (132 Hz)
}

elapsedMillis volmsec=0;

void loop() {
  ladder1.frequency(map(analogRead(pot2pin),0,1023,20,15000));
  //ladder1.frequency(double(analogRead(pot3pin))/1023);
  
   /*
  Serial.print("Filter CPU Usage: ");
  Serial.print(ladder1.processorUsageMax());
  Serial.print("%, Total CPU Usage: ");
  Serial.print(AudioProcessorUsageMax());
  Serial.println("%");
  ladder1.processorUsageMaxReset();
  AudioProcessorUsageMaxReset();*/
}



double scaleSimple(double x, double in_min, double in_max, double out_min, double out_max)
{
  double unlimitedOut;
  unlimitedOut = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return unlimitedOut;
}
