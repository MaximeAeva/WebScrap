#include <com.h>

Com::Com()
{
    /**
     * @brief       Constructor
     * 
     */

    CURL *curl;
    CURLcode res;
    std::string readBuffer;

    curl = curl_easy_init();
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.com");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);

        std::cout << readBuffer << std::endl;
    }
}

Com::~Com()
{
    /**
     * @brief       Deleter
     * 
     */

    std::cout << "bye" << std::endl;
}

