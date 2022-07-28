extern "C" {
#include "memory-double-free.h"
}

#include <gtest/gtest.h>

namespace {
TEST(MemTest, DoubleFree) { ASSERT_FALSE(memory_double_free()); }
} // namespace

int
main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
