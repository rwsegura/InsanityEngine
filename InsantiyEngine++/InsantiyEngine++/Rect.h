#ifndef __RED_RECT_H__
#define __RED_RECT_H__

namespace RedStd {

	class Rect {
		public:
			int x, y, width, height;

			Rect() : Rect(0, 0) {}
			Rect(int width, int height) : Rect(0, 0, width, height) {}
			Rect(int x, int y, int width, int height);

			bool Interescts(Rect &rect);

			friend bool operator==(Rect one, Rect two) {
				return one.x == two.x &&
					one.y == two.y &&
					one.width == two.width &&
					one.height == two.height;
			}
	};
}

#endif
