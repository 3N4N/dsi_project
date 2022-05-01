#include <iostream>
#include <vector>
#include <algorithm>

#include "instruction.h"
#include "global.h"

using namespace std;

vector<string> read_input(const char* inputfile)
{
    freopen(inputfile, "r", stdin);
    string buffer;
    vector<string> instructions = {};
    while (getline(cin, buffer)) {
        instructions.push_back(buffer);
    }

    return instructions;
}

void printseparator()
{
    cout << "---------------\n";
}

std::string trim(const string& str, const string& whitespace = " \t")
{
    const auto strBegin = str.find_first_not_of(whitespace);
    if (strBegin == std::string::npos)
        return "";

    const auto strEnd = str.find_last_not_of(whitespace);
    const auto strRange = strEnd - strBegin + 1;

    return str.substr(strBegin, strRange);
}


vector<string> parse_comments(vector<string> instructions)
{
    vector<string> retvec = {};
    for (auto const& instruction : instructions) {
        if (instruction[0] == '#') continue;
        string s = trim(instruction.substr(0, instruction.find("#", 0)));
        retvec.push_back(s);
    }

    return retvec;
}


void print_instructions(vector<string>& instructions)
{
    printseparator();
    for (auto const& instruction : instructions) {
        std::cout << instruction <<  " - " << instruction.size() << '\n';
    }
    printseparator();
}

void print_vector(vector<string>& vec)
{
    for (auto const& s : vec) {
        std::cout << s << ",";
    }
}


Instruction parse_instruction(string instruction)
{
    string opcode;
    vector<string> operands = {};

    string ops;
    string delimiter = ",";

    const auto opcode_end = instruction.find_first_of(" ");
    opcode = instruction.substr(0, opcode_end);

    if (opcode_end != string::npos) {
        ops = instruction.substr(opcode_end, instruction.length());
        ops.erase(remove(ops.begin(), ops.end(), ' '), ops.end());

        size_t pos = 0;
        while ((pos = ops.find(delimiter)) != string::npos) {
            operands.push_back(ops.substr(0, pos));
            ops.erase(0, pos + delimiter.length());
        }
        operands.push_back(ops);
    }

    // cout << opcode << " " ;
    // print_vector(operands);
    // cout << endl;

    Instruction inst(opcode, operands);

    return inst;
}


int main()
{
    vector<string> s_instrs = read_input("input.txt");
    print_instructions(s_instrs);

    s_instrs = parse_comments(s_instrs);
    print_instructions(s_instrs);

    vector<Instruction> instructions;

    for (auto const& instrc : s_instrs) {
        Instruction instruction = parse_instruction(instrc);
        if (instruction.verify()) {
            instructions.push_back(instruction);
            cout << instruction;
        }

    }


    return 0;
}
