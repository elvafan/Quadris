#ifndef LEVEL0_HPP
#define LEVEL0_HPP
#include "level.hpp"
#include <string>
class Level0:public Level {
	virtual Level* removelevel();
public:
	Level0(std::string file = "sequence.txt");
	virtual void dorandom(){};
	virtual void norandom(std::string){};
	virtual void setseed(int seed);
	virtual char getblock();
	virtual int getlevel();
	virtual ~Level0();
};
#endif /* level_hpp */
