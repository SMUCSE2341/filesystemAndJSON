#include <iostream>
#include <document.h>
#include <writer.h>
#include <stringbuffer.h>

#include <experimental/filesystem>

void testRapidJson(const char *json);

using namespace rapidjson;
using namespace std;
using namespace std::experimental::filesystem;

int main(int argc, char** argv) {
    // 1. Parse a JSON string into DOM.
    const char* json = "{\"project\":\"rapidjson\",\"stars\":10}";
    testRapidJson(json);

    //testing the Filesystem library
    cout << "Attempting to open " << argv[1] << endl;
    path p(argv[1]);

    directory_iterator begin = directory_iterator(p);
    directory_iterator end = directory_iterator();

    for(auto iter = begin; iter != end; ++iter) {
        directory_entry entry = *iter;
        if(is_regular_file(entry))
            cout << "File: " << entry << endl;
    }

    return 0;
}

void testRapidJson(const char *json) {
    Document d;
    d.Parse(json);

    // 2. Modify it by DOM.
    Value& s = d["stars"];
    s.SetInt(s.GetInt() + 1);

    // 3. Stringify the DOM
    StringBuffer buffer;
    Writer<StringBuffer> writer(buffer);
    d.Accept(writer);

    // Output {"project":"rapidjson","stars":11}
    std::cout << buffer.GetString() << std::endl;
}
