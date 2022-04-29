#pragma once
#include <iostream>
#include<cmath>
#include <string>

class triangle
{
public:
   triangle() = default;

   triangle(const int a, const int b, const int c)
      : a_(a),
      b_(b),
      c_(c)
   {
   }

   triangle(const triangle& triangle)
   {
      this->a_ = triangle.get_a();
      this->b_ = triangle.get_b();
      this->c_ = triangle.get_c();
   }

   ~triangle() = default;

   bool is_exist() const
   {
      if (a_ + b_ > c_ || a_ + c_ > b_ || c_ + b_ > a_)
         return true;

      return false;
   }

   int get_perimeter() const
   {
      return a_ + b_ + c_;
   }

   double get_area() const
   {
      const int p = get_perimeter();

      return sqrt(p * (p - a_) * (p - b_) * (p - c_));
   }

   int get_a() const
   {
      return a_;
   }

   void set_a(const int a)
   {
      this->a_ = a;
   }

   int get_b() const
   {
      return b_;
   }

   void set_b(const int b)
   {
      this->b_ = b;
   }

   int get_c() const
   {
      return c_;
   }

   void set_c(const int c)
   {
      this->c_ = c;
   }

   std::string to_string() const
   {
      std::string dump = "triangle: {\n";
      dump + "side A: " + std::to_string(a_) + ",\n";
      dump += "side B: " + std::to_string(b_) + ",\n";
      dump += "side C: " + std::to_string(c_) + ",\n";
      dump += "is exist: " + std::to_string(is_exist()) + ",\n";
      dump += "perimeter: " + std::to_string(get_perimeter()) + ",\n";
      dump += "area: " + std::to_string(get_area()) + ",\n";
      dump += "}";

      return dump;
   }

private:
   int a_;
   int b_;
   int c_;
};
