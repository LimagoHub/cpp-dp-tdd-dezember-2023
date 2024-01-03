//
// Created by JoachimWagner on 13.04.2023.
//

#pragma once
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../../source/presenter/euro_to_dollar_presenter_impl.h"
#include "../Mockeuro_to_dollar_calculator.h"
#include "../Mockeuro_to_dollar_view.h"
using namespace testing;

class euro_to_dollar_presenter_impl_test :public Test{

protected:
    Mockeuro_to_dollar_calculator  euro_to_dollar_calculatorMock;
    Mockeuro_to_dollar_view  euro_to_dollar_viewMock;
    euro_to_dollar_presenter_impl object_under_test{};

    void SetUp() override;
};
