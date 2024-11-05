#ifndef VEC_H
#define VEC_H
#include <functional>

namespace ProceduralSandbox::Util {
    /**
     * @struct Vec2f
     * @brief Represents a 2D vector with float components.
     */
    struct Vec2f {
        Vec2f() = default;
        
        /**
         * @brief Constructs a Vec2f with given x and y values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        Vec2f(float x, float y);

        float x; ///< X-coordinate.
        float y; ///< Y-coordinate.

        static const Vec2f ZERO;   ///< Zero vector (0, 0).
        static const Vec2f UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2f UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2f UNIT_XY;///< Unit vector in the X and Y directions (1, 1).

        Vec2f operator+(const Vec2f& other) const; ///< Adds two Vec2f vectors.
        Vec2f operator-(const Vec2f& other) const; ///< Subtracts two Vec2f vectors.
        Vec2f operator*(const Vec2f& other) const; ///< Multiplies two Vec2f vectors.
        float Dot(const Vec2f& other) const;       ///< Computes the dot product with another Vec2f.

        Vec2f operator*(const float& other) const; ///< Multiplies vector by a scalar.
        Vec2f operator/(const float& other) const; ///< Divides vector by a scalar.

        Vec2f& operator+=(const Vec2f& other); ///< Adds another Vec2f to this vector.
        Vec2f& operator-=(const Vec2f& other); ///< Subtracts another Vec2f from this vector.
        Vec2f& operator*=(const Vec2f& other); ///< Multiplies this vector by another Vec2f.

        Vec2f& operator*=(const float& other); ///< Multiplies this vector by a scalar.
        Vec2f& operator/=(const float& other); ///< Divides this vector by a scalar.

        bool operator==(const Vec2f& other) const; ///< Checks if two Vec2f vectors are equal.

        float Magnitude() const;       ///< Computes the magnitude (length) of the vector.
        Vec2f Normalize() const;       ///< Returns a normalized version of the vector.
        Vec2f VectorTo(const Vec2f& other) const; ///< Returns a vector from this to another Vec2f.

        struct Hash {
            std::size_t operator()(const Vec2f& vec) const;
        };
    };

    /**
     * @struct Vec2i
     * @brief Represents a 2D vector with integer components.
     */
    struct Vec2i {
        Vec2i() = default;

        /**
         * @brief Constructs a Vec2i with given x and y values.
         * @param x The x-coordinate.
         * @param y The y-coordinate.
         */
        Vec2i(int x, int y);

        int x; ///< X-coordinate.
        int y; ///< Y-coordinate.

        static const Vec2i ZERO;   ///< Zero vector (0, 0).
        static const Vec2i UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2i UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2i UNIT_XY;///< Unit vector in the X and Y directions (1, 1).

        Vec2i operator+(const Vec2i& other) const;
        Vec2i operator-(const Vec2i& other) const;
        Vec2i operator*(const Vec2i& other) const;
        int Dot(const Vec2i& other) const;
        Vec2i operator%(const Vec2i& other) const;

        Vec2i operator*(const int& other) const;
        Vec2i operator/(const int& other) const;
        Vec2i operator%(const int& other) const;

        Vec2i& operator+=(const Vec2i& other);
        Vec2i& operator-=(const Vec2i& other);
        Vec2i& operator*=(const Vec2i& other);

        Vec2i& operator*=(const int& other);
        Vec2i& operator/=(const int& other);

        bool operator==(const Vec2i& other) const;

        int Magnitude() const;   ///< Computes the magnitude (length) of the vector.
        Vec2i Normalize() const; ///< Returns a normalized version of the vector.
        Vec2i VectorTo(const Vec2i& other) const; ///< Returns a vector from this to another Vec2i.

        struct Hash {
            std::size_t operator()(const Vec2i& vec) const;
        };
    };
}
#endif