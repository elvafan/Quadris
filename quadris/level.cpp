#include "level.hpp"
#include "level0.hpp"
#include "level1.hpp"
#include "level2.hpp"
#include "level3.hpp"
#include "level4.hpp"

Level* Level::setlevel(int level, std::string file){
	Level* lv = new Level0(file);
	if(level > 0)lv = new Level1(lv);
	if(level > 1)lv = new Level2(lv);
	if(level > 2)lv = new Level3(lv);
	if(level > 3)lv = new Level4(lv);
	return lv;
}


Level* Level::levelup(Level* lv){
	int level = lv->getlevel();
	if(level == 0)return new Level1(lv);
	if(level == 1)return new Level2(lv);
	if(level == 2)return new Level3(lv);
	if(level == 3)return new Level4(lv);
	return lv;
}
Level* Level::leveldown(Level* lv){
	if(lv->getlevel() == 0)return lv;
	Level* inner = lv->removelevel();
	delete lv;
	return inner;
}