#include "loot/api.h"
#include <stdio.h>

using namespace loot;

int main(int argc, char const *argv[]) {
    try {
        CreateGameHandle(GameType::tes4, "dummy");
    }
    catch (...) {
        printf("some error");
        //SetLoggingCallback([](LogLevel, const char *) {});
    }

    printf("success");
    return 0;
}
