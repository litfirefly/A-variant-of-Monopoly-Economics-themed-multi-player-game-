#ifndef SUBJECT_H
#define SUBJECT_H
#include <vector>

// DO NOT MODIFY THIS FILE!

class Observer;

class Subject {
    std::vector<Observer*> observers;

  public:
    void attach(Observer *o);  
    void notifyObservers();
};

#endif
