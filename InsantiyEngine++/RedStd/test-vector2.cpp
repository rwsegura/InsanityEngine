#include "catch.hpp"

#include "Vector2.h"

using namespace RedStd;

TEST_CASE("Vector2 can perform mathematical operations", "[Vectory2]") {
	Vec2i one(5, 5);
	Vec2i two(10, 10);

	SECTION("Vectors can be added together.") {
		Vec2i three = one + two;

		REQUIRE(three.x == 15);
		REQUIRE(three.y == 15);
	}

	SECTION("Vectors can be subtracted together.") {
		Vec2i three = two - one;

		REQUIRE(three.x == 5);
		REQUIRE(three.y == 5);
	}

	SECTION("Vectors can be multiplied by a scalar.") {
		Vec2i three = one * 4;

		REQUIRE(three.x == 20);
		REQUIRE(three.y == 20);
	}

	SECTION("Vectors can be divided by a scalar.") {
		Vec2i three = one / 5;

		REQUIRE(three.x == 1);
		REQUIRE(three.y == 1);
	}
}
