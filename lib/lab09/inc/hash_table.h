#ifndef CMPE126S20_LABS_HASH_TABLE_H
#define CMPE126S20_LABS_HASH_TABLE_H

#include <string>
#include <vector>

namespace lab9 {

    struct key_value {
        std::string key;
        int value;
    };

    class hash_table {
        key_value *hash_table_array;

        /*
         * Define the probing technique
         * 'l': Linear probing
         *          hash_1() + attempt
         * 'q': Quadratic probing
         *          hash_1() + attempt^2
         * 'd': Double Probing
         *          hash_1() + attempt * hash_2()
         */
        char probing;

        unsigned max_size;
        unsigned current_size;

        // PRIMES[n+1]= next prime after 2*PRIMES[n]. Use this for setting max size
        const int PRIMES[16] = {31, 67, 137, 277, 557, 1117, 2237, 4481, 8963, 17929, 35863, 71741, 143483, 286999, 574003, 1148029};

        // These two hashing functions are built for you. You don't have to implement these.
        unsigned hash_1(std::string to_hash);
        unsigned hash_2(std::string to_hash);

        void expand();

    public:
        hash_table(char type);

        ~hash_table();

        bool insert(std::string key, int value);

        int get(std::string key);

        void remove(std::string key);

        bool in_table(std::string);

        void update(std::string key, int value);

        // Functions use for testings
        unsigned get_size() { return current_size; };

        unsigned get_max_size() { return max_size; };

        std::string to_string(); // Used for testing
    };
}

#endif //CMPE126S20_LABS_HASH_TABLE_H
