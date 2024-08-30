/**
* Copyright (C) Kirtus G. Leyba, 2024
* This software is freely available without warranty of any kind according
* to the MIT license found in the LICENSE file.
**/

#include "options.hpp"
#include <iostream>

//Example usage
int main(int argc, char** argv){
    opt = parseArgs(argc, argv);
    printOptions(opt); 
    return 0;
}
