#include "gtest/gtest.h"
#include "recursion.h"
#include <algorithm>

#include <cmath> // for pow

class Lab07Fixture : public ::testing::Test {

protected:
    virtual void SetUp() {
        rec = new lab7::recursion();
    }

    virtual void TearDown() {
        delete rec;
    }

public:
    std::vector<int> fib = {0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887};
    std::vector<int> stairs = {1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 832040, 1346269, 2178309, 3524578, 5702887};
    lab7::recursion * rec;
};

TEST_F(Lab07Fixture, constructor_destructor) {
    auto tc = new lab7::recursion();
    delete tc;
}

TEST_F(Lab07Fixture, fibonacci_negative) {
    for (int i = 1; i < 100; i++) {
        EXPECT_ANY_THROW(rec->fibonacci(-i));
    }
}

TEST_F(Lab07Fixture, fibonacci) {
    for (int i = 0; i < fib.size(); i++) {
        EXPECT_EQ(fib[i], rec->fibonacci(i));
    }
}

TEST_F(Lab07Fixture, climb_stairs_negative) {
    for (int i = 0; i < 100; i++) {
        EXPECT_ANY_THROW(rec->climb_stairs(-i));
    }
}

TEST_F(Lab07Fixture, climb_stairs) {
    for (int i = 0; i < stairs.size(); i++) {
        EXPECT_EQ(stairs[i], rec->climb_stairs(i + 1));
    }
}

TEST_F(Lab07Fixture, pow_throws) {
    // it should throw on negatives
    for (int i = 1; i < 100; i++) {
        EXPECT_ANY_THROW(rec->pow(2, -i));
    }

}

TEST_F(Lab07Fixture, pow) {
    // handle positives
    int base = 2;
    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(pow(base, i), rec->pow(base, i));
    }

    // handle negatives
    base = -2;
    for (int i = 0; i < 20; i++) {
        EXPECT_EQ(pow(base, i), rec->pow(base, i));
    }
}

TEST_F(Lab07Fixture, valid_parenthesis) {
    std::vector<std::string> nice_strings = {"", "()", "(())", "((()))", "(((())))"};
    for (const auto& nice_string : nice_strings) EXPECT_TRUE(rec->valid_parenthesis(nice_string));
}

TEST_F(Lab07Fixture, invalid_parenthesis) {
    std::vector<std::string> bad_strings = {"1", "a", "  ", "(x)", "(", ")", "(x())", "(()))", "(((()))", "((((abc)))", "((((ab)))"};
    for (const auto& bad_string : bad_strings) EXPECT_FALSE(rec->valid_parenthesis(bad_string));
}

TEST_F(Lab07Fixture, are_nodes_ok_yes) {
    auto head = new (lab7::node){nullptr, true};
    auto tmp = head;
    for (int i = 0; i < 100; i++) {
        tmp->next = new (lab7::node){nullptr, true};
        tmp = tmp->next;
    }

    EXPECT_TRUE(rec->are_nodes_ok(head));

    tmp = head;
    for (int i = 0; i < 100; i++) {
        auto prev = tmp;
        tmp = tmp->next;
        delete prev;
    }
}

TEST_F(Lab07Fixture, are_nodes_ok_no) {
    auto head = new (lab7::node){nullptr, true};
    auto tmp = head;
    for (int i = 0; i < 100; i++) {
        tmp->next = new (lab7::node){nullptr, (i != 85)};
        tmp = tmp->next;
    }

    EXPECT_FALSE(rec->are_nodes_ok(head));

    tmp = head;
    for (int i = 0; i < 100; i++) {
        auto prev = tmp;
        tmp = tmp->next;
        delete prev;
    }
}
