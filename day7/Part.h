//
// Created by henk on 12/9/15.
//
#include <iostream>
#include <string>
#ifndef DAY7_PART_H
#define DAY7_PART_H
#include <algorithm>


class Part
{
public:
    std::size_t pos;
    std::string text;

    bool isEnd()
    {
        return pos == std::string::npos;
    }

    bool isUppercase (std::string const& c)
    {
        return std::find_if(c.begin(), c.end(), isupper) == c.end();
    }

    bool isOperation()
    {
        return isUppercase(text);
    }

    bool isArrow()
    {

    }
};


#endif //DAY7_PART_H
