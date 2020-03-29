#ifndef CMPE126S20_LABS_RECURSION_H
#define CMPE126S20_LABS_RECURSION_H

namespace lab7 {
    struct node {
        node* next;
        bool ok;
    };

    class recursion {
    public:
        recursion();

        ~recursion();

        int fibonacci(int n);

        int climb_stairs(int n);

        int pow(int base, int n);

        bool valid_parenthesis(std::string input);

        bool are_nodes_ok(const node* head);
    };
}

#endif // CMPE126S20_LABS_RECURSION_H
