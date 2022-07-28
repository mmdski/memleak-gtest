extern "C" {
#include "memory-leak.h"
}

#include <gtest/gtest.h>

namespace {
TEST(MemTest, Leak) { ASSERT_FALSE(memory_leak()); }
} // namespace

int
main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
