#include <iostream>
using namespace std;

int main() {

    string s = "programming";


    // 1️⃣ Basic substring
    string sub1 = s.substr(0,5);
    cout << "Substring (0,5): " << sub1 << endl;


    // 2️⃣ Substring from middle
    string sub2 = s.substr(3,4);
    cout << "Substring (3,4): " << sub2 << endl;


    // 3️⃣ Substring till end
    string sub3 = s.substr(3);
    cout << "Substring from index 3: " << sub3 << endl;

    // 4️⃣ Substring with length exceeding string size
    string sub4 = s.substr(10,5);
    cout << "Substring (10,5): " << sub4 << endl;

    
    // 4️⃣ Print all substrings
    cout << "\nAll substrings:\n";
    for(int i = 0; i < s.size(); i++){
        for(int len = 1; len <= s.size() - i; len++){
            cout << s.substr(i,len) << endl;
        }
    }

    return 0;
}