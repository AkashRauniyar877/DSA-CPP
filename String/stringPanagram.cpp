#include <iostream>
#include <vector>
using namespace std;

bool checkIfPangram(string sentence) {
    vector<bool> seen(26, false);

    for(char c : sentence){
        seen[c - 'a'] = true;
    }

    for(bool x : seen){
        if(x == false) return false;
    }

    return true;
}

int main() {
    string s = "thequickbrownfoxjumpsoverthelazydog";

    if(checkIfPangram(s))
        cout << "Pangram";
    else
        cout << "Not Pangram";

    return 0;
}