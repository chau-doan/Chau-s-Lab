# Lab 7: Recursion #
For this lab, you will be writing several classic recursion algorithms. All of these algorithms can be solved iteratively. For this lab, you're required to solve them with recursion.

### Lab Instructions ###
Implement the following class and functions using recursion. The constructor and destructor should be empty, there's are data members for this class.

Any submissions with iterative solutions will receive zero.

Implement the following:

- `recursion() - constructor`

- `~recursion() - destructor`

- `int fibonacci(int n) - return the Nth number in the Fibonacci series. Throw any exception if n is less than 0.`

- `int climb_stairs(int n) - given a staircase with n stairs, return the number of distinct ways you can climb to the top by taking 1 or 2 steps at a time. Throw any exception if n is less than 1.`

- `int pow(int base, int n) - implement the power function recursively. Given a base, return the base raised to the power n. E.g, base = 2, n = 3, return 8. Throw any exception if n is negative. If you use the built-in "math.h" or <cmath> you will receive zero for this.`

- `bool valid_parenthesis(std::string input) - return true if the input string consists only of valid parenthesis. "((()))" is a valid parenthesis string. "((())" is an invalid parenthesis string, it is missing a closing parenthesis.`

- `bool are_nodes_okay(const node* head) - given a lab7::node, head, check if all connected nodes are ok. Return true/false. You must use recursion.`

### Hint ###
* Read the test cases!
* For `recursion::pow` you should throw an exception if `n` is less than 0. That's not how the power function works in real life, but for the sake of this lab, it is!