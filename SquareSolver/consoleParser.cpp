#include <cstdio>
#include <cstring>

#include "menu.h"

void consoleParser(int argc, char *argv[]) {
    for (int i = 1; i < argc; i++) {
        if (!strcmp(argv[i], "--gtest")) {
            googleTestMode(argc, argv);
        }
        else if (!strcmp(argv[i], "--test")) {
            testMode();
        }
        else {
            manualMode();
        }
    }
}