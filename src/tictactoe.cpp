#include "../lib/gameMechanic.cpp"

bool iswindows = false; 
bool islinux = false; 
bool ismac = false;

int main()
{
	#if _WIN32 // Windows 32 bit version

	iswindows = true;

	#elif _WIN64 // Windows 64 bit version

	iswindows = true;

	#elif __APPLE__ // Apple

	ismac = true;

	#elif __MACH__ // Alternative to __APPLE__

	ismac = true;

	#elif TARGET_OS_MAC // Another alternative, why are there so many lmao

	ismac = true;

	#elif __linux__ // FINALLY LINUX

	islinux = true;

	#elif _POSIX_VERSION // Cygwin windows

	islinux = true; // We'll assume that cygwin is linux; just for now

	#elif BSD // All BSD OSes ex: OpenBSD, DragonflyBSD, and so on and so forth

	islinux = true; // It works with the same commmands as linux, right? Idk I didn't check lolk

	#endif
	std::vector<int> cells; // Cells in the tictactoe
	for(int i = 0; i < 9; ++i)
	{
		cells.push_back(-1); // Fill em' out!
	}
	srand(time(0)); // Set a random seed
	int turn = rand() % 2; // Set first turn as random
	bool Player1Wins = false; // If player 1 wins
	bool Player2Wins = false; // If player 2 wins
	bool gameOver = false; // If either player 1 or 2 wins
	while(!gameOver) // Run while the game is not over
	{
		gameMechanic game(cells); // Initialize gameMechanic class
		if(islinux || ismac) // This is where the __MACH__ and __linux__ thingies come together
			system("clear"); // Mac, linux and BSDs uses clear
		else
			system("cls"); // Windows uses cls, I know it because I used to use Windows 10
		int counter = 0;
		for(auto i = cells.begin(); i != cells.end(); ++i) // Checks if all elements in cell are occupied
		{
			if(*i != -1)
				++counter;
		}
		if(counter == 9 && !(game.winConditionPlayer1() == true || game.winConditionPlayer2() == true)) // Checks if the opponent wins and get draw at the same time, if that happens
		{
			std::cout << "Draw!\nNobody won" << std::endl; // Pity
			gameOver = true;
			continue;
		}
		else // If not draw
		{
			if(game.winConditionPlayer1() == true) // If player 1 wins
			{
				std::cout << "Player 1 wins!" << std::endl;
				gameOver = true;
				continue;
			}
			else if(game.winConditionPlayer2() == true) // If player 0 wins
			{
				std::cout << "Player 0 wins!" << std::endl;
				gameOver = true;
				continue;
			}
		}
		std::cout << "Player " << turn << "'s turn" << std::endl; // Just telling the player(s) Who's turn it is
		int currentInput; // Current input for the turn
		int j = 0; // Counter variable
		for(auto i = cells.begin(); i != cells.end(); ++i)
		{
			std::cout << "|" << *i + 1 << "|"; // Creating the grid				
			if(j == 2 || j == 5)
				std::cout << std::endl; // Every time 3 |0|s has been drawn, it switches to the next line
			++j; // Incrementing counter
		}
		std::cout << std::endl << "> "; // Input arrow(So that it looks fancy lmao)
		std::cin >> currentInput; // Inputting the number
		if(currentInput < 1) // If the input is 0 or smaller
		{
			std::cout << "Number too small! Try again" << std::endl; // Screams at the user lol
			continue;
		}
		else if(currentInput > 9) // If the input is 10 or bigger
		{
			std::cout << "Number too big! Try again" << std::endl;
			continue;
		}

		if(cells[currentInput - 1] == 0 || cells[currentInput - 1] == 1) // Checks if the space is occupied
		{
			std::cout << "This space has been occupied, try again" << std::endl;
			continue;
		}

		if(turn == 0) // If turn is 0, cell[currentInput - 1] will be 1
			cells[currentInput - 1] = 0;
		else
			cells[currentInput - 1] = 1; // Else 2
		turn = !turn; // Inverts the turn every turn lol(It's a bad pun I know)
	}	
	return 0; // Return the program, DUH!
}
