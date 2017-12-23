//Vigenere Cipher Implementation in C++
#include<iostream>
#include<string>
using namespace std;

//Cyclically maps key to input string size
string generateKey(string str, string key)
{
	int x = str.size();
	for (int i = 0; ; i++)
	{
		if (x == i)
			i = 0;
		if (key.size() == str.size()) //size check
			break;                  
		key.push_back(key[i]);        
	}
	return key;
}

//Encyption function
string cText(string str, string key)
{
	string cipher_text;

	for (int i = 0; i < str.size(); i++)
	{
		// converting in range 0-25
		int x = (str[i] + key[i]) %26;

		// convert into alphabets(ASCII)
		x += 'A';

		cipher_text.push_back(x);
	}
	return cipher_text;
}

//Decryption function
string originalText(string c_text, string key)
{
	string orig_text;

	for (int i = 0 ; i < c_text.size(); i++)
	{
		int x = (c_text[i] - key[i] + 26) %26;  //Numeric form Conversion
		x =x+ 'A';                               //ASCII Conversion
		orig_text.push_back(x);
	}
	return orig_text;
}

//Main function
int main()
{
	string str = "MYNAMEISAMIT",keyword="LOHAN";
	string key = generateKey(str, keyword);
	string c_text = cText(str, key);

	cout << "Ciphertext : "	<< c_text << "\n";

	cout << "Decrypted Text : " << originalText(c_text, key);
	return 0;
}
//https://github.com/OLeoghain
