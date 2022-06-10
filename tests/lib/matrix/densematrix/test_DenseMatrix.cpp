#include <gtest/gtest.h>
#include <matrix/densematrix/DenseMatrix.hpp>
#include <matrix/size/MatrixSize.hpp>


TEST(DenseMatrix, constructor_2_x_3_size) {
	DenseMatrix<int> matrix(MatrixSize(2, 3));
	EXPECT_EQ(matrix.size, MatrixSize(2, 3));
}

TEST(DenseMatrix, constructor_1_x_1_values) {
	int* values = new int[1] {1};
	DenseMatrix<int> matrix(MatrixSize(1, 1), values);
	EXPECT_EQ(matrix[0][0], values[0]);
}

TEST(DenseMatrix, constructor_2_x_1_values) {
	int* values = new int[2] {1, 2};
	DenseMatrix<int> matrix(MatrixSize(2, 1), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[1][0], values[1]);
}

TEST(DenseMatrix, constructor_1_x_2_values) {
	int* values = new int[2] {1, 2};
	DenseMatrix<int> matrix(MatrixSize(1, 2), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[0][1], values[1]);
}

TEST(DenseMatrix, constructor_2_x_2_values) {
	int* values = new int[4] {1, 2, 3, 4};
	DenseMatrix<int> matrix(MatrixSize(2, 2), values);
	EXPECT_EQ(matrix[0][0], values[0]);
	EXPECT_EQ(matrix[0][1], values[1]);
	EXPECT_EQ(matrix[1][0], values[2]);
	EXPECT_EQ(matrix[1][1], values[3]);
}

TEST(DenseMatrix, constructor_3_x_3_values) {
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

TEST(DenseMatrix, multiplication_1_x_1_by_1_x_1_values) {
	int* values = new int[1] {1};
	DenseMatrix<int> matrix(MatrixSize(1, 1), values);
	int* values2 = new int[1] {2};
	DenseMatrix<int> matrix2(MatrixSize(1, 1), values2);
	DenseMatrix<int> result = matrix * matrix2;
	EXPECT_EQ(result[0][0], 2);
}

TEST(DenseMatrix, multiplication_3_x_2_by_2_x_3_values) {
	int* values = new int[6] {1, 2, -3, 4, 5, 6};
	DenseMatrix<int> matrix(MatrixSize(3, 2), values);
	int* values2 = new int[6] {-1, 9, 2, 7, 3, -5};
	DenseMatrix<int> matrix2(MatrixSize(2, 3), values2);
	DenseMatrix<int> result = matrix * matrix2;
	EXPECT_EQ(result[0][0], 13);
	EXPECT_EQ(result[0][1], 15);
	EXPECT_EQ(result[0][2], -8);
	EXPECT_EQ(result[1][0], 31);
	EXPECT_EQ(result[1][1], -15);
	EXPECT_EQ(result[1][2], -26);
	EXPECT_EQ(result[2][0], 37);
	EXPECT_EQ(result[2][1], 63);
	EXPECT_EQ(result[2][2], -20);
}