#include <string>
#include "../inc/recursion.h"


namespace lab7 {
    recursion::recursion() {
    }

    recursion::~recursion() {
    }

    int recursion::fibonacci(int N) {
        if (N<0)
            throw std::exception();
        else if (N<2)
            return N;
        else
            return fibonacci(N-1)+fibonacci(N-2);
    }

    int recursion::climb_stairs(int n) {
        if (n<1)
        {throw std::exception();}
        else if(n<3)
            return n;
        else
            return climb_stairs(n-1)+climb_stairs(n-2);
    }

    int recursion::pow(int base, int n) {
        if (n<0)
            throw std::exception();
        else if (n==0)
            return 1;
        else
            return base*pow(base, n-1);
    }

    // hint: first check the first and last characters, then recurse with what's left inside
    bool recursion::valid_parenthesis(std::string input) {
        if (input.empty())
            return true;
        if (input.at(0) == '(' && input.at(input.size()-1) == ')')
            return valid_parenthesis(input.substr(1,input.size()-2));
        else
            return false;

    }

    // hint: this is very similar to what you've done with linked lists previously, just using recursion.
    bool recursion::are_nodes_ok(const node* head) {
        if (head == nullptr)
            return true;
        if (head->ok)
            return are_nodes_ok(head->next);
        else
            return false;
    }
}