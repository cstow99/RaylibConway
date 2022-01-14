#ifndef VEC2_H
#define VEC2_H

template <typename T>
class Vec2 {
public:
    Vec2() = default;

    constexpr Vec2(T x, T y) :
        _x(x),
        _y(y) {}

    constexpr T GetX() const { return _x; }
    constexpr T GetY() const { return _y; }
    constexpr void SetX(T x_input) { _x = x_input; }
    constexpr void SetY(T y_input) { _y = y_input; }

public:
    constexpr bool operator==(const Vec2& rhs) const {
        return (_x == rhs._x && _y == rhs._y);
    }
    constexpr bool operator!=(const Vec2& rhs) const {
        return !(*this == rhs);
    }
    constexpr Vec2 operator+(const Vec2& rhs) const {
        return { _x + rhs._x, _y + rhs._y };
    }
    constexpr Vec2 operator+(const int rhs) const {
        return { _x + rhs, _y + rhs };
    }
    constexpr Vec2& operator+=(const Vec2& rhs) {
        return *this = *this + rhs;
    }
    constexpr Vec2 operator-(const Vec2& rhs) const {
        return { _x - rhs._x, _y - rhs._y };
    }
    constexpr Vec2 operator-(const int rhs) const {
        return { _x - rhs, _y - rhs };
    }
    constexpr Vec2& operator-=(const Vec2& rhs) {
        return *this = *this - rhs;
    }
    constexpr Vec2 operator*(const Vec2& rhs) const {
        return { _x * rhs._x, _y * rhs._y };
    }
    constexpr Vec2 operator*(const int rhs) const {
        return { _x * rhs, _y * rhs };
    }

private:
    T _x;
    T _y;
};

#endif