#ifndef AGENTSSTATE_HPP
#define AGENTSSTATE_HPP


struct AgentsState {
	const int yesCount;
	const int unsureCount;
	const int noCount;
	AgentsState(int yesCount, int unsureCount, int noCount);
};

#endif // AGENTSSTATE_HPP
