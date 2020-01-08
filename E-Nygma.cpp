/* Made By Debdip Banerjee on 3rd November,2019 */

/*Last Update 8th January,2020*/

/*Possible Update:
1.Add Display Function (Done)
2.Add PlayFair Cipher
3.Random Key Generation
*/

#pragma once
#include<iostream>
#include<string>

using namespace std;

class enygma 
{
private:
	string plainText;
	string cipherText;
	int key = 0;

public:
	void Encrypt();
	void Decrypt();
	void get_Data();
	void display_Data(string);
	void display();
};

void enygma::get_Data()
{
	cout << "Please Enter a text:" << endl;
	getline(cin, plainText);
	cout << "enter a key:" << endl;
	cin >> key;
}

void enygma::display_Data(string cipher)
{
	cout << "Plain Text: " << plainText << endl;
	cout << "Key: " << key << endl;
	cout << "Cipher Text: " << cipher << endl;
}

void enygma::display()
{
	cout << "_____________________________________________" << endl;
	cout << "                  E-Nygma:                   " << endl;
	cout << " A Fun Game Based on Caeser Cipher Technique " << endl;
	cout << "_____________________________________________" << endl;
	cout << endl;
}

void enygma::Encrypt()
{
	get_Data();
	string p_text = plainText;
	int k = key;
	string result = "";
	for (int i = 0; i < p_text.length(); i++)
	{
		if (isupper(p_text[i]))
		{
			result += char(int(p_text[i] + k - 65) % 26 + 65);
		}
		else
		{
			result += char(int(p_text[i] + k - 97) % 26 + 97);
		}
	}
	display_Data(result);
}

void enygma::Decrypt()
{
	get_Data();
	string p_text = plainText;
	int k = key;
	string result = "";
	for (int i = 0; i < p_text.length(); i++)
	{
		if (isupper(p_text[i]))
		{
			result += char(int(p_text[i] - k - 65) % 26 + 65);
		}
		else
		{
			result += char(int(p_text[i] - k - 97) % 26 + 97);
		}
	}
	display_Data(result);
}

int main()
{
	enygma e;
	e.display();
	char i;
	cout << "Encrypt/Decrypt(E/D): ";
	cin >> i;
	cin.ignore();
	switch (toupper(i))
	{
	case 'E': 
		e.Encrypt();
		break;
	case 'D':
		e.Decrypt();
		break;
	default:
		cout << "Please try again, sorry";
		break;
	}
	
	return 0;
}

