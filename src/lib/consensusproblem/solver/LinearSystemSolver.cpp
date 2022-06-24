#include "./LinearSystemSolver.hpp"


namespace ConsensusProblem {
	template <typename DT>
	std::vector<Rule*> LinearSystemSolver<DT>::findApplicableRules(
		const std::vector<short> states,
		const short rulesCount,
		Rule* const* rules
	) const {
		std::vector<Rule*> applicableRules;
		for (short i = 0; i < rulesCount; ++i) {
			if (!rules[i]->isApplicable(states)) continue;
			applicableRules.push_back(rules[i]);
		}
		return applicableRules;
	}

	template <typename DT>
	DT LinearSystemSolver<DT>::solve(
		const short statesCount,
		const short* targetStates,
		const short* startingStates,
		const short rulesCount,
		Rule* const* rules
	) const {
		std::map<std::vector<short>, std::vector<Rule*>> rulesByStates;
		// will be used to build the linear system

		std::vector<short> states(startingStates, startingStates + statesCount);
		std::vector<Rule*> applicableRules = findApplicableRules(states, rulesCount, rules);
		rulesByStates[states] = applicableRules;

		return 0;
	}
}
