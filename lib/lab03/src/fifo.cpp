#include "fifo.h"
#include "iostream"
#include <utility>

namespace lab3{
    fifo::fifo() {
        //Reserve 100 spaces in fifo_storage
        fifo_storage.reserve(100);
        front_index=0;
        back_index=0;
    }

    fifo::fifo(std::string input_string) {
        fifo_storage.reserve(100);
        fifo_storage.append(input_string);
        front_index=0;
        back_index=1;
    }

    fifo::fifo(const fifo &original) {
        front_index = original.front_index;
        back_index = original.back_index;
        fifo_storage = original.fifo_storage;
    }

    fifo::~fifo() {
        back_index = 0;
        front_index = 0;
    }

    fifo &fifo::operator=(const fifo &right) {
        //return <#initializer#>;
        if (this==&right){
            return *this;
        }
        fifo_storage.reserve(100);
        this->front_index = right.front_index;
        this->back_index = right.back_index;
        this->fifo_storage= right.fifo_storage;
        return *this;


    }

    bool fifo::is_empty(){
        //return false;
        if (front_index==back_index)
            return true;
        else
            return false;
    }

    int fifo::size(){
        if (front_index==back_index)
            return 0;
        else
            return back_index-front_index;
        //return 0;
    }

    std::string fifo::top(){
        if (back_index==front_index)
            throw std::out_of_range("Empty Queue Exception");
        else
            return fifo_storage[front_index % 100];
        //return std::__cxx11::string();

    }

    void fifo::enqueue(std::string input) {

        if(fifo_storage.size()<100){
            fifo_storage.append(input);
            back_index++;
            fifo_storage.reserve(100);
        }
        else if((back_index-front_index)>=100)
            throw std::out_of_range ("Queue already full");
        else{
            fifo_storage[back_index % 100]=input;
            back_index++;
        }
    }

    void fifo::dequeue() {
        if (front_index == back_index)
            throw std::out_of_range("Empty Queue Exception");
        else{
            front_index++;
        }

    }
}

