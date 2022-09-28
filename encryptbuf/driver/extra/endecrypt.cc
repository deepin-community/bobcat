#include <openssl/evp.h>

#include <cstring>
#include <string>
#include <iostream>
#include <iomanip>
#include <stdexcept>
using namespace std;

EVP_CIPHER const *md;

string encrypt(string const &in, string const &key, string const &iv)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    EVP_EncryptInit_ex(ctx, md, 0, 
                            (unsigned char *)&key[0], 
                            (unsigned char *)&iv[0]);

    cerr << "key len: " << key.length() << ": " << key << '\n';
    cerr << "iv len: " << iv.length() << ": " << iv << '\n';

//    string ret(in.length() + EVP_MAX_BLOCK_LENGTH, 0);
    string ret(1000, 0);
    int buflen;
    if (!EVP_EncryptUpdate(ctx, 
                (unsigned char *)&ret[0], 
                &buflen, (unsigned char*)&in[0], in.length())
    )
        return "";

    int tmplen;
    if (!EVP_EncryptFinal_ex(ctx, (unsigned char *)&ret[buflen], &tmplen))
        return "";
   
    ret.resize(buflen + tmplen);

    cerr << "IV: " << hex << setfill('0');
    for (unsigned char ch: iv)
        cerr << setw(2) << static_cast<unsigned>(ch);
    cerr << '\n';

    cerr << "ENCRYPTED: " << hex << setfill('0');
    for (unsigned char ch: ret)
        cerr << setw(2) << static_cast<unsigned>(ch);
    cerr << '\n';


    EVP_CIPHER_CTX_free(ctx);

    return ret;
}

string decrypt(string const &in, string const &key, string const &iv)
{
    EVP_CIPHER_CTX *ctx = EVP_CIPHER_CTX_new();

    EVP_DecryptInit_ex(ctx, md, 0, 
                            (unsigned char *)&key[0], 
                            (unsigned char *)&iv[0]);
   
//    string ret(EVP_MAX_BLOCK_LENGTH, 0);
    string ret(1000, 0);

    int buflen;
    if(!EVP_DecryptUpdate(ctx, (unsigned char *)&ret[0], &buflen, 
        (unsigned char *)&in[0], 
        in.length()))
        return "";
 
    int tmplen;
    if(!EVP_DecryptFinal_ex(ctx, (unsigned char *)&ret[buflen], &tmplen))
        return "";
 
    ret.resize(buflen + tmplen);
  
    EVP_CIPHER_CTX_free(ctx);

    return ret;
}

int main(int argc, char **argv)
{
    if (argc < 4)
    {
        cout << "specify method (1), key (2) and iv (3), opt: text to "
                "en/decrypt\n";
        return 0;
    }

    OpenSSL_add_all_ciphers();

    if ((md = EVP_get_cipherbyname(argv[1])) == 0)
    {
        cout << "method `" << argv[1] << "' not supported\n";
        return 1;
    }
    
    string key{ argv[2] };  //  {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    string iv{ argv[3] };   //  {1,2,3,4,5,6,7,8};

    string text;
    if (argc == 5)
        text = argv[4];
    else
    {
        cout << "Enter string to encrypt: ";
        getline(cin, text);
    }

    string encrypted = encrypt(text, key, iv);

    if (encrypted.length() == 0)
    {
        cout << "encryption failed\n";
        return 1;
    }

    string decrypted = decrypt(encrypted, key, iv);

    if (encrypted.length() == 0)
    {
        cout << "decryption failed\n";
        return 1;
    }

    cout << "After decryption: " << decrypted << '\n';
}


