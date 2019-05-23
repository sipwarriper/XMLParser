#include <pugixml.hpp>
#include <exception>
#include "Model.h"

#ifndef XMLPARSER_XHSTTPARSER_H
#define XMLPARSER_XHSTTPARSER_H


class XMLParser {
public:
    XMLParser(std::string filename); //constructor

    void parse_model();

    void parse_instance();

    void parse_times();
    void parse_time_groups();

    void parse_resources();
    void parse_resource_types();
    void parse_resource_groups();

    void parse_events();
    void parse_event_groups();
    void parse_optimize_events();


    void parse_constraints();
    //TODO: hi ha una historia de metodes necessaris

    bool constraint_required();

private:
    pugi::xml_document document;
    Model *model;
    //TODO:necessitem un assign_time i un assign_res.





};

class xmlParserException: public std::exception{
    virtual const char* what() const throw(){
        return "Error: given XML does not follow XHSTT convention. Aborting.";
    }

};


#endif //XMLPARSER_XHSTTPARSER_H
