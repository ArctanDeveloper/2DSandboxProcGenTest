#ifndef VEC_H
#define VEC_H
#include <functional>

namespace ProceduralSandbox::Util {
    struct Vec2f;
    struct Vec2i;

    /**
     * @struct Vec2f
     * @brief Represents a 2D vector with float components.
     * 
     * This structure allows for basic 2D vector operations such as addition, subtraction, multiplication,
     * and dot product calculations, as well as vector normalization and magnitude computation.
     */
    struct Vec2f {
        Vec2f() = default; ///< Default constructor.

        /**
         * @brief Constructs a Vec2f with given x and y values.
         * @param x The x-coordinate of the vector.
         * @param y The y-coordinate of the vector.
         */
        Vec2f(float x, float y);

        float x; ///< X-coordinate of the vector.
        float y; ///< Y-coordinate of the vector.

        static const Vec2f ZERO;   ///< Zero vector (0, 0).
        static const Vec2f UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2f UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2f UNIT_XY;///< Unit vector in both the X and Y directions (1, 1).

        /**
         * @brief Adds two Vec2f vectors.
         * @param other The other Vec2f to add.
         * @return The result of the vector addition.
         */
        Vec2f operator+(const Vec2f& other) const;

        /**
         * @brief Subtracts two Vec2f vectors.
         * @param other The other Vec2f to subtract.
         * @return The result of the vector subtraction.
         */
        Vec2f operator-(const Vec2f& other) const;

        /**
         * @brief Multiplies two Vec2f vectors component-wise.
         * @param other The other Vec2f to multiply.
         * @return The result of the component-wise multiplication.
         */
        Vec2f operator*(const Vec2f& other) const;

        /**
         * @brief Computes the dot product with another Vec2f.
         * @param other The other Vec2f to compute the dot product with.
         * @return The dot product of the two vectors.
         */
        float Dot(const Vec2f& other) const;

        /**
         * @brief Multiplies the vector by a scalar.
         * @param other The scalar value.
         * @return The result of the scalar multiplication.
         */
        Vec2f operator*(const float& other) const;

        /**
         * @brief Divides the vector by a scalar.
         * @param other The scalar value.
         * @return The result of the scalar division.
         */
        Vec2f operator/(const float& other) const;

        /**
         * @brief Adds another Vec2f to this vector.
         * @param other The Vec2f to add.
         * @return A reference to this vector after the addition.
         */
        Vec2f& operator+=(const Vec2f& other);

        /**
         * @brief Subtracts another Vec2f from this vector.
         * @param other The Vec2f to subtract.
         * @return A reference to this vector after the subtraction.
         */
        Vec2f& operator-=(const Vec2f& other);

        /**
         * @brief Multiplies this vector by another Vec2f component-wise.
         * @param other The Vec2f to multiply with.
         * @return A reference to this vector after the multiplication.
         */
        Vec2f& operator*=(const Vec2f& other);

        /**
         * @brief Multiplies this vector by a scalar.
         * @param other The scalar value.
         * @return A reference to this vector after the scalar multiplication.
         */
        Vec2f& operator*=(const float& other);

        /**
         * @brief Divides this vector by a scalar.
         * @param other The scalar value.
         * @return A reference to this vector after the scalar division.
         */
        Vec2f& operator/=(const float& other);

        /**
         * @brief Checks if two Vec2f vectors are equal.
         * @param other The other Vec2f to compare.
         * @return True if the vectors are equal, false otherwise.
         */
        bool operator==(const Vec2f& other) const;

        /**
         * @brief Checks if a Vec2f vector and a Vec2i vector are equal.
         * @param other The Vec2i to compare.
         * @return True if the vectors are equal, false otherwise.
         */
        bool operator==(const Vec2i& other) const;

        /**
         * @brief Computes the magnitude (length) of the vector.
         * @return The magnitude of the vector.
         */
        float Magnitude() const;

        /**
         * @brief Returns a normalized version of the vector (magnitude = 1).
         * @return A normalized Vec2f.
         */
        Vec2f Normalize() const;

        struct Hash {
            /**
             * @brief Computes the hash for a Vec2f vector.
             * @param vec The Vec2f to hash.
             * @return The hash value for the vector.
             */
            std::size_t operator()(const Vec2f& vec) const;
        };
    };

    /**
     * @struct Vec2i
     * @brief Represents a 2D vector with integer components.
     * 
     * This structure allows for basic 2D vector operations such as addition, subtraction, multiplication,
     * and dot product calculations, as well as vector normalization and magnitude computation, for integer-based vectors.
     */
    struct Vec2i {
        Vec2i() = default; ///< Default constructor.

        /**
         * @brief Constructs a Vec2i with given x and y values.
         * @param x The x-coordinate of the vector.
         * @param y The y-coordinate of the vector.
         */
        Vec2i(int x, int y);

        int x; ///< X-coordinate of the vector.
        int y; ///< Y-coordinate of the vector.

        static const Vec2i ZERO;   ///< Zero vector (0, 0).
        static const Vec2i UNIT_X; ///< Unit vector in the X direction (1, 0).
        static const Vec2i UNIT_Y; ///< Unit vector in the Y direction (0, 1).
        static const Vec2i UNIT_XY;///< Unit vector in both the X and Y directions (1, 1).

        /**
         * @brief Adds two Vec2i vectors.
         * @param other The other Vec2i to add.
         * @return The result of the vector addition.
         */
        Vec2i operator+(const Vec2i& other) const;

        /**
         * @brief Subtracts two Vec2i vectors.
         * @param other The other Vec2i to subtract.
         * @return The result of the vector subtraction.
         */
        Vec2i operator-(const Vec2i& other) const;

        /**
         * @brief Multiplies two Vec2i vectors component-wise.
         * @param other The other Vec2i to multiply.
         * @return The result of the component-wise multiplication.
         */
        Vec2i operator*(const Vec2i& other) const;

        /**
         * @brief Computes the dot product with another Vec2i.
         * @param other The other Vec2i to compute the dot product with.
         * @return The dot product of the two vectors.
         */
        int Dot(const Vec2i& other) const;

        /**
         * @brief Computes the modulus (remainder) of the vector components with another Vec2i.
         * @param other The other Vec2i for the modulus operation.
         * @return The result of the modulus operation.
         */
        Vec2i operator%(const Vec2i& other) const;

        /**
         * @brief Multiplies the vector by an integer scalar.
         * @param other The scalar value.
         * @return The result of the scalar multiplication.
         */
        Vec2i operator*(const int& other) const;

        /**
         * @brief Divides the vector by an integer scalar.
         * @param other The scalar value.
         * @return The result of the scalar division.
         */
        Vec2i operator/(const int& other) const;

        /**
         * @brief Computes the modulus (remainder) of the vector components with an integer scalar.
         * @param other The scalar value for the modulus operation.
         * @return The result of the modulus operation.
         */
        Vec2i operator%(const int& other) const;

        /**
         * @brief Adds another Vec2i to this vector.
         * @param other The Vec2i to add.
         * @return A reference to this vector after the addition.
         */
        Vec2i& operator+=(const Vec2i& other);

        /**
         * @brief Subtracts another Vec2i from this vector.
         * @param other The Vec2i to subtract.
         * @return A reference to this vector after the subtraction.
         */
        Vec2i& operator-=(const Vec2i& other);

        /**
         * @brief Multiplies this vector by another Vec2i component-wise.
         * @param other The Vec2i to multiply with.
         * @return A reference to this vector after the multiplication.
         */
        Vec2i& operator*=(const Vec2i& other);

        /**
         * @brief Multiplies this vector by an integer scalar.
         * @param other The scalar value.
         * @return A reference to this vector after the scalar multiplication.
         */
        Vec2i& operator*=(const int& other);

        /**
         * @brief Divides this vector by an integer scalar.
         * @param other The scalar value.
         * @return A reference to this vector after the scalar division.
         */
        Vec2i& operator/=(const int& other);

        /**
         * @brief Checks if two Vec2i vectors are equal.
         * @param other The other Vec2i to compare.
         * @return True if the vectors are equal, false otherwise.
         */
        bool operator==(const Vec2i& other) const;

        /**
         * @brief Checks if a Vec2i vector and a Vec2f vector are equal.
         * @param other The Vec2f to compare.
         * @return True if the vectors are equal, false otherwise.
         */
        bool operator==(const Vec2f& other) const;

        /**
         * @brief Computes the magnitude (length) of the vector.
         * @return The magnitude of the vector.
         */
        float Magnitude() const;

        /**
         * @brief Returns a normalized version of the vector (magnitude = 1).
         * @return A normalized Vec2f.
         */
        Vec2f Normalize() const;

        struct Hash {
            /**
             * @brief Computes the hash for a Vec2i vector.
             * @param vec The Vec2i to hash.
             * @return The hash value for the vector.
             */
            std::size_t operator()(const Vec2i& vec) const;
        };
    };
}

#endif // VEC_H