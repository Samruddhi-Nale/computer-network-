#include<iostream>
#include<vector>
#include<cmath>
#include<string>

using namespace std;

int main() {
    string input;
    
    cout << "== RECEIVER SIDE =="<< endl;
    cout << "Enter the received Hamming Code: ";
    cin >> input;

    int n = input.length();
    vector<int> received(n + 1, 0); // 1-based indexing
    
    // Convert string input to vector
    for(int i = 0; i < n; i++) {
        received[i+1] = input[i] - '0';
    }

    int r = 0;
    // Find number of redundant bits based on total length
    while (pow(2, r) <= n) {
        r++;
    }

    int errorPos = 0;

    // 1. Calculate parity checks (Syndrome calculation)
    for (int i = 0; i < r; i++) {
        int pos = pow(2, i);
        int parity = 0;
        
        for (int k = 1; k <= n; k++) {
            if (((k >> i) & 1) == 1) {
                parity ^= received[k];
            }
        }
        errorPos += parity * pos;
    }

    // 2. Report and correct error
    if (errorPos == 0) {
        cout << "Status: No error detected in transmission." << endl;
    } else {
        cout << "Status: Error detected at bit position: " << errorPos << endl;
        
        // Correct the flipped bit
        received[errorPos] ^= 1; 
        
        cout << "Corrected Hamming Code: ";
        for (int i = 1; i <= n; i++) {
            cout << received[i];
        }
        cout << endl;
    }

    // 3. Extract the original data payload
    cout << "Extracted Original Data: ";
    for (int i = 1; i <= n; i++) {
        // Ignore power-of-2 positions (they are parity bits)
        if ((i & (i - 1)) != 0) {
            cout << received[i];
        }
    }
    cout << endl;

    return 0;
}