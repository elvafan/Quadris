#ifndef TEXTDISPLAY_HPP
#define TEXTDISPLAY_HPP
#include "observer.hpp"
#include <vector>
#include <iostream>
class Subject;
class TextDisplay: public Observer{
	std::vector<std::vector<char> >&board;
	int level;
	int score;
	int hscore;
	char nextType;
public:
	TextDisplay(std::vector<std::vector<char> >& board);
    virtual void notify(Subject &whoFrom) override; 
    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};
#endif
