#ifndef CMPE126S20_LABS_LIB_LAB8_NODE_H
#define CMPE126S20_LABS_LIB_LAB8_NODE_H

namespace lab8{
    class node{
    public:
        node *left, *right;  // Pointers to the left and right children
        int data;           // Integer that is stored in the tree
        unsigned frequency; // Frequency of that integer in the tree

        explicit node(int input_data) : data(input_data), frequency(1), left(nullptr), right(nullptr) {}
        explicit node(node* copy_node){
            data = copy_node->data;
            frequency = copy_node->frequency;
            left = nullptr;
            right = nullptr;
        }
    };
}
#endif //CMPE126S20_LABS_NODE_H