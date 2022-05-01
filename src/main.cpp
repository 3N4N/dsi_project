#include <iostream>
#include <vector>

using namespace std;

vector<string> read_input(const char* inputfile) {
    freopen(inputfile, "r", stdin);
    string buffer;
    vector<string> instructions = {};
    while (getline(cin, buffer)) {
        instructions.push_back(buffer);
    }

    return instructions;
}

int main()
{
    cout << "---------------\n";

    vector<string> instructions = read_input("input.txt");

    // vector::iterator it;
    for (auto const& e : instructions) {
        std::cout << e << '\n';
    }

    cout << "---------------\n";
    return 0;
}
