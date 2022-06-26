#include "./LinearSystemSolver.hpp"


namespace ConsensusProblem {
	template <typename DT, typename MTRX>
	std::vector<Rule*> LinearSystemSolver<DT, MTRX>::findApplicableRules(
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

	template <typename DT, typename MTRX>
	void LinearSystemSolver<DT, MTRX>::buildRec(
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

	template <typename DT, typename MTRX>
	DT LinearSystemSolver<DT, MTRX>::solve(
		const short statesCount,
		const short* targetStates,
		const short* startingStates,
		const short rulesCount,
		Rule* const* rules
	) const {
		std::vector<short> targetStatesVec(statesCount);
		std::vector<short> startingStatesVec(statesCount);
		std::copy(targetStates, targetStates + statesCount, targetStatesVec.begin());
		std::copy(startingStates, startingStates + statesCount, startingStatesVec.begin());

		std::map<std::vector<short>, std::vector<Rule*>> rulesByStates;
		int total = 0;
		for (short i = 0; i < statesCount; ++i) {
			total += startingStates[i];
		}
		int contot = total * (total - 1) / 2;
		// will be used to build the linear system

		std::vector<short> states(startingStates, startingStates + statesCount);
		this->buildRec(states, rulesCount, rules, &rulesByStates);
		// std::cout << "--------- DEBUG ----------" << std::endl;
		// for (auto it = rulesByStates.begin(); it != rulesByStates.end(); ++it) {
			
		// 	for (short i = 0; i < it->first.size(); ++i) {
		// 		std::cout << it->first[i] << " ";
		// 	}
		// 	std::cout << " : ";
		// 	for (short i = 0; i < it->second.size(); ++i) {
		// 		double chance = (it->first[it->second[i]->before[0]]*it->first[it->second[i]->before[1]]) / double(contot);
		// 		std::cout << it->second[i]->before[0] << ',' << it->second[i]->before[1] << " -> " << it->second[i]->after[0] << ',' << it->second[i]->after[1] << "(" << chance << ") |";
		// 	}
		// 	std::cout << std::endl;
		// }
		// std::cout << "states: " << states.size() << std::endl;
		std::vector<std::vector<short>> variableDecoder;
		std::map<std::vector<short>, int> variableEncoder;
		for (auto it = rulesByStates.begin(); it != rulesByStates.end(); ++it) {
			
			variableDecoder.push_back(it->first);
			const int variableId = variableDecoder.size() - 1;
			variableEncoder[it->first] = variableId;
			// std::cout << variableId << ".\t";
			// for (short i = 0; i < it->first.size(); ++i) {
			// 	std::cout << it->first[i] << " ";
			// }
			// std::cout << " : ";
			// for (short i = 0; i < it->second.size(); ++i) {
			// 	double chance = (it->first[it->second[i]->before[0]]*it->first[it->second[i]->before[1]]) / double(contot);
			// 	std::cout << it->second[i]->before[0] << ',' << it->second[i]->before[1] << " -> " << it->second[i]->after[0] << ',' << it->second[i]->after[1] << "(" << chance << ") |";
			// }
			// std::cout << std::endl;

		}

		const int variablesCount = rulesByStates.size();
		LinearSystem<DT> linearSystem(
			LinearSystemSize(variablesCount, variablesCount),
			MTRX::zero(MatrixSize(variablesCount, variablesCount)),
			new DT[](variablesCount)
		);
		std::fill(linearSystem.constants, linearSystem.constants + variablesCount, 0);
		for (auto it = rulesByStates.begin(); it != rulesByStates.end(); ++it) {
			const std::vector<short>& states = it->first;
			const int mainVariableId = variableEncoder[states];
			(*linearSystem.coefficients)(mainVariableId, mainVariableId) = 1;
			const std::vector<Rule*>& rules = it->second;
			// iterate over all rules
			double chanceLeft = 1;
			for (const Rule* rule : rules) {
				std::vector<short> newStates = states;
				(*rule).apply(&newStates[0]);
				const int newVariableId = variableEncoder[newStates];

				int contot = total * (total - 1) / 2;
				double chance = (states[rule->before[0]]*states[rule->before[1]]) / double(contot);
				chanceLeft -= chance;
				(*linearSystem.coefficients)(mainVariableId, newVariableId) -= chance;

				// (*linearSystem.coefficients)(rule->before[0], rule->before[1]) += 1;
				// (*linearSystem.coefficients)(rule->after[0], rule->after[1]) -= 1;
			}
			if(rules.size()) (*linearSystem.coefficients)(mainVariableId, mainVariableId) -= chanceLeft;
			
		}
		const int targetStatesVariableId = variableEncoder[targetStatesVec];
		const int startingStatesVariableId = variableEncoder[startingStatesVec];
		linearSystem.constants[targetStatesVariableId] = 1;
		// print the linear system
		// std::cout << "Linear system:" << std::endl;
		// std::cout << "\t";
		// for (int x = 0; x < variablesCount; ++x) {
		// 	std::cout << "p" << variableDecoder[x][0] << variableDecoder[x][2] << "\t";
		// }
		// std::cout << std::endl;
		// for (int y = 0; y < variablesCount; ++y) {
		// 	std::cout << "p" << variableDecoder[y][0] << variableDecoder[y][2] << "\t";
		// 	for (int x = 0; x < variablesCount; ++x) {
		// 		std::cout << (*linearSystem.coefficients)(y, x) << "\t";
		// 	}
		// 	std::cout << "|\t" << linearSystem.constants[y] << std::endl;
		// }
		// solve the linear system
		DT solution[variablesCount];
		this->solver->solve(linearSystem, solution);
		// std::cout << "Linear system solved:" << std::endl;
		// // print the linear system
		// for (int y = 0; y < variablesCount; ++y) {
		// 	for (int x = 0; x < variablesCount; ++x) {
		// 		std::cout << (*linearSystem.coefficients)(y, x) << "\t";
		// 	}
		// 	std::cout << "|\t" << linearSystem.constants[y] << std::endl;
		// }
		// // print the solution
		// std::cout << "Solution:" << std::endl;
		// for (int x = 0; x < variablesCount; ++x) {
		// 	std::cout << "p" << variableDecoder[x][0] << variableDecoder[x][2] << " = " << solution[x] << std::endl;
		// }

	
		return solution[startingStatesVariableId];
	}

	template <typename DT, typename MTRX>
	LinearSystemSolver<DT, MTRX>::LinearSystemSolver(
		const Numalg::LinearSystemSolver<DT>* solver
	) :
		solver(solver) {
	}
}
