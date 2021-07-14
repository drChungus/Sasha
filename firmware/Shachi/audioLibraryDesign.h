#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=209,225
AudioSynthWaveformModulated waveformMod2;   //xy=445,335
AudioSynthWaveformModulated waveformMod1;   //xy=446,232
AudioAmplifier           amp2;           //xy=589,376
AudioAmplifier           amp1;           //xy=591,273
AudioEffectEnvelope      envelope2;      //xy=602,335
AudioEffectEnvelope      envelope1;      //xy=604,233
AudioMixer4              mixer12;        //xy=745,354
AudioMixer4              mixer11;        //xy=747,252
AudioFilterLadder        filter1;        //xy=1106,325
AudioFilterLadder        filter2; //xy=1109,427
AudioOutputI2S           i2s1;           //xy=1312,415
AudioConnection          patchCord1(i2s2, 0, waveformMod1, 0);
AudioConnection          patchCord2(waveformMod2, envelope2);
AudioConnection          patchCord3(waveformMod2, amp2);
AudioConnection          patchCord4(waveformMod1, envelope1);
AudioConnection          patchCord5(waveformMod1, amp1);
AudioConnection          patchCord6(amp2, 0, mixer12, 1);
AudioConnection          patchCord7(amp1, 0, mixer11, 1);
AudioConnection          patchCord8(envelope2, 0, mixer12, 0);
AudioConnection          patchCord9(envelope1, 0, mixer11, 0);
AudioConnection          patchCord10(mixer12, 0, filter2, 0);
AudioConnection          patchCord11(mixer11, 0, waveformMod2, 0);
AudioConnection          patchCord12(mixer11, 0, filter1, 0);
AudioConnection          patchCord13(filter1, 0, i2s1, 0);
AudioConnection          patchCord14(filter2, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1142,142
// GUItool: end automatically generated code
