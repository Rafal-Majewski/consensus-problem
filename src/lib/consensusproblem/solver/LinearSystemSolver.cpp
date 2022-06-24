#include "./LinearSystemSolver.hpp"

#include <iostream>


namespace ConsensusProblem {
	template <typename DT>
	std::vector<Rule*> LinearSystemSolver<DT>::findApplicableRules(
		const std::vector<short> states,
		const short rulesCount,
		Rule* const* rules
	) const {
		std::vector<Rule*> applicableRules;
		for (short i = 0; i < rulesCount; ++i) {
			if (!rules[i]->isApplicable(&states[0])) continue;
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
		std::cout << "states: " << std::endl;
		for (short i = 0; i < statesCount; ++i) {
			std::cout << states[i] << " ";
		}
		std::cout << "applicableRules: " << std::endl;
		for (auto rule : applicableRules) {
			std::cout << "  " << rule->before[0] << " " << rule->before[1] << " -> " << rule->after[0] << " " << rule->after[1] << std::endl;
		}

		return 0;
	}
}
