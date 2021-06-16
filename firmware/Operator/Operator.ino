#include "audioLibraryDesign.h"
#include "physicalLayer.h"
#include "initialize.h"
#include "waveforms.h"
//#include "audioEngine.h"
//#include "functions.h"

const int myInput = AUDIO_INPUT_LINEIN;





void setup()
{
  pinMode(button1pin,INPUT_PULLUP);
  pinMode(button2pin,INPUT_PULLUP);
  pinMode(button3pin,INPUT_PULLUP);
  pinMode(normalizationPin, OUTPUT);
  
  Serial.begin(115200);
  analogReadResolution(analogRes);
  digitalWrite(normalizationPin, LOW);
	// Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);

  // Enable the audio shield, select input, and enable output
  sgtl5000_1.enable();
  sgtl5000_1.inputSelect(myInput);
  sgtl5000_1.volume(0.8);
  initializeAudioEngine();
}

void loop()
{
  fpEventHandler();
  //delay(0); 
  //Serial.println(readCV(ai5pin));
  //Serial.println(AudioProcessorUsage()); 

  
}
