extern "C" {
#include "struct.h"
}
#include <gtest/gtest.h>

struct music_comp *buf = (struct music_comp*)malloc(sizeof(struct music_comp));

TEST(FIB_TEST, Assert_1) { EXPECT_TRUE(duration(5, 3, 5, 6)); }

TEST(FIB_TEST, Assert_2) { EXPECT_TRUE(bpm(4, 3)); }

TEST(FIB_TEST, Assert_3) { EXPECT_TRUE(bpm(1, 3)); }

TEST(FIB_TEST, Assert_4) { EXPECT_FALSE(duration(2, 3, 5, 6)); }

TEST(FIB_TEST, Assert_5) { EXPECT_TRUE(bpm(49, 50) && duration(0, 8, 0, 8)); }

TEST(FIB_TEST, Assert_6) { EXPECT_TRUE(duration(0, 8, 0, 8)); }

TEST(FIB_TEST, Assert_7) { EXPECT_TRUE(bpm(43, 43) && duration(0, 12, 0, 12)); }

TEST(FIB_TEST, Assert_8) { EXPECT_TRUE(bpm(48, 50) && duration(5, 7, 5, 7)); }

TEST(FIB_TEST, Assert_9) { EXPECT_EQ(find_first_structure(buf, 0), -1); }

TEST(FIB_TEST, Assert_10) { EXPECT_EQ(print_other_structures(0, buf), -1); }

TEST(FIB_TEST, Assert_11) { EXPECT_FALSE(bpm(2, 5)); }



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  free(buf);
  return RUN_ALL_TESTS();
}