double phaseAmt = 360.0;



void setAlgorithm(int algorithmCode){

	for (int i = 0; i < 4; ++i)	
	{
		mixer1.gain(i,getBit(algorithmCode,i));			//channel, gain
	}
	for (int i = 0; i < 4; ++i)	
	{
		mixer2.gain(i,getBit(algorithmCode,i+4));			//channel, gain
	}
	for (int i = 0; i < 4; ++i)	
	{
		mixer3.gain(i,getBit(algorithmCode,i+8));			//channel, gain
	}
	for (int i = 0; i < 4; ++i)	
	{
		mixer4.gain(i,getBit(algorithmCode,i+12));			//channel, gain
	}
	for (int i = 0; i < 4; ++i)	
	{
		mixerL.gain(i,getBit(algorithmCode,i)+16);			//channel, gain
	}
	for (int i = 0; i < 4; ++i)	
	{
		mixerR.gain(i,getBit(algorithmCode,i)+20);			//channel, gain
	}
	
}

void initializeAudioEngine(){
	waveformMod1.begin(1,50,WAVEFORM_SINE);
	waveformMod2.begin(1,50,WAVEFORM_SINE);
	waveformMod3.begin(1,50,WAVEFORM_SINE);
	waveformMod4.begin(1,50,WAVEFORM_SINE);
	waveformMod1.phaseModulation(phaseAmt);
	waveformMod2.phaseModulation(phaseAmt);
	waveformMod3.phaseModulation(phaseAmt);
	waveformMod4.phaseModulation(phaseAmt);
}


void updateLevel(frontPanel myPanels[], int myPage){
	waveformMod1.amplitude(myPanels[1].pot3);
	waveformMod2.amplitude(myPanels[2].pot3);
	waveformMod3.amplitude(myPanels[3].pot3);
	waveformMod4.amplitude(myPanels[4].pot3);
}

void updateWaveform(frontPanel myPanels[], int myPage){

}
