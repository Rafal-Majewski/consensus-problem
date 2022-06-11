#ifndef LINEARSYSTEMSIZE_HPP_INCLUDED
#define LINEARSYSTEMSIZE_HPP_INCLUDED


struct LinearSystemSize {
	const int equationsCount;
	const int variablesCount;
	LinearSystemSize(int equationsCount, int variablesCount);
	bool operator==(const LinearSystemSize& other) const;
	bool operator!=(const LinearSystemSize& other) const;
};

#endif // LINEARSYSTEMSIZE_HPP_INCLUDED
