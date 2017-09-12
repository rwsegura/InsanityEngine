#include <iostream>

namespace RedStd {

	template <class T>
	class Vec2 {
		public:
			T x, y;

			Vec2(T x, T y) {
				this->x = x;
				this->y = y;
			}

			Vec2<T> operator*(T scale) const {
				return Vect2<T>(this->x * scale, this->y * scale);
			}

			Vec2<T> operator/(T scale) const {
				return Vect2<T>(this->x / scale, this->y / scale);
			}

			Vec2<T> operator+(const Vec2 &other) const {
				return Vect2<T>(this->x + other->x, this->y + other->y);
			}
			
			Vec2<T> operator-(const Vec2 &other) const {
				return Vect2<T>(this->x - other->x, this->y - other->y);
			}

			const Vec2& operator*=(T scale) {
				this->x = this->x * scale;
				this->y = this->y * scale;

				return *this;
			}
			
			const Vec2& operator/=(T scale) {
				this->x = this->x / scale;
				this->y = this->y / scale;

				return *this;
			}
			
			const Vec2& operator+=(const Vec2 &other) {
				this->x = this->x + other->x;
				this->y = this->y + other->y;

				return *this;
			}
			
			const Vec2& operator-=(const Vec2 &other) {
				this->x = this->x - other->x;
				this->y = this->y - other->y;

				return *this;
			}

			friend bool operator==(Vec2<T> u, Vec2<T> v) {
				return (u->x == v->x) && (u->y == v->y);
			}
	};

	template <class T>
	std::ostream &operator<<(std::ostream &output, const Vec2<T> &v) {
		return output << "X: " << v->x << " Y: " << v->y << std::endl;
	}

	typedef class Vec2<int> Vec2i;
	typedef class Vec2 <long> Vec2l;
	typedef class Vec2<float> Vec2f;
	typedef class Vec2<double> Vec2d;
}
