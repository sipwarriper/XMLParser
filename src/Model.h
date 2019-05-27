#ifndef XMLPARSER_MODEL_H
#define XMLPARSER_MODEL_H

#include "ModelEntity.h"
#include <optional>
#include <map>
#include <unordered_map>
#include <exception>


class Model {

public:
	Model();

	void register_time(const std::string& id, const std::string& name);
	void register_event(const std::string& id, const std::string& name, const int &duration, const std::optional<std::string> &color = std::nullopt);
	void register_resource(std::string id, std::string name, std::string rtype);
	void register_resource_type(std::string id, std::string name);

	Time* get_time_by_ref(std::string ref) const;
	Resource* get_resource_by_ref(std::string ref) const;
	Event* get_event_by_ref(std::string ref) const;

	void declare_time_group(const std::string& id, const std::string& name, const std::string& tag ="");
	void declare_resource_group(const std::string& id, const std::string& name, const std::string& rtype_ref);
	void declare_event_group(const std::string& id, const std::string& name, const std::string& tag = "");

	void time_to_group(const std::string& time_id, const std::string& group_ref);
	void resource_to_group(const std::string& resource_id, const std::string& group_ref);
	void event_to_group(const std::string& event_id, const std::string& group_ref);

	int upper_bound_by_resource_type(const int &num) const; //Function used to determine the upper bound of a variable representing a given resource type

	std::set<std::string> get_events_from_group(const std::string & group_ref) const;
	std::set<std::string> get_resources_from_group(const std::string & group_ref) const;
	std::set<std::string> get_times_from_group(const std::string & group_ref) const;


	/*TODO: Falta el seguent:
	*	-metodes virtuals
	*/

protected:
	std::map<std::string, Event*> events_;
	std::map<std::string, Resource*> resources_;
	std::map<std::string, Time*> times_;

	std::unordered_map<std::string, ResourceType*> rtypes_;

	std::unordered_map<std::string, Group> time_groups_;
	std::unordered_map<std::string, Group> event_groups_;
	std::unordered_map<std::string, Group> resource_groups_;


	//num2 dictionaries (allowing fast fetching of elements by its elements.num attribute)
	std::unordered_map<int, Event*> num2event_;
	std::unordered_map<int, Resource*> num2resource_;
	std::unordered_map<int, Time*> num2time_;
	std::unordered_map<int, ResourceType*> num2rtype_;
	   	 
};

class ModelException : public std::exception{
private:
	std::string msg_;
public:
	ModelException(const std::string & msg){
		msg_ = msg;
	}
	virtual const char* what() const throw(){
		return msg_.c_str();
	}
};


#endif //XMLPARSER_MODEL_H
