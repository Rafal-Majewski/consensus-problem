#ifndef MATRIXROW_HPP_INCLUDED
#define MATRIXROW_HPP_INCLUDED


template <typename I>
class MatrixRow {
	public:
	virtual I& operator[](int index) = 0;
};

#endif // MATRIXROW_HPP_INCLUDED
