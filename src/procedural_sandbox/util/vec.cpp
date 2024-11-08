#include <procedural_sandbox/util/vec.h>
#include <cmath>

using namespace ProceduralSandbox::Util;

#pragma region Vec2f
Vec2f::Vec2f(float x, float y) : x(x), y(y) {}

const Vec2f Vec2f::ZERO = Vec2f(0.0f, 0.0f);
const Vec2f Vec2f::UNIT_X = Vec2f(1.0f, 0.0f);
const Vec2f Vec2f::UNIT_Y = Vec2f(0.0f, 1.0f);
const Vec2f Vec2f::UNIT_XY = Vec2f(1.0f, 1.0f);

Vec2f Vec2f::operator+(const Vec2f &other) const {
    return Vec2f(x + other.x, y + other.y);
}

Vec2f Vec2f::operator-(const Vec2f &other) const {
    return Vec2f(x - other.x, y - other.y);
}

Vec2f Vec2f::operator*(const Vec2f &other) const {
    return Vec2f(x * other.x, y * other.y);
}

float Vec2f::Dot(const Vec2f &other) const {
    return x * other.x + y * other.y;
}

Vec2f Vec2f::operator*(const float &other) const {
    return Vec2f(x * other, y * other);
}

Vec2f Vec2f::operator/(const float &other) const {
    return Vec2f(x / other, y / other);
}

Vec2f &Vec2f::operator+=(const Vec2f &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2f &Vec2f::operator-=(const Vec2f &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2f &Vec2f::operator*=(const Vec2f &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2f &Vec2f::operator*=(const float &other) {
    x *= other;
    y *= other;
    return *this;
}

Vec2f &Vec2f::operator/=(const float &other) {
    x /= other;
    y /= other;
    return *this;
}

bool Vec2f::operator==(const Vec2f &other) const {
    return x == other.x && y == other.y;
}

bool Vec2f::operator==(const Vec2i &other) const {
    return x == other.x && y == other.y;
}

float Vec2f::Magnitude() const {
    return sqrtf(x * x + y * y);
}

Vec2f Vec2f::Normalize() const {
    float magnitude = Magnitude();
    if (magnitude == 0.0f) {
        return Vec2f(0.0f, 0.0f);
    }
    return Vec2f(x, y) / magnitude;
}

std::size_t Vec2f::Hash::operator()(const Vec2f& vec) const {
    std::hash<float> hashFloat;
    return hashFloat(vec.x) ^ (hashFloat(vec.y) << 1);
}
#pragma endregion

#pragma region Vec2i
Vec2i::Vec2i(int x, int y) : x(x), y(y) {}

const Vec2i Vec2i::ZERO = Vec2i(0, 0);
const Vec2i Vec2i::UNIT_X = Vec2i(1, 0);
const Vec2i Vec2i::UNIT_Y = Vec2i(0, 1);
const Vec2i Vec2i::UNIT_XY = Vec2i(1, 1);

Vec2i Vec2i::operator+(const Vec2i &other) const {
    return Vec2i(x + other.x, y + other.y);
}

Vec2i Vec2i::operator-(const Vec2i &other) const {
    return Vec2i(x - other.x, y - other.y);
}

Vec2i Vec2i::operator*(const Vec2i &other) const {
    return Vec2i(x * other.x, y * other.y);
}

int Vec2i::Dot(const Vec2i &other) const {
    return x * other.x + y * other.y;
}

Vec2i Vec2i::operator%(const Vec2i &other) const {
    return Vec2i(x % other.x, y % other.y);
}

Vec2i Vec2i::operator*(const int &other) const {
    return Vec2i(x * other, y * other);
}

Vec2i Vec2i::operator/(const int &other) const {
    return Vec2i(x / other, y / other);
}

Vec2i Vec2i::operator%(const int &other) const {
    return Vec2i(x % other, y % other);
}

Vec2i &Vec2i::operator+=(const Vec2i &other) {
    x += other.x;
    y += other.y;
    return *this;
}

Vec2i &Vec2i::operator-=(const Vec2i &other) {
    x -= other.x;
    y -= other.y;
    return *this;
}

Vec2i &Vec2i::operator*=(const Vec2i &other) {
    x *= other.x;
    y *= other.y;
    return *this;
}

Vec2i &Vec2i::operator*=(const int &other) {
    x *= other;
    y *= other;

    return *this;
}

Vec2i &Vec2i::operator/=(const int &other) {
    x /= other;
    y /= other;
    return *this;
}

bool Vec2i::operator==(const Vec2i &other) const {
    return x == other.x && y == other.y;
}

bool Vec2i::operator==(const Vec2f &other) const {
    return x == other.x && y == other.y;
}

float Vec2i::Magnitude() const {
    return sqrt(x * x + y * y);
}

Vec2f Vec2i::Normalize() const {
    int magnitude = Magnitude();
    if (magnitude == 0) {
        return Vec2f(0, 0);
    }
    return Vec2f(x, y) / magnitude;
}

std::size_t Vec2i::Hash::operator()(const Vec2i& vec) const {
    std::hash<int> hashInt;
    return hashInt(vec.x) ^ (hashInt(vec.y) << 1);
}
#pragma endregion