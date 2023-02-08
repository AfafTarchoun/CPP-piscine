
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <string>

// dumb
class Fixed
{
    private:
        int _rawValue;
        static const int _fractionalBits = 8;
    public:
        Fixed();
        Fixed(const Fixed &other);
        ~Fixed();
        Fixed &operator=(const Fixed &other);
        int getRawBits() const;
        void setRawBits(int const raw);
};

#endif