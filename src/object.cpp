#include "../header/object.h"
#include <iostream>
#include <string>
using namespace std;

Object::Object() : type("Null"), value(0) {}

Object::Object(const string& type, int value) : type(type), value(value) {}

string Object::getType() const {
    return "Null";
}

int Object::getValue() const {
    return value;
}   

 void Object::setType(const string& newType) {
    type = newType;
 }
void Object::setValue(int newValue) {
    value = newValue;
}   

void Object::print() const {
    cout << "Name: " << type << ", Value: " << value << endl;
}