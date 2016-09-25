#include <stdio.h>
#include "include/controllercommand.h"

int main() {
    printf("%x %x %x\n", command.a[0], command.a[1], command.a[2]);
    printf("%x %x %x\n", command.b[0], command.b[1], command.b[2]);
    printf("%s\n", command.a);
    printf("%s\n", command.b);
}
