// Using strpbrk.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // strpbrk prototype
using std::strpbrk;

int main()
{
   const char *string1 = "This is a test";
   const char *string2 = "beware";

   cout << "Of the characters in \"" << string2 << "\"\n'"
      << *strpbrk( string1, string2 ) << "\' is the first character " 
      << "to appear in\n\"" << string1 << '\"' << endl;
   return 0;
} // end main

