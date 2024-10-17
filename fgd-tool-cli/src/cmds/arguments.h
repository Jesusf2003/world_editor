#ifndef ARGUMENTS_H
#define ARGUMENTS_H

#include <string>
#include <fstream>

class Arguments {
    public:
        static void getVersion();
        static void getHelp(const char* argName);
    private:
        const char* format = "";
        const char* inputFilename = 0;
        const char* outputFilename = 0;
};

#endif