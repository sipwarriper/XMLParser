#ifndef XMLPARSER_MODELENTITY_H
#define XMLPARSER_MODELENTITY_H

#include <optional>

#include <string>
#include <set>
#include <unordered_map>

//global variables

extern int times_counter;
extern int events_counter;
extern int resources_counter;
extern int resource_type_counter;

class Group{

};

class ModelEntity{
public:
    ModelEntity(const std::string &id = "", const std::string &name ="NAMELESS");
    int get_num();
    std::string get_identifier();

protected:
    std::string identifier_;
    std::string name_;
    int num_;
    std::set<std::string> groups_;

    //TODO: cal revisar tipus de groups.

};


class Resource;

class ResourceType: public ModelEntity{
public:
    ResourceType(const std::string &id="", const std::string &name ="NAMELESS_RESOURCE_TYPE");
    void add_resource(Resource resource);
protected:
    std::string type_;
    int lower_bound_, upper_bound_;
    std::set<int> domain_;


};

class Time: public ModelEntity{
public:
    Time(const std::string &id="", const std::string &name="NAMELESS_TIME");
private:
    std::string type_;
};

class Resource: public ModelEntity{
public:
	Resource(const std::string &id="", const std::string &rename = "NAMELESS_TIME", std::optional<ResourceType> r_type = std::nullopt);

protected:
    std::string type_;
	ResourceType rtype_;

};

class Event: public ModelEntity{
public:
	Event(const std::string& id="", const std::string& rename = "NAMELESS_EVENT", const int &duration = 1, const std::optional<std::string> &color= std::nullopt);
	
	bool has_role(std::string role);
	bool has_preassigned_resource(const std::string& role);
	bool has_preassigned_time() const;
	bool is_preassigned(int num);

	std::set<Resource> get_preassigned_resources();
	Resource get_preassigned_resource(const std::string &role);

	std::set<std::string> get_roles();
	std::set<int> get_needed_resources() const;

	Resource get_preassigned(const int &num);
	std::set<int> get_preassigned_nums(); //returns a set containing all numerals of preassigned resources

	void set_time(const std::string& time_ref);
	void attach_reosurce(); //TODO: primer caldria avançar el model




	

protected:
	std::string type_;
	std::optional<std::string> color_;
	int duration_;
	std::optional<std::string> time_; //time reference

	std::unordered_map<std::string, Resource*> resources_;
	std::unordered_map<std::string, ResourceType*> mapping_;

	std::set<int> needed_; //set of needed ResourceType num's 

};



#endif //XMLPARSER_MODELSTYPES_H
