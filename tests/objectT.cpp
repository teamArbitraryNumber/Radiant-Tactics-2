/*#include "gtest/gtest.h"
#include "../header/object.h"

TEST(ObjectTest, Constructor) {
    Object obj;
    EXPECT_EQ(obj.getType(), "");
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, Setters) {
    Object obj;
    obj.setType("character");
    obj.setValue(10);
    EXPECT_EQ(obj.getType(), "character");
    EXPECT_EQ(obj.getValue(), 10);
}

TEST(ObjectTest, Print) {
    Object obj("character", 10);
    testing::internal::CaptureStdout();
    obj.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_EQ(output, "character 10\n");
}

TEST(ObjectTest, GetType) {
    Object obj("character", 10);
    EXPECT_EQ(obj.getType(), "character");
}

TEST(ObjectTest, GetValue) {
    Object obj("character", 10);
    EXPECT_EQ(obj.getValue(), 10);
}

TEST(ObjectTest, ObjectDestructor) {
    Object* obj = new Object("character", 10);
    delete obj;
}

TEST(ObjectTest, ObjectDestructor2) {
    Object obj("character", 10);
}

TEST(ObjectTest, ObjectDestructor3) {
    Object obj;
}

TEST(ObjectTest, ObjectDestructor4) {
    Object obj("character", 10);
    Object obj2("sword", 5);
}

TEST(ObjectTest, ObjectDestructor5) {
    Object obj("character", 10);
    Object obj2("sword", 5);
    Object obj3("potion", 15);
}

TEST(ObjectTest, InvalidSetType) {
    Object obj;
    obj.setType("invalid");
    EXPECT_EQ(obj.getType(), "");
}

TEST(ObjectTest, InvalidSetValue) {
    Object obj;
    obj.setValue(-1);
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InvalidSetValue2) {
    Object obj;
    obj.setValue(100);
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InvalidSetValue3) {
    Object obj;
    obj.setValue(-100);
    EXPECT_EQ(obj.getValue(), 0);
}

TEST(ObjectTest, InvalidSetValue4) {
    Object obj;
    obj.setValue(0);
    EXPECT_EQ(obj.getValue(), 0);
}
*/


