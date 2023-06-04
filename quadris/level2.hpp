#ifndef LEVEL2_HPP
#define LEVEL2_HPP
#include "level.hpp"
class Level2:public Level {
	Level*lv;
	virtual Level* removelevel();
public:
	Level2(Level* lv);
	virtual void dorandom(){};
	virtual void norandom(std::string){};
	virtual void setseed(int seed);
	virtual char getblock();
	virtual int getlevel();
	~Level2();
};
#endif /* level_hpp */
