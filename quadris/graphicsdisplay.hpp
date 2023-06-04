#ifndef GRAPHICSDISPLAY_HPP
#define GRAPHICSDISPLAY_HPP
#include "observer.hpp"
#include "window.h"
#include <vector>
#include <iostream>
class Subject;
class GraphicsDisplay: public Observer{
	Xwindow* window;
	std::vector<std::vector<char> >&board;
public:
	GraphicsDisplay(std::vector<std::vector<char> >& board);
    void notify(Subject &whoFrom); 
    ~GraphicsDisplay();
};
#endif