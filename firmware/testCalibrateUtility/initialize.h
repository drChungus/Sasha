struct frontPanel{
  int pot1, pot2, pot3, pot4, pot5, pot6, pot7, pot8;
  bool button1, button2, button3;
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
            //default: throw std::runtime_error( "bad index" );
        }
  }
  bool &operator()( size_t idx ) {
        switch( idx ) {
            case 10 : return button1;
            case 20 : return button2;
            case 30 : return button3;
            //default: throw std::runtime_error( "bad index" );
        }
  }
    
};
