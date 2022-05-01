#include <iostream>
#include <vector>

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


vector<string> parse_comments(vector<string> instructions)
{
    vector<string> retvec = {};
    for (auto const& instruction : instructions) {
        if (instruction[0] == '#') continue;
        string s = instruction.substr(0, instruction.find("#", 0));
        retvec.push_back(s);
    }

    return retvec;
}


void print_instructions(vector<string>& instructions)
{
    printseparator();
    for (auto const& instruction : instructions) {
        std::cout << instruction << '\n';
    }
    printseparator();
}


int main()
{
    vector<string> instructions = read_input("input.txt");

    print_instructions(instructions);

    instructions = parse_comments(instructions);

    print_instructions(instructions);


    return 0;
}
