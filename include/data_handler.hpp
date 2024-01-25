//All the logic to read in, split the data and count the number of unique classes, convert to little endinan and pass aronudthe training, test and validation data.
//this is what the datra handler is going to do.

#define __DATA_HANDLER_H

#include <fstream> 
#include "stdint.h" 
#include "data.hpp" //this is the data class that we created.
#include <vector> //used to store the data.
#include <string> //used to store the path to the data file.
#include <map> //used to map class lable to its enumarted value. We want o access it quickly even thoguht we will be storing it.
#include <unordered_set> //used to keep track of the index of the data as we split the data in training test and validation data.

class data_handler
{
    std::vector<data *> * data_array; //all of the data pre split
    std::vector<data *> * training_data; //training data
    std::vector<data *> * test_data; //test data
    std::vector<data *> * validation_data; //validation data

    int num_classes; //number of unique classes in the data
    int feature_vector_size; //size of the feature vector
    std::map<uint8_t, int> * class_map; //maps the class label to its enumerated value

    const double training_split = 0.75; //75% of the data is used for training
    const double test_split = 0.20; //20% of the data is used for testing
    const double validation_split = 0.05; //5% of the data is used for validation

    public:
    data_handler();
    ~data_handler(); 

    void read_feature_vector(std::string path); //reads the feature vector from the file
    void read_feature_label(std::string path); //reads the feature label from the file
    void split_data(); //splits the data into training, test and validation data
    void count_classes(); //counts the number of unique classes in the data

    uint32_t convert_to_little_endian(const unsigned char* bytes); //converts the number to little endian

    std::vector<data *> * get_training_data(); //returns the training data
    std::vector<data *> * get_test_data(); //returns the test data
    std::vector<data *> * get_validation_data(); //returns the validation data

};

