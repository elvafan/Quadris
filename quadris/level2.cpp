#include "level2.hpp"
#include <stdlib.h>

Level2::Level2(Level*lv):lv(lv){}


Level* Level2::removelevel(){
	Level*tmp = lv;
	lv = nullptr;
	return tmp;
}

void Level2::setseed(int seed){
	lv->setseed(seed);
}

char Level2::getblock(){
  int num = rand() % 7;
  if(num < 1)return 'S';
	if(num < 2)return 'Z';
 	if(num < 3)return 'I';
 	if(num < 4)return 'J';
 	if(num < 5)return 'L';
 	if(num < 6)return 'O';
 	return 'T';
}
int Level2::getlevel(){
	return 2;
}
Level2::~Level2(){
	delete lv;
}