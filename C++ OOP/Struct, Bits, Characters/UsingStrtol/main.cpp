// Using strtol.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // strtol prototype
using std::strtol;

int main()
{
   long x;
   const char *string1 = "-1234567abc";
   char *remainderPtr;

   x = strtol( string1, &remainderPtr, 0 ); // convert characters to long

   cout << "The original string is \"" << string1
      << "\"\nThe converted value is " << x
      << "\nThe remainder of the original string is \"" << remainderPtr
      << "\"\nThe converted value plus 567 is " << x + 567 << endl;
   return 0;
} // end main

