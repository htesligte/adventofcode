#include <iostream>
#include <string>

class Elevator
{	
	protected:
		int _up;
		int _down;

	public:
	Elevator() 
	{
		_up = 0;
		_down = 0;
	}
	
	void goUp()
	{
		_up++;
	}

	void goDown()
	{
		_down++;
	}

	int up()
	{
		return _up;
	}

	int down()
	{
		return _down;
	}

	int crash(std::string const& msg)
	{
		std::cerr << msg << std::endl;
		return 1;	
	}
};


int main(int argc, char** argv)
{
	Elevator elevator;
	if( argc <= 1 )
		return elevator.crash("Invalid arguments specified, use: day1 \"<floors>\"");
	
	std::string input = std::string(argv[1]);

	for( int i = 0; i < input.length(); i++ )
	{
		if( input[i] == '(' )
			elevator.goUp();
		else if( input[i] == ')' )
			elevator.goDown();
		else
			return elevator.crash("Use only ( and ) characters!");
	}
	std::cout << "End result: " << std::endl;
	std::cout << "Up: " << elevator.up() << " times" << std::endl;
	std::cout << "Down: " << elevator.down() << " times" << std::endl;
	std::cout << "So we arrived on floor: " << elevator.up() - elevator.down() << std:: endl;
	
	return 0;
}
