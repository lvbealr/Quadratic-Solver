#include <cstdio>
#include <cstring>

#include "menu.h"

int consoleParser(int argc, char *argv[]) {
    bool wrongFlags = false;
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--test")) {
            testMode();
        }
        else if (!strcmp(argv[i],  "--manual")) {
            manualMode();
        }  
        else {
            printf("Wrong flag: %s\n", argv[i]);
            wrongFlags = true; 
        }
    }
    return wrongFlags;
}