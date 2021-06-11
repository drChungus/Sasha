frontPanel currentFrontPanel, previousFrontPanel;
frontPanel[6] myFrontPanels;
int frontPanelPage;

frontPanel readFrontPanel(){
  frontPanel currentFrontPanel;
  currentFrontPanel.pot1 = map(analogRead(pot1pin),0,1023,0,255);
  currentFrontPanel.pot2 = map(analogRead(pot2pin),0,1023,0,255);
  currentFrontPanel.pot3 = map(analogRead(pot3pin),0,1023,0,255);
  currentFrontPanel.pot4 = map(analogRead(pot4pin),0,1023,0,255);
  currentFrontPanel.pot5 = map(analogRead(pot5pin),0,1023,0,255);
  currentFrontPanel.pot6 = map(analogRead(pot6pin),0,1023,0,255);
  currentFrontPanel.pot7 = map(analogRead(pot7pin),0,1023,0,255);
  currentFrontPanel.pot8 = map(analogRead(pot8pin),0,1023,0,255);
  currentFrontPanel.button1 = !digitalRead(button1pin);
  currentFrontPanel.button2 = !digitalRead(button2pin);
  currentFrontPanel.button3 = !digitalRead(button3pin);
  return currentFrontPanel;
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
  double sum;
  for (int i=0; i<10; i++){ ///use 10000 samples for calibration and do every voltage! It makes sense to check the voltage source with a high precision meter, as the reference can also be off!
    sum+=analogRead(pin);
  }
  double dataValue = sum/10;
  dataValue = (dataValue-3149.1) / -409;
;
  return dataValue;  
}

int getBit(int code, int posi){ //LSB based
  int masked= ( code & (0b01<<posi) ) >> posi;
  return masked;
}

void fpEventHandler(){
  currentFrontPanel = readFrontPanel();
  int diffIndex = searchStructDiffIndex(previousFrontPanel, currentFrontPanel);  
  if (diffIndex != -1){
    int newValue = showStructValue(currentFrontPanel, diffIndex);
    Serial.print("Difference at index ");Serial.print(diffIndex);
    Serial.print(" New value: ");Serial.println(newValue);
    if (currentFrontPanel.button3 > previousFrontPanel.button3)
    {
      frontPanelPage++;
    }
    if (currentFrontPanel.button1 > previousFrontPanel.button1)
    {
      frontPanelPage--;
    }
    if (diffIndex > 10)
    {
      myFrontPanels[frontPanelPage][diffIndex] = currentFrontPanel[diffIndex];
    }
    
    previousFrontPanel = currentFrontPanel;
  }
}
double scaleSimple(double x, double in_min, double in_max, double out_min, double out_max)
{
  double limitedOut;
  limitedOut = (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
  return limitedOut;
}