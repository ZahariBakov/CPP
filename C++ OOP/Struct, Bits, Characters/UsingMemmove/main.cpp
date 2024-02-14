// Using memmove.
#include <iostream>
using std::cout;
using std::endl;

#include <cstring> // memmove prototype
using std::memmove;

int main()
{
   char x[] = "Home Sweet Home";

   cout << "The string in array x before memmove is: " << x;
   cout << "\nThe string in array x after memmove is:  "
      << static_cast< char * >( memmove( x, &x[ 5 ], 10 ) ) << endl;
   return 0;
} // end main


