#include <iostream>
#include "triangle.h"

using namespace std;

int main()
{
   auto* empty = new triangle();
   auto* with_params = new triangle(10, 15, 30);

   empty->set_a(100);
   empty->set_b(200);
   empty->set_c(300);

   cout << endl << "Show empty-object (constructor without params)" <<
      "after setting values : " << endl
      << empty->to_string() << endl;

   auto* copied = new triangle(*with_params);

   delete empty;
   delete copied;
   delete with_params;
}
