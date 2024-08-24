#include <cstdio>
#include <cstring>

#include "menu.h"

void consoleParser(int argc, char *argv[]) {
    if (argc == 1) {
        manualMode();
    }
    else {
        for (int i = 1; i < argc; i++) {
            if (!strcmp(argv[i], "--gtest")) {
                googleTestMode(argc, argv);
            }
            else if (!strcmp(argv[i], "--test")) {
                testMode();
            }
        }
    }
}