int quality[4][4] = {
  {0, 4, 7, 11},      //Major7
  {0, 3, 7, 10},      //Minor7
  {0, 4, 7, 10},      //Dominant7
  {0, 3, 6, 10}       //HalfDim7
};

int inversion[4][4] = {
  {0, 0, 0, 0},         //Root
  {12, 0, 0, 0},        //1st
  {12, 12, 0, 0},       //2nd
  {12, 12, 12, 0}       //3rd
};

int voicing[4][4] = {
  {0, 0, 0, 0},         //close
  {0, 0, -12, 0},       //drop2
  {0, -12, 0, 0},       //drop3
  { -12, 0, 0, 12}      //spread
};

int harmonization [2][7] = {
  {0, 1, 1, 0, 0, 1, 3},    //MajorHarmonization
  {1, 3, 0, 1, 1, 0, 0}     //Minor Harmonization
};
