#include "graphicsdisplay.hpp"
#include "subject.hpp"
#include <iostream>
using namespace std;


//  enum {White=0, Black, Red, Green, Blue}; // Available colours.

  // Draws a rectangle
//  void fillRectangle(int x, int y, int width, int height, int colour=Black);

  // Draws a string
//  void drawString(int x, int y, std::string msg);

GraphicsDisplay::GraphicsDisplay(std::vector<std::vector<char> >& board)
:window(new Xwindow()),board(board)
{
	window->fillRectangle(0,0,320,500,1);
}


//I J O S Z T L

void GraphicsDisplay::notify(Subject &whoFrom){
	State state = whoFrom.getState();
	int level = state.level;
	int score = state.score;
	int hscore = state.hscore;
	char nextType = state.nextType;

	int unit = 500/18;
	int xoffset = 10;
	int yoffset = 10;
	for (int y = 0; y <18; y++){
        for (int x = 0; x < 11; x ++){
        	char c = board[x][17-y];
        	int xpos = xoffset+ x* unit;
        	int ypos = yoffset+ y* unit;
        	if (c == 'S' || c == 'L' || c == 'O'||
                c == 'T' || c == 'Z' || c == 'J'
                || c == 'I' || c == '?'){
        		window->fillRectangle(xpos, ypos, unit, unit, 4);
            }else{
            	window->fillRectangle(xpos, ypos, unit, unit, 0);
            }
        }
    }

    string s1 = "level:  "+ std::to_string(level);
    string s2 = "Score:  "+ std::to_string(score);
    string s3 = "Hi Score:  "+ std::to_string(hscore);
    window->drawString(330, 20,s1);
    window->drawString(330, 40,s2);
    window->drawString(330, 60,s3);

    window->drawString(330, 300,"Next:");
    int xbase = 330;
    int ybase = 350;
    window->fillRectangle(xbase,ybase, unit*4, unit*4, 0);
    switch(nextType){
		case 'I':
            window->fillRectangle(xbase, ybase, unit*4, unit, 4);
			break;
		case 'J':
            window->fillRectangle(xbase, ybase, unit, unit, 4);
            window->fillRectangle(xbase, ybase+unit, unit*3, unit, 4);
			break;
		case 'L':
            window->fillRectangle(xbase+2*unit, ybase,  unit, unit, 4);
            window->fillRectangle(xbase, ybase+unit, unit*3, unit, 4);
			break;
		case 'O':
            window->fillRectangle(xbase, ybase, unit*2, unit, 4);
            window->fillRectangle(xbase, ybase+unit, unit*2, unit, 4);
			break;
		case 'S':
            window->fillRectangle(xbase+unit, ybase, unit*2, unit, 4);
            window->fillRectangle(xbase, ybase+unit, unit*2, unit, 4);
			break;
		case 'Z':
            window->fillRectangle(xbase, ybase, unit*2, unit, 4);
            window->fillRectangle(xbase+unit, ybase+unit, unit*2, unit, 4);
			break;
		case 'T':
            window->fillRectangle(xbase, ybase, unit*3, unit, 4);
            window->fillRectangle(xbase+unit, ybase+unit, unit, unit, 4);
			break;
	}
}

GraphicsDisplay::~GraphicsDisplay(){
    delete window;
}
