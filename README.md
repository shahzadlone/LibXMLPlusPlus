# LibXMLPlusPlus
Using libxml++ to Easily Build and Compile with CurlPlusPlus Repo

------------------------
Build:
------------------------
```sh
g++ -std=c++11 -Wall -Ithird_party -Ithird_party/glib-2.0 -Ithird_party/glibmm-2.4 Curl.cpp CatchConvertError.cpp main.cpp -o XML++ -Llibs/curl -lcurl -Llibs/libxml -lxml2 -Llibs/libxml++ -lxml++-3.0 -Llibs/glibmm -lglibmm-2.4 -Llibs/glib -lglib-2.0 -Wl,-rpath=libs/curl -Wl,-rpath=libs/libxml -Wl,-rpath=libs/libxml++ -Wl,-rpath=libs/glibmm -Wl,-rpath=libs/glib -Wl,-rpath=libs/other && echo $?
```

------------------------
Command Line Usage:
------------------------
```sh
Takes one argument: [URL-Containing-XML-To-Parse]
```
    WHERE:
          [URL-Containing-XML-To-Parse] : is a URL you wish to curl and the parse using the libxml++ wrapper.
