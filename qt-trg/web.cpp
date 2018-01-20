#include "web.h"
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>


Web::Web()
{

}

size_t Web::write_to_string(void* ptr, size_t size, size_t count, void* stream) {
  ((std::string*)stream)->append((char*)ptr, 0, size*count);
  return size*count;
}

Json::Value Web::getJsonFromAPI(const char* url)
{
    CURL* curl;
    CURLcode res;
    curl = curl_easy_init();
    if(curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, url);
        std::string response;
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, Web::write_to_string);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        res = curl_easy_perform(curl);
        if(res != CURLE_OK)
        {
            fprintf(stderr, "curl failed %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);

        Json::Value root;
        Json::Reader reader;

        bool parsingSuccessful = reader.parse(response.c_str(), root);
        if ( !parsingSuccessful )
        {
            std::cout  << "Failed to parse"
                   << reader.getFormattedErrorMessages();
            throw std::exception();
        }else
        {
            return root;
        }
    }else throw std::exception();
}
