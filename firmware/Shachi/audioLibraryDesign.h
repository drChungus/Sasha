#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=85,81
AudioMixer4              mixer1;         //xy=258,193
AudioMixer4              mixer2;         //xy=260,297
AudioMixer4              mixer3;         //xy=261,387
AudioMixer4              mixer4;         //xy=263,478
AudioSynthWaveformModulated waveformMod3;   //xy=437,393
AudioSynthWaveformModulated waveformMod4;   //xy=437,485
AudioSynthWaveformModulated waveformMod2;   //xy=439,303
AudioSynthWaveformModulated waveformMod1;   //xy=440,200
AudioAmplifier           amp3;           //xy=581,434
AudioAmplifier           amp4;           //xy=581,526
AudioAmplifier           amp2;           //xy=583,344
AudioAmplifier           amp1;           //xy=585,241
AudioEffectEnvelope      envelope3;      //xy=594,393
AudioEffectEnvelope      envelope4;      //xy=594,485
AudioEffectEnvelope      envelope2;      //xy=596,303
AudioEffectEnvelope      envelope1;      //xy=598,201
AudioMixer4              mixer13;        //xy=737,412
AudioMixer4              mixer14;        //xy=737,504
AudioMixer4              mixer12;        //xy=739,322
AudioMixer4              mixer11;        //xy=741,220
AudioMixer4              mixerL;         //xy=991,324
AudioMixer4              mixerR;         //xy=992,429
AudioFilterStateVariable filter2;        //xy=1149,435
AudioFilterStateVariable filter1;        //xy=1153,332
AudioOutputI2S           i2s1;           //xy=1306,383
AudioConnection          patchCord1(mixer1, 0, waveformMod1, 0);
AudioConnection          patchCord2(mixer2, 0, waveformMod2, 0);
AudioConnection          patchCord3(mixer3, 0, waveformMod3, 0);
AudioConnection          patchCord4(mixer4, 0, waveformMod4, 0);
AudioConnection          patchCord5(waveformMod3, envelope3);
AudioConnection          patchCord6(waveformMod3, amp3);
AudioConnection          patchCord7(waveformMod4, envelope4);
AudioConnection          patchCord8(waveformMod4, amp4);
AudioConnection          patchCord9(waveformMod2, envelope2);
AudioConnection          patchCord10(waveformMod2, amp2);
AudioConnection          patchCord11(waveformMod1, envelope1);
AudioConnection          patchCord12(waveformMod1, amp1);
AudioConnection          patchCord13(amp3, 0, mixer13, 1);
AudioConnection          patchCord14(amp4, 0, mixer14, 1);
AudioConnection          patchCord15(amp2, 0, mixer12, 1);
AudioConnection          patchCord16(amp1, 0, mixer11, 1);
AudioConnection          patchCord17(envelope3, 0, mixer13, 0);
AudioConnection          patchCord18(envelope4, 0, mixer14, 0);
AudioConnection          patchCord19(envelope2, 0, mixer12, 0);
AudioConnection          patchCord20(envelope1, 0, mixer11, 0);
AudioConnection          patchCord21(mixer13, 0, mixer1, 2);
AudioConnection          patchCord22(mixer13, 0, mixer2, 2);
AudioConnection          patchCord23(mixer13, 0, mixer3, 2);
AudioConnection          patchCord24(mixer13, 0, mixer4, 2);
AudioConnection          patchCord25(mixer13, 0, mixerL, 2);
AudioConnection          patchCord26(mixer13, 0, mixerR, 2);
AudioConnection          patchCord27(mixer14, 0, mixer1, 3);
AudioConnection          patchCord28(mixer14, 0, mixer2, 3);
AudioConnection          patchCord29(mixer14, 0, mixer3, 3);
AudioConnection          patchCord30(mixer14, 0, mixer4, 3);
AudioConnection          patchCord31(mixer14, 0, mixerL, 3);
AudioConnection          patchCord32(mixer14, 0, mixerR, 3);
AudioConnection          patchCord33(mixer12, 0, mixer1, 1);
AudioConnection          patchCord34(mixer12, 0, mixer3, 1);
AudioConnection          patchCord35(mixer12, 0, mixer4, 1);
AudioConnection          patchCord36(mixer12, 0, mixerL, 1);
AudioConnection          patchCord37(mixer12, 0, mixerR, 1);
AudioConnection          patchCord38(mixer12, 0, mixer2, 1);
AudioConnection          patchCord39(mixer11, 0, mixer1, 0);
AudioConnection          patchCord40(mixer11, 0, mixer2, 0);
AudioConnection          patchCord41(mixer11, 0, mixer3, 0);
AudioConnection          patchCord42(mixer11, 0, mixer4, 0);
AudioConnection          patchCord43(mixer11, 0, mixerL, 0);
AudioConnection          patchCord44(mixer11, 0, mixerR, 0);
AudioConnection          patchCord45(mixerL, 0, filter1, 0);
AudioConnection          patchCord46(mixerR, 0, filter2, 0);
AudioConnection          patchCord47(filter2, 0, i2s1, 1);
AudioConnection          patchCord48(filter1, 0, i2s1, 0);
AudioControlSGTL5000     sgtl5000_1;     //xy=1136,110
// GUItool: end automatically generated code
