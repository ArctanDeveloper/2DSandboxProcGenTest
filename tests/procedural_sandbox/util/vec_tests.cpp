#include <gtest/gtest.h>
#include <procedural_sandbox/util/vec.h>

using ProceduralSandbox::Util::Vec2f;
using ProceduralSandbox::Util::Vec2i;

TEST(VectorTest, UnitTest) {
    EXPECT_EQ(Vec2f(1.0, 1.0), Vec2f::UNIT_XY);
    EXPECT_EQ(Vec2f(1.0, 0.0), Vec2f::UNIT_X);
    EXPECT_EQ(Vec2f(0.0, 1.0), Vec2f::UNIT_Y);
    EXPECT_EQ(Vec2i(1, 1), Vec2i::UNIT_XY);
    EXPECT_EQ(Vec2i(1, 0), Vec2i::UNIT_X);
    EXPECT_EQ(Vec2i(0, 1), Vec2i::UNIT_Y);

    EXPECT_LT(Vec2f::UNIT_X.Magnitude(), Vec2f::UNIT_XY.Magnitude());
    EXPECT_LT(Vec2f::UNIT_Y.Magnitude(), Vec2f::UNIT_XY.Magnitude());
    EXPECT_EQ(Vec2f::UNIT_X.Magnitude(), Vec2f::UNIT_Y.Magnitude());
    EXPECT_LT(Vec2i::UNIT_X.Magnitude(), Vec2i::UNIT_XY.Magnitude());
    EXPECT_LT(Vec2i::UNIT_Y.Magnitude(), Vec2i::UNIT_XY.Magnitude());
    EXPECT_EQ(Vec2i::UNIT_X.Magnitude(), Vec2i::UNIT_Y.Magnitude());
    
    EXPECT_GT(Vec2f::UNIT_X.Normalize().x, Vec2f::UNIT_XY.Normalize().x);
    EXPECT_GT(Vec2f::UNIT_Y.Normalize().y, Vec2f::UNIT_XY.Normalize().y);
    EXPECT_EQ(Vec2i::UNIT_X.Normalize().x, Vec2i::UNIT_XY.Normalize().x);
    EXPECT_EQ(Vec2i::UNIT_Y.Normalize().y, Vec2i::UNIT_XY.Normalize().y);
}