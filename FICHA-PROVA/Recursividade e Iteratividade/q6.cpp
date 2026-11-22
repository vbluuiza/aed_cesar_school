#include <iostream>
#include <string>
using namespace std;

// Verificar se uma String é Palíndromo 
bool palindromo(const string& s, int ini, int fim) {
    if (ini >= fim) return true;
    if (s[ini] != s[fim]) return false;
    return palindromo(s, ini + 1, fim - 1);
}

int main() {
    string s;
    getline(cin, s);

    cout << (palindromo(s, 0, s.size() - 1) ? 1 : 0) << endl;
    return 0;
}