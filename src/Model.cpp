#include "Model.h"

Model::Model()
{
	events_ = std::map<std::string, Event>();
	resources_ = std::map<std::string, Resource>();
	times_ = std::map<std::string, Time>();

	rtypes_ = std::unordered_map<std::string, ResourceType>();

	time_groups_ = std::unordered_map<std::string, Group>();
	event_groups_ = std::unordered_map<std::string, Group>();
	resource_groups_ = std::unordered_map<std::string, Group>();

	num2event_ = std::unordered_map<int, Event>();
	num2resource_ = std::unordered_map<int, Resource>();
	num2time_ = std::unordered_map<int, Time>();
	num2rtype_ = std::unordered_map<int, ResourceType>();
}


