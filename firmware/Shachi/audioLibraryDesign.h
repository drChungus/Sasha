#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=71,104
AudioSynthWaveformModulated waveformMod2;   //xy=307,214
AudioSynthWaveformModulated waveformMod1;   //xy=308,111
AudioAmplifier           amp2;           //xy=451,255
AudioAmplifier           amp1;           //xy=453,152
AudioEffectEnvelope      envelope2;      //xy=464,214
AudioEffectEnvelope      envelope1;      //xy=466,112
AudioSynthWaveformDc     dc1;            //xy=591,382
AudioMixer4              mixer12;        //xy=607,233
AudioMixer4              mixer11;        //xy=609,131
AudioEffectEnvelope      envelope3;      //xy=769,359
AudioEffectWaveshaper    waveshape1;     //xy=795,190
AudioAnalyzePeak         envelopePeak;          //xy=967,407
AudioFilterLadder        filter1;        //xy=968,204
AudioFilterLadder        filter2;        //xy=971,306
AudioOutputI2S           i2s1;           //xy=1174,294
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
AudioConnection          patchCord11(mixer12, waveshape1);
AudioConnection          patchCord12(mixer11, 0, waveformMod2, 0);
AudioConnection          patchCord13(envelope3, 0, filter1, 1);
AudioConnection          patchCord14(envelope3, 0, filter2, 1);
AudioConnection          patchCord15(envelope3, envelopePeak);
AudioConnection          patchCord16(waveshape1, 0, filter1, 0);
AudioConnection          patchCord17(filter1, 0, i2s1, 0);
AudioConnection          patchCord18(filter2, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=80,155
// GUItool: end automatically generated code
