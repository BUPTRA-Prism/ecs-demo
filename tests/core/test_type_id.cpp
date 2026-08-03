#include "core/type_id.h"
#include <gtest/gtest.h>

struct Position { int x; int y; };
struct Velocity { int dx; int dy; };
struct Health { int value; };

TEST(TypeIDTest, DifferentTypesGetDifferentIds) {
    auto id1 = ecs::get_next_type_id<Position>();
    auto id2 = ecs::get_next_type_id<Velocity>();
    auto id3 = ecs::get_next_type_id<Health>();
    EXPECT_NE(id1, id2);
    EXPECT_NE(id2, id3);
    EXPECT_NE(id3, id1);
}

TEST(TypeIDTest, SameTypeGetsSameId) {
    auto id1 = ecs::get_next_type_id<Position>();
    auto id2 = ecs::get_next_type_id<Position>();
    auto id3 = ecs::get_next_type_id<Position>();
    EXPECT_EQ(id1, id2);
    EXPECT_EQ(id2, id3);
    EXPECT_EQ(id3, id1);
}

TEST(TypeIDTest, ReturnsNonEmpty) {
    EXPECT_FALSE(ecs::get_type_name<Position>().empty());
}

TEST(TypeIDTest, SameTypeSameName) {
    EXPECT_EQ(ecs::get_type_name<Position>(), ecs::get_type_name<Position>());
}

TEST(TypeIDTest, DifferentTypesDifferentNames) {
    EXPECT_NE(ecs::get_type_name<Position>(), ecs::get_type_name<Velocity>());
}

TEST(TypeIDTest, SameTypeSameHash) {
    EXPECT_EQ(ecs::get_type_hash<Position>(), ecs::get_type_hash<Position>());
}

TEST(TypeIDTest, DifferentTypesDifferentHash) {
    EXPECT_NE(ecs::get_type_hash<Position>(), ecs::get_type_hash<Velocity>());
}