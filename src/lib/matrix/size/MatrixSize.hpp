#ifndef MATRIXSIZE_HPP_INCLUDED
#define MATRIXSIZE_HPP_INCLUDED


struct MatrixSize {
	const int rowsCount;
	const int columnsCount;
	MatrixSize(int rowsCount, int columnsCount);
	bool operator==(const MatrixSize& other) const;
	bool operator!=(const MatrixSize& other) const;
	MatrixSize operator*(const MatrixSize& other) const;
};


#endif // MATRIXSIZE_H_INCLUDED
