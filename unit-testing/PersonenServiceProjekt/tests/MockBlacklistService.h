#pragma once

#include "gmock/gmock.h"
#include "../source/persistence/person.h"
#include "../source/services/BlacklistService.h"



class MockBlacklistService : public BlacklistService {
 public:
  MOCK_METHOD(bool, is_blacklisted, (const person& person), (const, override));

};
