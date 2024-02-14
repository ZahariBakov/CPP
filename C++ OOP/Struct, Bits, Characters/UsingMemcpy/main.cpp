// Using memcpy.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // memcpy prototype
using std::memcpy;

int main()
{
   char s1[ 17 ];

   // 17 total characters (includes terminating null)
   char s2[] = "Copy this string";

   memcpy( s1, s2, 17 ); // copy 17 characters from s2 to s1

   cout << "After s2 is copied into s1 with memcpy,\n"
      << "s1 contains \"" << s1 << '\"' << endl;
   return 0;
} // end main

