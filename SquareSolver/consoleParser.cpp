#include <cstdio>
#include <cstring>

#include "menu.h"
#include "consoleParser.h"

void consoleParser(int argc, char *argv[]) {
    if (argc == 1) {
        manualMode();
    }
    else {
        for (int flagNumber = 1; flagNumber < argc; flagNumber++) {

            if (!strcmp(argv[flagNumber], "--gtest")) {
                googleTestMode(argc, argv);
            }
            
            else if (!strcmp(argv[flagNumber], "--test")) {
                testMode();
            }
            else {
                printf("This Flag [%s] Doesn't Exist", argv[flagNumber]);
            }
        }
    }
}