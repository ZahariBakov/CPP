// Using strspn.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // strspn prototype
using std::strspn;

int main()
{
   const char *string1 = "The value is 3.14159";
   const char *string2 = "aehils Tuv";

   cout << "string1 = " << string1 << "\nstring2 = " << string2
      << "\n\nThe length of the initial segment of string1\n"
      << "containing only characters from string2 = "
      << strspn( string1, string2 ) << endl;
   return 0;
} // end main

