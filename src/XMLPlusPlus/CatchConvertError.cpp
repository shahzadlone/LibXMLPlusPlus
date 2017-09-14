# include "XMLPlusPlus/CatchConvertError.h"

# include <glibmm/convert.h>

using namespace std;

ostream & xmlhelp::operator<<( ostream & os, const CatchConvertError & utf8_string ) {
  
    try {
        os << static_cast<const Glib::ustring &>( utf8_string );
    }
    catch ( const Glib::ConvertError & ex ) {
        os << "[Glib::ConvertError: " << ( ex ).what() << "]";
    }

    return( os );
}
