double phaseAmt = 720.0;
double baseFreq = 50;
int octaveSwitch = 0;
double  multiplierLUT [16] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};

void initializeAudioEngine(){
	waveformMod1.begin(1,50,WAVEFORM_SINE);
	waveformMod2.begin(1,50,WAVEFORM_SINE);

  waveformMod1.arbitraryWaveform(wave_type[0],420);
  waveformMod2.arbitraryWaveform(wave_type[0],420);

  /*waveformMod1.begin(1,50,WAVEFORM_SINE);
  waveformMod2.begin(1,50,WAVEFORM_SINE);
  waveformMod3.begin(1,50,WAVEFORM_SINE);
  waveformMod4.begin(1,50,WAVEFORM_SINE);*/
  
	waveformMod1.phaseModulation(phaseAmt);
	waveformMod2.phaseModulation(phaseAmt);

  amp1.gain(0);
  amp2.gain(0);
  dc1.amplitude(1);

  envelope1.attack(1);
  envelope1.hold(0);
  envelope1.sustain(0);
  //envelope1.release(0);
   envelope2.attack(1);
  envelope2.hold(0);
  envelope2.sustain(0);
  //envelope2.release(0);
   envelope3.attack(1);
  envelope3.hold(0);
  envelope3.sustain(0);
  //envelope3.release(0);
  
  
}



/*
// CV input goes like:
// value = Pot + modPot * CV
void updateLevel(frontPanel levelPanel, frontPanel levelModPanel, int myPage){
  waveformMod1.amplitude(scaleSimple(levelPanel.pot4,0,255,0,1) + scaleSimple(levelModPanel.pot4,0,255,0,1)*readModCV(ai1pin) ); //need more tactile on levels! 
  waveformMod2.amplitude(scaleSimple(levelPanel.pot6,0,255,0,1) + scaleSimple(levelModPanel.pot6,0,255,0,1)*readModCV(ai2pin) );
  waveformMod3.amplitude(scaleSimple(levelPanel.pot7,0,255,0,1) + scaleSimple(levelModPanel.pot7,0,255,0,1)*readModCV(ai3pin) );
  waveformMod4.amplitude(scaleSimple(levelPanel.pot8,0,255,0,1) + scaleSimple(levelModPanel.pot8,0,255,0,1)*readModCV(ai4pin) );
  //Serial.println("Level Update completed");
}

void updateFreq (frontPanel ratioPanel, frontPanel ratioModPanel, int myPage){
  baseFreq = 130.8 * pow(2,readCV(ai5pin)+scaleSimple(analogRead(pot5pin),0,4095,-2,2)); //+pot detune Corse, Fine maybe??
  //baseFreq =50;
  waveformMod1.frequency(baseFreq * (multiplierLUT[(int)scaleSimple(ratioPanel[4] + ratioModPanel[4]*readModCV(ai1pin),0,256,0,15)]));
  waveformMod2.frequency(baseFreq * (multiplierLUT[(int)scaleSimple(ratioPanel[6] + ratioModPanel[6]*readModCV(ai2pin),0,256,0,15)]));
  waveformMod3.frequency(baseFreq * (multiplierLUT[(int)scaleSimple(ratioPanel[7] + ratioModPanel[7]*readModCV(ai3pin),0,256,0,15)]));
  waveformMod4.frequency(baseFreq * (multiplierLUT[(int)scaleSimple(ratioPanel[8] + ratioModPanel[8]*readModCV(ai4pin),0,256,0,15)]));  
  //Serial.println("Frequency Update completed");
}

void updateWaveform(frontPanel waveformPanel, frontPanel waveformModPanel, int myPage){
  //Serial.print("Starting Waveform Upadate:  ");
  //Serial.println((int)scaleLimited(waveformPanel[4] + waveformModPanel[4]*readModCV(ai1pin),0,256,0,6));
  waveformMod1.arbitraryWaveform(wave_type[(int)scaleLimited(waveformPanel[4] + waveformModPanel[4]*readModCV(ai1pin),0,256,0,10)], 420);
  waveformMod2.arbitraryWaveform(wave_type[(int)scaleLimited(waveformPanel[6] + waveformModPanel[6]*readModCV(ai2pin),0,256,0,10)], 420);
  waveformMod3.arbitraryWaveform(wave_type[(int)scaleLimited(waveformPanel[7] + waveformModPanel[7]*readModCV(ai3pin),0,256,0,10)], 420);
  waveformMod4.arbitraryWaveform(wave_type[(int)scaleLimited(waveformPanel[8] + waveformModPanel[8]*readModCV(ai4pin),0,256,0,10)], 420);
 }
*/
void updateFilter(frontPanel myFrontPanel){  
  filter1.frequency(scaleSimple(myFrontPanel[3],0,255,100,7500));
  filter2.frequency(scaleSimple(myFrontPanel[3],0,255,100,7500));
}

void updateIndex(frontPanel myFrontPanel){  
  waveformMod1.amplitude(scaleSimple(myFrontPanel[7],0,255,0,1) /* + scaleSimple(myFrontPanel[5],0,255,0,1)*readModCV(ai2pin) */);
  dc1.amplitude( scaleSimple(myFrontPanel[8],0,255,-1,1) );
}

void updateShape(frontPanel myFrontPanel){  
  //waveformMod1.arbitraryWaveform(wave_type[(int)scaleLimited(myFrontPanel[6] + myFrontPanel[8]*readModCV(ai3pin),0,256,0,10)], 420);
  //waveformMod2.arbitraryWaveform(wave_type[(int)scaleLimited(myFrontPanel[6] + myFrontPanel[8]*readModCV(ai3pin),0,256,0,10)], 420);
}

void updateFrequency(frontPanel myFrontPanel){  
  baseFreq = 32.7 * pow(2,readCV(ai5pin)+scaleSimple(analogRead(pot2pin),0,4095,-0.5,0.5)) * pow(2,octaveSwitch); //+pot detune Corse, Fine maybe??
  waveformMod1.frequency(baseFreq * (multiplierLUT[(int)scaleSimple(myFrontPanel[1] /* + myFrontPanel[7]*readModCV(ai1pin)*/,0,256,0,15)]));
  waveformMod2.frequency(baseFreq /** (multiplierLUT[(int)scaleSimple(ratioPanel[6] + ratioModPanel[6]*readModCV(ai2pin),0,256,0,15)])*/);
}
void triggerEnvelopes(){
  envelope1.noteOn();
  envelope2.noteOn();
  envelope3.noteOn();
}

void updateEnvelopes(frontPanel myFrontPanel){
  envelope1.decay( scaleSimple(myFrontPanel[4],0,255,0,2000) );
  envelope2.decay( scaleSimple(myFrontPanel[5],0,255,0,2000) );
  envelope3.decay( scaleSimple(myFrontPanel[6],0,255,0,2000) );
}
