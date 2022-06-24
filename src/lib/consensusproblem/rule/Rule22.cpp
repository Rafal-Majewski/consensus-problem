#include "./Rule22.hpp"


namespace ConsensusProblem {
	bool Rule22::isApplicable(const short* states) const {
		return states[this->before[0]] >= 1
			&& states[this->before[1]] >= 1;
	}

	void Rule22::apply(short* states) const {
		--states[this->before[0]];
		--states[this->before[1]];
		++states[this->after[0]];
		++states[this->after[1]];
	}

	Rule22::Rule22(
		const std::array<const short, 2> before,
		const std::array<const short, 2> after
	) : Rule(before, after) {}
}
