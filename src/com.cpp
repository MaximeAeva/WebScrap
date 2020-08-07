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
        std::string useragent= "curl/7.39.0";
        curl_easy_setopt(curl,CURLOPT_USERAGENT, useragent);
        curl_easy_setopt(curl, CURLOPT_DEBUGFUNCTION, trace);
        curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_URL, charVersion);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteMemoryCallback);
        progressBar(60);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, (void *)&file);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 1L);
        progressBar(80);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYHOST, 1L);
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
    progressBar(30, 0);
    char *ptr = (char*) realloc(mem->memory, mem->size + realsize + 1);
    if(ptr == NULL) 
    {

        printf("not enough memory (realloc returned NULL)\n");
        return 0;
    }
    progressBar(40, 0);
    mem->memory = ptr;
    memcpy(&(mem->memory[mem->size]), contents, realsize);
    mem->size += realsize;
    mem->memory[mem->size] = 0;
    progressBar(50, 0);
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


int Com::trace(CURL *handle, curl_infotype type,
             char *data, size_t size,
             void *userp)
{
    const char *text;
    (void)handle; /* prevent compiler warning */
    (void)userp;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    bool bdt = false;
    switch (type) {
    case CURLINFO_TEXT:
        std::cout << "== Info: " << data;
        SetConsoleTextAttribute(hConsole, 9);
        
    default: /* in case a new one is introduced to shock us */
        return 0;
     
    case CURLINFO_HEADER_OUT:
        text = "=> Send header";
        SetConsoleTextAttribute(hConsole, 12);
        break;
    case CURLINFO_DATA_OUT:
        text = "=> Send data";
        SetConsoleTextAttribute(hConsole, 12);
        break;
    case CURLINFO_SSL_DATA_OUT:
        text = "=> Send SSL data";
        SetConsoleTextAttribute(hConsole, 12);
        break;
    case CURLINFO_HEADER_IN:
        text = "<= Recv header";
        SetConsoleTextAttribute(hConsole, 10);
        break;
    case CURLINFO_DATA_IN:
        text = "<= Recv data";
        SetConsoleTextAttribute(hConsole, 10);
        bdt = true;
        break;
    case CURLINFO_SSL_DATA_IN:
        text = "<= Recv SSL data";
        SetConsoleTextAttribute(hConsole, 10);
        break;
    }
 
    dump(text, stderr, (unsigned char *)data, size, bdt);
    SetConsoleTextAttribute(hConsole, 15);
    return 0;
}

void Com::dump(const char *text,
          FILE *stream, unsigned char *ptr, size_t size, bool data)
{
    size_t i;
    size_t c;
    unsigned int width=0x10;
       
    std::cout << text << "," << (long)size << "bytes (0x" << (long)size << ")" << std::endl;
    if(!data)
    {
        for(i=0; i<size; i+= width) {
            std::cout << (long)i;
        
            /* show hex to the left */
            for(c = 0; c < width; c++) {
            if(i+c < size)
                std::cout << ptr[i+c];
            else
                std::cout << "   ";
            }
        
            /* show data on the right */
            for(c = 0; (c < width) && (i+c < size); c++) {
            char x = (ptr[i+c] >= 0x20 && ptr[i+c] < 0x80) ? ptr[i+c] : '.';
            std::cout << x;
            }
        
            std::cout << std::endl; /* newline */
        }
    }
    else std::cout << "datas ..." << std::endl;
}