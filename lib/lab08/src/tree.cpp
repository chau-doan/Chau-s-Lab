#include "../inc/tree.h"
#include <iostream>
#include <algorithm>

namespace lab8 {
    void clear(node *to_clear);
    void copytree_recursively(tree *paste,const node &copy);
    void insert_recursively(int value, node *top);
    int level_recursively(int value, int level, node* top);
    bool in_tree_recursively(int value, node* top);
    void path_to_recursively(int value, node* top);
    unsigned depth_recursively(node* top);
    int get_frequency_recursively(int value, node* top);
    void to_string_recursively(std::string &to_return, node* top);
    void values_above_recursively(std::vector<int> &vector, int key, node *top);
    void delete_the_node(node* &top);

    // Construct an empty tree

    tree::tree() {
        root = nullptr;
        tree_size = 0;
    }

    // Copy constructor
    tree::tree(const tree &copy) {
        copytree_recursively(this, *copy.root);
        tree_size = this->tree_size;
    }

    void copytree_recursively(tree *paste,const node &copy){
        if(&copy != nullptr){
            copytree_recursively(paste, *copy.left);
            for (int i = 0; i < copy.frequency; i++)
                paste->insert(copy.data);
            copytree_recursively(paste, *copy.right);
        }
    }

    // Deconstruct tree
    tree::~tree() {
        clear(root);
    }

    // Insert
    void tree::insert(int value) {
        if (root == nullptr){
            root = new node(value);
            tree_size = 1;
        }
        else{
            insert_recursively(value, root);
            tree_size++;
        }
    }

    void insert_recursively(int value, node *top){
        if (top->data < value){
            if (top->right == nullptr)
                top->right = new node(value);
            else
                insert_recursively(value,top->right);
        }
        else if(top->data > value){
            if (top->left == nullptr)
                top->left = new node(value);
            else
                insert_recursively(value, top->left);
        }
        else
            top->frequency = top->frequency + 1;
    }

    // Remove key return true if the key is deleted, and false if it isn't in the tree
    bool tree::remove(int key) {
        if (!in_tree(key))
            return false;
        else {
            node* current_node = root;
            node* previous_node;
            bool found = false;

            while (current_node != nullptr && !found){
                if (current_node -> data == key)
                    found = true;
                else{
                    previous_node = current_node;
                    if (current_node -> data > key)
                        current_node = current_node -> left;
                    else
                        current_node = current_node -> right;
                }
            }

            if (current_node -> frequency > 1)
                current_node -> frequency = current_node -> frequency - 1;
            else if (current_node == root)
                delete_the_node(root);
            else if (previous_node -> data > key)
                delete_the_node(previous_node -> left);
            else
                delete_the_node(previous_node -> right);
            tree_size--;
            return found;
        }
    }

    void delete_the_node(node* &top) {
        node* current_node;
        node* previous_node;
        node* temp_node;
        if (top->left == nullptr && top->right == nullptr){
            temp_node = top;
            top = nullptr;
            delete temp_node;
        }
        else if (top -> left == nullptr){
            temp_node = top;
            top = temp_node -> right;
            delete temp_node;
        }
        else if (top -> right == nullptr){
            temp_node = top;
            top = temp_node -> left;
            delete temp_node;
        }
        else{
            current_node = top -> left;
            previous_node = nullptr;

            while (current_node -> right != nullptr){
                previous_node = current_node;
                current_node = current_node -> right;
            }
            top -> data = current_node -> data;
            top -> frequency = current_node -> frequency;

            if (previous_node == nullptr)
                top -> left = current_node -> left;
            else
                previous_node -> right = current_node -> left;
            delete current_node;
        }
    }

    // What level is key on?
    int tree::level(int key) {
        if (!in_tree(key))
            return -1;
        else
            return level_recursively(key,0 ,root);
    }

    int level_recursively(int value, int level,node* top){
        if (top->data == value)
            return level;
        else if (top->data < value)
            return level_recursively(value, level+1, top->right);
        else
            return level_recursively(value, level+1, top->left);
    }

    // Print the path to the key, starting with root
    void tree::path_to(int key) {
        if (!in_tree(key))
            std::cout << "";
        else
            path_to_recursively(key, root);
    }

    void path_to_recursively(int value, node*top){
        std::cout << top->data;
        if (top->data == value)
            std::cout << std::endl;
        else if (top->data < value){
            std::cout << " -> ";
            path_to_recursively(value, top->right);
        }
        else{
            std::cout << " -> ";
            path_to_recursively(value, top->left);
        }
    }

    // Number of items in the tree
    unsigned tree::size() {
        return tree_size;
    }


    // Calculate the depth of the tree, longest string of connections
    unsigned tree::depth() {
        if (root == nullptr)
            return 0;
        else
            return depth_recursively(root)-1;
    }

    unsigned depth_recursively(node* top){
        if (top != nullptr){
            int left_depth;
            int right_depth;

            left_depth = 1 + depth_recursively(top->left);
            right_depth = 1 + depth_recursively(top->right);

            if (left_depth > right_depth)
                return left_depth;
            else
                return right_depth;
        }
        else
            return 0;
    }

    // Determine whether the given key is in the tree
    bool tree::in_tree(int key) {
        return in_tree_recursively(key, root);
    }

    bool in_tree_recursively(int value, node* top){
        if(top == nullptr)
            return false;
        else if (top->data == value)
            return true;
        else if (top->data < value)
            return in_tree_recursively(value, top->right);
        else if (top->data > value)
            return in_tree_recursively(value, top->left);
    }

    // Return the number of times that value is in the tree
    int tree::get_frequency(int key) {
        if (in_tree(key))
            return get_frequency_recursively(key, root);
        else
            return 0;
    }

    int get_frequency_recursively(int value, node* top){
        if (top->data == value)
            return top->frequency;
        else if (top->data < value)
            return get_frequency_recursively(value, top->right);
        else
            return get_frequency_recursively(value, top->left);
    }

    // Return a string of all of the elements in the tree in order
    std::string tree::to_string() {
        if (root == nullptr)
            return "";
        else{
            std::string to_return;
            to_string_recursively(to_return, root);
            return to_return;
        }
    }

    void to_string_recursively(std::string &to_return, node* top){
        if(top != nullptr){
            to_string_recursively(to_return, top->left);
            for (int i = 0; i < top->frequency; i++)
                to_return += std::to_string(top->data) + " ";
            to_string_recursively(to_return, top->right);
        }
    }

    //Use the to string function for the following two functions
    // Print the tree least to greatest, Include duplicates
    void tree::print() {
        std::cout << this->to_string() << std::endl;
    }

    // Print the tree least to greatest, Include duplicates
    std::ostream &operator<<(std::ostream &stream, tree &RHS) {
        stream << RHS.to_string() << std::endl;
        return stream;
    }

    // Operator= Overload. Allowing for copying of trees
    tree &tree::operator=(const tree &rhs) {
        if(this==&rhs)
            return *this;
        else {
            copytree_recursively(this, *rhs.root);
            return *this;
        }
    }

    /**************************
     * Extra credit functions *
     **************************/

    // Return a vector with all of the nodes that are greater than the input key in the tree
    std::vector<int> tree::values_above(int key) {
        std::vector<int> to_return;
        values_above_recursively(to_return, key, this->root);
        return to_return;
    }

    void values_above_recursively(std::vector<int> &vector, int key, node *top){
        if(top != nullptr){
            values_above_recursively(vector, key, top->left);
            if (top->data > key)
                for (int i = 0; i < top->frequency; i++)
                    vector.push_back(top->data);
            values_above_recursively(vector, key, top->right);
        }
    }

    // Merge rhs into this. Demo to a TA for credit
    tree tree::operator+(const tree &rhs) const {
        lab8::tree *to_return = new lab8::tree(*this);
        copytree_recursively(to_return, *rhs.root);
        return *to_return;
    }

    // Balance the tree using any published algorithm. Demo to a TA for credit
    void tree::balance() {
    }


    /*********************************************************************
     * Recursion Example                                                 *
     * Print the linked list from greatest to least using recursion      *
     *********************************************************************/

    // Auxiliary functions

    void node_print_gtl(node *top) {
        if (top == nullptr) return;
        node_print_gtl(top->right);
        for (int i = 0; i < top->frequency; i++) std::cout << top->data << " ";
        node_print_gtl(top->left);
    }

    void clear(node *to_clear) {
        if (to_clear == nullptr) return;
        if (to_clear->left != nullptr) clear(to_clear->left);
        if (to_clear->right != nullptr) clear(to_clear->right);
        delete to_clear;
    }

    // Class function
    void tree::print_gtl() {
        node_print_gtl(root);
        std::cout << std::endl;
    }
}
