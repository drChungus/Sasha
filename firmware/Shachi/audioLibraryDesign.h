#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=89,239
AudioSynthWaveformModulated waveformMod2;   //xy=325,349
AudioSynthWaveformModulated waveformMod1;   //xy=326,246
AudioAmplifier           amp2;           //xy=469,390
AudioAmplifier           amp1;           //xy=471,287
AudioEffectEnvelope      envelope2;      //xy=482,349
AudioEffectEnvelope      envelope1;      //xy=484,247
AudioSynthWaveformDc     dc1;            //xy=609,517
AudioMixer4              mixer12;        //xy=625,368
AudioMixer4              mixer11;        //xy=627,266
AudioEffectEnvelope      envelope3;      //xy=787,494
AudioFilterLadder        filter1;        //xy=986,339
AudioFilterLadder        filter2;        //xy=989,441
AudioOutputI2S           i2s1;           //xy=1192,429
AudioConnection          patchCord1(waveformMod2, envelope2);
AudioConnection          patchCord2(waveformMod2, amp2);
AudioConnection          patchCord3(waveformMod1, envelope1);
AudioConnection          patchCord4(waveformMod1, amp1);
AudioConnection          patchCord5(amp2, 0, mixer12, 1);
AudioConnection          patchCord6(amp1, 0, mixer11, 1);
AudioConnection          patchCord7(envelope2, 0, mixer12, 0);
AudioConnection          patchCord8(envelope1, 0, mixer11, 0);
AudioConnection          patchCord9(dc1, envelope3);
AudioConnection          patchCord10(mixer12, 0, filter2, 0);
AudioConnection          patchCord11(mixer11, 0, waveformMod2, 0);
AudioConnection          patchCord12(mixer11, 0, filter1, 0);
AudioConnection          patchCord13(envelope3, 0, filter1, 1);
AudioConnection          patchCord14(envelope3, 0, filter2, 1);
AudioConnection          patchCord15(filter1, 0, i2s1, 0);
AudioConnection          patchCord16(filter2, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=98,290
// GUItool: end automatically generated code
