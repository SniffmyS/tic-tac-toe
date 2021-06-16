#include "gameMechanic.hpp"

gameMechanic::gameMechanic(std::vector<int> cgc)
{
	srand(time(0));
	this->currentGameCondition = cgc;
}

bool gameMechanic::winConditionPlayer1()
{
	if(this->currentGameCondition[0] == 1 && this->currentGameCondition[4] == 1 && this->currentGameCondition[8] == 1)
	{
		return true;
	}
	else if(this->currentGameCondition[2] == 1 && this->currentGameCondition[4] == 1 && this->currentGameCondition[6] == 1)
	{
		return true;
	}
	else if(this->currentGameCondition[0] == 1 && this->currentGameCondition[1] == 1 && this->currentGameCondition[2] == 1)
	{
		return true;
	}
	else if(this->currentGameCondition[3] == 1 && this->currentGameCondition[4] == 1 && this->currentGameCondition[5] == 1)
	{
		return true;
	}
	else if(this->currentGameCondition[6] == 1 && this->currentGameCondition[7] == 1 && this->currentGameCondition[8] == 1)
	{
		return true;
	}
	else if(this->currentGameCondition[0] == 1 && this->currentGameCondition[3] == 1 && this->currentGameCondition[6] == 1)
	{
		return true;
	}
	else if(this->currentGameCondition[1] == 1 && this->currentGameCondition[4] == 1 && this->currentGameCondition[2] == 7)
	{
		return true;
	}
	else if(this->currentGameCondition[2] == 1 && this->currentGameCondition[5] == 1 && this->currentGameCondition[8] == 1)
	{
		return true;
	}
	return false;
}

bool gameMechanic::winConditionPlayer2()
{
	if(this->currentGameCondition[0] == 0 && this->currentGameCondition[4] == 0 && this->currentGameCondition[8] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[2] == 0 && this->currentGameCondition[4] == 0 && this->currentGameCondition[6] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[0] == 0 && this->currentGameCondition[1] == 0 && this->currentGameCondition[2] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[3] == 0 && this->currentGameCondition[4] == 0 && this->currentGameCondition[5] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[6] == 0 && this->currentGameCondition[7] == 0 && this->currentGameCondition[8] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[0] == 0 && this->currentGameCondition[3] == 0 && this->currentGameCondition[6] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[1] == 0 && this->currentGameCondition[4] == 0 && this->currentGameCondition[2] == 0)
	{
		return true;
	}
	else if(this->currentGameCondition[2] == 0 && this->currentGameCondition[5] == 0 && this->currentGameCondition[8] == 0)
	{
		return true;
	}
	return false;
}
