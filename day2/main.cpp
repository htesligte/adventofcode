#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>
#include "Box.h"

using namespace std;

int main() {
    std::string contents(std::istreambuf_iterator<char>(std::cin), std::istreambuf_iterator<char>());

    // loop through contents
    std::istringstream stream(contents);
    std::string line;
    std::vector<Box*> boxes;
    while(std::getline( stream, line ) )
    {
        Box* b = Box::parse( line );
        if( b != NULL )
            boxes.push_back( b );
    }

    int total_size_needed = 0;
    int ribbon_size_needed = 0;

    for( std::vector<Box*>::iterator it = boxes.begin(); it != boxes.end(); it++ )
    {
        std::cout << (*it)->get_height() << "_" << (*it)->get_length() << "_" << (*it)->get_width() << std::endl;
        std::cout << "Size is: " << (*it)->get_size() << std::endl;
        std::cout << "Smallest side is: " << (*it)->get_smallest_side() << std::endl;
        std::cout << "And the ribbon size needed is: " << (*it)->get_ribbon_size() << std::endl;

        total_size_needed += (*it)->get_size();
        total_size_needed += (*it)->get_smallest_side();
        ribbon_size_needed += (*it)->get_ribbon_size();

        delete (*it);
    }
    boxes.clear();

    std::cout << std::endl << "Total wrapping paper needed: " << total_size_needed << " square feet" << std::endl;
    std::cout << std::endl << "Total ribbon needed: " << ribbon_size_needed << " feet" << std::endl;
    return 0;
}