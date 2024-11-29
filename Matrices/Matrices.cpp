//
//  Matrices.cpp
//  Matrices
//
//  Created by Nooruddin Mohammadi on 9/20/24.
//
#include "Matrices.h"
#include <stdlib.h>

namespace Matrices
{
Matrix::Matrix(int _rows, int _cols)
{
    rows = _rows;
    cols = _cols;
    // constructing a matrix with specified size
    a.resize(rows);
    for (int i = 0; i < rows; ++i)
    {
        a[i].resize(cols, 0);
    }
    //assigning the number of rows and cols to member variables
    
    //intializing each element to zero
    //    for (int i = 0; i < _rows; ++i)
    //    {
    //        for (int j = 0; j < _cols; ++j)
    //        {
    //            a[i][j] = 0;
    //        }
    //    }
    //
}
Matrix operator+(const Matrix& a, const Matrix& b)
{
    Matrix result(a.getRows(), a.getCols());
    if(a.getRows() != b.getRows() && a.getCols() != b.getCols())
        throw runtime_error("Error: dimensions must agree");
    for (int i = 0; i < a.getRows(); ++i)
    {
        for (int j = 0; j < a.getCols(); ++j)
        {
            result(i,j) = a(i,j) + b(i,j);
        }
    }
    return result;
}

///Matrix multiply.  See description.
///usage:  c = a * b;
Matrix operator*(const Matrix& a, const Matrix& b)
{
    Matrix result(a.getRows(), b.getCols());
    
    if(a.getCols() != b.getRows())
    {
        throw runtime_error("Error: dimensions must agree");
    }
    for(int k = 0; k < b.getCols(); ++k)
    {
        for(int i = 0; i < a.getRows(); ++i)
        {
            for(int j = 0; j < b.getRows(); ++j)
            {
                result(i,k) += a(i, j) * b(j, k);
            }
        }
        
    }

    return result;
    
}

///Matrix comparison.  See description.
///usage:  a == b
///How to get cols and rows?
///will the function exit if it hits the return statement inside the for LOOPS?
bool operator==(const Matrix& a, const Matrix& b)
{
    if (a.getRows() != b.getRows() || b.getCols() != a.getCols())
    {
        return false;
    }
    for (int i = 0; i < a.getRows(); ++i)
    {
        for (int j = 0; j < a.getCols(); ++j)
        {
            if (abs(a(i,j) - b(i,j)) >= 0.001)
            {
                return false;
            }
        }
    }
    
    return true;
}
///Matrix comparison.  See description.
///usage:  a != b
bool operator!=(const Matrix& a, const Matrix& b)
{
    return !(a == b);
}

///Output matrix.
///Separate columns by ' ' and rows by '\n'
ostream& operator<<(ostream& os, const Matrix& a)
{
    for (int i = 0; i < a.getRows(); ++i)
    {
        for (int j = 0; j < a.getCols(); ++j)
        {
            os << setw(10) <<a(i,j) << " ";
        }
        os << '\n';
    }
    return os;
}
}
