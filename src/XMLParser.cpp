#include "XMLParser.h"

XMLParser::XMLParser(std::string filename) {

    if(!document.load_file(filename.c_str())){
        throw "Error loading xml file. Aborting.";
    }




}
