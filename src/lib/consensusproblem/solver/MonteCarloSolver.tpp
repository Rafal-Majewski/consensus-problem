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
		for (short i = 0; i < rulesCount; ++i) {
			const Rule& rule = rules[i];
			if (!this->checkIfRuleIsApplicable(states, rule)) continue;
			applicableRules[applicableRulesCount++] = rule;
		}
		return applicableRulesCount;
	}

	template <typename DT>
	void MonteCarloSolver<DT>::applyRule(
		short* states,
		const Rule& rule
	) const {
		--states[rule.first.first];
		--states[rule.first.second];
		++states[rule.second.first];
		++states[rule.second.second];
	}

	template <typename DT>
	void MonteCarloSolver<DT>::simulate(
		const short statesCount,
		short* states,
		const short rulesCount,
		const Rule* rules
	) const {
		Rule* applicableRules = new Rule[rulesCount];
		while (true) {
			const short applicableRulesCount = this->findApplicableRules(
				statesCount,
				states,
				rulesCount,
				rules,
				applicableRules
			);
			if (applicableRulesCount == 0) return;
			const short randomRuleIndex = rand() % applicableRulesCount;
			const Rule& rule = applicableRules[randomRuleIndex];
			this->applyRule(states, rule);
		}
	}

	template <typename DT>
	bool MonteCarloSolver<DT>::iteration(
		const short statesCount,
		const short* targetStates,
		const short* startingStates,
		const short rulesCount,
		const Rule* rules
	) const {
		short* states = new short[statesCount];
		std::copy(startingStates, startingStates + statesCount, states);
		this->simulate(statesCount, states, rulesCount, rules);
		return std::equal(states, states + statesCount, targetStates);
	}

	template <typename DT>
	DT MonteCarloSolver<DT>::solve(
		const short statesCount,
		const short* targetStates,
		const short* startingStates,
		const short rulesCount,
		const Rule* rules
	) const {
		DT matchesCount = 0;
		for (int i = 0; i < this->iterationsCount; ++i) {
			matchesCount += this->iteration(statesCount, targetStates, startingStates, rulesCount, rules);
		}
		return matchesCount / this->iterationsCount;
	}
}
