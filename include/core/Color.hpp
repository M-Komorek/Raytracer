#ifndef RAYTRACER_CORE_COLOR_HPP
#define RAYTRACER_CORE_COLOR_HPP

#include <iostream>
#include <sstream>
#include <string>

#include "core/Base3Object.hpp"

namespace rt::core
{

class Color : public Base3Object
{
public:
    Color();
    Color(const double x, const double y, const double z);

    Color operator+(const Color& color) const;
    Color& operator+=(const Color& color);
    Color operator*(const double scale) const;

    double red() const;
    double green() const;
    double blue() const;

    void serializeToStream(const int samplesPerPixel, std::ostream& out = std::cout);

    std::string toString() const override;
};

} // rt::core

#endif // RAYTRACER_CORE_COLOR_HPP
