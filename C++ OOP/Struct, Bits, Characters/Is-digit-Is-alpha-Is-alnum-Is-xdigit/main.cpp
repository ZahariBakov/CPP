// Using functions isdigit, isalpha, isalnum and isxdigit.
#include <iostream>
using std::cout;
using std::endl;

#include <cctype> // character-handling function prototypes
using std::isalnum;
using std::isalpha;
using std::isdigit;
using std::isxdigit;

int main()
{
   cout << "According to isdigit:\n"
      << ( isdigit( '8' ) ? "8 is a" : "8 is not a" ) << " digit\n"
      << ( isdigit( '#' ) ? "# is a" : "# is not a" ) << " digit\n";

   cout << "\nAccording to isalpha:\n"
      << ( isalpha( 'A' ) ? "A is a" : "A is not a" ) << " letter\n"
      << ( isalpha( 'b' ) ? "b is a" : "b is not a" ) << " letter\n"
      << ( isalpha( '&' ) ? "& is a" : "& is not a" ) << " letter\n"
      << ( isalpha( '4' ) ? "4 is a" : "4 is not a" ) << " letter\n";

   cout << "\nAccording to isalnum:\n"
      << ( isalnum( 'A' ) ? "A is a" : "A is not a" )
      << " digit or a letter\n"
      << ( isalnum( '8' ) ? "8 is a" : "8 is not a" )
      << " digit or a letter\n"
      << ( isalnum( '#' ) ? "# is a" : "# is not a" )
      << " digit or a letter\n";

   cout << "\nAccording to isxdigit:\n"
      << ( isxdigit( 'F' ) ? "F is a" : "F is not a" )
      << " hexadecimal digit\n"
      << ( isxdigit( 'J' ) ? "J is a" : "J is not a" )
      << " hexadecimal digit\n"
      << ( isxdigit( '7' ) ? "7 is a" : "7 is not a" )
      << " hexadecimal digit\n"
      << ( isxdigit( '$' ) ? "$ is a" : "$ is not a" )
      << " hexadecimal digit\n"
      << ( isxdigit( 'f' ) ? "f is a" : "f is not a" )
      << " hexadecimal digit" << endl;
   return 0;
} // end main


