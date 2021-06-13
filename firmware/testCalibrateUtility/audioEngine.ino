double phaseAmt = 360.0;



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

void initializeAudioEngine(){
	waveformMod1.begin(1,50,WAVEFORM_SINE);
	waveformMod2.begin(1,50,WAVEFORM_SINE);
	waveformMod3.begin(1,50,WAVEFORM_SINE);
	waveformMod4.begin(1,50,WAVEFORM_SINE);
	waveformMod1.phaseModulation(phaseAmt);
	waveformMod2.phaseModulation(phaseAmt);
	waveformMod3.phaseModulation(phaseAmt);
	waveformMod4.phaseModulation(phaseAmt);
  amp1.gain(1);
  amp2.gain(1);
  amp3.gain(1);
  amp4.gain(1);
  /*for (int i=0; i<4; i++){
    mixer11.gain(i,1);
  }
  for (int i=0; i<4; i++){
    mixer12.gain(i,1);
  }
  for (int i=0; i<4; i++){
    mixer13.gain(i,1);
  }
  for (int i=0; i<4; i++){
    mixer14.gain(i,1);
  }*/
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


void updateLevel(frontPanel myPanels[], int myPage){
	waveformMod1.amplitude(scaleSimple(myPanels[1].pot3,0,255,0,1));
	waveformMod2.amplitude(scaleSimple(myPanels[2].pot3,0,255,0,1));
	waveformMod3.amplitude(scaleSimple(myPanels[3].pot3,0,255,0,1));
	waveformMod4.amplitude(scaleSimple(myPanels[4].pot3,0,255,0,1));
}

void updateWaveform(frontPanel myPanels[], int myPage){

}
