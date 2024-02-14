// Using strrchr.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // strrchr prototype
using std::strrchr;

int main()
{
   const char *string1 = "A zoo has many animals including zebras";
   char c = 'z';

   cout << "string1 = " << string1 << "\n" << endl;
   cout << "The remainder of string1 beginning with the\n"
      << "last occurrence of character '"
      << c << "' is: \"" << strrchr( string1, c ) << '\"' << endl;
   return 0;
} // end main

