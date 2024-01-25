# define __DATA_H

#define __DATA_H

#include <vector>
#include "stdint.h"
#include "stdio.h"

class data 
{
    std::vector<uint8_t> * feature_vector;
    uint8_t label;
    int enum_label;

    public:
    
    void set_feature_vector(std::vector<uint8_t> *);
    void set_label(uint8_t);
    void set_enum_label(int);
    void append_feature_vector(uint8_t);

    int get_feature_vector_size();
    uint8_t get_label();
    uint8_t get_enum_label();

    std::vector<uint8_t> * get_feature_vector();

};
