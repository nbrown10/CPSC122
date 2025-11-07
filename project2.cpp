/*
Name: Nathan Brown
Course: CPSC122
Date Submitted: 9/19/25
Assighment Name: Project 2
Description: Program is to implement the Substitution Cipher by generating a random key, then encrypting the text in PTfile, 
with the key, and then decrypting it in the CTfile. */
#include <iostream>
#include <fstream>
#include <cstdlib>   // for rand(), srand(), atoi()
#include <ctime>     // for time()
#include <cctype>    // for toupper(), isalpha()
using namespace std;

void keyGen(string keyFile);
char encrypt(char ch, int key);
char decrypt(char ch, int key);
void control(int mode, string keyFile, string PTfile, string CTfile);

int main(int argc, char* argv[])
{
    int mode;
    string keyFile, PTfile, CTfile;

    if (argc != 3 && argc != 5) 
    {
        cout << "Wrong number of command line arguments" << endl;
       return 1;
    }

    mode = atoi(argv[1]);
    keyFile = argv[2];
    
    if (argc == 3)
    {
        keyGen(keyFile);
        return 0; 
    }

    if (argc == 5)
    {
        PTfile = argv[3];
        CTfile = argv[4];
        control(mode, keyFile, PTfile, CTfile); 
    }

    return 0;
}

// Generates a random key and stores it in keyFile
void keyGen(string keyFile)
{
    srand(time(0));           
    int key = rand() % 25 + 1; 

    ofstream fout(keyFile);
    if (!fout)
    {
        cout << "Error opening key file" << endl;
        exit(1);
    }
    fout << key;
    fout.close();

    cout << "Key generated: " << key << " stored in " << keyFile << endl;
}

// Encrypts a single character using the key
char encrypt(char ch, int key)
{
    ch = toupper(ch);
    if (ch < 'A' || ch > 'Z') return ch; 
    return 'A' + (ch - 'A' + key) % 26;
}

// Decrypts a single character using the key
char decrypt(char ch, int key)
{
    ch = toupper(ch);
    if (ch < 'A' || ch > 'Z') return ch;
    return 'A' + (ch - 'A' - key + 26) % 26; // Add 26 to avoid negative
}

// Control function to read/write files and encrypt/decrypt
void control(int mode, string keyFile, string PTfile, string CTfile)
{
    int key;
    ifstream finKey(keyFile);
    if (!finKey)
    {
        cout << "Error opening key file" << endl;
        exit(1);
    }
    finKey >> key;
    finKey.close();

    ifstream fin;
    ofstream fout;

    if (mode == 1) // Encrypt
    {
        fin.open(PTfile);
        fout.open(CTfile);
        if (!fin || !fout)
        {
            cout << "Error opening input and output files" << endl;
            exit(1);
        }

        char ch;
        while (fin.get(ch))
        {
            if (isalpha(ch))
                ch = encrypt(ch, key);
            fout.put(ch);
        }
    }
    else if (mode == 2) // Decrypt
    {
        fin.open(CTfile);
        fout.open(PTfile);
        if (!fin || !fout)
        {
            cout << "Error opening input and  output files" << endl;
            exit(1);
        }

        char ch;
        while (fin.get(ch))
        {
            if (isalpha(ch))
                ch = decrypt(ch, key);
            fout.put(ch);
        }
    }
    else
    {
        cout << "Invalid mode" << endl;
        exit(1);
    }

    fin.close();
    fout.close();
    cout << "Program completed" << endl;
}
