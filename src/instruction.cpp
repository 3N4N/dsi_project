#include "instruction.h"
#include <iostream>

using namespace std;


Instruction::Instruction(string opcode, vector<string> operands)
{
    this->opcode = opcode;
    this->operands = operands;
}


ostream& operator<<(ostream& output, const Instruction& instruction)
{
    cout << instruction.opcode << " ";
    for (auto const& s : instruction.operands) {
        std::cout << s << ",";
    }
    cout << endl;
    return output;
}
