extern "C" {
#include "struct.h"
}
#include <gtest/gtest.h>

class Struct : public ::testing::Test
{
protected:
	void SetUp()
	{
    buf->bpm = 12;
    buf->dur_min = 10;
	}
	void TearDown()
	{
      free(buf);
	}
  struct music_comp *buf = (struct music_comp*)malloc(sizeof(struct music_comp));
};


TEST(FIB_TEST, Assert_1) { EXPECT_TRUE(cmp_duration(5, 3, 5, 6)); }

TEST(FIB_TEST, Assert_2) { EXPECT_TRUE(cmp_bpm(4, 3)); }

TEST(FIB_TEST, Assert_3) { EXPECT_TRUE(cmp_bpm(1, 3)); }

TEST(FIB_TEST, Assert_4) { EXPECT_FALSE(cmp_duration(2, 3, 5, 6)); }

TEST(FIB_TEST, Assert_5) { EXPECT_TRUE(cmp_bpm(49, 50) && cmp_duration(0, 8, 0, 8)); }

TEST(FIB_TEST, Assert_6) { EXPECT_TRUE(cmp_duration(0, 8, 0, 8)); }

TEST(FIB_TEST, Assert_7) { EXPECT_TRUE(cmp_bpm(43, 43) && cmp_duration(0, 12, 0, 12)); }

TEST(FIB_TEST, Assert_8) { EXPECT_TRUE(cmp_bpm(48, 50) && cmp_duration(5, 7, 5, 7)); }

TEST_F(Struct, Assert_9) { EXPECT_EQ(find_first_structure(buf, 0), -1); }

TEST_F(Struct, Assert_10) { EXPECT_EQ(print_other_structures(0, buf), -1); }


TEST(FIB_TEST, Assert_13) { EXPECT_FALSE(cmp_bpm(2, 5)); }



int main(int argc, char **argv) {
  printf("%i\n",ERR);
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}