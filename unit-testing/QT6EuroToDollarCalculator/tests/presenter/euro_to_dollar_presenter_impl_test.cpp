//
// Created by JoachimWagner on 13.04.2023.
//

#include "euro_to_dollar_presenter_impl_test.h"

void euro_to_dollar_presenter_impl_test::SetUp() {
    object_under_test.set_view(&euro_to_dollar_viewMock);
    object_under_test.set_model(&euro_to_dollar_calculatorMock);
}

TEST_F(euro_to_dollar_presenter_impl_test, beenden__HappyDay__maskDisposed){
    EXPECT_CALL(euro_to_dollar_viewMock, dispose);
    object_under_test.beenden();
}

TEST_F(euro_to_dollar_presenter_impl_test, populate_items__HappyDay__maskInitialized){
    // Arrange
    EXPECT_CALL(euro_to_dollar_viewMock, set_euro("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("0"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));

    // Act
    object_under_test.populate_items();
}
TEST_F(euro_to_dollar_presenter_impl_test, rechnen__NANInEuroField__error_message_in_dollar_field){
    // Arrange
    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));

    // Act
    object_under_test.rechnen();
}
TEST_F(euro_to_dollar_presenter_impl_test, rechnen__Number_followed_by_string__InEuroField__error_message_in_dollar_field){
    // Arrange
    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("10x"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));

    // Act
    object_under_test.rechnen();
}

TEST_F(euro_to_dollar_presenter_impl_test, rechnen__empty_string__InEuroField__error_message_in_dollar_field){
    // Arrange
    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return(""));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Keine Zahl"));

    // Act
    object_under_test.rechnen();
}
TEST_F(euro_to_dollar_presenter_impl_test, rechnen__unexpected_exception_in_underlying_service__error_message_in_dollar_field){
    // Arrange
    InSequence s;
    const auto validEuroValue = "10";
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return(validEuroValue));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(_)).WillOnce(Throw(std::out_of_range{"upps"}));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("Internal Server Error"));

    // Act
    object_under_test.rechnen();
}

//TEST_F(euro_to_dollar_presenter_impl_test, rechnen__valid_value_in_euro_field__euro_passed_to_model){
//    // Arrange
//    InSequence s;
//    const auto validEuroValue = "10";
//    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return(validEuroValue));
//    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.));
//
//
//    // Act
//    object_under_test.rechnen();
//}
TEST_F(euro_to_dollar_presenter_impl_test, rechnen__happyDay__dollar_value_in_dollar_field){
    // Arrange
    InSequence s;
    const auto validEuroValue = "10";
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return(validEuroValue));
    EXPECT_CALL(euro_to_dollar_calculatorMock, convert(10.)).WillOnce(Return(100.));
    EXPECT_CALL(euro_to_dollar_viewMock, set_dollar("100.00"));

    // Act
    object_under_test.rechnen();

}
TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__NANInEuroField__rechnen_action_disabled){
    // Arrange
    InSequence s;
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return("Not a Number"));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(false));

    // Act
    object_under_test.update_rechnen_action_state();
}

TEST_F(euro_to_dollar_presenter_impl_test, update_rechnen_action_state__validEuroValueField__rechnen_action_enabled){
    // Arrange
    InSequence s;
    const auto validEuroValue = "10";
    EXPECT_CALL(euro_to_dollar_viewMock, get_euro()).WillOnce(Return(validEuroValue));
    EXPECT_CALL(euro_to_dollar_viewMock, set_rechnen_enabled(true));

    // Act
    object_under_test.update_rechnen_action_state();
}
//