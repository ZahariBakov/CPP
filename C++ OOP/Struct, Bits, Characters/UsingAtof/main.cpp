// Using atof.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // atof prototype
using std::atof;

int main()
{
   double d = atof( "99.0" ); // convert string to double

   cout << "The string \"99.0\" converted to double is " << d 
      << "\nThe converted value divided by 2 is " << d / 2.0 << endl;
   return 0;
} // end main

