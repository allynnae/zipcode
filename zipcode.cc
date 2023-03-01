
/**
 *   @file: word-count.cc
 * @author: Allison McKee
 *   @date: 02-24-2023
 *  @brief: Zip codes to Barcodes 
 */
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>

using namespace std;

string getDigitCode(char digit);
int getCheckDigitValue (int sum);

int main(int argc, char const *argv[]) {
    char digit;
    char response = 'y';
    string zip_code;
    int sum = 0;
    while (response != 'n' && response == 'y')
    {
        cout << "Enter a zip code: ";
        cin >> zip_code;
        bool invalid = false;
        if (zip_code.length() != 5) 
        {
            cout << "Error: zip code must be 5 digits" << endl;
            invalid = true;
        } 
        else 
        {
            for (int i = 0; i < zip_code.length(); i++) 
            {
                if (!isdigit(zip_code[i]) && zip_code[i] != ' ') 
                {
                    cout << "Error: Code is invalid" << endl;
                    invalid = true;
                    break;
                }
            }
        }
        if (!invalid) 
        {
            cout << "Code: |  ";
            for (int i = 0; i < zip_code.length(); i++)
            {
                digit = zip_code[i];
                if (digit != ' ') 
                {
                    sum += digit - '0';
                    string DigitCode = getDigitCode(digit);
                    cout << DigitCode;
                }
            }
            int check_digit = getCheckDigitValue(sum);
            string check_digit_code = getDigitCode(check_digit + '0');
            cout << check_digit_code << " |" << endl;
        }
        cout << "More codes (y/n)? ";
        cin >> response;
    }
    return 0;
}

string getDigitCode(char digit)
{ 
    if (digit == '1')
    {
        return ":::|| ";
    }
    if (digit == '2')
    {
        return "::|:| ";
    }
    if (digit == '3')
    {
        return "::||: ";
    }
    if (digit == '4')
    {
        return ":|::| ";
    }
    if (digit == '5')
    {
        return ":|:|: ";
    }
    if (digit == '6')
    {
        return ":||:: ";
    }
    if (digit == '7')
    {
        return "|:::| ";
    }
    if (digit == '8')
    {
        return "|::|: ";
    }
    if (digit == '9')
    {
        return "|:|:: ";
    }
    if (digit == '0')
    {
        return "||::: ";
    }
    return "";
}

int getCheckDigitValue (int sum)
{
    int check_digit = (10 - (sum % 10)) % 10;
    return check_digit;
}
