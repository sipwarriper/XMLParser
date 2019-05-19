
#ifndef XMLPARSER_MODELSTYPES_H
#define XMLPARSER_MODELSTYPES_H

#include <string>
#include <set>

//global variables

extern int times_counter;
extern int events_counter;
extern int resources_coutner;
extern int resource_type_counter;

class Group{

};

class ModelEntity{
public:
    ModelEntity(std::string id, std::string n="NAMELESS");
    int get_num();
    std::string get_identifier();

protected:
    std::string identifier;
    std::string name;
    int num;
    std::set<std::string> groups;

    //TODO: cal revisar tipus de groups.

};


class Resource;

class ResourceType: public ModelEntity{
public:
    ResourceType(std::string id, std::string n="NAMELESS_RESOURCE_TYPE");
    void add_resource(Resource resource);
protected:
    std::string type;
    int lower_bound, upper_bound;
    std::set<int> domain;


};

class Time: public ModelEntity{
public:
    Time(std::string id, std::string n="NAMELESS_TIME");
private:
    std::string type;
};

class Resource: public ModelEntity{
public:
    Resource(std::string id, std::string n="NAMELESS_TIME", std::optional<ResourceType> rType = std::nullopt);

protected:
    std::string type;

};

class Event: public ModelEntity{

};



#endif //XMLPARSER_MODELSTYPES_H
