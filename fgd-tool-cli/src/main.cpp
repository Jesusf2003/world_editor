#include <cstdlib>
#include <cstring>

#include "cmds/arguments.h"

/*
    TODO: How to use
    AppName.exe
        -inputfile [path/.ent, path/.def, path/.fgd] (optional)
        -outputfile [path/.ent, path/.def, path/.fgd] (optional) to convert format
        -format [jack, vhe-gs, tbroom, nradiant, gtkradiant]
*/

int main(int argc, char* argv[])
{
    const char* appName = argv[0];
    for (int i=1; i<argc; ++i) {
        const char* arg = argv[i];
        if (strcmp(arg, "-h") == 0 || strcmp(arg, "--help") == 0) {
            // Comando --help, -h
            Arguments::getHelp(appName);
            return EXIT_SUCCESS;
        } else if (strcmp(arg, "-v") == 0 || strcmp(arg, "--version") == 0) {
            // Command --version, -v
            Arguments::getVersion();
            return EXIT_SUCCESS;
        } else if (strcmp(arg, "-init") == 0) {
            printf("Initializing");
        }
    }
    return EXIT_SUCCESS;
}