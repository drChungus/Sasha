#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioInputI2S            i2s2;           //xy=79.00569152832031,43.0056848526001
AudioMixer4              mixer1;         //xy=378.0056953430176,79.00563669204712
AudioMixer4              mixer2; //xy=380.0056953430176,245.00570917129517
AudioMixer4              mixer3; //xy=381.0057182312012,412.00570917129517
AudioMixer4              mixer4; //xy=382.0057182312012,559.0057091712952
AudioSynthWaveformDc     dc1;            //xy=399.0056571960449,146.00563287734985
AudioSynthWaveformDc     dc2; //xy=401.0056571960449,312.0057053565979
AudioSynthWaveformDc     dc3; //xy=402.0056800842285,479.0057053565979
AudioSynthWaveformDc     dc4; //xy=403.0056800842285,626.0057053565979
AudioSynthWaveformModulated waveformMod1;   //xy=537.0056533813477,85.0056037902832
AudioSynthWaveformModulated waveformMod2; //xy=539.0056533813477,251.00567626953125
AudioSynthWaveformModulated waveformMod3; //xy=540.0056762695312,418.00567626953125
AudioSynthWaveformModulated waveformMod4; //xy=541.0056762695312,565.0056762695312
AudioEffectEnvelope      envelope1;      //xy=554.0056457519531,146.0055947303772
AudioEffectEnvelope      envelope2; //xy=556.0056457519531,312.00566720962524
AudioEffectEnvelope      envelope3; //xy=557.0056686401367,479.00566720962524
AudioEffectEnvelope      envelope4; //xy=558.0056686401367,626.0056672096252
AudioEffectMultiply      multiply1;      //xy=713.0056533813477,127.005606174469
AudioEffectMultiply      multiply2; //xy=715.0056533813477,293.00567865371704
AudioEffectMultiply      multiply3; //xy=716.0056762695312,460.00567865371704
AudioEffectMultiply      multiply4; //xy=717.0056762695312,607.005678653717
AudioMixer4              mixerL;         //xy=985.0056610107422,307.005672454834
AudioMixer4              mixerR; //xy=986.0055770874023,412.0056686401367
AudioOutputI2S           i2s1;           //xy=1149.0058288574219,362.0056629180908
AudioConnection          patchCord1(mixer1, 0, waveformMod1, 0);
AudioConnection          patchCord2(mixer2, 0, waveformMod2, 0);
AudioConnection          patchCord3(mixer3, 0, waveformMod3, 0);
AudioConnection          patchCord4(mixer4, 0, waveformMod4, 0);
AudioConnection          patchCord5(dc1, envelope1);
AudioConnection          patchCord6(dc2, envelope2);
AudioConnection          patchCord7(dc3, envelope3);
AudioConnection          patchCord8(dc4, envelope4);
AudioConnection          patchCord9(waveformMod1, 0, multiply1, 0);
AudioConnection          patchCord10(waveformMod2, 0, multiply2, 0);
AudioConnection          patchCord11(waveformMod3, 0, multiply3, 0);
AudioConnection          patchCord12(waveformMod4, 0, multiply4, 0);
AudioConnection          patchCord13(envelope1, 0, multiply1, 1);
AudioConnection          patchCord14(envelope2, 0, multiply2, 1);
AudioConnection          patchCord15(envelope3, 0, multiply3, 1);
AudioConnection          patchCord16(envelope4, 0, multiply4, 1);
AudioConnection          patchCord17(multiply1, 0, mixer1, 0);
AudioConnection          patchCord18(multiply1, 0, mixer2, 0);
AudioConnection          patchCord19(multiply1, 0, mixer3, 0);
AudioConnection          patchCord20(multiply1, 0, mixer4, 0);
AudioConnection          patchCord21(multiply1, 0, mixerL, 0);
AudioConnection          patchCord22(multiply1, 0, mixerR, 0);
AudioConnection          patchCord23(multiply2, 0, mixer1, 1);
AudioConnection          patchCord24(multiply2, 0, mixer2, 1);
AudioConnection          patchCord25(multiply2, 0, mixer3, 1);
AudioConnection          patchCord26(multiply2, 0, mixer4, 1);
AudioConnection          patchCord27(multiply2, 0, mixerL, 1);
AudioConnection          patchCord28(multiply2, 0, mixerR, 1);
AudioConnection          patchCord29(multiply3, 0, mixer1, 2);
AudioConnection          patchCord30(multiply3, 0, mixer2, 2);
AudioConnection          patchCord31(multiply3, 0, mixer3, 2);
AudioConnection          patchCord32(multiply3, 0, mixer4, 2);
AudioConnection          patchCord33(multiply3, 0, mixerL, 2);
AudioConnection          patchCord34(multiply3, 0, mixerR, 2);
AudioConnection          patchCord35(multiply4, 0, mixer1, 3);
AudioConnection          patchCord36(multiply4, 0, mixer2, 3);
AudioConnection          patchCord37(multiply4, 0, mixer3, 3);
AudioConnection          patchCord38(multiply4, 0, mixer4, 3);
AudioConnection          patchCord39(multiply4, 0, mixerL, 3);
AudioConnection          patchCord40(multiply4, 0, mixerR, 3);
AudioConnection          patchCord41(mixerL, 0, i2s1, 0);
AudioConnection          patchCord42(mixerR, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=1130.0057830810547,72.00001335144043
// GUItool: end automatically generated code
