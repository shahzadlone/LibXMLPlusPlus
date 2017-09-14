#include <glibmm/ustring.h>
#include <iostream>

namespace xmlhelp {
    
    // CatchConvertError is identical to Glib::ustring, except that
    // std::ostream& operator<<(std::ostream&, const CatchConvertError&)
    // catches Glib::ConvertError, and prints the exception message.
    // If a printed string contains characters that don't exist in the global
    // locale's character set, an exception is thrown, but it's caught locally,
    // and the program continues.
    // This is particularly useful when the example programs are run by 'make check'.
    // If the user-specified locale's character set does not contain all characters
    // in the Glib::ustring, operator<<(std::ostream&, const Glib::ustring&) throws
    // a Glib::ConvertError exception.
    class CatchConvertError : public Glib::ustring {
   
        public:
     
         explicit CatchConvertError( const Glib::ustring & str ) : Glib::ustring( str ) {
         }
    };
    
    // Overloader for the << Operator.    
    std::ostream& operator<<( std::ostream & os, const CatchConvertError & utf8_string );

} // End Brace of namespace xmlhelp.
