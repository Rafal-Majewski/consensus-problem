#include "./createRule.hpp"


namespace ConsensusProblem {
	Rule* createRule(
		const std::array<const short, 2> before,
		const std::array<const short, 2> after
	) {
		if (before[0] == before[1]) {
			if (after[0] == after[1]) {
				return new Rule11(before[0], after[0]);
			} else {
				return new Rule12(before[0], after);
			}
		} else {
			if (after[0] == after[1]) {
				return new Rule21(before, after[0]);
			} else {
				return new Rule22(before, after);
			}
		}
	}
}
