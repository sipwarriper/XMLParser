#ifndef XMLPARSER_MODEL_H
#define XMLPARSER_MODEL_H

#include "ModelEntity.h"
#include <map>
#include <unordered_map>


class Model {

public:
	Model();



    //TODO: falten els getters
protected:
	std::map<std::string, Event> events_;
	std::map<std::string, Resource> resources_;
	std::map<std::string, Time> times_;

	std::unordered_map<std::string, ResourceType> rtypes_;

	std::unordered_map<std::string, Group> time_groups_;
	std::unordered_map<std::string, Group> event_groups_;
	std::unordered_map<std::string, Group> resource_groups_;


	//num2 dictionaries (allowing fast fetching of elements by its elements.num attribute)
	std::unordered_map<int, Event> num2event_;
	std::unordered_map<int, Resource> num2resource_;
	std::unordered_map<int, Time> num2time_;
	std::unordered_map<int, ResourceType> num2rtype_;




};


#endif //XMLPARSER_MODEL_H
