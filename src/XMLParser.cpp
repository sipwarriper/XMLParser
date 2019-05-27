#include "XMLParser.h"

XMLParser::XMLParser(Model* model, std::string filename) {

    if(!document.load_file(filename.c_str())){
        throw std::exception("Error loading xml file. Aborting.");
    }
	model_ = model;

	xml_source_filename_ = filename;
	xml_root_ = document.root();

	assign_time_ = std::set<std::string>();
	assign_res_ =  std::unordered_map<std::string, std::set<std::string>>();

}

void XMLParser::parse_model(){

	//ignore all child tags but <Instances> and just parse the first instance below that
	pugi::xml_node xml_instance = xml_root_.child("Instances").child("Instance");

	parse_instance(xml_instance);

	
}


