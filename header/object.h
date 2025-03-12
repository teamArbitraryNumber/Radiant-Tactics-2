// object.h
#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>

using namespace std;
class Object {
public:
    Object();
    Object(const string& type, int value, bool isBarrier = false);
    Object(bool isDoor, const string& type, int value);

    std::string getType() const;
    int getValue() const;
    bool isBarrier() const;  // Check if the object is a barrier
    bool isDoor() const;
    void setType(const std::string& newType);
    void setValue(int newValue);
    void setIsBarrier(bool isBarrier);  // Set whether the object is a barrier
    void setIsDoor(bool isDoor);
    void print() const;
    virtual string getDisplayChar();

private:
    string type;
    int value;
    bool barrier;  // Indicates whether this object is a barrier
    bool door;
};

#endif // OBJECT_H