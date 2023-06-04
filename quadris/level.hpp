#ifndef LEVEL_HPP
#define LEVEL_HPP
#include <fstream>
#include <string>
class Level {
	virtual Level* removelevel() = 0;
protected:
	std::ifstream infile;
public:
	virtual void dorandom() = 0;
	virtual void norandom(std::string file) = 0;
	virtual void setseed(int seed) = 0;
	virtual char getblock() = 0;
	virtual int getlevel() = 0;
	virtual ~Level(){}
	static Level* setlevel(int level, std::string = "sequence.txt");
	static Level* levelup(Level* lv);
	static Level* leveldown(Level* lv);

};
#endif /* level_hpp */
