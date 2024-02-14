// Using memcmp.
#include <iostream>
using std::cout;
using std::endl;

#include <iomanip>
using std::setw;

#include <cstring> // memcmp prototype
using std::memcmp;

int main()
{
   char s1[] = "ABCDEFG";
   char s2[] = "ABCDXYZ";

   cout << "s1 = " << s1 << "\ns2 = " << s2 << endl
      << "\nmemcmp(s1, s2, 4) = " << setw( 3 ) << memcmp( s1, s2, 4 )
      << "\nmemcmp(s1, s2, 7) = " << setw( 3 ) << memcmp( s1, s2, 7 )
      << "\nmemcmp(s2, s1, 7) = " << setw( 3 ) << memcmp( s2, s1, 7 )
      << endl;
   return 0;
} // end main

