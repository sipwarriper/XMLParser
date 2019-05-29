#include <iostream>
#include "XHSTTPrinterModel.h"
#include "XMLParser.h"

int main() {
	
	std::string filename = "instances/BrazilInstance1.xml";

	auto printer = XHSTTPrinterModel(filename);



    return 0;
}