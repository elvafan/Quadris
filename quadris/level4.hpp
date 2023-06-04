#ifndef LEVEL4_HPP
#define LEVEL4_HPP
#include "level.hpp"
class Level4:public Level {
	Level* lv;
	virtual Level* removelevel();
public:
	Level4(Level*lv);
	virtual void dorandom();
	virtual void norandom(std::string file);
	virtual void setseed(int seed);
	virtual char getblock();
	virtual int getlevel();
	~Level4();
};
#endif /* level_hpp */
