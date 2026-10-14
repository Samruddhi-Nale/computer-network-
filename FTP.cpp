#include <iostream>
#include <string>
using namespace std;

int main(){
    string username, password;
    int choice;

    cout << "===== FTP CLIENT =====" << endl;

    cout << "Enter Username: ";
    cin >> username;

    cout << "Enter Password: ";
    cin >> password;

    if (username == "student" && password == "1234"){
        cout << "\nFTP Login Successful!" << endl;

        do{
            cout << "\n===== FTP MENU =====" << endl;
            cout << "1. List Files" << endl;
            cout << "2. Download File" << endl;
            cout << "3. Upload File" << endl;
            cout << "4. Exit FTP" << endl;

            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice){
                case 1:
                    cout << "Displaying server files..." << endl;
                    cout << "1. notes.txt" << endl;
                    cout << "2. assignment.txt" << endl;
                    break;

                case 2:
                    cout << "File downloaded successfully!" << endl;
                    break;

                case 3:
                    cout << "File uploaded successfully!" << endl;
                    break;

                case 4:
                    cout << "FTP session terminated." << endl;
                    break;

                default:
                    cout << "Invalid choice!" << endl;
            }

        } while (choice != 4);
    }
    else{
        cout << "Login Failed! Invalid username or password."
             << endl;
    }

    return 0;
}