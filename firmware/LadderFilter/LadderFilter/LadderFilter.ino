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
AudioInputI2S          
i2s1;           //xy=83,184
AudioAmplifier           amp1;           //xy=244,191
AudioFilterLadder        ladder1;        //xy=391,205
AudioAmplifier           amp2;           //xy=424,317
AudioFilterStateVariable filter1;        //xy=566,165
AudioEffectDigitalCombine combine1;       //xy=647,373
AudioMixer4              mixer2;         //xy=698,322
AudioMixer4              mixer1;         //xy=772,218
AudioOutputI2S           i2s2;           //xy=1083,212
//AudioConnection          patchCord1(i2s1, 0, ladder1, 1);
AudioConnection          patchCord2(i2s1, 1, amp1, 0);
AudioConnection          patchCord3(amp1, 0, ladder1, 0);
AudioConnection          patchCord4(amp1, amp2);
AudioConnection          patchCord5(ladder1, 0, filter1, 0);
AudioConnection          patchCord6(ladder1, 0, mixer2, 0);
AudioConnection          patchCord7(ladder1, 0, mixer1, 3);
AudioConnection          patchCord8(ladder1, 0, combine1, 0);
AudioConnection          patchCord9(amp2, 0, mixer2, 1);
AudioConnection          patchCord10(amp2, 0, combine1, 1);
AudioConnection          patchCord11(filter1, 0, mixer1, 0);
AudioConnection          patchCord12(filter1, 1, mixer1, 1);
AudioConnection          patchCord13(filter1, 2, mixer1, 2);
AudioConnection          patchCord14(mixer2, 0, i2s2, 0);
AudioConnection          patchCord15(mixer1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=263,380
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
  ladder1.octaveControl(7); // up 5 octaves (4850 Hz) & down 2.6 octaves (132 Hz)
  
  filter1.resonance(0.1);    //
  filter1.frequency(2000);     //
  filter1.octaveControl(5); // up 5 octaves (4850 Hz) & down 2.6 octaves (132 Hz)

  amp1.gain(1);
  amp2.gain(-1);
  mixer2.gain(1,1);   
}

elapsedMillis volmsec = 0;

void loop() {
  ladder1.frequency(pow(2,((     double(analogRead(pot8pin)) + double(analogRead(pot4pin))/1023 * -2*double(analogRead(ai1pin)-512) + double(analogRead(pot6pin))/1023 * -2*double(analogRead(ai2pin)-512)  )/100))*20);
  ladder1.resonance((double(analogRead(pot1pin)) / 1023)*1.1);
  Serial.println(analogRead(ai1pin));

  filter1.frequency(map(analogRead(pot8pin), 0, 1023, 20, 13000));
  filter1.resonance(double(analogRead(pot3pin)) / 1023);

  amp1.gain(( double(analogRead(pot2pin)) + double(analogRead(pot5pin))/1023 *-2*double(analogRead(ai3pin)-512) ) / 1023);

  if (digitalRead(button1pin) == true) {
    filterMode++;
    filterMode %= 4;
  }
  filterMode = 3;
  /*switch (filterMode) {
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
