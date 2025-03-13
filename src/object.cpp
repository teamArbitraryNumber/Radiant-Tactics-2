#include "../header/object.h"
#include <iostream>
#include <string>
using namespace std;

Object::Object() : type("Null"), value(0), barrier(false){}

Object::Object(const string& type, int value, bool isBarrier) 
    : type(type), value(value), barrier(isBarrier) {}

Object::Object(bool isDoor, const string& type, int value)
    : type(type), value(value), barrier(false), door(isDoor) {}

string Object::getType() const {
    return type;
}

int Object::getValue() const {
    return value;
}

bool Object::isBarrier() const {
    return barrier;
}

bool Object::isDoor() const {
    return door;
}

void Object::setType(const string& newType) {
    type = newType;
}

void Object::setValue(int newValue) {
    value = newValue;
}

void Object::setIsBarrier(bool isBarrier) {
    barrier = isBarrier;
}

void Object::setIsDoor(bool isDoor){
    door = isDoor;
}

void Object::print() const {
    cout << "Name: " << type << ", Value: " << value << ", Barrier: " << (barrier ? "Yes" : "No") << endl;
}

string Object::getDisplayChar(){
    
    if(barrier){
        return "🪨 ";
    }
    if(door){
        return "🚪 ";
    }
    return ".";
}