// Using memchr.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // memchr prototype
using std::memchr;

int main()
{
   char s[] = "This is a string";

   cout << "s = " << s << "\n" << endl;
   cout << "The remainder of s after character 'r' is found is \""
      << static_cast< char * >( memchr( s, 'r', 16 ) ) << '\"' << endl;
   return 0;
} // end main

