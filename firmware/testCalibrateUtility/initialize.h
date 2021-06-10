#include <BiColorLED.h> 
#define frontPanelCatalogElements 17  //number of elements on the frontPanel

int frontPanelIndexCatalog [frontPanelCatalogElements] = {1,2,3,4,5,6,7,8,10,20,30,11,22,33,44};  //indexes of fron panele element in the struct


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
int potTolerance = 2;
