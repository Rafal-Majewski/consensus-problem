#include "./MonteCarloSolver.hpp"
#include <algorithm>


namespace ConsensusProblem {
	template <typename DT>
	MonteCarloSolver<DT>::MonteCarloSolver(
		const int iterationsCount
	) : iterationsCount(iterationsCount) {}

	// template <typename DT>
	// short MonteCarloSolver<DT>::findApplicableRules(
	// 	const short statesCount,
	// 	const short* states,
	// 	const short rulesCount,
	// 	const Rule* const* rules,
	// 	Rule* const* applicableRules
	// ) const {
	// 	short applicableRulesCount = 0;
	// 	for (short i = 0; i < rulesCount; ++i) {
	// 		const Rule* rule = rules[i];
	// 		if (!rule->isApplicable(states)) continue;
	// 		applicableRules[applicableRulesCount++] = rule;
	// 	}
	// 	return applicableRulesCount;
	// }

	// template <typename DT>
	// void MonteCarloSolver<DT>::simulate(
	// 	const short statesCount,
	// 	short* states,
	// 	const short rulesCount,
	// 	const Rule** rules
	// ) const {
	// 	Rule** applicableRules = new Rule*[rulesCount];
	// 	while (true) {
	// 		const short applicableRulesCount = this->findApplicableRules(
	// 			statesCount,
	// 			states,
	// 			rulesCount,
	// 			rules,
	// 			applicableRules
	// 		);
	// 		if (applicableRulesCount == 0) return;
	// 		tmp(statesCount, states, applicableRulesCount, applicableRules)
	// 		// const short randomRuleIndex = rand() % applicableRulesCount;
	// 		// const Rule& rule = applicableRules[randomRuleIndex];
	// 		// this->applyRule(states, rule);
	// 		// while (true) {

	// 		// 	for 
	// 		// }
			
	// 	}
	// }

	// template <typename DT>
	// void MonteCarloSolver<DT>::tmp(
	// 	short statesCount,
	// 	short* states,
	// 	const short applicableRulesCount,
	// 	const Rule** applicableRules
	// ) const {
	// 	while (true) {
	// 		const short randomStateIndex1 = rand() % statesCount;
	// 		const short randomStateIndex2 = rand() % statesCount;
	// 		if (randomStateIndex1 == randomStateIndex2) continue;
	// 		for (short i = 0; i < applicableRulesCount; ++i) {
	// 			const Rule* rule = applicableRules[i];
	// 			if (!rule->isApplicable(states)) continue;
	// 			rule->apply(states);
	// 			return;
	// 		}
	// 	}
	// }

	// template <typename DT>
	// bool MonteCarloSolver<DT>::iteration(
	// 	const short statesCount,
	// 	const short* targetStates,
	// 	const short* startingStates,
	// 	const short rulesCount,
	// 	const Rule* rules
	// ) const {
	// 	short* states = new short[statesCount];
	// 	std::copy(startingStates, startingStates + statesCount, states);
	// 	this->simulate(statesCount, states, rulesCount, rules);
	// 	return std::equal(states, states + statesCount, targetStates);
	// }

	template <typename DT>
	DT MonteCarloSolver<DT>::solve(
		const short statesCount,
		const short* targetStates,
		const short* startingStates,
		const short rulesCount,
		const Rule* const* rules
	) const {
		return 0;
		// DT matchesCount = 0;
		// for (int i = 0; i < this->iterationsCount; ++i) {
		// 	matchesCount += this->iteration(statesCount, targetStates, startingStates, rulesCount, rules);
		// }
		// return matchesCount / this->iterationsCount;
	}
}
