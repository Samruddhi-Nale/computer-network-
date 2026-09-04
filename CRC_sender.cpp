#include <iostream>
#include <string>
using namespace std;

int main()
{
    string data, generator;

    cout << "CRC Calculation\n\n";

    cout << "Enter Data Bits: ";
    cin >> data;

    cout << "Enter Generator Bits: ";
    cin >> generator;

    int r = generator.length() - 1;

    string temp = data;
    for(int i = 0; i < r; i++)
        temp += '0';

    for(int i = 0; i <= (int)temp.length() - (int)generator.length(); i++)
    {
        if(temp[i] == '1')
        {
            for(int j = 0; j < (int)generator.length(); j++)
            {
                if(temp[i+j] == generator[j])
                    temp[i+j] = '0';
                else
                    temp[i+j] = '1';
            }
        }
    }

    string remainder = temp.substr(temp.length() - r);
    string codeword = data + remainder;

    cout << "\n\nData bits: " << data << endl;
    cout << "Generator bits: " << generator << endl;
    cout << "Number of redundant bits: " << r << endl;
    cout << "Data after appending zeros: " << data;

    for(int i = 0; i < r; i++)
        cout << "0";

    cout << endl;
    cout << "CRC Remainder: " << remainder << endl;
    cout << "Transmitted Codeword: " << codeword << endl;

    return 0;
}