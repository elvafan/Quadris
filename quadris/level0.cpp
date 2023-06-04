#include "level0.hpp"
#include <fstream>
#include <iostream>
using namespace std;

Level0::Level0(std::string file){
	infile.open(file);
}

Level* Level0::removelevel(){
	return this;
}
void Level0::setseed(int seed){
}

char Level0::getblock(){
	char type;
	infile>>type;
	return type;

}
int Level0::getlevel(){
	return 0;
}

Level0::~Level0(){
	infile.close();
}