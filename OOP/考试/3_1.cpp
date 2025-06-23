class Point
{
    int x, y;

public:
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    Point &operator+=(const Point &other)
    {
        x += other.x;
        y += other.y;
        return *this;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int x) { this->x = x; }
    void setY(int y) { this->y = y; }
};