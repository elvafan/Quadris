#include "subject.hpp"


void Subject::attach(Observer *o) {
    observers.emplace_back(o);
}

void Subject::clearObservers(){
	observers.clear();
}

void Subject::notifyObservers() {
    for (auto &ob : observers) ob->notify(*this);
}


State Subject::getState(){
	return state;
}

void Subject::setState(State state){
	this->state = state;
}