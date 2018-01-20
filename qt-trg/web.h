#ifndef WEB_H
#define WEB_H
#include <curl/curl.h>
#include <string>
#include <iostream>
#include <jsoncpp/json/json.h>
#include <jsoncpp/json/reader.h>
#include <jsoncpp/json/writer.h>
#include <jsoncpp/json/value.h>

class Web
{
public:
    Web();
    size_t static write_to_string(void* ptr, size_t size, size_t count, void* stream);
    Json::Value static getJsonFromAPI(const char* url);

};

#endif // WEB_H
