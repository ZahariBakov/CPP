// Using strtoul.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // strtoul prototype
using std::strtoul;

int main()
{
   unsigned long x;
   const char *string1 = "1234567abc";
   char *remainderPtr;

   // convert a sequence of characters to unsigned long
   x = strtoul( string1, &remainderPtr, 0 );

   cout << "The original string is \"" << string1
      << "\"\nThe converted value is " << x
      << "\nThe remainder of the original string is \"" << remainderPtr
      << "\"\nThe converted value minus 567 is " << x - 567 << endl;
   return 0;
} // end main
