all:
	@echo "Testing for g++...."
	@g++ -o testg++ test/test.cpp
	@./testg++
	@rm testg++
	@echo "Building...";
	@g++ -o tictactoe src/tictactoe.cpp
	@echo "Build passed"
