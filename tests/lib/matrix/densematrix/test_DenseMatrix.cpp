#include <gtest/gtest.h>
#include <matrix/densematrix/DenseMatrix.hpp>
#include <matrix/size/MatrixSize.hpp>


TEST(DenseMatrix, validSize) {
	DenseMatrix<int> matrix(MatrixSize(2, 3));
	EXPECT_EQ(matrix.size, MatrixSize(2, 3));
}

TEST(DenseMatrix, validValues_1_x_1) {
	int* values = new int[1] {1};
	DenseMatrix<int> matrix(MatrixSize(1, 1), values);
	EXPECT_EQ(matrix[0][0], values[0]);
}

TEST(DenseMatrix, validValues_2_x_1) {
	int* values = new int[2] {1, 2};
	DenseMatrix<int> matrix(MatrixSize(2, 1), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[1][0], values[1]);
}

TEST(DenseMatrix, validValues_1_x_2) {
	int* values = new int[2] {1, 2};
	DenseMatrix<int> matrix(MatrixSize(1, 2), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[0][1], values[1]);
}

TEST(DenseMatrix, validValues_2_x_2) {
	int* values = new int[4] {1, 2, 3, 4};
	DenseMatrix<int> matrix(MatrixSize(2, 2), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[0][1], values[1]);
	EXPECT_EQ(matrix[1][0], values[2]);
	EXPECT_EQ(matrix[1][1], values[3]);
}

TEST(DenseMatrix, validValues_3_x_3) {
	int* values = new int[9] {1, 2, 3, 4, 5, 6, 7, 8, 9};
	DenseMatrix<int> matrix(MatrixSize(3, 3), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[0][1], values[1]);
	EXPECT_EQ(matrix[0][2], values[2]);
	EXPECT_EQ(matrix[1][0], values[3]);
	EXPECT_EQ(matrix[1][1], values[4]);
	EXPECT_EQ(matrix[1][2], values[5]);
	EXPECT_EQ(matrix[2][0], values[6]);
	EXPECT_EQ(matrix[2][1], values[7]);
	EXPECT_EQ(matrix[2][2], values[8]);
}
