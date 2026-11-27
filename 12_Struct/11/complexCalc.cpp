#include <iostream>
#include <cmath>
using namespace std;

struct Complex {
    double re;
    double im;
    double mod;
    double phase;
};

// costruisce un complesso dalla forma cartesiana, aggiornando anche quella esponenziale
Complex fromCartesian(double re, double im) {
    Complex c;
    c.re = re;
    c.im = im;
    c.mod = sqrt(re * re + im * im);
    c.phase = atan2(im, re);
    return c;
}

// costruisce un complesso dalla forma esponenziale, aggiornando anche quella cartesiana
Complex fromPolar(double mod, double phase) {
    Complex c;
    c.mod = mod;
    c.phase = phase;
    c.re = mod * cos(phase);
    c.im = mod * sin(phase);
    return c;
}

Complex sum(const Complex &a, const Complex &b) {
    return fromCartesian(a.re + b.re, a.im + b.im);
}

Complex difference(const Complex &a, const Complex &b) {
    return fromCartesian(a.re - b.re, a.im - b.im);
}

Complex product(const Complex &a, const Complex &b) {
    return fromPolar(a.mod * b.mod, a.phase + b.phase);
}

Complex ratio(const Complex &a, const Complex &b) {
    return fromPolar(a.mod / b.mod, a.phase - b.phase);
}

void print(const string &label, const Complex &c) {
    cout << label << ": " << c.re << (c.im < 0 ? " - " : " + ") << fabs(c.im) << "i"
         << "   |   " << c.mod << " * e^(i*" << c.phase << ")" << endl;
}

int main() {
    double re, im;
    cout << "Inserire parte reale e immaginaria del primo numero: ";
    cin >> re >> im;
    Complex z1 = fromCartesian(re, im);
    cout << "Inserire parte reale e immaginaria del secondo numero: ";
    cin >> re >> im;
    Complex z2 = fromCartesian(re, im);

    print("z1", z1);
    print("z2", z2);
    print("Somma", sum(z1, z2));
    print("Differenza", difference(z1, z2));
    print("Prodotto", product(z1, z2));
    if (z2.mod < 1e-12)
        cout << "Rapporto: impossibile (divisione per zero)" << endl;
    else
        print("Rapporto", ratio(z1, z2));
    return 0;
}
