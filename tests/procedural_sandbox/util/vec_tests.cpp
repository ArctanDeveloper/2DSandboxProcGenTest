#include <gtest/gtest.h>
#include <procedural_sandbox/util/vec.h>

using ProceduralSandbox::Util::Vec2f;
using ProceduralSandbox::Util::Vec2i;

TEST(VectorTest, UnitTest) {
    EXPECT_EQ(Vec2f(1.0, 1.0), Vec2f::UNIT_XY) << "Expected (1, 1) to be equal to (1, 1).";
    EXPECT_EQ(Vec2f(1.0, 0.0), Vec2f::UNIT_X) << "Expected (1, 0) to be equal to (1, 0).";
    EXPECT_EQ(Vec2f(0.0, 1.0), Vec2f::UNIT_Y) << "Expected (0, 1) to be equal to (0, 1).";

    EXPECT_LT(Vec2f::UNIT_X.Magnitude(), Vec2f::UNIT_XY.Magnitude()) << "Expected (1, 0) to be less than (1, 1).";
    EXPECT_LT(Vec2f::UNIT_Y.Magnitude(), Vec2f::UNIT_XY.Magnitude()) << "Expected (0, 1) to be less than (1, 1).";
    EXPECT_EQ(Vec2f::UNIT_X.Magnitude(), Vec2f::UNIT_Y.Magnitude()) << "Expected (1, 0) to be equal to (0, 1).";
    
    EXPECT_GT(Vec2f::UNIT_X.Normalize().x, Vec2f::UNIT_XY.Normalize().x) << "Expected UNIT_X x to be greater than normalized UNIT_XY x.";
    EXPECT_GT(Vec2f::UNIT_Y.Normalize().y, Vec2f::UNIT_XY.Normalize().y) << "Expected UNIT_Y y to be greater than normalized UNIT_XY y.";

    EXPECT_EQ(Vec2i(1, 1), Vec2i::UNIT_XY) << "Expected (1, 1) to be equal to (1, 1).";
    EXPECT_EQ(Vec2i(1, 0), Vec2i::UNIT_X) << "Expected (1, 0) to be equal to (1, 0).";
    EXPECT_EQ(Vec2i(0, 1), Vec2i::UNIT_Y) << "Expected (0, 1) to be equal to (0, 1).";
    
    EXPECT_LT(Vec2i::UNIT_X.Magnitude(), Vec2i::UNIT_XY.Magnitude()) << "Expected (1, 0) to be less than (1, 1).";
    EXPECT_LT(Vec2i::UNIT_Y.Magnitude(), Vec2i::UNIT_XY.Magnitude()) << "Expected (0, 1) to be less than (1, 1).";
    EXPECT_EQ(Vec2i::UNIT_X.Magnitude(), Vec2i::UNIT_Y.Magnitude()) << "Expected (1, 0) to be equal to (0, 1).";
    
    EXPECT_GT(Vec2i::UNIT_X.Normalize().x, Vec2i::UNIT_XY.Normalize().x) << "Expected UNIT_X x to be greater than normalized UNIT_XY x.";
    EXPECT_GT(Vec2i::UNIT_Y.Normalize().y, Vec2i::UNIT_XY.Normalize().y) << "Expected UNIT_Y y to be greater than normalized UNIT_XY y.";

}

TEST(VectorTest, AdditionTest) {
    
}

TEST(VectorTest, SubtractionTest) {

}

TEST(VectorTest, MultiplicationTest) {

}

TEST(VectorTest, DivisionTest) {

}

TEST(VectorTest, MagnitudeTest) {

}

TEST(VectorTest, NormalizeTest) {

}