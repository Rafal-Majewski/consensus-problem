#ifndef CONSENSUSPROBLEM_RULE11_HPP_INCLUDED
#define CONSENSUSPROBLEM_RULE11_HPP_INCLUDED

#include "./Rule.hpp"


namespace ConsensusProblem {
	class Rule11 : public Rule {
		public:

		bool isApplicable(const short* states) const override;
		void apply(short* states) const override;
		Rule11(
			const short before,
			const short after
		);
	};
}


#endif // CONSENSUSPROBLEM_RULE11_HPP_INCLUDED
