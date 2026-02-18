#include <iostream>
#include <algorithm>
using namespace std;

int main() {

    string s = "Hello";

    // length / size
    cout << "Length: " << s.length() << endl;
    cout << "Size: " << s.size() << endl;

    // push_back
    s.push_back('!');
    cout << "After push_back: " << s << endl;

    // pop_back
    s.pop_back();
    cout << "After pop_back: " << s << endl;

    // insert
    s.insert(5, " World");
    cout << "After insert: " << s << endl;

    // erase
    s.erase(5, 6);   // remove " World"
    cout << "After erase: " << s << endl;

    // substr
    string sub = s.substr(1, 3);
    cout << "Substring (1,3): " << sub << endl;

    // find
    cout << "Find 'lo': " << s.find("lo") << endl;

    // replace
    s.replace(0, 5, "Hi");
    cout << "After replace: " << s << endl;

    // reverse
    reverse(s.begin(), s.end());
    cout << "After reverse: " << s << endl;

    // compare
    string a = "Apple";
    string b = "Banana";
    if(a.compare(b) < 0)
        cout << "Apple comes before Banana" << endl;

    return 0;
}
