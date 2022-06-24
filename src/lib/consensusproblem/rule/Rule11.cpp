#include "./Rule11.hpp"


namespace ConsensusProblem {
	bool Rule11::isApplicable(const short* states) const {
		return states[this->before[0]] >= 2;
	}

	void Rule11::apply(short* states) const {
		states[this->before[0]] -= 2;
		states[this->after[0]] += 2;
	}

	Rule11::Rule11(
		const short before,
		const short after
	) : Rule({before, before}, {after, after}) {}
}
