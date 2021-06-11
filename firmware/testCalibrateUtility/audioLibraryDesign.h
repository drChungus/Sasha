#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=79.00569152832031,43.0056848526001
AudioMixer4              mixer3; //xy=272.0000419616699,349.0000329017639
AudioMixer4              mixer4; //xy=272.0000419616699,441.0000329017639
AudioMixer4              mixer2; //xy=274.0000419616699,259.0000329017639
AudioMixer4              mixer1; //xy=275.0057029724121,156.64207696914673
AudioSynthWaveformModulated waveformMod3; //xy=431,355
AudioSynthWaveformModulated waveformMod4; //xy=431,447
AudioSynthWaveformModulated waveformMod2; //xy=433,265
AudioSynthWaveformModulated waveformMod1; //xy=434.0056610107422,162.6420440673828
AudioAmplifier           amp3; //xy=575.9999198913574,396.0909376144409
AudioAmplifier           amp4; //xy=575.9999198913574,488.0909376144409
AudioAmplifier           amp2; //xy=577.9999198913574,306.0909376144409
AudioAmplifier           amp1;           //xy=579.0055809020996,203.73298168182373
AudioEffectEnvelope      envelope3; //xy=588.9999847412109,355.9999942779541
AudioEffectEnvelope      envelope4; //xy=588.9999847412109,447.9999942779541
AudioEffectEnvelope      envelope2; //xy=590.9999847412109,265.9999942779541
AudioEffectEnvelope      envelope1; //xy=592.0056457519531,163.6420383453369
AudioMixer4              mixer13; //xy=731.9998931884766,374.90916442871094
AudioMixer4              mixer14;  //xy=731.9998931884766,466.90916442871094
AudioMixer4              mixer12; //xy=733.9998931884766,284.90916442871094
AudioMixer4              mixer11;         //xy=735.0055541992188,182.55120849609375
AudioMixer4              mixerL;         //xy=985.0056381225586,286.0056800842285
AudioMixer4              mixerR; //xy=986.0055541992188,391.00567626953125
AudioOutputI2S           i2s1;           //xy=1149.0058059692383,341.00567054748535
AudioConnection          patchCord1(mixer3, 0, waveformMod3, 0);
AudioConnection          patchCord2(mixer4, 0, waveformMod4, 0);
AudioConnection          patchCord3(mixer2, 0, waveformMod2, 0);
AudioConnection          patchCord4(mixer1, 0, waveformMod1, 0);
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
AudioConnection          patchCord34(mixer12, 0, mixer2, 1);
AudioConnection          patchCord35(mixer12, 0, mixer3, 1);
AudioConnection          patchCord36(mixer12, 0, mixer4, 1);
AudioConnection          patchCord37(mixer12, 0, mixerL, 1);
AudioConnection          patchCord38(mixer12, 0, mixerR, 1);
AudioConnection          patchCord39(mixer11, 0, mixer1, 0);
AudioConnection          patchCord40(mixer11, 0, mixer2, 0);
AudioConnection          patchCord41(mixer11, 0, mixer3, 0);
AudioConnection          patchCord42(mixer11, 0, mixer4, 0);
AudioConnection          patchCord43(mixer11, 0, mixerL, 0);
AudioConnection          patchCord44(mixer11, 0, mixerR, 0);
AudioConnection          patchCord45(mixerL, 0, i2s1, 0);
AudioConnection          patchCord46(mixerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1130.0057830810547,72.00001335144043
// GUItool: end automatically generated code
