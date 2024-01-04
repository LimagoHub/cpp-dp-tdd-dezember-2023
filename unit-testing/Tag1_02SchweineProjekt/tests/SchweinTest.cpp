#include "SchweinTest.h"

const int default_weight = 10;

TEST_F(SchweinTest,ctor__default__fields_initialized)
{
	// Act ist ctor-call
	
	const  std::string default_name = "nobody";
	EXPECT_EQ(default_name, object_under_test.get_name());
	EXPECT_EQ(default_weight, object_under_test.get_gewicht());
}

TEST_F(SchweinTest, ctor__with_valid_name___fields_initialized)
{
	// Arrange
	const int default_weight = 10;
	const  std::string valid_name = "Piggy";

	Schwein object_under_test{ valid_name};
	
	EXPECT_EQ(valid_name, object_under_test.get_name());
	EXPECT_EQ(default_weight, object_under_test.get_gewicht());
}

TEST_F(SchweinTest, ctor__invalid_name___throws_invalid_argument_exception)
{
	try {
		const int default_weight = 10;
		const  std::string invalid_name = "Elsa";

		Schwein object_under_test{ invalid_name };
		
	}catch(const std::invalid_argument ex)
	{
		EXPECT_STREQ("name nicht erlaubt", ex.what());
	}
	
}

TEST_F(SchweinTest, fuettern__happy_day___weight_increased_by_one)
{
	const int expected_weight = default_weight + 1;
	object_under_test.fuettern();
	EXPECT_EQ(expected_weight, object_under_test.get_gewicht());
	
}