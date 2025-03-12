// object.h
#ifndef OBJECT_H
#define OBJECT_H

#include <string>
#include <memory>

class Object {
public:
    Object();
    Object(const std::string& type, int value, bool isBarrier = false);

    std::string getType() const;
    int getValue() const;
    bool isBarrier() const;  // Check if the object is a barrier

    void setType(const std::string& newType);
    void setValue(int newValue);
    void setIsBarrier(bool isBarrier);  // Set whether the object is a barrier

    void print() const;

private:
    std::string type;
    int value;
    bool barrier;  // Indicates whether this object is a barrier
};

#endif // OBJECT_H