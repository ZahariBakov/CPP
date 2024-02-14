// Using strcspn.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // strcspn prototype
using std::strcspn;

int main()
{
   const char *string1 = "The value is 3.14159";
   const char *string2 = "1234567890";

   cout << "string1 = " << string1 << "\nstring2 = " << string2
      << "\n\nThe length of the initial segment of string1"
      << "\ncontaining no characters from string2 = "
      << strcspn( string1, string2 ) << endl;
   return 0;
} // end main
