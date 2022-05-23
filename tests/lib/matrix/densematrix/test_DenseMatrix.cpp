#include <gtest/gtest.h>
#include <matrix/densematrix/DenseMatrix.hpp>
#include <matrix/size/MatrixSize.hpp>

TEST(DenseMatrix, validSize) {
	DenseMatrix<int> matrix(MatrixSize(2, 3));
	EXPECT_EQ(matrix.size, MatrixSize(2, 3));
}
