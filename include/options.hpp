#pragma once
#include <vector>
#include <stdlib.h>
#include <string>
#include <unordered_map>
#include <utility>
#include <fstream>

/**
* Copyright (C) Kirtus G. Leyba, 2024
* This software is freely available without warranty of any kind according
* to the MIT license found in the LICENSE file.
**/

/**
Options: struct containing parameter variables
**/
struct Options {
    //Example parameters
    int anInteger = 1000;
  
    float aFloat = 1.0f;

    //config files
    std::string config;

    //string parameters
    std::string aString;

    //maps for parameters
    std::unordered_map<std::string, int*> argMapInts;
    std::unordered_map<std::string, float*> argMapFloats;
    std::unordered_map<std::string, std::string*> argMapStrings;

};

Options parseArgs(int argc, char** argv);
void printOptions(const Options& opt);
extern Options opt;
