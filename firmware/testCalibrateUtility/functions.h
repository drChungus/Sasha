frontPanel readFrontPanel(){
  frontPanel currentFrontPanel;
  currentFrontPanel.pot1 = analogRead(pot1pin);
  currentFrontPanel.pot2 = analogRead(pot2pin);
  currentFrontPanel.pot3 = analogRead(pot3pin);
  currentFrontPanel.pot4 = analogRead(pot4pin);
  currentFrontPanel.pot5 = analogRead(pot5pin);
  currentFrontPanel.pot6 = analogRead(pot6pin);
  currentFrontPanel.pot7 = analogRead(pot7pin);
  currentFrontPanel.pot8 = analogRead(pot8pin);
  currentFrontPanel.button1 = digitalRead(button1pin);
  currentFrontPanel.button2 = digitalRead(button2pin);
  currentFrontPanel.button3 = digitalRead(button3pin);
  return currentFrontPanel;
};


int searchStructDiffIndex (frontPanel s1, frontPanel s2){
    int diffIndex = -1;
    for (int i = 0; i < 8; ++i) //check Pots
    {
      if(s1[i] != s2[i]){
        diffIndex = frontPanelIndexCatalog[i];
      };
    }    
    for (int i = 0; i < 3; ++i) //CheckButtons
    {
      if(s1(i*10) != s2(i*10)){
        diffIndex = frontPanelIndexCatalog[i+8];
      };
    }
    return diffIndex;
};

int showStructValue (frontPanel thisPanel, int diffIndex()){
  int Value = thisPanel[diffIndex];
  return Value;
};
