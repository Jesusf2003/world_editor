#include "arguments.h"

#include <iostream>
#include <fstream>

void Arguments::getVersion() {
    printf("0.1");
}

void Arguments::getHelp(const char* argName) {
    printf("Usage %s [options]", argName);
}