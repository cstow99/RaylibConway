// A wrapper for dealing with rectangle drawing using the Vec2 class
#ifndef RAYLIB_EXTRAWRAPPER_H
#define RAYLIB_EXTRAWRAPPER_H
#include "Vec2.h"
#include <raylib.h>
// Might not even need the Raylib C++ wrapper for these functions
//#include <raylib-cpp.hpp>

#include <cassert>

namespace raylib {
    inline void DrawRectangle_Vec2Int(Vec2<int> pos, Vec2<int> size, Color color) {
        DrawRectangle(pos.GetX(),pos.GetY(),size.GetX(),size.GetY(),color);
    }

    inline void DrawRectangleLines_Vec2Int(Vec2<int> pos, Vec2<int> size, float lineThickness, Color color) {
        assert(pos.GetX() >= 0 && pos.GetY() >= 0 &&
               pos.GetX() < GetScreenWidth() && pos.GetY() < GetScreenHeight() &&
        "raylib_extra.DrawRectangleLines_Vec2Int: Attempted to draw outside of screen!");

        DrawRectangleLinesEx({(float)pos.GetX(),(float)pos.GetY(),(float)size.GetX(),(float)size.GetY()},lineThickness,color);
    }
}

#endif