/*
Name: Nathan Brown
Course: CPSC122
Date Submitted: 9/26/25
Assighment Name: Project 3
Description: Program is to implement the Affine Cipher by generating a random key, then encrypting the text 
with the key, and then decrypting it. */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

void keyGen(string keyFile);
char encrypt(char ch, int alpha, int beta);
char decrypt(char ch, int alpha, int beta, int MI[]);
void control(int mode, string keyFile, string input, string output);

int main(int argc, char* argv[])
{
    int mode;
    string keyFile, input, output;

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
        input = argv[3];
        output = argv[4];
        control(mode, keyFile, input, output);
    }

    return 0;
}

// Generates random alpha, beta and stores them in the keyfile
void keyGen(string keyFile)
{
    srand(time(0));
    int alphaChoices[12] = {1,3,5,7,9,11,15,17,19,21,23,25};
    int alpha = alphaChoices[rand() % 12];
    int beta = rand() % 25 + 1;

    ofstream fout(keyFile);
    if (!fout)
    {
        cout << "Error opening the key file" << endl;
        exit(1);
    }
    fout << alpha << endl << beta;
    fout.close();

    cout << "Keys generated: alpha=" << alpha << " beta=" << beta
         << " stored in " << keyFile << endl;
}

// Encrypts a character
char encrypt(char ch, int alpha, int beta)
{
    ch = toupper(ch);
    if (ch < 'A' || ch > 'Z') return ch;
    int x = ch - 'A';
    int y = (alpha * x + beta) % 26;
    return 'A' + y;
}

// Decrypts a character
char decrypt(char ch, int alpha, int beta, int MI[])
{
    ch = toupper(ch);
    if (ch < 'A' || ch > 'Z') return ch;

    int a_inv = MI[alpha]; 
    if (a_inv == 0)
    {
        cout << "Error: alpha does not have an inverse mod 26" << endl;
        exit(1);
    }

    int y = ch - 'A';
    int p = (a_inv * (y - beta + 26)) % 26;  
    return 'A' + p;
}

void control(int mode, string keyFile, string input, string output)
{
    int alpha, beta;
    ifstream finKey(keyFile);
    if (!finKey)
    {
        cout << "Error opening the key file" << endl;
        exit(1);
    }
    finKey >> alpha >> beta;
    finKey.close();

    int MI[26] = {0,1,0,9,0,21,0,15,0,0,0,19,0,0,0,7,0,23,0,11,0,5,0,17,0,25};

    ifstream fin(input);
    ofstream fout(output);
    if (!fin || !fout)
    {
        cout << "Error opening the input and output files" << endl;
        exit(1);
    }

    char ch;
    while (fin.get(ch))
    {
        if (isalpha(ch))
        {
            if (mode == 1) ch = encrypt(ch, alpha, beta);
            else if (mode == 2) ch = decrypt(ch, alpha, beta, MI);
        }
        fout.put(ch);
    }

    fin.close();
    fout.close();
    cout << "Program ran correctly" << endl;
}
