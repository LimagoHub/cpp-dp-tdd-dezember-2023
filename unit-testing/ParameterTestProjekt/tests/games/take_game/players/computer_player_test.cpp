//
// Created by JoachimWagner on 14.12.2022.
//

#include "computer_player_test.h"

TEST_F(computer_player_test, do_turn_happy_day) {

    EXPECT_THAT(object_under_test.do_turn(20), Eq(3));
}

TEST_P(computer_player_parameter_test, do_turn_happy_day) {

    EXPECT_THAT(object_under_test.do_turn(param), Eq(result));
}

INSTANTIATE_TEST_SUITE_P(
        DoTurnHappyDayParameterTests, // Name der Tests, frei waehlbar
        computer_player_parameter_test, // Verbindung zur Testklasse
        Values(
                std::make_pair(20, 3),
                std::make_pair(21, 1),
                std::make_pair(22, 1),
                std::make_pair(23, 2),
                std::make_pair(4, 3),
                std::make_pair(5, 1),
                std::make_pair(6, 1),
                std::make_pair(7, 2))
);

