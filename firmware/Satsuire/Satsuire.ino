#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SerialFlash.h>
#include "structure.h"
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
  sgtl5000_1.volume(0.8);

  //pots are:
  //  WAVEFORM
  //  VOICING
  //  INVERSION
  //  QUALITY
  //  TUNE

  voice1.begin(WAVEFORM_SINE);
  voice1.amplitude(1);
  voice1.pulseWidth(0.5);
  voice2.begin(WAVEFORM_SINE);
  voice2.amplitude(1);
  voice2.pulseWidth(0.5);
  voice3.begin(WAVEFORM_SINE);
  voice3.amplitude(1);
  voice3.pulseWidth(0.5);
  voice4.begin(WAVEFORM_SINE);
  voice4.amplitude(1);
  voice4.pulseWidth(0.5);

  for (int i = 0; i < 4; i++) {
    mixer.gain(i, 0.25);
  }

  Serial.begin(9600);
}

void loop() {

  currentWaveform = map(analogRead(A14), 0, 1004, 0, 5);
  currentVoicing = map(analogRead(A15), 0, 1007, 0, 3);
  currentInversion = map(analogRead(A16), 0, 1001, 0, 3);
  currentQuality = map(analogRead(A18), 0, 1010, 0, 3);
  TUNEpot = analogRead(A17);


  cvIn = analogRead(A20);

  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 3.3V):
  double voltage = cvIn * (3.3 / 1023.0);
  int rootNote =  12 * voltage + 17  + scale(TUNEpot, 0, 1000, -24, 24);
  if (analogRead(A18)>1004){
    currentQuality = harmonization[0][harmonise(voltage)];
  }

  for (int i = 0; i < 4; i++) {
    notes [i] = rootNote + quality[currentQuality][i] + inversion[currentInversion][i] + voicing[currentVoicing][i];
    //Serial.print(notes [i]); Serial.print(" ");
  }
  //Serial.println();

  for (int i = 0; i < 4; i++) {
    //notes[i] = round(notes[i]);
    freqis[i] = pow (2, ((notes[i] - 41 ) / 12 ) ) * 440 ;

  }

  setWaveforms(currentWaveform);

  voice1.frequency(freqis[1]);
  voice2.frequency(freqis[2]);
  voice3.frequency(freqis[3]);
  voice4.frequency(freqis[4]);

  //showStat();

}

double scale(double x, double in_min, double in_max, double out_min, double out_max)
{
  double limitedOut;
  limitedOut = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  if (limitedOut > out_max) {
    limitedOut = out_max;
  }
  if (limitedOut < out_min) {
    limitedOut = out_min;
  }
  return limitedOut;
}
double scaleSimple(double x, double in_min, double in_max, double out_min, double out_max)
{
  double limitedOut;
  limitedOut = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return limitedOut;
}

void showStat()
{
  Serial.print("Diagnostics: ");
  Serial.print(AudioProcessorUsageMax());
  Serial.print(" ");
  Serial.println(AudioMemoryUsageMax());
  AudioProcessorUsageMaxReset();
}

void setWaveforms(int select) {
  switch (select) {
    case 0:   //SINE
      voice1.begin(WAVEFORM_SINE);
      voice1.pulseWidth(0.5);
      voice2.begin(WAVEFORM_SINE);
      voice2.pulseWidth(0.5);
      voice3.begin(WAVEFORM_SINE);
      voice3.pulseWidth(0.5);
      voice4.begin(WAVEFORM_SINE);
      voice4.pulseWidth(0.5);
      break;
    case 1:   //TRIANNGLE
      voice1.begin(WAVEFORM_TRIANGLE);
      voice1.pulseWidth(0.5);
      voice2.begin(WAVEFORM_TRIANGLE);
      voice2.pulseWidth(0.5);
      voice3.begin(WAVEFORM_TRIANGLE);
      voice3.pulseWidth(0.5);
      voice4.begin(WAVEFORM_TRIANGLE);
      voice4.pulseWidth(0.5);
      break;
    case 2:   //SAWTOOTH
      voice1.begin(WAVEFORM_SAWTOOTH);
      voice1.pulseWidth(0.5);
      voice2.begin(WAVEFORM_SAWTOOTH);
      voice2.pulseWidth(0.5);
      voice3.begin(WAVEFORM_SAWTOOTH);
      voice3.pulseWidth(0.5);
      voice4.begin(WAVEFORM_SAWTOOTH);
      voice4.pulseWidth(0.5);
      break;
    case 3:   //50%
      voice1.begin(WAVEFORM_SQUARE);
      voice1.pulseWidth(0.5);
      voice2.begin(WAVEFORM_SQUARE);
      voice2.pulseWidth(0.5);
      voice3.begin(WAVEFORM_SQUARE);
      voice3.pulseWidth(0.5);
      voice4.begin(WAVEFORM_SQUARE);
      voice4.pulseWidth(0.5);
      break;
    case 4:   //25%
      voice1.begin(WAVEFORM_PULSE);
      voice1.pulseWidth(0.25);
      voice2.begin(WAVEFORM_PULSE);
      voice2.pulseWidth(0.25);
      voice3.begin(WAVEFORM_PULSE);
      voice3.pulseWidth(0.25);
      voice4.begin(WAVEFORM_PULSE);
      voice4.pulseWidth(0.25);
      break;
    case 5:   //12,5%
      voice1.begin(WAVEFORM_PULSE);
      voice1.pulseWidth(0.125);
      voice2.begin(WAVEFORM_PULSE);
      voice2.pulseWidth(0.125);
      voice3.begin(WAVEFORM_PULSE);
      voice3.pulseWidth(0.125);
      voice4.begin(WAVEFORM_PULSE);
      voice4.pulseWidth(0.125);
      break;
  }
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
