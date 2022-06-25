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
	void LinearSystemSolver<DT>::buildRec(
		const std::vector<short> states,
		const short rulesCount,
		Rule* const* rules,
		std::map<std::vector<short>, std::vector<Rule*>>* rulesByStates
	) const {
		std::vector<Rule*> applicableRules = findApplicableRules(states, rulesCount, rules);
		(*rulesByStates)[states] = applicableRules;
		for (short i = 0; i < applicableRules.size(); ++i) {
			Rule* rule = applicableRules[i];
			// copy states
			std::vector<short> newStates = states;
			// apply rule
			rule->apply(&newStates[0]);
			if (rulesByStates->contains(newStates)) continue;
			buildRec(newStates, rulesCount, rules, rulesByStates);
		}
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
		this->buildRec(states, rulesCount, rules, &rulesByStates);
		std::cout << "--------- DEBUG ----------" << std::endl;
		for (auto it = rulesByStates.begin(); it != rulesByStates.end(); ++it) {
			std::cout << "states: ";
			int total = 0;
			for (short i = 0; i < it->first.size(); ++i) {
				std::cout << it->first[i] << " ";
				total += it->first[i];
			}
			int contot = total * (total - 1) / 2;
			std::cout << " : ";
			for (short i = 0; i < it->second.size(); ++i) {
				double chance = (it->first[it->second[i]->before[0]]*it->first[it->second[i]->before[1]]) / double(contot);
				std::cout << it->second[i]->before[0] << ',' << it->second[i]->before[1] << " -> " << it->second[i]->after[0] << ',' << it->second[i]->after[1] << "(" << chance << ") |";
			}
			std::cout << std::endl;
		}

		return 0;
	}
}
