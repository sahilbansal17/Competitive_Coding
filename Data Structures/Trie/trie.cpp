#include<iostream>
#define ALPHABET_SIZE 26   //defining the alphabet size of the english language
using namespace std;
//a single trienode definition
class TrieNode{
    //creating array for holding references to child nodes
    public:
    TrieNode *child[ALPHABET_SIZE];
    //checks whether the current node is the including end of word
    bool end_of_word;
};
TrieNode* createNode(){
    //creating the instance of TrieNode by using new keyword
    TrieNode *ptr = new TrieNode();
    //loop for inserting values into the reference array which is a part of structure
    for(int i = 0; i < ALPHABET_SIZE; i++){
            ptr -> child[i] = NULL;
    }
    //initially each node has default value to false
    ptr -> end_of_word = false;
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
        int arr_index = word[i] - 'a';
            if(!cp -> child[arr_index]){
                cp -> child[arr_index] = createNode();
            }
        cp = cp ->child[arr_index];
    }
    //We have reached the end of letter of the word so set value of node corresponding to last letter to true
    cp -> end_of_word = true;
}
/*  Calculating the time complexity and space complexity of insertion operation

    Time Complexity clearly depends on the length of the word so total time being being calculated as
    Total time = (time taken over insertion of single word) * (number of words in the array)
    (Note : Time taken over creation of a node is a constant i.e O(1) or more accurately O(C) where
     C = Constant)
    Since the strings are of variable lengths so therefore we take up the average length of the string
    Therefore total time being computed as
               = O(l*n) where
               = l = average length of the string word
               = n = number of words to be inserted into the trie

    Space Complexity is also another thing which is to be considered in trie

    As for each node we have an array of references whose size is dependent on the number of alphabet
    therefore total size is  (size of each node ) * (total no of nodes)
     where size of each node = ((size of array of pointers containing references to child nodes) + sizeof(bool))

*/
//Search Operation :- Searches the word and if the word not found inserts into the tree
bool searchWord(TrieNode *root , string word){
    TrieNode *cp = root;
      //iterating over the each letter of the word and checking if present already or not
        for(int i = 0; i < word.length(); i++){
            int arr_index = word[i] -'a';

            //checks whether current has any reference to its child node at a particular arrayIndex in its array
            if(!cp -> child[arr_index]){
                return false;
            }
            cp = cp -> child[arr_index];
        }
    //either prefix of the word is found and the value corresponding to it is false in the node
    //so both of condition must be true
    if(cp != NULL && cp ->end_of_word)
        return true;
    else
        return false;
}
/*  Calculating the time complexity of search operation

    Time Complexity clearly depends on the length of the word so total time being being directly
    dependent on the length of string
*/
int main(){
    string word_array[10];
    int number_of_words;
    cout<< "How many values do you want to insert ?" <<endl;
    cin >> number_of_words;

    //creating the root node
    TrieNode *root = createNode();
    cout<<"Enter the values which you want to insert to the trie" <<endl;
    for(int i = 0; i < number_of_words; i++){
        cin >> word_array[i];
        insertNode(root, word_array[i]);
    }
    string key;
    cout << "Enter the word which you want to search" << endl;
    cin >> key;
    if(searchWord(root, key) == true)
        cout << "Word is found" << endl;
    else
        cout <<"Not Found !!" << endl;
    return 0;
}
