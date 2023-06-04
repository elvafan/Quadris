#include "level3.hpp"
#include <stdlib.h>
#include <iostream>
using namespace std;
Level3::Level3(Level*lv):lv(lv),Random(true){}


Level* Level3::removelevel(){
	Level*tmp = lv;
	lv = nullptr;
	return tmp;
}

void Level3::dorandom(){
	Random = true;
}
void Level3:: norandom(std::string file){
	Random = false;
	infile.close();
	infile.open(file);
}


void Level3::setseed(int seed){
	lv->setseed(seed);
}

char Level3::getblock(){
	if(!Random){
		char type;
		infile>>type;
		return type;
	}
  	int num = rand() % 9;
  	if(num < 2)return 'S';
  	if(num < 4)return 'Z';
  	if(num < 5)return 'I';
	if(num < 6)return 'J';
	if(num < 7)return 'L';
	if(num < 8)return 'O';
	return 'T';
}
int Level3::getlevel(){
	return 3;
}
Level3::~Level3(){
	delete lv;
}
