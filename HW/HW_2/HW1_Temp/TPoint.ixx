export module TPoint;

export template <typename T>
class TPoint
{
private:
	T x, y;
	TPoint() { x = 0; y = 0 }
	TPoint(T _x, T _y) { x = _x; y = _y };
	TPoint(const T& _Point) { x = _Point.x; y = _Point.y; return *this };

};
