/**
* Copyright (C) Kirtus G. Leyba, 2024
* This software is freely available without warranty of any kind according
* to the MIT license found in the LICENSE file.
**/

#include "options.hpp"

Options parseArgs(int argc, char** argv){
    Options o;

    o.argMapInts.insert(std::make_pair("--anInteger", &o.anInteger));
    o.argMapFloats.insert(std::make_pair("--aFloat", &o.aFloat));
    o.argMapStrings.insert(std::make_pair("--config", &o.config));
    o.argMapStrings.insert(std::make_pair("--aString", &o.aString));

    for(int i = 1; i < argc; i++){
        std::string argument = argv[i];
        std::string indicator = "--";
        
        if(argument.find(indicator) != std::string::npos) {
            if(o.argMapInts.find(argument) != o.argMapInts.end()){
                *(o.argMapInts.at(argument)) = atoi(argv[i+1]);
            } else if (o.argMapFloats.find(argument) != o.argMapFloats.end()) {
                *(o.argMapFloats.at(argument)) = atof(argv[i+1]);
            } else if (o.argMapStrings.find(argument) != o.argMapStrings.end()){
                *(o.argMapStrings.at(argument)) = argv[i+1];
            }
        }
        
        if(argument == "--config"){
            //read config file
            std::ifstream configFile(argv[i+1]);
            std::string parameter;
            std::string value;
            while(configFile >> parameter >> value){
                if(o.argMapInts.find(parameter) != o.argMapInts.end()){
                    *(o.argMapInts.at(parameter)) = atoi(value.c_str());
                } else if (o.argMapFloats.find(parameter) != o.argMapFloats.end()) {
                    *(o.argMapFloats.at(parameter)) = atof(value.c_str());
                } else if (o.argMapStrings.find(parameter) != o.argMapStrings.end()){
                    *(o.argMapStrings.at(parameter)) = value.c_str();
                }
            }
        }
    }
    return o;

}

void printOptions(const Options& opt){
    printf("# Running with the following options:\n");
    for(auto a : opt.argMapInts){
        printf("%s = %d\n", a.first.c_str(), *a.second);
    }
    for(auto a : opt.argMapFloats){
        printf("%s = %f\n", a.first.c_str(), *a.second);
    }
}

//Global Options Struct
Options opt;
