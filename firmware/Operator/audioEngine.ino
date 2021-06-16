double phaseAmt = 720.0;
double baseFreq = 50;
int currentAlgorithm = 0;
double  multiplierLUT [16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void initializeAudioEngine(){
	waveformMod1.begin(1,50,WAVEFORM_SINE);
	waveformMod2.begin(1,50,WAVEFORM_SINE);
	waveformMod3.begin(1,50,WAVEFORM_SINE);
	waveformMod4.begin(1,50,WAVEFORM_SINE);
  /*
  waveformMod1.begin(1,50,WAVEFORM_SINE);
  waveformMod2.begin(1,50,WAVEFORM_SINE);
  waveformMod3.begin(1,50,WAVEFORM_SINE);
  waveformMod4.begin(1,50,WAVEFORM_SINE);
  */
	waveformMod1.phaseModulation(phaseAmt);
	waveformMod2.phaseModulation(phaseAmt);
	waveformMod3.phaseModulation(phaseAmt);
	waveformMod4.phaseModulation(phaseAmt);
  amp1.gain(1);
  amp2.gain(1);
  amp3.gain(1);
  amp4.gain(1);
  for (int i=0; i<4; i++){
    mixer1.gain(i,0);
  }
  for (int i=0; i<4; i++){
    mixer2.gain(i,0);
  }
  for (int i=0; i<4; i++){
    mixer3.gain(i,0);
  }
  for (int i=0; i<4; i++){
    mixer4.gain(i,0);
  }
  for (int i=0; i<4; i++){
    mixerL.gain(i,0);
  }
  for (int i=0; i<4; i++){
    mixerR.gain(i,0);
  }
  
}

void setAlgorithm(int algorithmCode){	//Algorith code is 0b000, where mixer gains are stored in binary 
	for (int i = 0; i < 4; ++i)	
	{
	 mixer1.gain(i, getBit(algorithmCode,23-i));			//channel, gain
   Serial.print(getBit(algorithmCode,23-i));
	}
	for (int i = 0; i < 4; ++i)	
	{
	 mixer2.gain(i,getBit(algorithmCode,19-i));			//channel, gain
   Serial.print(getBit(algorithmCode,19-i));
	}
	for (int i = 0; i < 4; ++i)	
	{
	 mixer3.gain(i,getBit(algorithmCode,15-i));			//channel, gain
   Serial.print(getBit(algorithmCode,15-i));
	}
	for (int i = 0; i < 4; ++i)	
	{
	 mixer4.gain(i,getBit(algorithmCode,11-i));			//channel, gain
   Serial.print(getBit(algorithmCode,11-i));
	}
	for (int i = 0; i < 4; ++i)	
	{
	 mixerL.gain(i,getBit(algorithmCode,7-i));			//channel, gain
   Serial.print(getBit(algorithmCode,7-i));
	}
	for (int i = 0; i < 4; ++i)	
	{
   mixerR.gain(i,getBit(algorithmCode,3-i));        //channel, gain
   Serial.print(getBit(algorithmCode,3-i));
	}	
  Serial.println();
}

void updateLevel(frontPanel levelPanel, int myPage){
  waveformMod1.amplitude(scaleSimple(levelPanel.pot4,0,255,0,1) + readModCV(ai1pin)); //need more tactile on levels! 
  waveformMod2.amplitude(scaleSimple(levelPanel.pot6,0,255,0,1) + readModCV(ai2pin));
  waveformMod3.amplitude(scaleSimple(levelPanel.pot7,0,255,0,1) + readModCV(ai3pin));
  waveformMod4.amplitude(scaleSimple(levelPanel.pot8,0,255,0,1) + readModCV(ai4pin));
}

void updateWaveform(frontPanel myPanels[], int myPage){
  
}

void updateFreq (frontPanel ratioPanel, int myPage){
  baseFreq = 130.8 * pow(2,readCV(ai5pin)+scaleSimple(analogRead(pot5pin),0,4095,-2,2)); //+pot detune Corse, Fine maybe??
  //baseFreq =50;
  waveformMod1.frequency(baseFreq*multiplierLUT[map(ratioPanel[1],0,256,0,15)]);
  waveformMod2.frequency(baseFreq*multiplierLUT[map(ratioPanel[2],0,256,0,15)]);
  waveformMod3.frequency(baseFreq*multiplierLUT[map(ratioPanel[3],0,256,0,15)]);
  waveformMod4.frequency(baseFreq*multiplierLUT[map(ratioPanel[4],0,256,0,15)]);  
}