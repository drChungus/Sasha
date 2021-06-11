#include "audioLibraryDesign.h"
#include "physicalLayer.h"
#include "initialize.h"
#include "functions.h"
#include "audioEngine.h"


const int myInput = AUDIO_INPUT_LINEIN;





void setup()
{
  pinMode(button1pin,INPUT_PULLUP);
  pinMode(button2pin,INPUT_PULLUP);
  pinMode(button3pin,INPUT_PULLUP);
  
  Serial.begin(115200);
  analogReadResolution(analogRes);
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
  fpEventHandler();
  colorCode=0b00011011;
  updateLEDs(colorCode);
  delay(0); 
  //Serial.println(readCV(ai5pin));
  Serial.println(AudioProcessorUsage());
}
