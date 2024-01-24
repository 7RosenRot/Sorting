#include "sort.h"
#define lenght 20

int main() {
    int i, main_array[lenght];

    srand(time(NULL));
    for (i = 0; i != lenght; i++) {
        main_array[i] = rand() % 100;
    }

    HUD(main_array, lenght);

    return 0;
}