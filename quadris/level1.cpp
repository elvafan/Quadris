#include "level1.hpp"
#include <stdlib.h>
Level1::Level1(Level*lv):lv(lv){
	srand (0);
}

Level* Level1::removelevel(){
	Level*tmp = lv;
	lv = nullptr;
	return tmp;
}

void Level1::setseed(int seed){
	srand (seed);
}

char Level1::getblock(){
  	int num = rand() % 12;
  	if(num < 1)return 'S';
  	if(num < 2)return 'Z';
  	if(num < 4)return 'I';
	if(num < 6)return 'J';
 	if(num < 8)return 'L';
 	if(num <10)return 'O';
 	return 'T';
}
int Level1::getlevel(){
	return 1;
}
Level1::~Level1(){
	delete lv;
}