#ifndef MATH_LINEAR_ALGEBRA_TRANSFORMATION_H
#define MATH_LINEAR_ALGEBRA_TRANSFORMATION_H

#include <assert.h>

#include "vector.h"
#include "matrix.h"

namespace math
{
    // NOTE(Joey): scale
    // -----------------
    template <unsigned int n, typename T>
    matrix<n, n, T> scale(vector<n, T> scale)
    {
        matrix<n, n, T> mat;
        for (unsigned int i = 0; i < n; ++i)
            mat[i][i] = scale[i];
        return mat;
    }
    // NOTE(Joey): version w/ reference
    template <unsigned int n, typename T>
    matrix<n, n, T>& scale(matrix<n, n, T>& result, vector<n, T> scale)
    {
        // NOTE(Joey): we can do a manual operation on the matrix scale
        for(unsigned int i = 0; i < n; ++i)
            result[i][i] *= scale[i];
        return result;
    }

    // NOTE(Joey): rotation
    // --------------------
    // NOTE(Joey): getting a direct rotation matrix is only allowed on 3 dimensions
    template <typename T>
    matrix<3, 3, T> rotate(vector<3, T> axis, T radians)
    {
        matrix<3, 3, T> mat;
        return mat;
    }

    // TODO(Joey): find mathematical proof of rotation matrix around any axis
    template <typename T>
    matrix<3, 3, T>& rotate(matrix<3, 3, T> &result, vector<3, T> axis, T radians)
    {
        matrix<3, 3, T> mat;

        result = mat * result;
        return result;
    }

    // TODO(Joey): think of clean API way to seperate 4 dimensional vector in 3 
    // dimensions before storing it back as 4 dimensional vector.
    template <typename T>
    matrix<4, 4, T>& rotate(matrix<4, 4, T> &result, vector<3, T> axis, T radians)
    {
        matrix<3, 3, T> mat;

        result = result * mat;
        return result;
    }

    // NOTE(Joey): translation
    // -----------------------
    // NOTE(Joey): translations are only defined for 4-dimensional matrices/vectors
    template <typename T>
    matrix<4, 4, T> translate(vector<3, T> translation)
    {
        matrix<4, 4, T> mat;
        mat[3] = vector<4, T>(translation, 1.0);
        return mat;
    }

    template <typename T>
    matrix<4, 4, T>& translate(matrix<4, 4, T> &result, vector<3, T> translation)
    {
        matrix<4, 4, T> mat;
        mat[3] = vector<4, T>(translation, 1.0);

        result = result * mat;
        return result;
    }

    // NOTE(Joey): view-space 
    // ----------------------
    template <typename T>
    matrix<4, 4, T> lookAt(vector<3, T> position, vector<3, T> target, vector<3, T> up)
    {
        matrix<4, 4 T> result;

        return result;
    }

    // NOTE(Joey): projection
    // ----------------------
    template <typename T>
    matrix<4, 4, T> orthographic(T left, T right, T top, T bottom, T near, T far)
    {
        matrix<4, 4, T> result;

        return result;
    }

    template <typename T>
    matrix<4, 4, T> perspective(T fov, T aspect, T near, T far)
    {
        matrix<4, 4, T> result;

        return result;
    }
}
#endif