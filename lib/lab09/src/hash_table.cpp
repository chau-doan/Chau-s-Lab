#include "../inc/hash_table.h"

namespace lab9 {
    // Implemented for you.
    unsigned hash_table::hash_1(std::string to_hash) {
        // DJB2 Hashing Algorithm
        unsigned int hash = 5381;
        for(char c: to_hash){
            hash = ((hash << 5) + hash) + c;
        }
        return hash;
    }

    // Implemented for you.
    unsigned hash_table::hash_2(std::string to_hash) {
        // BKDR Hashing Algorithm
        unsigned int seed = 131;
        unsigned int hash = 0;
        for(char c: to_hash){
            hash = (hash * seed) + c;
        }
        return hash;
    }

    void hash_table::expand() {
        // Expand the hash table by a factor of 2 every time this function is called
        unsigned new_size;
        int i = 0;
        while(i<16 && new_size <= this->max_size) {
            new_size = PRIMES[i];
            i++;
        }
        this-> max_size = new_size;
        key_value *previous_table = this->hash_table_array;
        unsigned previous_size = this->current_size;
        this->current_size = 0;
        this->hash_table_array  = new key_value[new_size];
        for (int i = 0; i < previous_size; i++)
            this->insert(previous_table[i].key, previous_table[i].value);
        delete[] previous_table;
    }

    hash_table::hash_table(char type) {
        /*
         * Define the probing technique
         * 'l': Linear probing
         *          hash_1() + attempt
         * 'q': Quadratic probing
         *          hash_1() + attempt^2
         * 'd': Double Probing
         *          hash_1() + attempt * hash_2()
         *
         * Create a hash table with an initial size of 100
         */
        if (type != 'l' && type != 'q' && type != 'd')
            throw std::exception();
        else{
            probing = type;
            max_size = PRIMES[0];
            current_size = 0;
            hash_table_array = new key_value[max_size];
        }
    }

    hash_table::~hash_table() {
        delete[] hash_table_array ;
    }

    bool hash_table::insert(std::string key, int value) {
        // Insert a key according to the defined probing technique
        // If you run into an issue where you get an infinite collision loop,
        //   figure out a way to get out of the loop.
        if(this->in_table(key))
            return false;
        else{
            unsigned hash = hash_1(key) % max_size;
            if (hash_table_array[hash].key.empty()){
                hash_table_array[hash].key = key;
                hash_table_array[hash].value = value;
            }
            else{
                unsigned attempt = 1;
                while(!hash_table_array[hash].key.empty()){
                    if (probing == 'l')
                        hash = (hash_1(key) + attempt) % max_size;
                    else if (probing == 'q')
                        hash = (hash_1(key) + attempt * attempt) % max_size;
                    else
                        hash = (hash_1(key) + attempt * hash_2(key)) % max_size;
                    attempt ++;
                }
                hash_table_array[hash].key = key;
                hash_table_array[hash].value = value;
            }
            current_size ++;
            if (current_size / max_size > 0.7)
                expand();
            return true;
        }

    }

    bool hash_table::in_table(std::string key){
        // Checks to see if that key is in the table.
        // Use the specified probing technique
        // Keep collisions in mind
        unsigned hash = hash_1(key) % max_size;
        if (hash_table_array[hash].key == key)
            return true;
        else{
            unsigned attempt = 1;
            while (!hash_table_array[hash].key.empty()) {
                if (hash_table_array[hash].key == key)
                    return true;
                else if (probing == 'l')
                    hash = (hash_1(key) + attempt) % max_size;
                else if (probing == 'q')
                    hash = (hash_1(key) + attempt * attempt) % max_size;
                else
                    hash = (hash_1(key) + attempt * hash_2(key)) % max_size;
                attempt++;
            }
            return false;
        }
    }

    int hash_table::get(std::string key) {
        // Get the int value from the node that has key
        // Use the specified probing technique
        if(this->in_table(key)){
            unsigned hash = hash_1(key) % max_size;
            unsigned attempt = 1;
            while (!hash_table_array[hash].key.empty()) {
                if (hash_table_array[hash].key == key)
                    return hash_table_array[hash].value;
                else if (probing == 'l')
                    hash = (hash_1(key) + attempt) % max_size;
                else if (probing == 'q')
                    hash = (hash_1(key) + attempt * attempt) % max_size;
                else
                    hash = (hash_1(key) + attempt * hash_2(key)) % max_size;
                attempt++;
            }
        }
        else
            throw std::exception();
    }

    void hash_table::update(std::string key, int value){
        // Update a key in the hash table.
        // Keep collisions in mind
        // Use the specified probing technique
        if(this->in_table(key)){
            unsigned hash = hash_1(key) % max_size;
            unsigned attempt = 1;
            for(int i = 0; i < current_size; i++) {
                if (hash_table_array[hash].key == key)
                    break;
                else if (probing == 'l')
                    hash = (hash_1(key) + attempt) % max_size;
                else if (probing == 'q')
                    hash = (hash_1(key) + attempt * attempt) % max_size;
                else
                    hash = (hash_1(key) + attempt * hash_2(key)) % max_size;
                attempt++;
            }
            hash_table_array[hash].value = value;
        }
        else
            insert(key, value);
    }

    void hash_table::remove(std::string key){
        // Remove an item from the hash table. Keep collisions in mind
        // Use the specified probing technique
        // If the item isn't in the table, do nothing.
        if(this->in_table(key)){
            unsigned hash = hash_1(key) % max_size;
            unsigned attempt = 1;
            for(int i = 0; i < current_size; i++) {
                if (hash_table_array[hash].key == key)
                    break;
                else if (probing == 'l')
                    hash = (hash_1(key) + attempt) % max_size;
                else if (probing == 'q')
                    hash = (hash_1(key) + attempt * attempt) % max_size;
                else
                    hash = (hash_1(key) + attempt * hash_2(key)) % max_size;
                attempt++;
            }
            hash_table_array[hash].key = "";
            hash_table_array[hash].value = 0;
            current_size --;
        }
    }

    std::string hash_table::to_string(){
        // Run through the entire array and create a string following this format. The {} brackets aren't part of the return
        // [{array location}]{key_value.key}:{key_value.int}
        int size = current_size;
        std::string to_return;
        for(int i = 0; i < max_size; i++){
            if(size == 0)
                break;
            else if(!hash_table_array[i].key.empty()){
                to_return = to_return + std::to_string(i) + " " + hash_table_array[i].key + ":" + std::to_string(hash_table_array[i].value) + "\n";
                size --;
            }
        }
        return to_return;
    }
}
