#include <iostream>
#include <string>
using namespace std;

int main()
{
    string codeword, generator;

    cout << "Enter Received Codeword: ";
    cin >> codeword;

    cout << "Enter Generator Bits: ";
    cin >> generator;

    int r = generator.length() - 1;

    string temp = codeword;

    for (int i = 0; i <= temp.length() - generator.length(); i++)
    {
        if (temp[i] == '1')
        {
            for (int j = 0; j < generator.length(); j++)
            {
                if (temp[i + j] == generator[j])
                    temp[i + j] = '0';
                else
                    temp[i + j] = '1';
            }
        }
    }

    string remainder = temp.substr(temp.length() - r);

    cout << "\nReceived Codeword: " << codeword << endl;
    cout << "Generator Bits: " << generator << endl;
    cout << "Remainder: " << remainder << endl;

    bool error = false;

    for (char bit : remainder)
    {
        if (bit == '1')
        {
            error = true;
            break;
        }
    }

    if (error)
        cout << "Error is present in the received codeword." << endl;
    else
        cout << "No error detected in the received codeword." << endl;

    return 0;
}