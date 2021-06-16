#include <BiColorLED.h> 

#define frontPanelCatalogElements 17  //number of elements on the frontPanel

int frontPanelIndexCatalog [frontPanelCatalogElements] = {1,2,3,4,5,6,7,8,10,20,30,11,22,33,44};  //indexes of fron panele element in the struct
//int fpLedLut[5] = {0b10101010, 0b01101010, 0b10011010, 0b10100110, 0b10101001}; //operator index // 10:red, 01: green
int fpLedPageLut[8] = { 0b01010101, 0b00000101, 0b00010001, 0b01000101, 0b00001010, 0b00100010, 0b10001010, 0b10101010 };
int fpLedAlgoLUT[12] = {  };
//int algorithmLUT [6] = {0b000010000000000001000011, 0b000000000000001011000001, 000010000100001000010001, 000010000000001001000100, 000000000100001010011001, 000000000100000010111011}; //Alkemie's
int algorithmLUT [12] = { 0b000010000100001000010001, 0b000000001100001000010001, 0b000000000100101000010001, 0b000010001000011000010001, 0b000010001000011000010001, 0b000010000100010000110011, 0b000010000100010000110011, 0b000000000000111000010001, 0b000010000000001000110011, 0b000010001000100001110111, 000000000000000011111111 }; //Ableton Operator



struct frontPanel{
  int pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8; //Potmeters
  bool button1, button2, button3;                     //Buttons
  bool conn1, conn2, conn3, conn4;                    //Jack Connections
  int &operator[]( size_t idx ) {
        switch( idx ) {
            case 1 : return pot1;
            case 2 : return pot2;
            case 3 : return pot3;
            case 4 : return pot4;
            case 5 : return pot5;
            case 6 : return pot6;
            case 7 : return pot7;
            case 8 : return pot8;
            default: return pot1;
            //default: throw std::runtime_error( "bad index" );
        }
  }
  bool &operator()( size_t idx ) {
        switch( idx ) {
            case 10 : return button1;
            case 20 : return button2;
            case 30 : return button3;
            case 11 : return conn1;
            case 22 : return conn2;
            case 33 : return conn3;
            case 44 : return conn4;
            default: return button1;
            //default: throw std::runtime_error( "bad index" );
        }
  }
    
};

bool normalizationProbeState;
int analogRes = 12;
int potTolerance = 3;

int colorCode;
BiColorLED led1=BiColorLED(8,5);
BiColorLED led2=BiColorLED(24,2);
BiColorLED led3=BiColorLED(26,25);
BiColorLED led4=BiColorLED(27,28);
