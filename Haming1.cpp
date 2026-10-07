//vectors are powerful tool to store data of unknown size
//it is an dynamic array that can grow and shrink in size as needed
//<cmath> specially use to the pow() function 
// pow() function is used to calculate power of a number
#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using namespace std;

int main(){
    string data;
    
    cout << "== SENDER SIDE ==" << endl;
    cout << "Enter binary data to transmit (e.g., 1011): ";
    cin >> data;

    int m = data.length();
    int r = 0;
    // 1. Calculate the number of redundant bits (r)
    // Formula: 2^r >= m + r + 1
    while (pow(2, r) < m + r + 1){
        r++;
    }
    int n = m + r;
    vector<int> hamming(n + 1, 0); // 1-based indexing

    // 2. Place data bits in non-power-of-2 positions
    int j = 0;
    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) != 0) {
            hamming[i] = data[j] - '0';
            j++;
        }
    }

    // 3. Calculate parity bits (Even Parity)
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;
        
        for (int k = 1; k <= n; k++) {
            if (((k >> i) & 1) == 1) {
                parity ^= hamming[k];
            }
        }
        hamming[pos] = parity;
    }

    // 4. Output the generated Hamming Code
    cout << "Generated Hamming Code: ";
    for (int i = 1; i <= n; i++) {
        cout << hamming[i];
    }
    cout << endl;
    return 0;
}