#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>

class gameMechanic
{
public:
	bool winConditionPlayer1();
	bool winConditionPlayer2();
	gameMechanic(std::vector<int>);
	int getStartingNodeOnGameCondition();
private:
	std::vector<int> currentGameCondition;
};
