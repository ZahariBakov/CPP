// Using atol.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // atol prototype
using std::atol;

int main()
{
   long x = atol( "1000000" ); // convert string to long

   cout << "The string \"1000000\" converted to long is " << x
      << "\nThe converted value divided by 2 is " << x / 2 << endl;
   return 0;
} // end main

