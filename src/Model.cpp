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

void Model::register_time(const std::string& id, const std::string& name){
	if (times_.find(id) == times_.end()) {
		Time time = Time(id, name);
		times_.insert({id, time});
		num2time_.insert({ time.get_num() ,time});
	}
	else throw ModelException("Multiple Times with the same id");
}

void Model::register_event(const std::string& id, const std::string& name, const int &duration, const std::optional<std::string> &color){
	if (events_.find(id) == events_.end()) {
		Event event = Event(id, name, duration, color.value());
		events_.insert({id,event});
		num2event_.insert({ event.get_num(), event });
	}
	else throw ModelException("Multiple Events with the same id");
}

void Model::register_resource(std::string id, std::string name, std::string rtype_id){
	if(rtypes_.find(rtype_id) != rtypes_.end()){
		if(resources_.find(id) == resources_.end()){
			Resource resource = Resource(id, name, rtype_id);
			resources_.insert({id, resource});
			num2resource_.insert({ resource.get_num(), resource });
			rtypes_[rtype_id].add_resource(resource);
		}
		else throw ModelException("Multiple Resources with the same id");
	}
	else throw ModelException("Attempt to register a resource with an unregistered resource type");
}

void Model::register_resource_type(std::string id, std::string name){
	if(rtypes_.find(id) == rtypes_.end()){
		ResourceType rtype = ResourceType(id, name);
		rtypes_.insert({ id, rtype });
	}
}

std::optional<Time> Model::get_time_by_ref(std::string ref){
	auto it = times_.find(ref);
	if (it != times_.end()) return it->second;
	return std::nullopt;
}

std::optional<Resource> Model::get_resource_by_ref(std::string ref){
	auto it = resources_.find(ref);
	if (it != resources_.end()) return it->second;
	return std::nullopt;
}

std::optional<Event> Model::get_event_by_ref(std::string ref){
	auto it = events_.find(ref);
	if (it != events_.end()) return it->second;
	return std::nullopt;
}

void Model::declare_time_group(const std::string& id, const std::string& name, const std::string& tag){
	if (time_groups_.find(id)==time_groups_.end()){
		Group group = Group(id, name, "TimeGroup", tag);
		time_groups_.insert({id, group});
	}
	else throw ModelException("'Already defined TimeGroup");
}

void Model::declare_resource_group(const std::string& id, const std::string& name, const std::string& rtype_ref){
	if(rtypes_.find(rtype_ref) != rtypes_.end()){
		if(resource_groups_.find(id) == resource_groups_.end()){
			Group group = Group(id, name, "ResourceGroup", rtype_ref);
			resource_groups_.insert({ id, group });
		}
		else throw ModelException("'Already defined ResourceGroup");
	}
	else throw ModelException("Undeclared resource type");
}

void Model::declare_event_group(const std::string& id, const std::string& name, const std::string& tag){
	if (event_groups_.find(id) == event_groups_.end()){
		Group group = Group(id, name, "EventGroup", tag);
		event_groups_.insert({ id, group });
	}
	else throw ModelException("'Already defined EventGroup");
}













