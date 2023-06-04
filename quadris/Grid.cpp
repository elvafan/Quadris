#include "Grid.hpp"
#include "Iblock.hpp"
#include "Jblock.hpp"
#include "Lblock.hpp"
#include "Oblock.hpp"
#include "Sblock.hpp"
#include "Zblock.hpp"
#include "Tblock.hpp"
#include "level0.hpp"
#include "level1.hpp"
#include "level2.hpp"
#include "level3.hpp"
#include "level4.hpp"
using namespace std;
const int width = 11;
const int height = 18;
const int block_size = 4;

void Grid::dorandom(){
    lv->dorandom();
}
void Grid::norandom(string file){
    lv->norandom(file);
}
void Grid::level_up(){
    lv = Level::levelup(lv);
    notify();
}
void Grid::level_down(){
    lv = Level::leveldown(lv);
    notify();
}

void Grid::getBlock(){
    // update history
    for (int i = 0; i < height; i ++){
        for (int k = 0; k < width; k ++){
            history[k][i] = board[k][i];
        }
    }
    Info info;
    if (type != ' ' && next_type != ' '){
        info = b->getinfo();
        if (info.level == 4){
            if (level_4_count == 5){
                level_4_count = 0;
                b = new Oblock('O',level);
                blocks.push_back(b);
                modify_bolck("drop");
                return;
            } else {
                level_4_count += 1;
            }
        }
    }
    
    // Call new block
    if (type == ' ' && next_type == ' '){
        type = lv->getblock();
        next_type = lv->getblock();
    } else {
        type = next_type;
        next_type = lv->getblock();
    }
    
    level = lv->getlevel();
    if (type == 'I'){
        b = new Iblock(type,level);
    } else if (type == 'J'){
        b = new Jblock(type,level);
    } else if (type == 'L'){
        b = new Lblock(type,level);
    } else if (type == 'O'){
        b = new Oblock(type,level);
    } else if (type == 'Z'){
        b = new Zblock(type,level);
    } else if (type == 'T'){
        b = new Tblock(type,level);
    } else {
        b = new Sblock(type,level);
    }
    blocks.push_back(b);
    info = b->getinfo();
    // Detect if the board will be full when the next blcok falls (Is the game over?)
    for (int i = 0; i < block_size; i ++){
        int x = info.pos[i].x;
        int y = info.pos[i].y;
        if (history[x][y] != ' ' && history[x][y] != '?'){
            full = true;
            return;
        }
    }
    // If not full, update board
    if (!full){
        for (int i = 0; i < block_size; i ++) {
            board[info.pos[i].x][info.pos[i].y] = info.type;
        }
    }// if full
    else {
        info = b->getinfo();
        int lowest = info.pos[0].y;
        for (int i = 0; i < block_size; i ++){
            if (info.pos[i].y < lowest) lowest = info.pos[i].y;
        }
        int distance = lowest;
        for (int i = 0 ; i < 4 ; i ++){
            int x = info.pos[i].x;
            int y = info.pos[i].y;
            for (int k = height - 1; k >= 0; k --){
                if (history[x][k] != ' ' && history[x][k] != '?'){
                    if (distance > (y - k - 1)) distance = y - k - 1;
                }
            }
        }
        if (lowest <= 0) full = true;
        else b->drop(distance);
    }
}
bool Grid::isFull(){
    if (full == true) return true;
    for (int i = 0; i < width; i ++){
        if (board[i][15] != ' ' && board[i][15] != '?'){
            if (history[i][14]  != ' ' && history[i][14] != '?'){
                full = true;
                return true;
            }
        }
    }
    return false;
}
void Grid::notify(){
    State state = {lv->getlevel(), cu_score(), hi_score(), next_type};
    setState(state);
    notifyObservers();
}

int Grid::hi_score(){return High_Score;}
int Grid::cu_score(){return Curr_Score;}

void Grid::clear(){
    delete td;
    //delete ob;
    clearObservers();
    for(unsigned int i = 0;i < history.size(); i ++){
        history[i].clear();
        history[i].resize(0);
    }
    history.clear();
    history.resize(0);
    for(unsigned int i = 0;i < board.size(); i ++){
        board[i].clear();
        board[i].resize(0);
    }
    board.clear();
    board.resize(0);
    const int size = blocks.size();
    for (int i = 0; i < size; i ++){
        delete blocks[i];
    }
    blocks.clear();
    blocks.resize(0);
    full = false;
    delete lv;
    Curr_Score = 0;
    level_4_count = 0;
    type = ' ';
    next_type = ' ';
}
void Grid::init(bool text, int level, int seed, string file){
    this->level = level;
    lv = Level::setlevel(level, file);
    lv->setseed(seed);
    history.resize(width);
    board.resize(width);
    for (int i = 0; i < width; i ++){
        for (int k = 0; k < height; k ++){
            history[i].push_back(' ');
            board[i].push_back(' ');
        }
    }
    getBlock();
    Curr_Score = 0;
    level_4_count = 0;
    full = false;
    Only_Text = text;
    td = new TextDisplay(board);
    this->attach(td);
    /*if (Only_Text){
        td = new TextDisplay(board);
        this->attach(td);
    } else {
        td = new TextDisplay(board);
        this->attach(td);
        //ob = new GraphicsDisplay(board);
        //this->attach(ob);
    }*/
    notify();
}

void Grid::update_board(Info org, Info info){
    for (int i = 0; i < block_size; i ++){
        int orgin_x = org.pos[i].x;
        int orgin_y = org.pos[i].y;
        board[orgin_x][orgin_y] = ' ';
    }
    for (int i = 0; i < block_size; i ++){
        int x = info.pos[i].x;
        int y = info.pos[i].y;
        board[x][y] = info.type;
    }
}
bool Grid::has_effect(Info info){
    for (int i = 0; i < block_size; i ++){
        if (info.pos[i].x < 0 || info.pos[i].x > 10 || info.pos[i].y > 17 || info.pos[i].y < 0) {
            return true;
        }
    }
    for (int i = 0; i < block_size; i ++){
        int x = info.pos[i].x;
        int y = info.pos[i].y;
        if (history[x][y] != ' ' && history[x][y] != '?'){
            return true;
        }
    }
    return false;
}
void Grid::modify_bolck(string s){
    Info orgin_info = b->getinfo();
    bool new_block = false;
    Info info;
    // First check if the operator has effect, if it dont have effect then return
    if (s != "down" && s != "drop"){
        if (s == "left") {
            b->left();
            info = b->getinfo();
            if (has_effect(info)){
                b->right();
                return;
            }
        } else if (s == "right"){
            b->right();
            info = b->getinfo();
            if (has_effect(info)){
                b->left();
                return;
            }
        } else if (s == "clockwise") {
            info = b->getinfo();
            b->clockwise();
            info = b->getinfo();
            if (has_effect(info)){
                b->counterclock();
                return;
            }
        } else if (s == "counterclockwise"){
            info = b->getinfo();
            b->counterclock();
            info = b->getinfo();
            if (has_effect(info)){
                b->clockwise();
                return;
            }
        }
        // Then check if we need a new block, if we need, set new_block to true;
        // check if the line under the block has another block, if it has, then we need a new block
        for (int i = 0; i < block_size; i ++){
            int x = info.pos[i].x;
            int y = info.pos[i].y;
            if (history[x][y - 1] != ' ' && history[x][y - 1] != '?'){
                new_block = true;
                break;
            }
        }
    } else if (s == "drop"){
        info = b->getinfo();
        int lowest = info.pos[0].y;
        for (int i = 0; i < block_size; i ++){
            if (info.pos[i].y < lowest) lowest = info.pos[i].y;
        }
        int distance = lowest;
        for (int i = 0 ; i < 4 ; i ++){
            int x = info.pos[i].x;
            int y = info.pos[i].y;
            for (int k = height - 1; k >= 0; k --){
                if (history[x][k] != ' ' && history[x][k] != '?'){
                    if (distance > (y - k - 1)) distance = y - k - 1;
                }
            }
        }
        b->drop(distance);
        info = b->getinfo();
        new_block = true;
    } else if (s == "down"){
        info = b->getinfo();
        int lowest = info.pos[0].y;
        for (int i = 0; i < block_size; i ++){
            if (info.pos[i].y < lowest) lowest = info.pos[i].y;
        }
        // If the lowest pos is 1, then it cannot have any block under it. Thus, update current bolck and call a new block;
        if (lowest == 1) {
            b->down();
            info = b->getinfo();
            new_block = true;
        }
        // if the lowest pos is greater than one, then we need to determine shall we call a new block;
        else {
            for (int i = 0; i < block_size; i ++){
                int x = info.pos[i].x;
                int y = info.pos[i].y;
                if (history[x][y - 2] != ' ' && history[x][y - 2] != '?'){
                    new_block = true;
                    break;
                }
            }
            b->down();
            info = b->getinfo();
        }
    }
    // if it has effect, then update board;
    update_board(orgin_info, info);
    // if we need a new block;
    // getBlock has duty to update history, type, next type and call a new block;
    if (new_block == true)  {
        remove_row();
        getBlock();
    }
    notify();
}


void Grid::remove_row(){
    vector <int> remove_line;
    // check which line need to be removed
    for (int i = 0; i < height; i ++){
        int count = 0;
        for (int k = 0; k < width; k ++){
            if (board[k][i] != ' ' && board[k][i] != '?') count += 1;
        }
        if (count == width){
            remove_line.push_back(i);
            count = 0;
        }
    }
    // Copy other line to temp, then copy back to board
    if (remove_line.size() == 0) return;
    if (level == 4) level_4_count = 0;
    vector <vector<char>> temp;
    temp.resize(width);
    for (int i = 0; i < width; i ++){
        for (int k = 0; k < height; k ++){
            temp[i].push_back(' ');
        }
    }
    int temp_count = 0;
    for (int i = 0; i < height; i ++){
        bool r = false;
        for (unsigned int j = 0; j < remove_line.size(); j ++) {
            if (remove_line[j] == i) r = true;
        }
        if (!r) {
            for (int k = 0; k <= 10; k ++) temp[k][temp_count] = board[k][i];
            temp_count += 1;
        }
    }
    for (int i = 0; i < height; i ++){
        for (int k = 0; k < width; k ++){
            board[k][i] = temp[k][i];
        }
    }
    int line_score = (level + remove_line.size()) * (level + remove_line.size());
    Curr_Score += line_score;
    int block_score = 0;
    for (unsigned int i = 0; i < blocks.size(); i ++){
        for (int j = 0; j < block_size; j ++){
            for (unsigned int k = 0; k < remove_line.size(); k++){
                Info info = blocks[i]->getinfo();
                if (info.pos[j].y == remove_line[k]){
                    blocks[i]->setsize(info.size - 1);
                }
            }
        }
    }

    // Count score of block
    for (unsigned int i = 0; i < blocks.size(); i ++){
        Info info = blocks[i]->getinfo();
        if (info.size == 0){
            block_score += (info.level + 1)*(info.level + 1);
        }
    }
    // Delete block
    vector <int> index;
    for (unsigned int i = 0; i < blocks.size(); i ++){
        Info info = blocks[i]->getinfo();
        if (info.size != 0){
            index.push_back(i);
        } else{
            delete blocks[i];
        }
    }
    for (unsigned int i = 0; i < index.size(); i ++){
        blocks[i] = blocks[index[i]];
    }
    blocks.resize(index.size());
    int ss = remove_line.size() - 1;
    for (unsigned int k = 0; k < blocks.size(); k ++){
        for (int i = ss; i >= 0; i --){
            blocks[k]->clear(remove_line[i]);
        }
    }
    Curr_Score += block_score;
    if (Curr_Score >= High_Score) High_Score = Curr_Score;
}

void Grid::set_block(char c){
    Info org = b->getinfo();
    b->setblock(c);
    Info info = b->getinfo();
    for (int i = 0; i < block_size; i ++){
        int x = info.pos[i].x;
        int y = info.pos[i].y;
        if (history[x][y] != ' ' && history[x][y] != '?'){
            b->setblock(org.type);
        }
    }
    bool new_block = false;
    for (int i = 0; i < block_size; i ++){
        int x = info.pos[i].x;
        int y = info.pos[i].y;
        if (history[x][y - 1] != ' ' && history[x][y - 1] != '?'){
            new_block = true;
            break;
        }
    }
    update_board(org, info);
    if (new_block == true)  {
        remove_row();
        getBlock();
    }
    notify();
}
std::ostream &operator<<(std::ostream &out, const Grid &g){
    out<<(*g.td);
    /*
    for (int i = 17; i >= 0; i --){
        for (int k = 0; k < 11; k ++){
            if (g.board[k][i] == 'S' || g.board[k][i] == 'L' || g.board[k][i] == 'O'||
                g.board[k][i] == 'T' || g.board[k][i] == 'Z' || g.board[k][i] == 'J'
                || g.board[k][i] == 'I' || g.board[k][i] == '?'){
                out << g.board[k][i];
            }
            else out << '-';
        }
        out << std::endl;
    }
    */
    //out << "Current Score" << g.Curr_Score << std::endl;
    //out << "High Score" << g.High_Score << std::endl;
    return out;
}

void Grid::hint(){
}
    
