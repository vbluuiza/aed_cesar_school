#include <iostream>
using namespace std;

struct Retangulo {
    float base;
    float altura;
};

float area(const Retangulo& r) {
    return r.base * r.altura;
}

float perimetro(const Retangulo& r) {
    return 2 * (r.base + r.altura);
}

int main() {
    Retangulo r;

    cout << "Base: ";
    cin >> r.base;

    cout << "Altura: ";
    cin >> r.altura;

    cout << "Area: " << area(r) << endl;
    cout << "Perimetro: " << perimetro(r) << endl;

    return 0;
}