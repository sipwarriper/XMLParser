//
// Created by sipwarriper on 5/17/19.
//

#include "xmlParser.h"

xmlParser::xmlParser(std::string filename) {

    if(!document.load_file(filename.c_str())){
        throw "Error loading xml file. Aborting.";
    }




}
