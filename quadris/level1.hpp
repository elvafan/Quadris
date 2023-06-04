#ifndef LEVEL1_HPP
#define LEVEL1_HPP
#include "level.hpp"
class Level1: public Level {
	Level *lv;
	virtual Level* removelevel();
public:
	Level1(Level* lv);
	virtual void dorandom(){};
	virtual void norandom(std::string){};
	virtual void setseed(int seed);
	virtual char getblock();
	virtual int getlevel();
	~Level1();
};
#endif /* level_hpp */
