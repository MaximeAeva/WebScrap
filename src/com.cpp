#include <com.hpp>

Com::Com(std::string aStringName)
{
    /**
     * @brief       Constructor
     * 
     */

    int n = aStringName.length();
    char charVersion[n + 1]; 
    strcpy(charVersion, aStringName.c_str());

    CURL *curl;
    CURLcode res;
 
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, charVersion);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        /* Perform the request, res will get the return code */ 
        res = curl_easy_perform(curl);
        /* Check for errors */ 
        if(res != CURLE_OK)
        std::cout << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;        
    }
 
    

    std::cout << "Created" << std::endl;
}

Com::~Com()
{
    /**
     * @brief       Deleter
     * 
     */
    curl_easy_cleanup(curl);
    curl_global_cleanup();
    std::cout << "Cleaned" << std::endl;
}

