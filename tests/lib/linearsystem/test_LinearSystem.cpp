#include <gtest/gtest.h>
#include <linearsystem/LinearSystem.hpp>
#include <linearsystem/size/LinearSystemSize.hpp>


TEST(LinearSystem, constructor_2_x_3_has_valid_size) {
	LinearSystem<int> linearSystem(
		LinearSystemSize(2, 3),
		new int[6] {
			1, 2, 3,
			4, 5, 6
		},
		new int[2] {7, 8}
	);
	EXPECT_EQ(linearSystem.size, LinearSystemSize(2, 3));
}


TEST(LinearSystem, constructor_2_x_3_has_valid_values) {
	LinearSystem<int> linearSystem(
		LinearSystemSize(2, 3),
		new int[6] {
			1, 2, 3,
			4, 5, 6
		},
		new int[2] {7, 8}
	);
	EXPECT_EQ(linearSystem.coefficients[0][0], 1);
	EXPECT_EQ(linearSystem.coefficients[0][1], 2);
	EXPECT_EQ(linearSystem.coefficients[0][2], 3);
	EXPECT_EQ(linearSystem.coefficients[1][0], 4);
	EXPECT_EQ(linearSystem.coefficients[1][1], 5);
	EXPECT_EQ(linearSystem.coefficients[1][2], 6);
	EXPECT_EQ(linearSystem.constants[0], 7);
	EXPECT_EQ(linearSystem.constants[1], 8);
}
