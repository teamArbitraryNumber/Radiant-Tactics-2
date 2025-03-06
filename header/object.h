#include <string>
#ifndef OBJECT_H
#define OBJECT_H

using namespace std;

class Object {
public:

    std::string type;//{}; // "character" | "sword" | "potion" | "empty"
    int value;//{}; // 0 | 5 | 10 | 15
    
    Object();
    virtual ~Object() {};
    Object(const std::string& type, int value);

     virtual std::string getType() const;
    void setType(const std::string& newType);
    int getValue() const;
    void setValue(int newValue);
    virtual void print() const;
};

#endif