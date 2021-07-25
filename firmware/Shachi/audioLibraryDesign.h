#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=89,239
AudioSynthWaveform       vsTriangleB;    //xy=293,1409
AudioSynthWaveformModulated waveformMod2;   //xy=325,349
AudioSynthWaveformModulated waveformMod1;   //xy=326,246
AudioSynthWaveformSineModulated modulatorB;     //xy=328,1498
AudioEffectWaveshaper    waveshaperB;    //xy=443,1435
AudioMixer4              indexB;         //xy=460,1554
AudioAmplifier           amp2;           //xy=469,390
AudioAmplifier           amp1;           //xy=471,287
AudioEffectEnvelope      envelope2;      //xy=482,349
AudioEffectEnvelope      envelope1;      //xy=484,247
AudioSynthWaveform       vaWaveform2B;   //xy=490,1304
AudioSynthWaveform       vaWaveform1B;   //xy=505,1343
AudioSynthWaveformSineModulated carrierB;       //xy=600,1498
AudioSynthWaveformDc     dc1;            //xy=609,517
AudioMixer4              vsMixerB;       //xy=614,1427
AudioMixer4              mixer12;        //xy=625,368
AudioMixer4              mixer11;        //xy=627,266
AudioMixer4              vaMixerB;       //xy=660,1330
AudioEffectEnvelope      envelope3;      //xy=787,494
AudioMixer4              auxMixer;       //xy=822,1490
AudioFilterLadder        filter1;        //xy=986,339
AudioFilterLadder        filter2;        //xy=989,441
AudioAmplifier           auxAmp;         //xy=990,1192
AudioOutputI2S           i2s1;           //xy=1192,429
AudioConnection          patchCord1(i2s2, 0, waveformMod1, 0);
AudioConnection          patchCord2(vsTriangleB, waveshaperB);
AudioConnection          patchCord3(vsTriangleB, 0, vsMixerB, 0);
AudioConnection          patchCord4(waveformMod2, envelope2);
AudioConnection          patchCord5(waveformMod2, amp2);
AudioConnection          patchCord6(waveformMod1, envelope1);
AudioConnection          patchCord7(waveformMod1, amp1);
AudioConnection          patchCord8(modulatorB, 0, indexB, 0);
AudioConnection          patchCord9(waveshaperB, 0, vsMixerB, 1);
AudioConnection          patchCord10(indexB, carrierB);
AudioConnection          patchCord11(amp2, 0, mixer12, 1);
AudioConnection          patchCord12(amp1, 0, mixer11, 1);
AudioConnection          patchCord13(envelope2, 0, mixer12, 0);
AudioConnection          patchCord14(envelope1, 0, mixer11, 0);
AudioConnection          patchCord15(vaWaveform2B, 0, vaMixerB, 0);
AudioConnection          patchCord16(vaWaveform1B, 0, vaMixerB, 1);
AudioConnection          patchCord17(carrierB, 0, auxMixer, 2);
AudioConnection          patchCord18(carrierB, 0, indexB, 1);
AudioConnection          patchCord19(dc1, envelope3);
AudioConnection          patchCord20(vsMixerB, 0, auxMixer, 1);
AudioConnection          patchCord21(mixer12, 0, filter2, 0);
AudioConnection          patchCord22(mixer11, 0, waveformMod2, 0);
AudioConnection          patchCord23(mixer11, 0, filter1, 0);
AudioConnection          patchCord24(vaMixerB, 0, auxMixer, 0);
AudioConnection          patchCord25(envelope3, 0, filter1, 1);
AudioConnection          patchCord26(envelope3, 0, filter2, 1);
AudioConnection          patchCord27(auxMixer, auxAmp);
AudioConnection          patchCord28(filter1, 0, i2s1, 0);
AudioConnection          patchCord29(filter2, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=98,290
// GUItool: end automatically generated code
