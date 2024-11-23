#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

int main() {
    void *handle;
    void (*double_to_ieee754)(double, char *);
    char *error;

    handle = dlopen("./libdouble_to_ieee754.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }

    double_to_ieee754 = dlsym(handle, "double_to_ieee754");
    if ((error = dlerror()) != NULL) {
        fprintf(stderr, "%s\n", error);
        exit(1);
    }

    char binary[65];
    double num = 3.14;
    double_to_ieee754(num, binary);
    printf("IEEE 754 Representation: %s\n", binary);

    if (dlclose(handle) < 0) {
        fprintf(stderr, "%s\n", dlerror());
        exit(1);
    }
    return 0;
}
