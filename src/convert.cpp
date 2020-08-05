#include <convert.hpp>

Conv::Conv(const char *someHTMLString)
{
    /**
     * @brief       Create an XML object 
     * 
     */
    std::cout << "Tidying";
    output = {0};
    errbuf = {0};
    rc = -1;
    Bool ok;

    tdoc = tidyCreate();                     // Initialize "document"

    ok = tidyOptSetBool( tdoc, TidyXmlOut, yes );std::cout << " .";  // Convert to XML
    if ( ok )
        rc = tidySetErrorBuffer( tdoc, &errbuf );std::cout << " .";      // Capture diagnostics
    if ( rc >= 0 )
        rc = tidyParseString( tdoc, someHTMLString );std::cout << " .";           // Parse the input
    if ( rc >= 0 )
        rc = tidyCleanAndRepair( tdoc );std::cout << " .";               // Tidy it up!
    if ( rc >= 0 )
        rc = tidyRunDiagnostics( tdoc );std::cout << " .";               // Kvetch
    if ( rc > 1 )                                    // If error, force output.
        rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );std::cout << " .";
    if ( rc >= 0 )
        rc = tidySaveBuffer( tdoc, &output );std::cout << " .";// Pretty Print  
    std::cout << std::endl;    
}

Conv::~Conv()
{
    /**
     * @brief       Construct a new tidy Buf Free object
     * 
     */
    tidyBufFree( &output );
    tidyBufFree( &errbuf );
    tidyRelease( tdoc );
    std::cout << "Cleaned CONV" << std::endl;
}

char* Conv::getContent()
{
    /**
     * @brief       Get the XML content
     * 
     */
    if ( rc >= 0 )
        {
            return reinterpret_cast<char *>(output.bp);
        }
        else
            printf( "A severe error (%d) occurred.\n", rc );
            return 0;
}

void Conv::getDiagnostic()
{
    /**
     * @brief       Get diagnoses regarding the HTML file build
     * 
     */
    if ( rc >= 0 )
        {
            if ( rc > 0 )
            std::cout << "Diagnostics:\n\n" << errbuf.bp << std::endl;
        }
        else
            std::cout << "A severe error (%d) occurred.\n" << rc << std::endl;
}