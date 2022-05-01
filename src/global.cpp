#include "global.h"


std::map<std::string, int> opcode_map = {
    {"add", 3},
    {"addi", 3},
    {"sub", 3},
    {"subi", 3},
    {"la", 2},
    {"li", 2},
    {"sub", 2},
    {"subi", 2},
    {"ecall", 0}
};
