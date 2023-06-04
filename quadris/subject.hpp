#ifndef subject_hpp
#define subject_hpp
#include <vector>
#include "observer.hpp"

struct State{
	int level;
	int score;
	int hscore;
	char nextType;
};

class Subject {
    std::vector<Observer *> observers;
    State state;
public:
	void setState(State state);
	State getState();
    void attach(Observer * o);
    void clearObservers();
    void notifyObservers();
};

#endif
