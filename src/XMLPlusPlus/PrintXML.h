#ifndef PRINTXML_H
#define PRINTXML_H

#include <libxml++/libxml++.h>

namespace xmlhelp { 

    // Function to help us print node if we ever watn to.
    void PrintNode( const xmlpp::Node * node, unsigned int indentation = 0 ); 

}

#endif // End of Header Guard for PRINTXML_H
