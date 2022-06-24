#ifndef CONSENSUSPROBLEM_RULE12_HPP_INCLUDED
#define CONSENSUSPROBLEM_RULE12_HPP_INCLUDED

#include "./Rule.hpp"


namespace ConsensusProblem {
	class Rule12 : public Rule {
		public:

		bool isApplicable(const short* states) const override;
		void apply(short* states) const override;
		Rule12(
			const short before,
			const std::array<const short, 2> after
		);
	};
}


#endif // CONSENSUSPROBLEM_RULE12_HPP_INCLUDED
