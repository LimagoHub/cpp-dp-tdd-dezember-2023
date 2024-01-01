//
// Created by JoachimWagner on 06.06.2023.
//

#pragma once
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../Mockpersonen_repository.h"
#include "../MockBlacklistService.h"
#include "../../source/services/personen_service_impl.h"
#include "../../source/services/personen_service_exception.h"
using namespace testing;

class personen_service_impl_test :public Test{

protected:
    NaggyMock<Mockpersonen_repository> repoMock;
    NiceMock<MockBlacklistService> blacklistMock;
    personen_service_impl object_under_test{repoMock, blacklistMock};

    void SetUp() override;
};

class personen_service_impl_parameter_test : public personen_service_impl_test, public WithParamInterface<std::pair<person, std::string>> {
public:
    personen_service_impl_parameter_test(): personen_service_impl_test(){}

protected:
    person invalidPerson{"",""};
    std::string expectedErrorMessage;

    void SetUp() override{

        std::tie<person, std::string>(invalidPerson, expectedErrorMessage) = GetParam();

    }

};
