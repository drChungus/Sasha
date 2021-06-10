#include "audioLibraryDesign.h"
#include "physicalLayer.h"
#include "initialize.h"
#include "functions.h"


const int myInput = AUDIO_INPUT_LINEIN;
frontPanel currentFrontPanel, previousFrontPanel;




void setup()
{
  pinMode(button1pin,INPUT_PULLUP);
  pinMode(button2pin,INPUT_PULLUP);
  pinMode(button3pin,INPUT_PULLUP);
  
  Serial.begin(115200);
	// Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.8);
}

void loop()
{
  currentFrontPanel = readFrontPanel();
  int diffIndex = searchStructDiffIndex(previousFrontPanel, currentFrontPanel);
  
  if (diffIndex != -1){
    int newValue = showStructValue(currentFrontPanel, diffIndex);
    Serial.print("Difference at index ");Serial.print(diffIndex);
    Serial.print(" New value: ");Serial.println(newValue);
    previousFrontPanel = currentFrontPanel;
  }

  updateLEDs(colorCode);
  delay(10); 
}
