#include <iostream>
#include <fstream>
using namespace std;

const int SIZE = 1000;
string tab[SIZE];

int binToDec(string bin) 
{
    int n = 0;
    int base = 1;
    for (int i = bin.length() - 1; i >= 0; i--) 
    {
        n += (bin[i] - '0') * base;
        base *= 2;
    }
    return n;
}



bool isPrime(int x) 
{
    if (x <= 1) return false;
    if (x % 2 == 0 && x != 2) return false;
    for (int i = 3; i * i <= x; i += 2) 
    {
        if (x % i == 0) return false;
    }
    return true;
}

bool isHalfPrime(int x)
{
    if (isPrime(x)) return false;
    if (x % 2 == 0) return isPrime(x / 2);
    for (int i = 3; i * i <= x; i++)
    {
        if (x % i == 0) return isPrime(x / i);
    }
}


void zadanie() {
    int ctn = 0, max = 0, min = 999999999;
    int number;
    for (int i = 0; i < SIZE; i++) 
    {
        number = binToDec(tab[i]);

        if (isHalfPrime(number)) 
        {
            ctn++;
            if (number > max) max = number;
            if (number < min) min = number;
        }
    }
    cout << ctn << " ciagow" << endl;
    cout << "Max: " << max << " Min: " << min << endl;
}

int main() {
    ifstream in("ciagi.txt");
    for (int i = 0; i < SIZE; i++) in >> tab[i];
    in.close();
    zadanie();
}
