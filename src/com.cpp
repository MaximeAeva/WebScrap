#include <com.hpp>

Com::Com(std::string aStringName)
{
    /**
     * @brief       Constructor
     * 
     */
    CURL *curl;
    CURLcode res;

    std::cout << "On dirait que jusque là ça va !" << std::endl;
 
    curl_global_init(CURL_GLOBAL_DEFAULT);
    
    curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, aStringName);
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

