// Author: Shashank 


#include<bits/stdc++.h>
using namespace std;

/*------------------------------------------- STEP - 3 -----------------------------------------------*/

// Node Structure 
struct Node{
    char character;
    int frequency;
    struct Node* left, *right;

    // This line is the constructor of the Node structure and 
    // it's using a member initializer list to initialize the member variables of the structure. 
    Node(char c, int f): character(c), frequency(f), left(nullptr), right(nullptr){}



    // overloading the < operator for Min Heap
    bool operator<(const Node&next)const {
        return frequency > next.frequency;
    }
    // (const Node &other) is specifying that the less than operator (operator<) takes a constant reference 
    // to another Node object (other). This ensures that the function doesn't modify the other object.

};

// Function to build min-heap with data given
// chr[] - array of unique characters
// freq[] - array of frequencies of unique characters

 priority_queue<Node> buildMinHeap(vector<char>& chr, vector<int>& freq){
    priority_queue<Node> minHeap;
    for(int i=0; i < chr.size(); ++i){
        Node* node = new Node(chr[i], freq[i]);
        minHeap.push(*node);
    }

    return minHeap;
}

/*------------------------------------------ END ------------------------------------------------------*/

// Function to build Huffman tree
Node* buildHuffman(priority_queue<Node>& minHeap){
    while(minHeap.size() > 1){
        Node* left = new Node(minHeap.top());
        minHeap.pop();
        Node* right = new Node(minHeap.top());
        minHeap.pop();

        Node* mergedNode = new Node('$', left->frequency + right->frequency);
        mergedNode->left = left;
        mergedNode->right = right;
        minHeap.push(*mergedNode);
    }
    return new Node(minHeap.top());
}


// Function to prnt Huffman Codes
unordered_map<char, string> H_codes;
unordered_map<char, string> HuffmanCodes(Node* root, string code=""){
    if(root == nullptr){
        return H_codes;
    }

    if(root->character!='$'){
        H_codes[root->character]= code;
    }

    HuffmanCodes(root->left,code+"0");
    HuffmanCodes(root->right,code+"1");
    return H_codes;
}

// Function to substite the Huffman Codes(Compressor)
void compressor(string f_name, const std::string& outputFileName){
    
}
/*------------------------------------------- STEP - 2 -----------------------------------------------*/

// Function to extract unique characters and store in a character array
vector<char> buildchar(unordered_map<char, int>& map){
    vector<char> unique_chars;
    
    for(auto pair: map){
        unique_chars.push_back(pair.first);
    }

    return unique_chars;
}

// Function to store frequency of unique character in an array
vector<int> buildfreq(unordered_map<char, int>& map){
    vector<int> char_freq;

    for(auto pair: map){
        char_freq.push_back(pair.second);
    }

    return char_freq;
}

/*------------------------------------------ END ------------------------------------------------------*/

/*----------------------------------------- STEP - 1 -------------------------------------------------*/

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

/*---------------------------------------------- END ----------------------------------------------*/

int main(){
    int ch;
    string F_name;

    cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<< endl;
    cout << "|                             |"<< endl;
    cout << "|           MENU              |"<< endl;
    cout << "|                             |"<< endl;
    cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<< endl;
    cout << "|                             |"<< endl;
    cout << "|       1. COMPRESS           |"<< endl;
    cout << "|       2. DECOMPRESS         |"<< endl;
    cout << "|                             |"<< endl;
    cout << "x-x-x-x-x-x-x-x-x-x-x-x-x-x-x-x"<< endl;
    cout << "Enter Your Choice: 🌝"<<endl;
    cin  >> ch;

    if(ch==1){
        cout << "Enter Filename"<<endl;
        cin >> F_name;

        // Step 1 : Count unique characcters and their frequencies
        unordered_map<char, int> result = countChars_freq(F_name);

        // Step 2 : Store unique characters and their frequencies in two different arrays
        vector<char> uniqueChar = buildchar(result);
        vector<int> char_freq = buildfreq(result);

        // Step 3 : Sort the above two data with Min Heap
        priority_queue<Node> minHeap = buildMinHeap(uniqueChar, char_freq);

        // Step 4 : Build Huffman tree from MinHeap
         Node* root = buildHuffman(minHeap);

        // Step 5 : Generate Huffman Codes
        unordered_map<char, string> codes= HuffmanCodes(root, "");

        for(const auto&it: codes){
            cout<<it.first<<" "<<it.second<<endl;
        }

        // Step 6 : Substitute Huffman codes(Compressor)
        compressor(F_name, "output.txt");
    }

}