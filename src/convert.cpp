#include <convert.hpp>

Conv::Conv(const char *someHTMLString)
{
    output = {0};
    errbuf = {0};
    rc = -1;
    Bool ok;

    tdoc = tidyCreate();                     // Initialize "document"
    printf("Tidying . . .\n");

    ok = tidyOptSetBool( tdoc, TidyXhtmlOut, yes );  // Convert to XML
    if ( ok )
        rc = tidySetErrorBuffer( tdoc, &errbuf );      // Capture diagnostics
    if ( rc >= 0 )
        rc = tidyParseString( tdoc, someHTMLString );           // Parse the input
    if ( rc >= 0 )
        rc = tidyCleanAndRepair( tdoc );               // Tidy it up!
    if ( rc >= 0 )
        rc = tidyRunDiagnostics( tdoc );               // Kvetch
    if ( rc > 1 )                                    // If error, force output.
        rc = ( tidyOptSetBool(tdoc, TidyForceOutput, yes) ? rc : -1 );
    if ( rc >= 0 )
        rc = tidySaveBuffer( tdoc, &output );          // Pretty Print    
}

Conv::~Conv()
{
    tidyBufFree( &output );
    tidyBufFree( &errbuf );
    tidyRelease( tdoc );
    std::cout << "Cleaned CONV" << std::endl;
}

char* Conv::getContent()
{
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
    if ( rc >= 0 )
        {
            if ( rc > 0 )
            std::cout << "Diagnostics:\n\n" << errbuf.bp << std::endl;
        }
        else
            std::cout << "A severe error (%d) occurred.\n" << rc << std::endl;
}