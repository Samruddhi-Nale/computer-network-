#include <iostream>
#include <string>
using namespace std;

int main(){
    string ipAddress, macAddress;
    string targetIP;

    cout << "Enter Host IP Address: ";
    cin >> ipAddress;

    cout << "Enter Host MAC Address: ";
    cin >> macAddress;

    cout << "\nARP Table Entry Created:" << endl;
    cout << "IP Address: " << ipAddress << endl;
    cout << "MAC Address: " << macAddress << endl;

    cout << "\nEnter IP Address to Resolve: ";
    cin >> targetIP;

    if (targetIP == ipAddress){
        cout << "\nARP Reply Received!" << endl;
        cout << "IP Address: " << targetIP << endl;
        cout << "MAC Address: " << macAddress << endl;
    }
    else{
        cout << "\nARP Request Broadcast:" << endl;
        cout << "Who has IP address " << targetIP << "?" << endl;
        cout << "No matching ARP entry found." << endl;
    }
    return 0;
}