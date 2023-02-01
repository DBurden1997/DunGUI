//
//  vector2d.hpp
//  SDL2
//
//  Created by Dylan Burden on 2022-07-11.
//

#ifndef vector2d_hpp
#define vector2d_hpp

#include <stdio.h>
#include <iostream>
#include <type_traits>
#include <cmath>

template<typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value, T>::type>
class Vector2D
{
    T           mFirst;
    T           mSecond;
    
public:
    Vector2D(T first, T second) :
        mFirst(first),
        mSecond(second)
    {}
    
    Vector2D(const Vector2D<T>& s, const Vector2D<T>& e)
    {
        mFirst = e.first() - s.first();
        mSecond = e.second() - s.second();
    }
    
    const T first() const {return mFirst;}
    const T second() const {return mSecond;}
    
    void first(T val) {mFirst = val;}
    void second(T val) {mSecond = val;}
    
    void set(const Vector2D<T>& v)
    {
        mFirst = v.first();
        mSecond = v.second();
    }
    
    float length() const
    {
        return sqrt(float(mFirst * mFirst) + float(mSecond * mSecond));
    }
    
    float angleRad() const
    {
        return atan2(float(mFirst), float(mSecond));
    }
    
    void operator=(const Vector2D<int>& rhs)
    {
        mFirst = rhs.first();
        mSecond = rhs.second();
    }
    void operator=(const Vector2D<float>& rhs)
    {
        mFirst = rhs.first();
        mSecond = rhs.second();
    }
    void operator=(const Vector2D<double>& rhs)
    {
        mFirst = rhs.first();
        mSecond = rhs.second();
    }
    
    Vector2D<T> operator+(const Vector2D<int>& rhs) const
    {
        return Vector2D(mFirst + rhs.first(), mSecond + rhs.second());
    }
    
    Vector2D<T> operator+(const Vector2D<float>& rhs) const
    {
        return Vector2D(mFirst + rhs.first(), mSecond + rhs.second());
    }
    
    Vector2D<T> operator+(const Vector2D<double>& rhs) const
    {
        return Vector2D(mFirst + rhs.first(), mSecond + rhs.second());
    }
    
    Vector2D<T>& operator+=(const Vector2D<T>& rhs)
    {
        mFirst += rhs.first();
        mSecond += rhs.second();
        
        return *this;
    }
    
    Vector2D<T> operator-(const Vector2D<T>& rhs) const
    {
        return Vector2D(mFirst - rhs.first(), mSecond - rhs.second());
    }
    
    Vector2D<T>& operator-=(const Vector2D<T>& rhs)
    {
        mFirst -= rhs.first();
        mSecond -= rhs.second();
        
        return *this;
    }
    
    Vector2D<T> operator*(const int rhs) const
    {
        return Vector2D(mFirst * rhs, mSecond * rhs);
    }
    
    Vector2D<T> operator*(const float rhs) const
    {
        return Vector2D(mFirst * rhs, mSecond * rhs);
    }
    
    Vector2D<T> operator*(const double rhs) const
    {
        return Vector2D(mFirst * rhs, mSecond * rhs);
    }
    
    Vector2D<T>& operator*=(const int rhs)
    {
        mFirst *= rhs;
        mSecond *= rhs;
        
        return *this;
    }
    
    Vector2D<T>& operator*=(const float rhs)
    {
        mFirst *= rhs;
        mSecond *= rhs;
        
        return *this;
    }
    
    Vector2D<T>& operator*=(const double rhs)
    {
        mFirst *= rhs;
        mSecond *= rhs;
        
        return *this;
    }
    
    Vector2D<T> operator*(const Vector2D<T>& rhs) const
    {
        return Vector2D(mFirst * rhs.first(), mSecond * rhs.second());
    }
    
    Vector2D<T>& operator*=(const Vector2D<T>& rhs)
    {
        mFirst *= rhs.first();
        mSecond *= rhs.second();
        
        return *this;
    }
    
    Vector2D<T> operator/(const int rhs) const
    {
        return Vector2D(mFirst / rhs, mSecond / rhs);
    }
    
    Vector2D<T> operator/(const float rhs) const
    {
        return Vector2D(mFirst / rhs, mSecond / rhs);
    }
    
    Vector2D<T> operator/(const double rhs) const
    {
        return Vector2D(mFirst / rhs, mSecond / rhs);
    }
    
    Vector2D<T>& operator/=(const int rhs)
    {
        mFirst /= rhs;
        mSecond /= rhs;
        
        return *this;
    }
    
    Vector2D<T>& operator/=(const float rhs)
    {
        mFirst /= rhs;
        mSecond /= rhs;
        
        return *this;
    }
    
    Vector2D<T>& operator/=(const double rhs)
    {
        mFirst /= rhs;
        mSecond /= rhs;
        
        return *this;
    }
    
    bool operator==(const Vector2D<T>& rhs) const
    {
        return (mFirst == rhs.first() && mSecond == rhs.second());
    }
    
    bool operator!=(const Vector2D<T>& rhs) const
    {
        return !(*this == rhs);
    }
    
    T dot(const Vector2D<T>& v) const
    {
        return ( mFirst * v.first() ) + ( mSecond * v.second() );
    }
    
    float angleBetween(const Vector2D<T>& v) const
    {
        return acos( float( dot(v) / (length() * v.length()) ) );
    }
    
    void normalize()
    {
        mFirst /= length();
        mSecond /= length();
    }
    
    Vector2D<double> getNormal() const
    {
        return Vector2D<double>(mFirst / length(), mSecond / length());
    }
    
    Vector2D<int> roundDown() const
    {
        return Vector2D<int>(static_cast<int>(mFirst), static_cast<int>(mSecond));
    }
    
    void print() const
    {
        std::cout << "First: " << mFirst << ", Second: " << mSecond << "\n";
    }
};

#endif /* vector2d_hpp */
