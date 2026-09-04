//#include<vector> is used for dynamic arrays.
/*#include<sstream> is used for working with strings as streams.
It is especially useful for converting data and breaking a string into separate values.*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to validate the IP address and extract its 4 octets
bool validateAndExtractIP(const string& ip, vector<int>& octets) {
    octets.clear();
    int dotCount = 0;
    
    // Check for invalid characters and count dots
    for (char c : ip) {
        if (c == '.') {
            dotCount++;
        } else if (!isdigit(c)) {
            return false; // Invalid character found
        }
    }
    
    // A valid IPv4 must have exactly 3 dots
    if (dotCount != 3) return false;

    stringstream ss(ip);
    string token;
    
    while (getline(ss, token, '.')) {
        // Check for empty tokens (e.g., "192..1.1") or overly long tokens
        if (token.empty() || token.length() > 3) return false;
        
        // Prevent leading zeros unless the number is exactly "0"
        if (token.length() > 1 && token[0] == '0') return false;
        
        int num = stoi(token);
        
        // Octet must be between 0 and 255
        if (num < 0 || num > 255) return false;
        
        octets.push_back(num);
    }
    
    return octets.size() == 4;
}

int main() {
    string ip;
    vector<int> octets;

    // Loop until a valid IP is entered
    while (true) {
        cout << "Enter an IPv4 address in dotted decimal format: ";
        cin >> ip;

        if (validateAndExtractIP(ip, octets)) {
            cout << "\nValid IPv4 Address entered.\n\n";
            break;
        } else {
            cout << "Invalid IPv4 Address. Please try again.\n\n";
        }
    }

    int firstOctet = octets[0];
    char ipClass;
    string mask, netId, hostId;

    if (firstOctet >= 0 && firstOctet <= 127) {
        ipClass = 'A';
        mask = "255.0.0.0";
        netId = to_string(octets[0]);
        hostId = to_string(octets[1]) + "." + to_string(octets[2]) + "." + to_string(octets[3]);
        
    } else if (firstOctet >= 128 && firstOctet <= 191) {
        ipClass = 'B';
        mask = "255.255.0.0";
        netId = to_string(octets[0]) + "." + to_string(octets[1]);
        hostId = to_string(octets[2]) + "." + to_string(octets[3]);
        
    } else if (firstOctet >= 192 && firstOctet <= 223) {
        ipClass = 'C';
        mask = "255.255.255.0";
        netId = to_string(octets[0]) + "." + to_string(octets[1]) + "." + to_string(octets[2]);
        hostId = to_string(octets[3]);
        
    } else if (firstOctet >= 224 && firstOctet <= 239) {
        ipClass = 'D';
        mask = "Not Defined";
        netId = "Not Applicable";
        hostId = "Not Applicable";
        
    } else if(firstOctet >= 240 && firstOctet <= 255){
        ipClass = 'E';
        mask = "Not Defined";
        netId = "Not Applicable";
        hostId = "Not Applicable";
    }

    // Display Results
    //cout << "--- IP Address Details ---\n";
    cout << "IP Address : " << ip << "\n";
    cout << "Class      : " << ipClass << "\n";
    cout << "Subnet Mask: " << mask << "\n";
    cout << "Network ID : " << netId << "\n";
    cout << "Host ID    : " << hostId << "\n";

    return 0;
}