#ifndef observer_hpp
#define observer_hpp

class Subject;

class Observer {
public:
    virtual void notify(Subject &whoFrom) = 0; // pass the Subject that called the notify method
    virtual ~Observer() = default;
};
#endif /* observer_hpp */
