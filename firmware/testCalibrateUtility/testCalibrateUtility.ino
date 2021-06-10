#include "audioLibraryDesign.h"
#include "physicalLayer.h"
#include "initialize.h"
#include "functions.h"


const int myInput = AUDIO_INPUT_LINEIN;
frontPanel currentFrontPanel;


void setup()
{
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
  Serial.println(currentFrontPanel.pot1);
}
