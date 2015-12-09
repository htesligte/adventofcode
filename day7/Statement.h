//
// Created by henk on 12/9/15.
//

#ifndef DAY7_STATEMENT_H
#define DAY7_STATEMENT_H
#include <string>
#include <iostream>
#include <map>

class Statement
{

public:
    const std::string &getResult() const {
        return result;
    }

    void setResult(const std::string &result) {
        Statement::result = result;
    }

    const std::string &getOperation() const {
        return operation;
    }

    void setOperation(const std::string &operation) {
        Statement::operation = operation;
    }

    const std::string &getRight() const {
        return right;
    }

    void setRight(const std::string &right) {
        Statement::right = right;
    }

    const std::string &getLeft() const {
        return left;
    }

    void setLeft(const std::string &left) {
        Statement::left = left;
    }

    std::string getPart()
    {
        size_t found = line.find( ' ', pos );
        std::string result = line.substr( pos, ( found - pos ) );

        pos = found+1;

        if( result[0] == '-' )
            return getPart();

        return result;
    }

    bool isNotCalculation()
    {

        return left.length() <= 0;
    }

    bool isSimpleAssignment()
    {
        return operation.length() <= 0;
    }

    unsigned short getNumericLeft()
    {
        return (unsigned short)std::stoi(left);
    }

    unsigned short getNumericRight()
    {
        return (unsigned short)std::stoi(right);
    }

    unsigned short getLeftValue()
    {
        if( (*wires).find( left ) == (*wires).end() )
            return 0;

        return (*wires)[left];
    }

    unsigned short getRightValue()
    {
        if( (*wires).find( right ) == (*wires).end() )
            return 0;

        return (*wires)[right];
    }

    bool isNumericLeft()
    {
        return isdigit( left[0] );
    }

    bool isNumericRight()
    {
        return isdigit( right[0] );
    }

    void debug()
    {
        std::cout << "Line: " << line << std::endl;
        std::cout << "Left: " << left << std::endl;
        std::cout << "Operation: " << operation << std::endl;
        std::cout << "Right: " << right << std::endl;
        std::cout << "Result: " << result << std::endl;
    }



    void doSimpleAssignment()
    {
        if( isNumericLeft() )
            (*wires)[result] = getNumericLeft();
        else
            (*wires)[result] = getLeftValue();
    }

    void doNotCalculation()
    {
        if( isNumericRight() )
            (*wires)[result] = ~getNumericRight();
        else
            (*wires)[result] = ~getRightValue();
    }

    void doCalculation( std::map<std::string, unsigned short>* wires )
    {
        this->wires = wires;
        if( isSimpleAssignment() )
        {
            doSimpleAssignment();
            return;
        }
        if( isNotCalculation() )
        {
            doNotCalculation();
            return;
        }
        else
        {
        }

        unsigned short l;
        unsigned short r;
        if( isNumericLeft() )
            l = getNumericLeft();
        else
            l = getLeftValue();

        if( isNumericRight() )
            r = getNumericRight();
        else
            r = getRightValue();

        switch( operation[0] )
        {
            case 'A':
                (*wires)[result] = l & r;
                break;

            case 'L':
                (*wires)[result] = l << r;
                break;

            case 'R':
                (*wires)[result] = l >> r;
                break;

            case 'O':
                (*wires)[result] = l | r;
                break;

        }
    }


protected:
    std::string left;
    std::string right;
    std::string operation;
    std::string result;
    std::size_t pos;
    std::map<std::string, unsigned short>* wires;
public:
    const std::string &getLine() const {
        return line;
    }

    void setLine(const std::string &line) {
        Statement::line = line;
    }

protected:
    std::string line;

public:
    static Statement* parse( std::string const& line )
    {
        Statement* s = new Statement();
        s->setLine( line );
        // does the string start with an uppercase character? If so, there is no left side, only a right

        if( isupper( line[0] ) ) // NOT gw -> gx
        {
            s->setOperation( s->getPart() );
            s->setRight( s->getPart() );
            s->setResult( s->getPart() );
            return s;
        }

        // 1 AND io -> ip
        // lx -> a
        s->setLeft( s->getPart() );
        std::string next = s->getPart();
        if( isupper( next[0] ) ) // 1 AND io -> ip
        {
            s->setOperation( next );
            s->setRight( s->getPart() );
            s->setResult( s->getPart() );
            return s;
        }

        // lx -> a
        s->setResult( next );
        return s;
    }
};


#endif //DAY7_STATEMENT_H
