#include "../inc/stringVector.h"
#include "iostream"

namespace lab2 {
    stringVector::stringVector() {
        data = NULL;
        length=0;
        allocated_length=0;

    }

    stringVector::~stringVector() {
        delete [] data;
        length = 0;
        allocated_length = 0;
    }

    unsigned stringVector::size() const{
        //return;
        return length;
    }

    unsigned stringVector::capacity() const{
        //return ;
        return allocated_length;
    }

    void stringVector::reserve(unsigned new_size) {
        std::string *temp = new std::string[new_size];
        for (int i=0; i<new_size; i++){
            if (i<length){
                temp[i]=data[i];
            } else
                break;
        }
        delete []data;
        data=temp;
        allocated_length=new_size;
        if (length>new_size){
            length=new_size;
        }
    }

    bool stringVector::empty() const{
        //return ;
        return(length==0)?true:false;
    }

    void stringVector::append(std::string new_data) {
        std::string *temp;

        if (allocated_length==0 && allocated_length==length){
            delete [] data;
            data= new std::string[1];
            allocated_length=1;
            data[0]=new_data;
            length=1;
        }
        else {
            temp = new std::string[2 * allocated_length];
            for (int i = 0; i < length; i++) {
                temp[i] = data[i];
            }
            allocated_length = 2 * allocated_length;
            if (data != NULL)
                delete[]data;
            data = temp;
            data[length] = new_data;
            length++;
        }


    }

    void stringVector::swap(unsigned pos1, unsigned pos2) {
        std::string str;
        if((pos1>=length)||(pos2>=length)){
            std::cout <<"Index Out of bounds "<< std::endl;
            return;
        }
        str= data[pos1];
        data[pos1]=data[pos2];
        data[pos2]=str;

    }

    stringVector &stringVector::operator=(stringVector const &rhs) {
        //return ;
        if (this == &rhs)
            return *this;
        delete[] data;
        length = rhs.length;
        allocated_length = rhs.allocated_length;
        this->data = new std::string[allocated_length];
        for (int i = 0; i < length; i++) {
            this->data[i] = rhs.data[i];
        }
        return *this;
    }


    std::string &stringVector::operator[](unsigned position) {
        //return ;
        if (position >= length || position < 0 || length == 0){
            throw std::out_of_range("Position out of range");
        }
        return data[position];
    }

    void stringVector::sort() {
        std::string temp;

        for(int i= (length - 1) ; i > 0; i--){
            for(int j = 0; j < i; j++){
                if(islower(data[j].at(0)) && islower(data[j+1].at(0))){
                    if((data[j].compare(data[j + 1])) > 0){
                        this->swap(j,j+1);
                    }
                }

                else if(isupper(data[j].at(0)) && islower(data[j+1].at(0))){
                    this->swap(j,j+1);
                }

                else if(isupper(data[j].at(0)) && isupper(data[j+1].at(0))){
                    if((data[j].compare(data[j + 1])) > 0){
                        this->swap(j,j+1);
                    }
                }
            }
        }
    }

}
