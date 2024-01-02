//
// Created by JoachimWagner on 02.01.2024.
//

#include "ServiceTest.h"
using namespace testing;
TEST_F(ServiceTest, bar)
{
    std::unique_ptr<DependencyMock> dependencyMock=std::make_unique<DependencyMock>();
    // Arrange Mock in der RecordMode versetzen
    EXPECT_CALL(*dependencyMock, foo(3)).WillRepeatedly(Return(42));
    // Replay
    Service objectUnderTest{std::move(dependencyMock)};

    objectUnderTest.bar(3);
}