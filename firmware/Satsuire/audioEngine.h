void initAudioEngine(){
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
    mixer.gain(i, 0.2);
  }
}
