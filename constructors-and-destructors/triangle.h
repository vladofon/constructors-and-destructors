#pragma once
#include <cassert>
#include <iostream>
#include<cmath>
#include <string>

class triangle
{
public:

   triangle()
   {
      std::cout << "Constructor without params:" << std::endl;

      this->a_ = -1;
      this->b_ = -1;
      this->c_ = -1;

      std::cout << to_string() << std::endl;
   }

   triangle(const int a, const int b, const int c)
      : a_(a),
      b_(b),
      c_(c)
   {
      std::cout << "Constructor with params:" << std::endl;
      std::cout << to_string() << std::endl;
   }

   triangle(const triangle& triangle)
   {
      std::cout << "Copy constructor:" << std::endl;

      this->a_ = triangle.get_a();
      this->b_ = triangle.get_b();
      this->c_ = triangle.get_c();

      std::cout << to_string() << std::endl;
   }

   ~triangle()
   {
      std::cout << "Call the destructor" << std::endl;
   }

   bool is_exist() const
   {
      if (a_ + b_ > c_ || a_ + c_ > b_ || c_ + b_ > a_)
         return true;

      return false;
   }

   int get_perimeter() const
   {
      return is_exist() ? a_ + b_ + c_ : -1;
   }

   double get_area() const
   {
      const int p = get_perimeter();

      return is_exist() ? sqrt(p * (p - a_) * (p - b_) * (p - c_)) : -1;
   }

   int get_a() const
   {
      return a_;
   }

   void set_a(const int a)
   {
      this->a_ = a;
      std::cout << "Call the [a] field setter" << std::endl;
   }

   int get_b() const
   {
      return b_;
   }

   void set_b(const int b)
   {
      this->b_ = b;
      std::cout << "Call the [b] field setter" << std::endl;
   }

   int get_c() const
   {
      return c_;
   }

   void set_c(const int c)
   {
      this->c_ = c;
      std::cout << "Call the [c] field setter" << std::endl;
   }

   std::string to_string() const
   {
      std::string dump = "triangle: [{\n";
      dump += "  side A: " + std::to_string(a_) + ",\n";
      dump += "  side B: " + std::to_string(b_) + ",\n";
      dump += "  side C: " + std::to_string(c_) + ",\n";
      dump += "  is exist: " + std::to_string(is_exist()) + ",\n";
      dump += "  perimeter: " + std::to_string(get_perimeter()) + ",\n";
      dump += "  area: " + std::to_string(get_area()) + ",\n";
      dump += "}];\n";

      return dump;
   }

private:
   int a_;
   int b_;
   int c_;
};
