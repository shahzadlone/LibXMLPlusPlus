# include "CurlPlusPlus/Curl.h"

using namespace std;

// ================ Namespace curlcpp::libcurlwrapper Implementations  ================

// Callback Function for libcurl to Set the write Option (CURLOPT_WRITEFUNCTION).
size_t curlcpp::libcurlwrapper::CurlWriter( void * dataPointer,
                                            size_t size,
                                            size_t nmemb,
                                            string * writerData ) {
    if ( writerData == NULL ) {
        return( 0 );
    }
     
    // Using the "from buffer" constructor, which is a part of std::string library.
    // Usage: string(const char* s, size_t n);
    // Purpose: Copies the first n characters from the array of characters pointed by s.
    string data( static_cast<const char *>( dataPointer ),
                 static_cast<size_t>( size * nmemb ) 
               ); 

    // Append data on to the string that writerData points at.
    *( writerData ) = ( *( writerData ) + data );
   
    // Return the total size of data wrote(appended).
    return( size * nmemb );
}
 

// Function to Initialize Curl Connection and Set All the Required Options.
bool curlcpp::libcurlwrapper::CurlInitialization( CURL *& conn,
                                                  const string & url,
                                                  string * errorStr, 
                                                  string * resultStoreBuffer ) {
    // Initialize Connection.
    // Note: This call MUST have a corresponding call to curl_easy_cleanup,
    //        curlcpp::libcurlwrapper::CurlAndClean does that for us. 
    conn = curl_easy_init(); 
    if( conn == NULL ) {
        fprintf( stderr, "Failed to create CURL connection\n" );
        exit( EXIT_FAILURE );
    }
  
    // Set Error Buffer Option for More Human Readable Error Handling.
    CURLcode code = curl_easy_setopt( conn, CURLOPT_ERRORBUFFER, ( *( errorStr ) ).c_str() );
    if( code != CURLE_OK ) {
        fprintf( stderr, "Failed to set error buffer [%d]\n", code );
        return( false );
    }
  
    // Set URL to Curl. 
    code = curl_easy_setopt( conn, CURLOPT_URL, ( url ).c_str() );
    if( code != CURLE_OK ) {
        fprintf( stderr, "Failed to set URL [%s]\n", ( *( errorStr ) ).c_str() );
        return( false );
    }
  
    // Set Redirecting Option. 
    code = curl_easy_setopt( conn, CURLOPT_FOLLOWLOCATION, 1L );
    if( code != CURLE_OK ) {
        fprintf( stderr, "Failed to set redirect option [%s]\n", ( *( errorStr ) ).c_str() );
        return( false );
    }
    
    // Set Write Function Using Our Defined curlcpp::libcurlwrapper::CurlWriter Function.
    code = curl_easy_setopt( conn, CURLOPT_WRITEFUNCTION, curlcpp::libcurlwrapper::CurlWriter );
    if( code != CURLE_OK ) {
        fprintf( stderr, "Failed to set CurlWriter [%s]\n", ( *( errorStr ) ).c_str() );
        return( false );
    }
    
    // Set Where to Write Data to (Store the Result).
    code = curl_easy_setopt( conn, CURLOPT_WRITEDATA, resultStoreBuffer );
    if( code != CURLE_OK ) {
        fprintf(stderr, "Failed to set write data [%s]\n", ( *( errorStr ) ).c_str() );
        return( false );
    }
  
    // Return true if Every Option Properly Set. 
    return( true );
}


// This Function Curls the URL with a Pre-Established Curl Connection, to Retrieve the Content from the URL
//  and then Cleans Up by Calling the curl_easy_cleanup. Returns true on Success and false Otherwise.
bool curlcpp::libcurlwrapper::CurlAndClean( CURL *& conn,
                                            const string & url,
                                            string * errStr ) {

    // Retrieve Content from the URL, and perform Error Checking.
    CURLcode code = curl_easy_perform( conn );
    if( code != CURLE_OK ) {
        fprintf( stderr, "Failed to get '%s' [%s]\n", ( url ).c_str(), ( *( errStr ) ).c_str() );
        return( false );
    }  

    // Clean Up - curl_easy_cleanup returns a void so can't error check here.
    curl_easy_cleanup( conn ); 
   
    return( true );
}

// =================== Namespace curlcpp Implementation  ===================

// Returns an Empty String if Failed to Curl the url or if url Has no Content to Retrieve and
//  on Success Returns a std::string with the Output After Curling the url.
string curlcpp::Curl( const string & url ) { 

    // Buffer to store the Curl Result that will be returned.
    string bufferWithCurlResult( "" );

    // Buffer to store the libcurl error strings and returned data.
    string errorStr( "" );

    // Curl Connection.
    CURL * conn = NULL;
    curl_global_init(CURL_GLOBAL_DEFAULT);
 
    // ----- (Step 1) Initiate a CURL Connection ----- 
    // Store the Result After Initiating a CURL Connection.
    bool result = curlcpp::libcurlwrapper::CurlInitialization( conn, 
                                                               url,
                                                               &( errorStr ),
                                                               &( bufferWithCurlResult )
                                                             ); 
    // Check if Initiation was Successfull or not.
    if ( result == false ) {
        fprintf( stderr, "Curl Connection Initializion Failed\n" );
        exit( EXIT_FAILURE );
    }

    // ----- (Step 2) Retrieve Curled Output and Cleanup ----- 
    // Curls to Retrieve Content from the URL and then performs Cleanup, Handle Errors.
    if ( curlcpp::libcurlwrapper::CurlAndClean( conn, url, &errorStr ) == false ) {
        fprintf( stderr, "Curling Failed\n" );
        exit( EXIT_FAILURE );
    }  
    
    // Return the String with the Output After Curling the URL.
    return( bufferWithCurlResult );
}

