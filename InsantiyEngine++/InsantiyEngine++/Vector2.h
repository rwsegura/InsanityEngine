#include <iostream>

namespace RedStd {

	typedef class Vec2* vecRef;

	class Vec2 {
		private:
			int x, y;
		public:
			Vec2();
			Vec2(int x, int y);
			Vec2(int vec_array[2]);

			//Operator overloads
			float &operator[](int index);
			float operator[](int index) const;

			Vec2 operator*(float scale) const;
			Vec2 operator/(float scale) const;
			Vec2 operator+(const Vec2 &other) const;
			Vec2 operator-(const Vec2 &other) const;
			Vec2 operator-() const;

			const Vec2 &operator*=(float scale);
			const Vec2 &operator/=(float scale);
			const Vec2 &operator+=(const Vec2 &other);
			const Vec2 &operator-=(const Vec2 &other);

			friend bool operator==(Vec2 u, Vec2 v);
	};

	std::ostream &operator<<(std::ostream &output, const Vec2 &v);

}