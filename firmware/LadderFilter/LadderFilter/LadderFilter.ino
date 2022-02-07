/*
   A simple hardware test which receives audio from the audio shield
   Line-In pins and send it to the Line-Out pins and headphone jack.

   This example code is in the public domain.
*/

#include "physicalLayer.h"

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=243,173
AudioFilterLadder        ladder1;        //xy=442,193
AudioFilterStateVariable filter1;        //xy=638,199
AudioMixer4              mixer2;         //xy=639,292
AudioMixer4              mixer1;         //xy=823,206
AudioAmplifier           amp1;           //xy=977,206
AudioOutputI2S           i2s2;           //xy=1134,200
AudioConnection          patchCord1(i2s1, 1, ladder1, 0);
AudioConnection          patchCord2(ladder1, 0, filter1, 0);
AudioConnection          patchCord3(ladder1, 0, mixer2, 0);
AudioConnection          patchCord4(filter1, 0, mixer1, 0);
AudioConnection          patchCord5(filter1, 1, mixer1, 1);
AudioConnection          patchCord6(filter1, 2, mixer1, 2);
AudioConnection          patchCord7(mixer2, 0, mixer1, 3);
AudioConnection          patchCord8(mixer1, amp1);
AudioConnection          patchCord9(amp1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=314,368
// GUItool: end automatically generated code






const int myInput = AUDIO_INPUT_LINEIN;
//const int myInput = AUDIO_INPUT_MIC;
byte filterMode;


void setup() {
  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(24);
  //Serial.begin(115200);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(1);
  sgtl5000_1.lineInLevel(15);
  sgtl5000_1.lineOutLevel(13);
  

  ladder1.resonance(0.1);    //
  ladder1.frequency(2000);     //
  ladder1.octaveControl(5); // up 5 octaves (4850 Hz) & down 2.6 octaves (132 Hz)
  filter1.resonance(0.1);    //
  filter1.frequency(2000);     //
  filter1.octaveControl(5); // up 5 octaves (4850 Hz) & down 2.6 octaves (132 Hz)

  amp1.gain(1);
}

elapsedMillis volmsec = 0;

void loop() {
  ladder1.frequency(map(analogRead(pot7pin) - ((double(analogRead(pot4pin))/1023) * analogRead(ai1pin)), 0, 1023, 20, 13000));
  ladder1.resonance((double(analogRead(pot1pin)) / 1023)*1.3);
  

  filter1.frequency(map(analogRead(pot8pin), 0, 1023, 20, 13000));
  filter1.resonance(double(analogRead(pot3pin)) / 1023);

  amp1.gain(double(analogRead(pot2pin)) / 1023);

  if (button1pin == true) {
    filterMode++;
    filterMode %= 4;
  }
  switch (filterMode) {
    case 0:
      mixer1.gain(0, 1);
      mixer1.gain(1, 0);
      mixer1.gain(2, 0);
      mixer1.gain(3, 0);
      break;
    case 1:
      mixer1.gain(0, 0);
      mixer1.gain(1, 1);
      mixer1.gain(2, 0);
      mixer1.gain(3, 0);
      break;
    case 2:
      mixer1.gain(0, 0);
      mixer1.gain(1, 0);
      mixer1.gain(2, 1);
      mixer1.gain(3, 0);
      break;
    default:
      // do something
      break;
  }

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
