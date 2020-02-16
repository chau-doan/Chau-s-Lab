#include "lifo.h"
#include "iostream"

namespace lab3{
    lifo::lifo() {
        //Reserve 100 spaces in lifo_storage
        lifo_storage.reserve(100);
        index=0;
    }

    lifo::lifo(std::string input_string) {
        lifo_storage.reserve(100);
        lifo_storage.append(input_string);
        index=1;
    }

    lifo::lifo(const lifo &original) {
        index = original.index;
        lifo_storage = original.lifo_storage;
    }

    lifo::~lifo() {
        for (int i = index; i> 0; i--)
            this->pop();
        index=0;
    }

    lifo &lifo::operator=(const lifo &right) {
        //return <#initializer#>;
        if (this==&right){
            return *this;
        }
        index = right.index;
        lifo_storage = right.lifo_storage;
        return *this;
    }

    bool lifo::is_empty(){
        //return false;
        if (index==0)
            return true;
        else
            return false;
    }

    int lifo::size(){
        //return 0;
        return index;
    }

    std::string lifo::top(){
        //return std::__cxx11::string();
        if (index==0)
            throw std::out_of_range ("Stack empty");
        else
            return lifo_storage[index-1];
    }

    void lifo::push(std::string input) {
        if (index == 100)
            throw std::out_of_range ("Stack already full");
        else
        if (index != lifo_storage.size() && index!=0) {
            lifo_storage[index] = input;
            index++;
        }
        else{
            lifo_storage.append(input);
            index++;
            lifo_storage.reserve(100);
        }
    }

    void lifo::pop() {
        if (index == 0)
            throw std::out_of_range("Empty Stack Exception");
        else
            index--;
    }
}

