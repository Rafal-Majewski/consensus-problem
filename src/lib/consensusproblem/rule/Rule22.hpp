#ifndef CONSENSUSPROBLEM_RULE22_HPP_INCLUDED
#define CONSENSUSPROBLEM_RULE22_HPP_INCLUDED

#include "./Rule.hpp"


namespace ConsensusProblem {
	class Rule22 : public Rule {
		public:

		bool isApplicable(const short* states) const override;
		void apply(short* states) const override;
		Rule22(
			const std::array<const short, 2> before,
			const std::array<const short, 2> after
		);
	};
}


#endif // CONSENSUSPROBLEM_RULE22_HPP_INCLUDED
