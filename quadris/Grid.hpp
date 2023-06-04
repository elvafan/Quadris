#ifndef Grid_hpp
#define Grid_hpp
#include <vector>
#include <sstream>
#include "subject.hpp"
#include "observer.hpp"
#include "block.hpp"
#include "level.hpp"
#include "textdisplay.hpp"
//#include "graphicsdisplay.hpp"
class TextDisplay;
class GraphicsDisplay;

class Grid: public Subject{
    Block * b;
    char type = ' ';
    char next_type = ' ';
    int Curr_Score;
    int High_Score = 0;
    int level = 0;
    bool full = false;
    bool Only_Text;
    int level_4_count;
    std::vector<std::vector<char>> history;
    std::vector<std::vector<char>> board;
    std::vector<Block *> blocks;
    Level* lv = nullptr;
public:
    TextDisplay *td = nullptr;
    GraphicsDisplay *ob = nullptr;
    void dorandom();
    void norandom(std::string file);
    void getBlock();  // update my current block;
    // has duty to update td and ob;
    int hi_score();
    int cu_score();
    void init(bool text, int level, int seed, std::string file); // Sets up an 10 x 11 grid.
    bool isFull(); // Is the game over
    void clear(); // Clears old grid, if necessary.
    void set_block(char c); // c replace the current undropped block with the stated block.
    void level_up();
    void level_down();
    void notify(); // Notify td and ob;
    int getlevel() { return level;}
    void modify_bolck(std::string s);  // the string has six type
    // (down,left,right,drop,clockwise and counterclockwise)
    // has duty to check if it can be modefied
    // has duty to remove rows
    // has duty to update history
    void remove_row();
    void update_board(Info org, Info info); // If operation has effect, then we need to update board;
    bool has_effect(Info);
    
    
    friend std::ostream &operator<<(std::ostream &out, const Grid &g);
    
    void hint();
    
};
#endif
