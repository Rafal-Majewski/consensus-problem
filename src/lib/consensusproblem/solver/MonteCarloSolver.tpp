#include "./MonteCarloSolver.hpp"
#include <algorithm>


namespace ConsensusProblem {
	template <typename DT>
	MonteCarloSolver<DT>::MonteCarloSolver(
		const int iterationsCount
	) : iterationsCount(iterationsCount) {}

	template <typename DT>
	bool MonteCarloSolver<DT>::checkIfRuleIsApplicable(
		const short* states,
		const Rule& rule
	) const {
		if (rule.first.first == rule.first.second) {
			return states[rule.first.first] >= 2;
		}
		return states[rule.first.first] >= 1 && states[rule.first.second] >= 1;
	}
		

	template <typename DT>
	short MonteCarloSolver<DT>::findApplicableRules(
		const short statesCount,
		const short* states,
		const short rulesCount,
		const Rule* rules,
		Rule* applicableRules
	) const {
		short applicableRulesCount = 0;
		for (const Rule& rule : rules) {
			if (this->checkIfRuleIsApplicable(states, rule)) {
				applicableRules[applicableRulesCount++] = rule;
			}
		}
		return applicableRulesCount;
	}

	template <typename DT>
	bool MonteCarloSolver<DT>::simulate(
		const short statesCount,
		short* states,
		const short rulesCount,
		const Rule* rules
	) const {
		Rule* applicableRules = new Rule[rulesCount];
		return true;
		// while (true) {

		// }
	}

	template <typename DT>
	bool MonteCarloSolver<DT>::iteration(
		const short targetState,
		const short statesCount,
		const short* startingStates,
		const short rulesCount,
		const Rule* rules
	) const {
		short* states = new short[statesCount];
		std::copy(startingStates, startingStates + statesCount, states);
		this->simulate(statesCount, states, rulesCount, rules);
		return true;
	}

	template <typename DT>
	DT MonteCarloSolver<DT>::solve(
		const short targetState,
		const short statesCount,
		const short* startingStates,
		const short rulesCount,
		const Rule* rules
	) const {
		DT matchesCount = 0;
		for (int i = 0; i < this->iterationsCount; ++i) {
			matchesCount += this->iteration(targetState, statesCount, startingStates, rulesCount, rules);
		}
		return matchesCount / this->iterationsCount;
	}
}
