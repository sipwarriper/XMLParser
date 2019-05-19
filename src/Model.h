#ifndef XMLPARSER_MODEL_H
#define XMLPARSER_MODEL_H

#include "ModelEntity.h"


class Model {

public:
    //TODO: estaria be unificar-los aqui
    virtual void register_time() = 0;
    virtual void register_event() = 0;
    virtual void register_resource() =0;
    virtual void register_resource_type() = 0;

    virtual void declare_time_group() = 0;
    virtual void declare_resource_group() = 0;
    virtual void declare_event_group() = 0;

    virtual void time_to_group() = 0;
    virtual void resource_to_group() = 0;
    virtual void event_to_group() = 0;


    //TODO: falten els getters
protected:




};


#endif //XMLPARSER_MODEL_H
