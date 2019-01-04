//
// Created by wujiahao on 2019-01-04.
//

#include "gtest/gtest.h"
#include "../src/msg.h"

TEST(test1, test2) {
    Msg<double, 3> msg;
    std::cout << sizeof(msg) << typeid(msg).name() << "\n";
    long b = 2;
    std::cout << (typeid(b)==typeid(int));
}

