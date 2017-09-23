# ifndef CURL_H
# define CURL_H

# include <string>
# include <curl/curl.h>
# include <cstdlib>

namespace curlcpp {

    namespace libcurlwrapper {
    
        // Used for an Option inside CurlInitialization.
        size_t CurlWriter( void * dataPointer,
                           size_t size,
                           size_t nmemb,
                           std::string * writerData ); 

        // Sets the Curling Options and Tells Where to Save the Result and Errors.
        bool CurlInitialization( CURL *& conn,
                                 const std::string & url,
                                 std::string * errorStr, 
                                 std::string * resultStoreBuffer ); 

        // Curls the URL to Get the Result and then Cleans Up.
        bool CurlAndClean( CURL *& conn,
                           const std::string & url,
                           std::string * errStr ) ;
    
    } // Closing Brace of namespace libcurlwrapper
    
    // Returns the Curled Output of the consumed url, in a String Form.
    std::string Curl( const std::string & url );

} // Closing Brace of namespace curlcpp

# endif // End of Guard for CURL_H
