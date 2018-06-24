#include<iostream>
#define ALPHABET_SIZE 26   //defining the alphabet size of the english language
using namespace std;

//a single trienode definition
class TrieNode{
    //creating array for holding references to child nodes
    public:
    TrieNode *child[ALPHABET_SIZE];
    //checks whether the current node is the including end of word
    bool EndOfWord;

};

TrieNode* createNode(){
    //creating the instance of TrieNode by using new keyword
    TrieNode *ptr = new TrieNode();

    //loop for inserting values into the reference array which is a part of structure
    for(int i = 0; i < ALPHABET_SIZE; i++){
            ptr -> child[i] = NULL;
    }

    //initially each node has default value to false
    ptr -> EndOfWord = false;
    return ptr;
}

//Insertion operation

//function to insert a new node to build a branch path forming a word
 void insertNode(TrieNode * root , string word){
    //Initialize current pointer to point to root node
    //to check whether the letter present already in the tree or not
    TrieNode *cp = root;

    //loop counter to move through the each letter of the word (string)
    for(int i = 0; i < word.length(); i++){

        //assuming that entered string is in small case letters only
        int arrIndex = word[i] - 'a';
            if(!cp -> child[arrIndex]){
                cp -> child[arrIndex] = createNode();
            }
        cp = cp ->child[arrIndex];
    }
    //We have reached the end of letter of the word so set value of node corresponding to last letter to true
    cp -> EndOfWord = true;
}

//Search Operation :- Searches the word and if the word not found inserts into the tree
bool searchWord(TrieNode *root , string word){
    TrieNode *cp = root;

      //iterating over the each letter of the word and checking if present already or not
        for(int i = 0; i < word.length(); i++){
            int arrIndex = word[i] -'a';

            //checks whether current has any reference to its child node at a particular arrayIndex in its array
            if(!cp -> child[arrIndex]){
                return false;
            }
            cp = cp -> child[arrIndex];
        }

    //either prefix of the word is found and the value corresponding to it is false in the node
    //so both of condition must be true
    if(cp != NULL && cp ->EndOfWord)
        return true;
    else
        return false;
}

int main(){

    string wordArray[] = {"peacock", "peahen", "ram","shyam", "hello" ,"world" };

    int numberOfWords = sizeof(wordArray)/sizeof(wordArray[0]);

    //creating the root node
    TrieNode *root = createNode();


    for (int i = 0; i < numberOfWords; i++)
        insertNode(root, wordArray[i]);

    string key;
    cout << "Enter the word which you want to search" << endl;
    cin >> key;
    if(searchWord(root, key) == true)
        cout << "Word is found" << endl;
    else
        cout <<"Not Found !!" << endl;

    return 0;
}
