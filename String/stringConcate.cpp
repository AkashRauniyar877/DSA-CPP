#include<iostream>
using namespace std;
int main() {
    string s1 = "Hello";
    string s2 = " World";

    // Concatenation using + operator
    string s3 = s1 + s2;
    cout << "Concatenated String: " << s3 << endl;

    // Concatenation using append() method
    s1.append(s2);
    cout << "Concatenated String using append(): " << s1 << endl;

    return 0;
}