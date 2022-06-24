#ifndef CONSENSUSPROBLEM_CREATERULE_HPP_INCLUDED
#define CONSENSUSPROBLEM_CREATERULE_HPP_INCLUDED

#include "./Rule.hpp"
#include "./Rule11.hpp"
#include "./Rule12.hpp"
#include "./Rule21.hpp"
#include "./Rule22.hpp"


namespace ConsensusProblem {
	Rule* createRule(
		const std::array<const short, 2> before,
		const std::array<const short, 2> after
	);
}


#endif // CONSENSUSPROBLEM_CREATERULE_HPP_INCLUDED
