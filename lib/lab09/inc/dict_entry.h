#ifndef CMPE126S20_LABS_ENTRY_H
#define CMPE126S20_LABS_ENTRY_H

#include <string>
namespace lab9{
    class dict_entry{
    public:
        char key;
        std::string value;

        explicit dict_entry(char input_key, const std::string& input_value){

        }
    };
}
#endif //CMPE126S20_LABS_ENTRY_H
