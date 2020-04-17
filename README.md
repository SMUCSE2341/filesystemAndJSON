# Example RapidJSON and Filesystem

The program expects one command line arg: a path to a folder that contains files. 

A few things to notice:

- the `cMakeLists.txt` file includes a few new statements:
    - `file (COPY ...)` - this copies the rapidjson folder from the src directory into the build directory.
    - `include_directories(rapidjson)` - this makes the files in the rapidjson directory act like files on the system include path.  This means you can include them with `<>` and not `""`. 
    - `set (CMAKE_CXX_STANDARD_LIBRARIES -lstdc++fs)` - this tells the linker to link against the file system library. 

- The `main.cpp` includes `#include <experimental/filesystem>`.  In C++ 14, the filesystem lib is part of an experimental set of features.  It isn't taken out of experimental until C++ 17.  But the version of gcc that we are using isn't fully C++17 compliant.   
