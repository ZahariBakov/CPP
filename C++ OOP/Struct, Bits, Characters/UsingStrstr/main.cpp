// Using strstr.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // strstr prototype
using std::strstr;

int main()
{
   const char *string1 = "abcdefabcdef";
   const char *string2 = "def";

   cout << "string1 = " << string1 << "\nstring2 = " << string2
      << "\n\nThe remainder of string1 beginning with the\n"
      << "first occurrence of string2 is: " 
      << strstr( string1, string2 ) << endl;
   return 0;
} // end main

