//
// Created by henk on 12/8/15.
//
#include <string>
#include <regex>
#ifndef DAY2_BOX_H
#define DAY2_BOX_H


class Box {
protected:

public:
    int get_width() const {
        return _width;
    }

    void set_width(int _width) {
        Box::_width = _width;
    }

    int get_height() const {
        return _height;
    }

    void set_height(int _height) {
        Box::_height = _height;
    }

    int get_length() const {
        return _length;
    }

    void set_length(int _length) {
        Box::_length = _length;
    }

    int get_smallest_side()
    {
        std::vector<int> sizes;
        sizes.push_back(_length * _width);
        sizes.push_back(_width * _height);
        sizes.push_back(_length * _height);


        return *std::min_element(std::begin(sizes), std::end(sizes));
    }

    int get_size()
    {
        return (2*_length*_width) + (2*_width*_height) + (2*_height*_length);
    }

    int get_ribbon_size()
    {
        int ribbon_size = 0;

        std::vector<int> sizes;
        sizes.push_back(_length );
        sizes.push_back(_width );
        sizes.push_back(_height );

        std::sort(sizes.begin(), sizes.end() );

        // so now the first two elements are the shortest sides
        ribbon_size = (2*sizes.at(0)) + (2*sizes.at(1));
        ribbon_size += _length * _width * _height;

        return ribbon_size;
    }

    static Box* parse( std::string const& line )
    {
        std::regex regex("(\\d*)x(\\d*)x(\\d*)"); // and now we have two problems :-P
        std::smatch match;

        std::regex_search (line, match, regex);
        if( match.size() > 1 )
            return new Box( std::stoi(match.str(1).c_str()), std::stoi(match.str(2).c_str()), std::stoi(match.str(3).c_str()) );
        else
            return NULL;
    }

protected:
    int _width;
    int _height;
    int _length;

public:
    Box(int l, int w, int h);
};


#endif //DAY2_BOX_H
