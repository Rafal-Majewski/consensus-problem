#include "./MatrixSize.hpp"


MatrixSize::MatrixSize(int rowsCount, int columnsCount) : rowsCount(rowsCount), columnsCount(columnsCount) {
};

bool MatrixSize::operator==(const MatrixSize& other) const {
	return rowsCount == other.rowsCount && columnsCount == other.columnsCount;
};

bool MatrixSize::operator!=(const MatrixSize& other) const {
	return !operator==(other);
};
