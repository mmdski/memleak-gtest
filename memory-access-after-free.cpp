extern "C" {
#include "memory-access-after-free.h"
}

#include <gtest/gtest.h>

namespace {
TEST(MemTest, AccessAfterFree) { ASSERT_FALSE(memory_access_after_free()); }
} // namespace

int
main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
