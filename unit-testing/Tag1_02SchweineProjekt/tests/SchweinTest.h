#pragma once

#include "gtest/gtest.h"
#include "../source/Schwein.h"

using namespace testing;

class SchweinTest: public Test
{
protected:
	Schwein object_under_test;
};
