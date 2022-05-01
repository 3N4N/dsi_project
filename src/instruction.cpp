#include "instruction.h"
#include "global.h"
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

bool Instruction::verify()
{
    map<string, int>::iterator p;
    p = opcode_map.find(opcode);

    if (p == opcode_map.end()) return false;
    if (operands.size() != p->second) return false;

    return true;
}
