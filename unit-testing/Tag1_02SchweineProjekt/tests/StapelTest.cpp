//
// Created by JoachimWagner on 11.04.2023.
//

#include "StapelTest.h"


TEST_F(StapelTest, is_empty_bla_bla) {
    EXPECT_TRUE(object_under_test.is_empty());
}

TEST_F(StapelTest, is_empty_bla_bla_bla) {
    object_under_test.push(1);
    EXPECT_FALSE(object_under_test.is_empty());
}