# Lab 8: Binary Search Trees #
For this lab, you will be implementing a Binary Search Tree to store integers and do various operations on the tree.

A tree is a data structure very similar to a doubly linked list, but instead of linking back and forth, the node pointers point to nodes one layer deeper. The way data is input into the tree also sorts the data by design. 

### Lab Instructions ###
You will be writing all of the code for the implementation of a tree. You can use any helper functions you would like, but all of the functions that are provided to you need to do the functions that are commented above them. 

Every function than can be implemented with recursion, needs to be implemented with it. Check out the example recursive function `print_gtl()` for an idea of how to accomplish this. Take note of the auxilary functions 

The following functions need to be implemented recursively

- `tree(const tree& copy) - copy constructor. Create a deepcopy of the tree passed in.`

- `~tree() - destructor. You'll need to delete all children within the tree.`

- `void insert(int value) - insert a new node into the tree. If the value already exists, increment its frequency.`

- `bool in_tree(int key) - checks if a key is present in the tree. Returns true if present, false if not.` 

- `int get_frequency(int key) - returns the frequency of the value within the tree.`

- `int level(int key) - the level of a node is the level from the root that the node lives. The root node is always at level 0. The direct left,right children of the root would be at level 1, and so on. Look at a picture of a BST to understand "levels" better.`

- `void path_to(int key) - print the path to a node from the root. Check the test cases for the format. You should be able to use std::cout for this.`

- `unsigned depth() - the depth of the tree is the deepest level that the tree goes to. Look up "depth of BST" for additional explanation.`

- `std::string to_string() - return a std::string representation of the tree. The format should be similar to tree::print().`

- `void print() - print the contents of the tree. See test cases for format. You should be able to use std::cout.`

- `tree& operator=(const tree &rhs) - this = rhs; copy over the contents of rhs into this.`

- `friend std::ostream& operator<<(std::ostream& stream, tree& RHS) - similar to tree::print, use the given stream to output the contents of the tree.`

- `tree operator+(const tree &rhs) const - this + rhs; return a new tree with the merged contents of THIS and RHS.`

- `std::vector<int> values_above(int key) - return a std::vector containing all values greater than the given key within the tree.`


### Hints ###
- `left` children of a parent are **ALWAYS** less than the parent 
- `right` children of a a parent are **ALWAYS** greater than the parent
- You cannot access the parent from a child. It is a one way connection.
- If you are trying to insert a value into a node that already exists, you need to increment the frequency of that value when you find it.
- You will be writing a lot of auxiliary functions.
- Wikipedia article on [Binary Search Tree](https://en.wikipedia.org/wiki/Binary_search_tree)
- Article talking about several different [balancing techniques](https://web.eecs.umich.edu/~qstout/pap/CACM86.pdf)
