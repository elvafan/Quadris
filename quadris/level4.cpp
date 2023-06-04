#include "level4.hpp"
Level4::Level4(Level*lv):lv(lv){}


Level* Level4::removelevel(){
	Level*tmp = lv;
	lv = nullptr;
	return tmp;
}


void Level4::dorandom(){
	lv->dorandom();
}
void Level4::norandom(std::string file){
	lv->norandom(file);
}
void Level4::setseed(int seed){
	lv->setseed(seed);
}

char Level4::getblock(){
	return lv->getblock();
}
int Level4::getlevel(){
	return 4;
}
Level4::~Level4(){
	delete lv;
}