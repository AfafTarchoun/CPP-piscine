

#ifndef FIXED_HPP
#define FIXED_HPP

#include <math.h>
#include <iostream>

class Fixed {
    private:
        int _rawValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const int value);
        Fixed(const float value);
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        float toFloat() const;
        int toInt() const;
        // int getRawBits() const;
        // void setRawBits(int const raw);
};
std::ostream &operator<<(std::ostream& op, const Fixed& f);


#endif