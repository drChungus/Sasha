#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s1;           //xy=177,163
AudioSynthWaveform       vsTriangleB;    //xy=293,1409
AudioSynthWaveformSineModulated modulatorB;     //xy=328,1498
AudioAnalyzeFFT256       fft256_1;       //xy=390,164
AudioEffectWaveshaper    waveshaperB;    //xy=443,1435
AudioMixer4              indexB;         //xy=460,1554
AudioSynthWaveform       vaWaveform2B;   //xy=490,1304
AudioSynthWaveform       vaWaveform1B;   //xy=505,1343
AudioSynthWaveformModulated carrier;   //xy=573,332
AudioSynthWaveformSineModulated carrierB;       //xy=600,1498
AudioMixer4              vsMixerB;       //xy=614,1427
AudioMixer4              vaMixerB;       //xy=660,1330
AudioFilterLadder        ladder1;        //xy=763,217
AudioFilterLadder        ladder2; //xy=763,294
AudioFilterLadder        ladder3; //xy=766,366
AudioFilterLadder        ladder4; //xy=767,434
AudioMixer4              auxMixer;       //xy=822,1490
AudioMixer4              mixer1;         //xy=992,321
AudioAmplifier           auxAmp;         //xy=990,1192
AudioOutputI2S           i2s2;           //xy=1209,321
AudioConnection          patchCord1(i2s1, 0, fft256_1, 0);
AudioConnection          patchCord2(vsTriangleB, waveshaperB);
AudioConnection          patchCord3(vsTriangleB, 0, vsMixerB, 0);
AudioConnection          patchCord4(modulatorB, 0, indexB, 0);
AudioConnection          patchCord5(waveshaperB, 0, vsMixerB, 1);
AudioConnection          patchCord6(indexB, carrierB);
AudioConnection          patchCord7(vaWaveform2B, 0, vaMixerB, 0);
AudioConnection          patchCord8(vaWaveform1B, 0, vaMixerB, 1);
AudioConnection          patchCord9(carrier, 0, ladder1, 0);
AudioConnection          patchCord10(carrier, 0, ladder2, 0);
AudioConnection          patchCord11(carrier, 0, ladder3, 0);
AudioConnection          patchCord12(carrier, 0, ladder4, 0);
AudioConnection          patchCord13(carrierB, 0, auxMixer, 2);
AudioConnection          patchCord14(carrierB, 0, indexB, 1);
AudioConnection          patchCord15(vsMixerB, 0, auxMixer, 1);
AudioConnection          patchCord16(vaMixerB, 0, auxMixer, 0);
AudioConnection          patchCord17(ladder1, 0, mixer1, 0);
AudioConnection          patchCord18(ladder2, 0, mixer1, 1);
AudioConnection          patchCord19(ladder3, 0, mixer1, 2);
AudioConnection          patchCord20(ladder4, 0, mixer1, 3);
AudioConnection          patchCord21(auxMixer, auxAmp);
AudioConnection          patchCord22(mixer1, 0, i2s2, 0);
AudioConnection          patchCord23(mixer1, 0, i2s2, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=212,528
// GUItool: end automatically generated code
