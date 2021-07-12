#include "audioLibraryDesign.h"
#include "audioEngine.h"
#include "physicalLayer.h"
#include "init.h"



//#include "first256.h"


int WAVEFORMpot, VOICINGpot, INVERSIONpot, QUALITYpot, TUNEpot;
int currentWaveform, currentQuality, currentInversion, currentVoicing;
int cvIn, harmony;
double notes [4] = {0, 0, 0, 0};
double freqis[4] = {0, 0, 0, 0};

const int myInput = AUDIO_INPUT_LINEIN;



void setup() {
  // put your setup code here, to run once:
  AudioMemory(24);
  
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(1);

  //pots are:
  //  WAVEFORM
  //  VOICING
  //  INVERSION
  //  QUALITY
  //  TUNE

  initAudioEngine();
  



  //Serial.begin(115200);
  analogReadResolution(12);
}

void loop() {

  currentWaveform = map(analogRead(pot4pin), 0, 4095, 0, 5);
  currentVoicing = map(analogRead(pot6pin), 0, 4095, 0, 3);
  currentInversion = map(analogRead(pot7pin), 0, 4095, 0, 3);
  currentQuality = map(analogRead(pot8pin), 0, 4095, 0, 3);
  TUNEpot = analogRead(pot5pin);


  //cvIn = analogRead(A20);

  // Convert the analog reading:
  double voltage = readCV(ai5pin);
  int rootNote =  12 * voltage + 17  + scaleSimple(TUNEpot, 0, 4096, -24, 24);
  
  //showStat();

}


void showStat()
{
  Serial.print("Diagnostics: ");
  Serial.print(AudioProcessorUsageMax());
  Serial.print(" ");
  Serial.println(AudioMemoryUsageMax());
  AudioProcessorUsageMaxReset();
}



int harmonise (double voltage) {
  int harmony;
  voltage = voltage - (int)(voltage);
  if (voltage < 0.16) {
    harmony = 0;
  }
  else if (voltage < 0.32) {
    harmony = 1;
  }
  else if (voltage < 0.41) {
    harmony = 2;
  }
  else if (voltage < 0.57) {
    harmony = 3;
  }
  else if (voltage < 0.74) {
    harmony = 4;
  }
  else if (voltage < 0.90) {
    harmony = 5;
  }
  else if (voltage < 0) {
    harmony = 6;
  }
  else {
    //harmony = 6;
  }
  Serial.println(harmony);
  //harmony = scale(voltage,0,1,0,6);
  return harmony;
 
}


//Supported Waveforms:
//WAVEFORM_SINE
//WAVEFORM_SAWTOOTH
//WAVEFORM_SAWTOOTH_REVERSE
//WAVEFORM_SQUARE
//WAVEFORM_TRIANGLE
//WAVEFORM_TRIANGLE_VARIABLE
//WAVEFORM_PULSE
//WAVEFORM_SAMPLE_HOLD
