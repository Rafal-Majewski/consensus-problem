#include "./Rule.hpp"


namespace ConsensusProblem {
	Rule::Rule(
		const std::array<const short, 2> before,
		const std::array<const short, 2> after
	) : before(before), after(after) {}
}
