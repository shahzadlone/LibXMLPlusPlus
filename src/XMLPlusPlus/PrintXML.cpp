#include "XMLPlusPlus/PrintXML.h"
#include "XMLPlusPlus/CatchConvertError.h"

#include <iostream>

// Use these Namespaces.
using namespace std;
using namespace xmlpp;

// Helper Function to Print a Node from xml++
void xmlhelp::PrintNode( const Node * node, unsigned int indentation ) {

    const Glib::ustring indent( indentation, ' ' );
    
    // Separate nodes by an empty line.
    cout << endl;
  
    const auto nodeContent = dynamic_cast<const ContentNode*>( node );
    const auto nodeText = dynamic_cast<const TextNode*>( node );
    const auto nodeComment = dynamic_cast<const CommentNode*>( node );
  
    if ( nodeText &&
         nodeText->is_white_space() ) { // Let's ignore the indenting - you don't always want to do this.
        return;
    } 
    const auto nodename = node->get_name();
  
    if ( !( nodeText ) && 
         !( nodeComment ) &&
         !( nodename.empty() )
       ) { // Let's not say "name: text. 
        const auto namespace_prefix = node->get_namespace_prefix();
  
        cout << indent << "Node name = ";
        if ( !( namespace_prefix.empty() ) ) {
            cout << CatchConvertError( namespace_prefix ) << ":";
        }
        cout << CatchConvertError( nodename ) << endl;
    }
    else if( nodeText ) { // Let's say when it's text. - e.g. let's say what that white space is) 
        cout << indent << "Text Node" << endl;
    }
  
    // Treat the various node types differently:
    if ( nodeText ) {
        cout << indent << "text = \"" << CatchConvertError( nodeText->get_content() ) << "\"" << endl;
    }
    else if( nodeComment ) {
        cout << indent << "comment = " << CatchConvertError( nodeComment->get_content() ) << endl;
    }
    else if ( nodeContent ) {
        cout << indent << "content = " << CatchConvertError( nodeContent->get_content() ) << endl;
    }
    else if ( const Element* nodeElement = dynamic_cast<const Element*>( node ) ) { // A normal Element node:
  
        // line() works only for ElementNodes.
        cout << indent << "     line = " << node->get_line() << endl;
  
        // Print attributes:
        for ( const auto & attribute : nodeElement->get_attributes() ) {

            const auto namespace_prefix = attribute->get_namespace_prefix();
  
            cout << indent << "  Attribute ";
            if( !( namespace_prefix.empty() ) ) {
                cout << CatchConvertError( namespace_prefix ) << ":";
            }
            
            cout << CatchConvertError( attribute->get_name() ) << " = "
                 << CatchConvertError( attribute->get_value() ) << endl;
        }
  
        const auto attribute = nodeElement->get_attribute( "title" );
        if( attribute ) {
            cout << indent;
            if ( dynamic_cast<const AttributeNode*>( attribute ) ) {
                cout << "AttributeNode ";
            }
            else if ( dynamic_cast<const AttributeDeclaration*>( attribute ) ) {
                cout << "AttributeDeclaration ";
            }

            cout << "title = " << CatchConvertError( attribute->get_value() ) << endl;
        }
    }
  
    if( !( nodeContent ) ) {
        // Recurse through child nodes:
        for( const auto& child : node->get_children() ) {
            // Recurse through
            PrintNode( child, indentation + 4 ); 
        }
    }
}

