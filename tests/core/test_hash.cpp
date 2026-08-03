#include "core/hash.h"
#include <gtest/gtest.h>
#include <string_view>

TEST(HashTest, KnownTestVectors) {
    EXPECT_EQ(fnv1a_hash("a"), 0xaf63dc4c8601ec8c);
    EXPECT_EQ(fnv1a_hash("hello"), 0xa430d84680aabd0b);
}

TEST(HashTest, SameInputSameHash) {
    EXPECT_EQ(fnv1a_hash("Position"), fnv1a_hash("Position"));
}

TEST(HashTest, DifferentInputDifferentHash) {
    EXPECT_NE(fnv1a_hash("Position"), fnv1a_hash("Velocity"));
    EXPECT_NE(fnv1a_hash("Health"), fnv1a_hash("health"));
}

TEST(HashTest, EmptyString) {
    EXPECT_EQ(fnv1a_hash(""), 0xcbf29ce484222325);
}

TEST(HashTest, LongString) {
    std::string long_str(200, 'a');
    EXPECT_EQ(fnv1a_hash(long_str), 0x96245ce14f7a5b0dULL);
}

TEST(HashedStringTest, ConstructFromString) {
    hashed_string str("hello");
    EXPECT_EQ(str.getStr(), "hello");
    EXPECT_EQ(str.getHash(), fnv1a_hash("hello"));
}

TEST(HashedStringTest, Equality) {
    hashed_string str1("Position");
    hashed_string str2("Position");
    hashed_string str3("Velocity");
    EXPECT_EQ(str1, str2);
    EXPECT_NE(str1, str3);
}

TEST(HashedStringTest, EmptyString) {
    hashed_string str("");
    EXPECT_EQ(str.getStr(), "");
}

TEST(HashedStringTest, Copy) {
    hashed_string str1("hello");
    hashed_string str2 = str1;
    EXPECT_EQ(str1, str2);
}

TEST(HashedStringTest, Move) {
    hashed_string a("hello");
    hashed_string b = std::move(a);
    EXPECT_EQ(b, hashed_string("hello"));
}