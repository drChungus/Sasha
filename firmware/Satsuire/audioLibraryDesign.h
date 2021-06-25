#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=181,109
AudioSynthWaveform       vsTriangleB;    //xy=293,1409
AudioSynthWaveform       voice3;         //xy=325,368
AudioSynthWaveform       voice2;         //xy=326,332
AudioSynthWaveform       voice4;         //xy=327,407
AudioSynthWaveform       voice1;         //xy=328,297
AudioSynthWaveformSineModulated modulatorB;     //xy=328,1498
AudioEffectWaveshaper    waveshaperB;    //xy=443,1435
AudioMixer4              indexB;         //xy=460,1554
AudioSynthWaveform       vaWaveform2B;   //xy=490,1304
AudioSynthWaveform       vaWaveform1B;   //xy=505,1343
AudioMixer4              mixer;          //xy=525,355
AudioSynthWaveformSineModulated carrierB;       //xy=600,1498
AudioMixer4              vsMixerB;       //xy=614,1427
AudioMixer4              vaMixerB;       //xy=660,1330
AudioOutputI2S           i2s2;           //xy=787,310
AudioMixer4              auxMixer;       //xy=822,1490
AudioAmplifier           auxAmp;         //xy=990,1192
AudioConnection          patchCord1(vsTriangleB, waveshaperB);
AudioConnection          patchCord2(vsTriangleB, 0, vsMixerB, 0);
AudioConnection          patchCord3(voice3, 0, mixer, 2);
AudioConnection          patchCord4(voice2, 0, mixer, 1);
AudioConnection          patchCord5(voice4, 0, mixer, 3);
AudioConnection          patchCord6(voice1, 0, mixer, 0);
AudioConnection          patchCord7(voice1, 0, i2s2, 0);
AudioConnection          patchCord8(modulatorB, 0, indexB, 0);
AudioConnection          patchCord9(waveshaperB, 0, vsMixerB, 1);
AudioConnection          patchCord10(indexB, carrierB);
AudioConnection          patchCord11(vaWaveform2B, 0, vaMixerB, 0);
AudioConnection          patchCord12(vaWaveform1B, 0, vaMixerB, 1);
AudioConnection          patchCord13(mixer, 0, i2s2, 1);
AudioConnection          patchCord14(carrierB, 0, auxMixer, 2);
AudioConnection          patchCord15(carrierB, 0, indexB, 1);
AudioConnection          patchCord16(vsMixerB, 0, auxMixer, 1);
AudioConnection          patchCord17(vaMixerB, 0, auxMixer, 0);
AudioConnection          patchCord18(auxMixer, auxAmp);
AudioControlSGTL5000     sgtl5000_1;     //xy=212,528
// GUItool: end automatically generated code
