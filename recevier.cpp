#include <iostream>
#include <string>
using namespace std;
int main(){
    int x;
    cout<<"Enter bits of the frame:";
    cin>>x;
    // Step 1: Read the stuffed frame length n (implicitly handled by string)[span_16](start_span)[span_16](end_span).
    // Step 2: Read the stuffed frame into array a[][span_17](start_span)[span_17](end_span).
    string a;
    cout << "Enter the stuffed frame: ";
    cin >> a;
    int n = a.length();
    string b = ""; 
    
    // Step 3: Initialize i = 0, j = 0, and count = 0[span_19](start_span)[span_19](end_span).
    int i = 0, j = 0, count = 0;
    
    cout << "--- Receiver Side: Bit De-stuffing ---" << endl;
    cout << "Stuffed Frame : " << a << endl;
    
    // Step 4: Repeat Steps 5–11 (adjusted for loop) until i < n[span_20](start_span)[span_20](end_span).
    while (i < n){
        // Step 5: Copy a[i] to b[j][span_21](start_span)[span_21](end_span).
        b += a[i]; 
        
        // Step 6: If a[i] = 1, increment count; otherwise, set count = 0[span_22](start_span)[span_22](end_span).
        if (a[i] == '1'){
            count++;
        } else{
            count = 0;
        }
        
        // Step 7: If count = 5[span_23](start_span)[span_23](end_span).
        if (count == 5) {
            i++;       // Increment i to skip the stuffed 0[span_24](start_span)[span_24](end_span).
            count = 0; // Reset count = 0[span_25](start_span)[span_25](end_span).
        }
        
        // Step 8: Increment i and j[span_26](start_span)[span_26](end_span).
        i++;
        j++;
    }
    
    // Step 10: Display the original frame after bit de-stuffing by printing all elements of array b[][span_27](start_span)[span_27](end_span).
    cout << "Original Frame: " << b << endl;
    return 0;
}