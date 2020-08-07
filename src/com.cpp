#include <com.hpp>

Com::Com(std::string aStringName)
{
    /**
     * @brief       Constructor
     * 
     */
    std::cout << "Curling" << std::endl;
    progressBar(0);
    int n = aStringName.length();
    char charVersion[n + 1]; 
    strcpy(charVersion, aStringName.c_str());
    progressBar(10);

    CURLcode res;
    file.memory = (char *) malloc(1); 
    file.size = 0;
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    progressBar(20);
    if(curl) 
    {
        curl_easy_setopt(curl, CURLOPT_URL, charVersion);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        progressBar(60);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&file);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        progressBar(80);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 0L);
        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        std::cout << curl_easy_strerror(res) << std::endl;        
    }
    progressBar(100);
    std::cout << std::endl;
}

Com::~Com()
{
    /**
     * @brief       Destructor
     * 
     */
    curl_easy_cleanup(curl);
    free(file.memory);
    curl_global_cleanup();
    std::cout << "Cleaned COM" << std::endl;
}

size_t Com::WriteMemoryCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    /**
     * @brief       Save HTML file in a struct
     * 
     */
    size_t realsize = size * nmemb;
    struct MemoryStruct *mem = (struct MemoryStruct *)userp;
    progressBar(30);
    char *ptr = (char*) realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) 
    {

        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }
    progressBar(40);
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    progressBar(50);
    return realsize;
}

int Com::getSize()
{
    /**
     * @brief       Get object size
     * 
     */
    return file.size;
}

char* Com::getContent()
{
    /**
     * @brief       Get content HTML
     * 
     */
    return file.memory;
}

