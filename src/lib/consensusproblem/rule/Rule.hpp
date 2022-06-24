#ifndef CONSENSUSPROBLEM_RULE_HPP_INCLUDED
#define CONSENSUSPROBLEM_RULE_HPP_INCLUDED

#include <utility>
#include <array>


namespace ConsensusProblem {
	class Rule {
		public:

		const std::array<const short, 2> before;
		const std::array<const short, 2> after;

		virtual bool isApplicable(const short* states) const = 0;
		virtual void apply(short* states) const = 0;
		Rule(
			const std::array<const short, 2> before,
			const std::array<const short, 2> after
		);
	};
};


#endif // CONSENSUSPROBLEM_RULE_HPP_INCLUDED
