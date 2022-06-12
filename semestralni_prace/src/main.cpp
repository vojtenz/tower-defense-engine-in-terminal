#include "CGame.h"

int main() {
    CGame h(110000,300);
    if(!h.init()) {
        return EXIT_FAILURE;
    }
    h.start();
    return EXIT_SUCCESS;
}
