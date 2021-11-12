#include "core/Color.hpp"

#include <algorithm>
#include <cmath>

namespace rt::core
{

Color::Color() : Base3Object()
{
}

Color::Color(const double x, const double y, const double z)
    : Base3Object(x, y, z)
{
}

Color Color::operator+(const Color& color) const
{
    return Color(x_+color.x(), y_+color.y(), z_+color.z());
}

Color& Color::operator+=(const Color& color)
{
    x_ += color.x();
    y_ += color.y();
    z_ += color.z();
    return *this;
}

Color Color::operator*(const double scale) const
{
    return Color(x_*scale, y_*scale, z_*scale);
}

Color Color::operator*(const Color& color) const
{
    return Color(x_*color.x(), y_*color.y(), z_*color.z());
}

double Color::red() const {return x_;}
double Color::green() const {return y_;}
double Color::blue() const {return z_;}

std::string Color::toString() const
{
    return std::string("{" + std::to_string(x_) + ", "
                           + std::to_string(y_) + ", "
                           + std::to_string(z_) + "}");
}

void Color::serializeToStream(const int samplesPerPixel, std::ostream& out)
{
    const auto scale = 1.0 / samplesPerPixel;

    x_ = std::sqrt(x_*scale);
    y_ = std::sqrt(y_*scale);
    z_ = std::sqrt(z_*scale);

    out << static_cast<int>(256 * std::clamp(x_, 0.0, 0.9999)) << ' '
        << static_cast<int>(256 * std::clamp(y_, 0.0, 0.9999)) << ' '
        << static_cast<int>(256 * std::clamp(z_, 0.0, 0.9999)) << '\n';
}

} // rt::core
