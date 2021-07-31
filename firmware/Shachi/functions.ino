frontPanel currentFrontPanel, previousFrontPanel;
struct frontPanel myFrontPanels[8];

bool previousTriggerState, currentTriggerState;



void initFrontPanels (frontPanel myFrontPanels[]){
  for(int i=0; i<6; i++){
    myFrontPanels[i].pot4 = 0;
    myFrontPanels[i].pot5 = 0;
    myFrontPanels[i].pot6 = 0;
    myFrontPanels[i].pot7 = 0;
    myFrontPanels[i].pot8 = 0;
  }
}

frontPanel readFrontPanel(){
  frontPanel currentFrontPanel;
  currentFrontPanel.pot1 = map(analogRead(pot1pin),0,4095,0,255);
  currentFrontPanel.pot2 = map(analogRead(pot2pin),0,4095,0,255);
  currentFrontPanel.pot3 = map(analogRead(pot3pin),0,4095,0,255);
  currentFrontPanel.pot4 = map(analogRead(pot4pin),0,4095,0,255);
  currentFrontPanel.pot5 = map(analogRead(pot5pin),0,4095,0,255);
  currentFrontPanel.pot6 = map(analogRead(pot6pin),0,4095,0,255);
  currentFrontPanel.pot7 = map(analogRead(pot7pin),0,4095,0,255);
  currentFrontPanel.pot8 = map(analogRead(pot8pin),0,4095,0,255);
  currentFrontPanel.button1 = !digitalRead(button1pin);
  currentFrontPanel.button2 = !digitalRead(button2pin);
  currentFrontPanel.button3 = !digitalRead(button3pin);
  currentFrontPanel.cv1 = map(analogRead(ai1pin),0,4095,255,-255);
  currentFrontPanel.cv2 = map(analogRead(ai2pin),0,4095,255,-255);
  currentFrontPanel.cv3 = map(analogRead(ai3pin),0,4095,255,-255);
  currentFrontPanel.cv4 = map(analogRead(ai4pin),0,4095,255,-255);  
  //Serial.println(currentFrontPanel.cv1);
  return currentFrontPanel;
  normalizationTest();
};

int searchStructDiffIndex (frontPanel s1, frontPanel s2){
    int diffIndex = -1;
    for (int i = 0; i < 9; ++i) //check Pots /////1 only!!!
    {
      if( abs(s1[i] - s2[i]) > potTolerance){
        diffIndex = i; //this indexin works, but it is shady AF
      };
    }    
    for (int i = 1; i < 4; ++i) //CheckButtons
    {
      if(s1(i*10) != s2(i*10)){
        diffIndex = frontPanelIndexCatalog[i+7];
      };
    }
    return diffIndex;
};

int showStructValue (frontPanel thisPanel, int diffIndex){
  int Value;
  if (diffIndex < 10){
    Value = thisPanel[diffIndex];
  }
  else {
    Value= thisPanel(diffIndex);
  }
  return Value;
};

void updateLEDs(byte colorCode){
  led4.setColor(colorCode & 0b11);    //led colors encoded in one byte, MSB to LSB order
  led3.setColor((colorCode & 0b1100)>>2);
  led2.setColor((colorCode & 0b110000)>>4);
  led1.setColor((colorCode & 0b11000000)>>6);
  led1.drive();
  led2.drive();
  led3.drive();
  led4.drive();
}
double readCV(int pin){
  double sum = 0;
  for (int i=0; i<10; i++){ ///use 10000 samples for calibration and do every voltage! It makes sense to check the voltage source with a high precision meter, as the reference can also be off!
    sum+=analogRead(pin);
  }
  double dataValue = sum/10;
  dataValue = (dataValue-3149.1) / -409;
  return dataValue;  
}
double readModCV(int pin){
  double result;
  result = scaleSimple(analogRead(pin),0,4095,1,-1);  //note that modulation CV ins are not calibrated here
  return result;
}

int getBit(int code, int posi){ //LSB based
  int masked= ( code & (0b01<<posi) ) >> posi;
  return masked;
}

void fpEventHandler(){
  currentFrontPanel = readFrontPanel();

  currentTriggerState = ttlLogic(currentFrontPanel.cv1, 64, 26);
  triggerDetector (previousTriggerState, currentTriggerState);
  previousTriggerState = currentTriggerState;
  
  int diffIndex = searchStructDiffIndex(previousFrontPanel, currentFrontPanel);  
  if (diffIndex != -1){
    int newValue = showStructValue(currentFrontPanel, diffIndex);
    Serial.print("Difference at index ");Serial.print(diffIndex);
    Serial.print(" New value: ");Serial.println(newValue);
    if ((currentFrontPanel.button1 > previousFrontPanel.button1) && (octaveSwitch < 5))
    {
      octaveSwitch++;
      EEPROM.put(0,octaveSwitch);
    }
    if ((currentFrontPanel.button3 > previousFrontPanel.button3) && (octaveSwitch > 1))
    {
      octaveSwitch--;
      EEPROM.put(0,octaveSwitch);
    }
    if ((currentFrontPanel.button2 > previousFrontPanel.button2))
    {
      triggerEnvelopes();
    }
    if(diffIndex == 1){

    }
    //Serial.println(frontPanelPage); 
    else{updateLEDs(fpLedPageLut[frontPanelPage]);}
    if (diffIndex > 3 && diffIndex < 10)
    {
      myFrontPanels[frontPanelPage][diffIndex] = currentFrontPanel[diffIndex];
      //Serial.println(myFrontPanels[frontPanelPage][diffIndex]);
    }

    //updateLevel(currentFrontPanel, frontPanelPage);
    previousFrontPanel = currentFrontPanel;
  }
  //updateLevel(myFrontPanels[1], myFrontPanels[4], frontPanelPage);  //this pot depends on what page is selected, but updated based with cv too!
  //updateFreq(myFrontPanels[2], myFrontPanels[5], frontPanelPage);   //this pot depends on what page is selected, but updated based with cv too!
  //updateWaveform(myFrontPanels[3], myFrontPanels[6], frontPanelPage); //
  
  updateFilter(currentFrontPanel); 
  updateIndex(currentFrontPanel);
  updateShape(currentFrontPanel);
  updateFrequency(currentFrontPanel);
  updateEnvelopes(currentFrontPanel);
  
}

double scaleSimple(double x, double in_min, double in_max, double out_min, double out_max)
{
  double unlimitedOut;
  unlimitedOut = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return unlimitedOut;
}

double scaleLimited(double x, double in_min, double in_max, double out_min, double out_max)
{
  double limitedOut;
  limitedOut = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  if (limitedOut > out_max){
    limitedOut = out_max;
  }
  else if ( limitedOut < out_min){
    limitedOut = out_min;
  }
  return limitedOut;
}

void saveParams(int eeAddress, frontPanel customVar[]){
  for (int i=0; i < 8; i++){
    //EEPROM.put(eeAddress+i, customVar[i]);
  }  
}
 
void loadParams(int eeAddress, frontPanel customVar[]){
  for (int i=0; i < 8; i++){
    Serial.println("Started EEPROM panel Read");
    //EEPROM.get(eeAddress+i, customVar[i]);
  }
}

void initFromMemory(){
  
}
void normalizationTest (){
  digitalWrite(normalizationPin,HIGH);
  if (digitalRead(ai1pin)){
    currentFrontPanel(11) = false; //false = open connection, unplugged
  }
  else{
    digitalWrite(normalizationPin,LOW);
    if (!digitalRead(ai1pin)){
    currentFrontPanel(11) = false; //false = open connection, unplugged
    }
  }
  //Serial.println(currentFrontPanel(11));
  
}

bool ttlLogic(int currentValue, int limitHigh, int limitLow){
  bool result;
  if (currentValue > limitHigh){
    result = true;
    //Serial.println("TRUE");
  }
  else if (currentValue < limitLow){
    result = false;
    //Serial.println("FALSE");
  }
  else {
    //Serial.println("none");
    result = false;
  }  
  return result;
}

void triggerDetector (bool previousState, bool currentState){
  if (previousState < currentState){
    triggerEnvelopes();    
  }
  else if (previousState > currentState){
    
  }
  else {
    
  }  
}

void waveshapeInit(){
  waveshapeBase[0] = -1;
  for (int i = 0; i < 129; i++){
    waveshapeBase[i+1] = waveshapeBase[i] +  0.015625; //Fill in WaveshapeBase array with 129 values between -1 to +1
    Serial.println(waveshapeBase[i]);  
  }
}
  
void waveshaperUpdate(double waveshaperCoefficient){
  for (int i = 0; i < 129; i++){
    waveshape1Array[i] = 1-2/(1+exp(2*waveshapeBase[i]* waveshaperCoefficient));   //tanh(x) = 1-2/(1+exp(2*x)) = (exp(2*x)-1)/(exp(2*x)+1)
  }
}
