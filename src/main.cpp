#include "CurlPlusPlus/Curl.h"
#include "XMLPlusPlus/PrintXML.h"
#include "XMLPlusPlus/CatchConvertError.h"

#include <libxml++/libxml++.h>

#include <iostream>

using namespace std;
using namespace xmlpp;

int main( int argc, char* argv[] ) {

  // Set the global C++ locale to the user-specified locale. Then we can
  //  hopefully use std::cout with UTF-8, via Glib::ustring, without exceptions.
  locale::global( locale( "" ) );

  // Ensure Only One Argument is Given.
    if ( argc != 2 ) {
        cerr << "Usage: " << argv[0] << " <url>" << endl;
        exit( EXIT_FAILURE );
    }

    // Curl Url and Store the Result.
    string curlResult = curlcpp::Curl( argv[1] );

    // Start Parsing XML
    cout << " ==================[Start Parsing with XML++ ]==================" << endl; 
    
    // Create our DomParser Object.
    DomParser parser;
    // Make Sure parser it is Created Successfully.
    if ( parser ) {
        // Walk the tree:
        
        // This Sets the Document With Our String.
        ( parser ).parse_memory( curlResult );   
        
        // Get the Document, which should be constant (non-modifiable).
        const Document * doc = ( parser ).get_document(); 
          
        // Get the Root Node( NOTE: Element Class is derived class of  Node Class). 
        const Element * rootNode = ( doc )->get_root_node(); 

        // Print Root Node.
        xmlhelp::PrintNode( rootNode );
    }

    // Done Parsing XML
    cout << " ==================[DONE Parsing with XML++ ]==================" << endl; 

    return ( EXIT_SUCCESS );
}
