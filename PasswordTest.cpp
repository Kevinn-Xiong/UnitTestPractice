/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PasswordTest : public ::testing::Test
{
	protected:
		PasswordTest(){} //constructor runs before each test
		virtual ~PasswordTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, mixed_case_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("ZZz");
	ASSERT_EQ(2, actual);
}

/*TEST(PasswordTest, has_mixed_case)
{
	Password my_password;
	int actual = my_password.has_mixed_case("zZzZz");
	ASSERT_TRUE(actual);
}*/

TEST(PasswordTest, cover_lowercase)
{
	Password my_password;
	int actual = my_password.has_mixed_case("AAAbb");
	ASSERT_EQ(2,actual);
}

TEST(PasswordTest, NoLetters) {
    Password my_password;
    EXPECT_FALSE(my_password.has_mixed_case("12345"));
    EXPECT_FALSE(my_password.has_mixed_case("!@#$%"));
}

TEST(PasswordTest, OnlyOneLetterCasePresentWithSymbols) {
    Password p;
    EXPECT_FALSE(p.has_mixed_case("abc123!"));
    EXPECT_FALSE(p.has_mixed_case("ABC123!"));
}
