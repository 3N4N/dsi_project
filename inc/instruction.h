#ifndef _INSTRUCTION_H_
#define _INSTRUCTION_H_

#include <iostream>
#include <vector>

class Instruction {
public:
    std::string opcode;
    std::vector<std::string> operands;

public:
    Instruction() {}
    Instruction(std::string opcode, std::vector<std::string> operands);
    friend std::ostream& operator<<(std::ostream&, const Instruction&);

    bool verify();
};


#endif // _INSTRUCTION_H_
