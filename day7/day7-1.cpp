#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <regex>
#include "Part.h"
#include "Statement.h"
#include <unistd.h>

std::map<std::string, unsigned short> wires;


Part* retrievePart( std::string const& line )
{
	Part* part = new Part();
	static size_t pos = 0;

	size_t found = 0;
	found = line.find(" ", pos );

	part->pos = found;
	part->text = line.substr( pos, ( found - pos ) );

	if( found == std::string::npos )
		pos = 0;
	else
		pos = found+1;

	return part;
}



void parseLine(std::string const& line)
{
	// we search through the string until we found a space
	Part* part;
	bool isEnd = false;
	do
	{
		part = retrievePart( line );
		std::cout << "Found part: " << part->text << std::endl;
		isEnd = part->isEnd();
		delete part;
	}
	while( !isEnd );
}

void printWires()
{
	for (const auto &p : wires) {
		std::cout << "wires[" << p.first << "] = " << p.second << '\n';
	}
}

int main( int argc, char** argv )
{
	std::string contents(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>());
	std::istringstream stream(contents);

	std::string line;

	unsigned short l = 0;
	unsigned short r = 2;
	std::cout << "l << r" << std::endl << ( l << r ) << std::endl;


	while(std::getline( stream, line ) )
	{
		Statement* s = Statement::parse( line );

		std::cout << line << std::endl;
		s->doCalculation( &wires );
		//printWires();
		//std::cout << std::endl << std::endl;
		//sleep(1);
		delete s;
	}
	printWires();


	return 0;

}
