#ifndef RULE_HPP_INCLUDED
#define RULE_HPP_INCLUDED


struct Rule {
	// Rule represents a state change occuring
	// between two agents when they meet each other.
	// char is used to represent a state, taking
	// the values -1 (no), 0 (unsure) and 1 (yes).
	const std::pair<char, char> before;
	const std::pair<char, char> after;
	Rule(const std::pair<char, char>& before, const std::pair<char, char>& after);
};

#endif // RULE_HPP_INCLUDED
