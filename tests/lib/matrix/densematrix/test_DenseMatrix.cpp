#include <gtest/gtest.h>
#include <matrix/densematrix/DenseMatrix.hpp>
#include <matrix/size/MatrixSize.hpp>

TEST(DenseMatrix, validSize) {
	DenseMatrix<int> matrix(MatrixSize(2, 3));
	EXPECT_EQ(matrix.size, MatrixSize(2, 3));
}

TEST(DenseMatrix, validValues_1_x_1) {
	int* values = new int[6];
	DenseMatrix<int> matrix(MatrixSize(1, 1), values);
	EXPECT_EQ(matrix[0][0], values[0]);
}
