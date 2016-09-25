#ifndef CONTROLLER_COMMAND_H
#define CONTROLLER_COMMAND_H

#include <stdint.h>

const uint8_t _command_A[] = { 0x3A, 0x00, 0x3A };
const uint8_t _command_B[] = { 0x3B, 0x00, 0x3B };

typedef struct {
    const uint8_t *a;
    const uint8_t *b;
} _command_struct;

_command_struct command = { .a = _command_A, .b = _command_B };

#endif
