#ifndef LEVEL3_HPP
#define LEVEL3_HPP
#include "level.hpp"
class Level3:public Level {
	Level* lv;
	bool Random;
	virtual Level* removelevel();
public:
	Level3(Level*lv);
	virtual void dorandom();
	virtual void norandom(std::string file);
	virtual void setseed(int seed);
	virtual char getblock();
	virtual int getlevel();
	~Level3();
};
#endif /* level_hpp */
