#include "ModelEntity.h"

int times_counter = 0;
int events_counter = 0;
int resources_counter = 0;
int resource_type_counter = 0;


ModelEntity::ModelEntity(const std::string &id, const std::string &name) {
    identifier_ = id;
    name_ = name;
    num_ = -1;
    groups_ = std::set<std::string>();
}

int ModelEntity::get_num() {
    return num_;
}

std::string ModelEntity::get_identifier() {
    return identifier_;
}

ResourceType::ResourceType(const std::string &id, const std::string &name) : ModelEntity(id, name) {
    type_ = "resource_type";
    lower_bound_ = upper_bound_ = 0;
    domain_ = std::set<int>();
    num_ = resource_type_counter;
    resource_type_counter++; 
}

void ResourceType::add_resource(Resource resource) {
    groups_.insert(resource.get_identifier());
    domain_.insert(resource.get_num());

    //update upper and lower bounds
    if (resource.get_num() > upper_bound_) upper_bound_ = resource.get_num();
    else if(resource.get_num() < lower_bound_) lower_bound_ = resource.get_num();
}


Time::Time(const std::string &id, const std::string &name) : ModelEntity(id, name) {
    type_ = "time";
    num_ = times_counter;
    times_counter++;
}


Resource::Resource(const std::string &id, const std::string &rename, std::optional<ResourceType> r_type) : ModelEntity(id, rename) {
	if (r_type == std::nullopt) {/*throw*/ }
	rtype_ = r_type.value();
	type_ = "resources";
	num_ = resources_counter;
	resources_counter++;
}

Event::Event(const std::string& id, const std::string& rename, const int &duration, const std::optional<std::string> &color): ModelEntity(id,rename) {
	type_ = "event";
	num_ = events_counter;
	events_counter++;
	duration_ = duration;
	color_ = color;
	time_ = std::nullopt;
	resources_ = std::unordered_map<std::string, Resource*>();
	mapping_ = std::unordered_map<std::string, ResourceType*>();
	needed_ = std::set<int>();
}

bool Event::has_role(std::string role) {
	return resources_.find(role) != resources_.end();
}

bool Event::has_preassigned_resource(const std::string& role) {
	return resources_[role] != nullptr;
}

bool Event::has_preassigned_time() const
{
	return time_ != std::nullopt;
}

bool Event::is_preassigned(int num)
{
	bool result = false;
	for (auto & resource : resources_) if (resource.second->get_num() == num) result = true;
	return result;
}

std::set<Resource> Event::get_preassigned_resources()
{
	auto result = std::set<Resource>();
	for (auto& resource : resources_) if (resource.second != nullptr) result.insert(*resource.second);
	return result;
}

Resource Event::get_preassigned_resource(const std::string& role)
{
	return *resources_[role];
}

std::set<std::string> Event::get_roles()
{
	auto result = std::set<std::string>();
	for (auto & resource : resources_) result.insert(resource.first);
	return result;
}

std::set<int> Event::get_needed_resources() const
{
	return needed_;
}

Resource Event::get_preassigned(const int& num)
{
	for (auto & resource : resources_) if (resource.second->get_num() == num) return *resource.second;
}

std::set<int> Event::get_preassigned_nums()
{
	auto result = std::set<int>();
	for(auto & resource : resources_)
		if (resource.second != nullptr) result.insert(resource.second->get_num());
	return result;
}

void Event::set_time(const std::string& time_ref)
{
	time_ = time_ref;
}







