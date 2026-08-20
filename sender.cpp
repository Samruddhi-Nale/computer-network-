#include <iostream>
#include <string>

using namespace std;

int main() {
    // Step 1: Read the frame length n (implicitly handled by string)[span_2](start_span)[span_2](end_span).
    // Step 2: Read the input frame into array a[][span_3](start_span)[span_3](end_span).
    string a;
    cout << "Enter the original frame: ";
    cin >> a;
    int n = a.length();
    string b = ""; 
    
    // Step 3: Initialize i = 0, j = 0, and count = 0[span_5](start_span)[span_5](end_span).
    int i = 0, j = 0, count = 0; 
    
    cout << "--- Sender Side: Bit Stuffing ---" << endl;
    cout << "Original Frame: " << a << endl;
    
    // Step 4: Repeat Steps 5–14 (adjusted for loop) until i < n[span_6](start_span)[span_6](end_span).
    while (i < n) {
        // Step 5: Copy a[i] to b[j][span_7](start_span)[span_7](end_span).
        b += a[i]; 
        
        // Step 6: If a[i] = 1, then increment count; otherwise, set count = 0[span_8](start_span)[span_8](end_span).
        if (a[i] == '1') {
            count++;
        } else {
            count = 0;
        }
        
        // Step 7: If count = 5[span_9](start_span)[span_9](end_span).
        if (count == 5) {
            b += '0';  // Insert 0 into b[j + 1][span_10](start_span)[span_10](end_span).
            j++;       // Increment j[span_11](start_span)[span_11](end_span).
            count = 0; // Reset count = 0[span_12](start_span)[span_12](end_span).
        }
        
        // Step 8: Increment both i and j[span_13](start_span)[span_13](end_span).
        i++;
        j++;
    }
    
    // Step 10: Display the frame after bit stuffing by printing all elements of array b[][span_14](start_span)[span_14](end_span).
    cout << "Stuffed Frame : " << b << endl;
    
    return 0;
}