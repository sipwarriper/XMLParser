#include "ModelEntity.h"

int times_counter = 0;
int events_counter = 0;
int resources_coutner = 0;
int resource_type_counter = 0;


ModelEntity::ModelEntity(std::string id, std::string n) {
    identifier = id;
    name = n;
    num = -1;
    groups = std::set<std::string>();

}

int ModelEntity::get_num() {
    return num;
}

std::string ModelEntity::get_identifier() {
    return identifier;
}

ResourceType::ResourceType(std::string id, std::string n) : ModelEntity(id, n) {
    type = "resource_type";
    lower_bound = upper_bound = 0;
    domain = std::set<int>();
    num = resource_type_counter;
    resource_type_counter++;
}

void ResourceType::add_resource(Resource resource) {
    groups.insert(resource.get_identifier());
    domain.insert(resource.get_num());

    //update upper and lower bounds
    if (resource.get_num() > upper_bound) upper_bound = resource.get_num();
    else if(resource.get_num() < lower_bound) lower_bound = resource.get_num();
}


Time::Time(std::string id, std::string n) : ModelEntity(id, n) {
    type = "time";
    num = times_counter;
    times_counter++;
}


Resource::Resource(std::string id, std::string n, std::optional<ResourceType> rType) : ModelEntity(id, n){
    if (rType == std::nullopt){/*throw*/}
    type = "resources";
    num=resources_coutner;
    resources_coutner++;
}
