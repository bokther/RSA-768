// Bokther Ahmed
// John Yosko
// Alvin Williams
// Younes Chacha

#include <cmath>
#include <iostream>
#include <fstream>
#include <string>
#include "GMPStringUtilities.h"
#include "rsakeys.h"

using namespace std;

void encrypt(string file_name)
{
   ifstream input_file(file_name);
   ofstream output_file("Encrypted_" + file_name);

   //The following line stores all the contents of the input_file
   //into one string variable
   string file_contents { istreambuf_iterator<char>(input_file), istreambuf_iterator<char>() };
   mpz_class m = from_string(file_contents.substr(0, file_contents.length()-1));
   mpz_class ciphertext;
   mpz_powm(ciphertext.get_mpz_t(), m.get_mpz_t(), e.get_mpz_t(), n.get_mpz_t());
   output_file << ciphertext.get_mpz_t();

   input_file.close();
   output_file.close();
   cout << file_name + " has been encrypted";
   cout << " as Encrypted_" + file_name << endl;
}

void decrypt(string file_name)
{
   ifstream input_file(file_name);
   ofstream output_file("Decrypted_" + file_name);

   //The following line stores all the contents of the input_file
   //into one string variable
   string file_contents {istreambuf_iterator<char>(input_file), istreambuf_iterator<char>()};
   mpz_class c(file_contents, 10);
   
   mpz_class plaintext;
   mpz_powm(plaintext.get_mpz_t(), c.get_mpz_t(), d.get_mpz_t(), n.get_mpz_t());
   output_file << to_string(plaintext);

   input_file.close();
   output_file.close();
   cout << file_name + " has been decrypted";
   cout << " as Decrypted_" + file_name << endl;
}

int main()
{
   string file_name;
   char response;
   cout << "Welcome to the J.A.B. RSA Encrypter v0.45b" << endl;
   cout << "Would you like to encrypt or decrypt? [e/d] ";
   cin >> response;
   if(response == 'e')
   {
      cout << "Please enter the name of the file you wish to encrypt: " << endl;
      cin >> file_name;
      encrypt(file_name);
   }
   else if(response == 'd')
   {
      cout << "Please enter the name of the file you wish to decrypt: " << endl;
      cin >> file_name;
      decrypt(file_name);
   }
   else
   {
      cout << "Invalid response. Please re-run the program." << endl;
   } 
   return 0; 
}
