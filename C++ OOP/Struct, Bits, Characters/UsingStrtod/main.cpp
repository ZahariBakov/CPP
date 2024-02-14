// Using strtod.
#include <iostream>
using std::cout;
using std::endl;

#include <cstdlib> // strtod prototype
using std::strtod;

int main()
{
   double d;
   const char *string1 = "51.2% are admitted";
   char *stringPtr;

   d = strtod( string1, &stringPtr ); // convert characters to double

   cout << "The string \"" << string1 
      << "\" is converted to the\ndouble value " << d 
      << " and the string \"" << stringPtr << "\"" << endl;
   return 0;
} // end main


