extern "C" {
#include "memory-no-leak.h"
}

#include <gtest/gtest.h>

namespace {
TEST(MemTest, NoLeak) { ASSERT_FALSE(memory_no_leak()); }
} // namespace

int
main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
