// Copyright 2013-2017 Edgar Costa
// See LICENSE file for license details.

#include "wrapper.h"

using namespace std;
using namespace NTL;



int main()
{
  char input[] = "17\n[[1 2 1] [2 0 2] [3 1 0] [1 3 0] [2 2 0] [0 2 2] [1 1 2] [3 0 1] [0 0 4] [2 1 1] [1 0 3] [0 4 0]]\n[-3 1 1 -4 1 3 -3 1 2 3 -4 2]";

  ZZX out;
  Mat<ZZ> Frob;
  zeta_function(out, Frob, input, true, 1);


  return 0;

}

