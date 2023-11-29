// Author: Shashank 
#include<bits/stdc++.h>
using namespace std;

// Function to Count Unique Characters and their frequencies
unordered_map<char, int> countChars_freq(string& file_name){
    unordered_map<char, int> charcount;

    fstream file; // fstream is a class provides the capability of creating, writing and reading a file.
    // Created an object of the fstream class and named it as ‘file’.

    file.open(file_name, ios:: in); 
    // On the above-created object, we have to apply the open() function to create a new file, 
    // and the mode is set to ‘in’ which will allow us to read from the file.

    if(!file){ 
        cout << "Check File Name";
        return charcount;
    }

    while(file){

        string line;
        getline(file, line);

        for(char ch: line){
            if(charcount.find(ch) == charcount.end()){
                charcount[ch]=1;
            } 
            else{
                charcount[ch]++;
            }
        }
    }
    return charcount;
}

int main(){
    int ch;
    string F_name;

    cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<< endl;
    cout << "|                             |"<< endl;
    cout << "|          MENU               |"<< endl;
    cout << "|                             |"<< endl;
    cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<< endl;
    cout << "|                             |"<< endl;
    cout << "|      1. COMPRESS            |"<< endl;
    cout << "|      2. DECOMPRESS          |"<< endl;
    cout << "|                             |"<< endl;
    cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<< endl;
    cout << "Enter Your Choice: 🌝"<<endl;
    cin  >> ch;

    if(ch==1){
        cout << "Enter Filename"<<endl;
        cin >> F_name;

        // Step 1 : Count unique characcters and their frequencies
        unordered_map<char, int> result = countChars_freq(F_name);
    }

}