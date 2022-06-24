#include "./Rule11.hpp"


namespace ConsensusProblem {
	bool Rule21::isApplicable(const short* states) const {
		return states[this->before[0]] >= 1
			&& states[this->before[1]] >= 1;
	}

	void Rule21::apply(short* states) const {
		--states[this->before[0]];
		--states[this->before[1]];
		states[this->after[0]] += 2;
	}

	Rule21::Rule21(
		const std::array<const short, 2> before,
		const short after
	) : Rule(before, {after, after}) {}
}
