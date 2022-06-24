#include "./Rule12.hpp"


namespace ConsensusProblem {
	bool Rule12::isApplicable(const short* states) const {
		return states[this->before[0]] >= 2;
	}

	void Rule12::apply(short* states) const {
		states[this->before[0]] -= 2;
		++states[this->after[0]];
		++states[this->after[1]];
	}

	Rule12::Rule12(
		const short before,
		const std::array<const short, 2> after
	) : Rule({before, before}, after) {}
}
