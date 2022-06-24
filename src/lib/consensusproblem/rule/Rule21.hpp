#ifndef CONSENSUSPROBLEM_RULE21_HPP_INCLUDED
#define CONSENSUSPROBLEM_RULE21_HPP_INCLUDED

#include "./Rule.hpp"


namespace ConsensusProblem {
	class Rule21 : public Rule {
		public:

		bool isApplicable(const short* states) const override;
		void apply(short* states) const override;
		Rule21(
			const std::array<const short, 2> before,
			const short after
		);
	};
}


#endif // CONSENSUSPROBLEM_RULE21_HPP_INCLUDED
