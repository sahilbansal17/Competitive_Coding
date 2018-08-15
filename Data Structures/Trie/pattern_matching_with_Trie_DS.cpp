//Name:Anuj Goyal
//Email:anujg935@gmail.com

//This program is to present you pattern matching in trie data structure
//with complete implementation of trie datastructure itself for better understanding 
#include<iostream>
#include<vector>
#include<string>
using namespace std;

//trie node class for every node in Trie that contains data and
//refrence to its childrens and also isTerminal for end of word 
class TrieNode{
	public:
	char data;
	TrieNode **children;
	bool isTerminal;
	
	//constructor to initialize the node
	TrieNode(char data){
		this->data = data;
		children = new TrieNode*[26];
		
		for(int i=0;i<26;i++){
			children[i] =NULL;
		}
		isTerminal = false;
	}
};

//Trie class for all its functionaliy
class Trie{
	TrieNode *root;
	
	public:
		//constructor creates TrieNode
		Trie(){
			root = new TrieNode(NULL);
		}
		
		//insertWord() function inserts a new word in the trie
		void insertWord(TrieNode * root,string word){
			//base case
			if(word.size() ==0){
				root->isTerminal = true;
				return;
			}
			
			//small calculations
			int index = word[0] - 'a';
			TrieNode * child;
			if(root->children[index] !=NULL){
				child = root->children[index];
			}
			else{
				child  = new TrieNode(word[0]);
				root->children[index] = child;
			}
			
			//Recursive call
			insertWord(child,word.substr(1));
		}
		
		void insertWord(string word){
			insertWord(root,word);
		}
		
		//Sreches th word in the trie
		bool searchWord(TrieNode * root,string word){
			//base case
			if(word.size() == 0){
				if(root->isTerminal ==true){
					return true;
				}
				else {
					return false;
				}
			}
			
			//small calculations
			int index = word[0] - 'a';
			TrieNode * child;
			if(root->children[index] !=NULL){
				child = root->children[index];
              	return searchWord(child,word.substr(1));
			}
			else{
				return false;
			}
			
			//Recursive call
			
		}
		
		bool search(string word){
			return searchWord(root,word);
		}
		
		//removes the word from the trie
		void removeWord(TrieNode * root,string word){
			if(word.size() ==0){
				root->isTerminal = false;
				return;
			}
			
			//small calculations
			
			TrieNode *child;
			int index = word[0]-'a';
			
			if(root->children[index]!=NULL){
				child =root->children[index];
			}
			else{
				//word not found 
				return;
			}
			removeWord(child,word.substr(1));
			
			//Remove child node if its  useless
		
			if(child->isTerminal == false){
				for(int i=0;i<26;i++){
					if(child->children[i] !=NULL){
						return;
					}
				}
				delete child;
				root->children[index] = NULL;
			}
		}
		void removeWord(string word){
			removeWord(root,word);
		}
		
		//helper function of the patternMatching() function 
		bool patern(TrieNode * root,string pattern){
			//base case for recursion when the size of pattern is equal to zero 
      		if(pattern.size()==0){
        		return true;
      		}
      		
      		//finding the index of the first element of pattern 
	      	TrieNode *child;
		  	int index = pattern[0]-'a';
			
			//if the first char of patern is present in the trie or not	
			//than callng recursion next chars of pattern
		  	if(root->children[index]!=NULL){
				child =root->children[index];
	        	return patern(child,pattern.substr(1));
		  	}
		  	//else the patern is not their in the trie
		  	else{
				//word not found 
				return false;
			}
	    }
	    //Given a list of n words and a pattern p that we want to search. 
		//Check if the pattern p is present the given words or not
		bool patternMatching(vector<string> vect, string pattern) {
			
			//creating a trie node
	      	Trie *tree = new Trie;
	      	//insering the words in the input array vect of type string
	      	//with all its sub strings or sub patterns
	      	for(int i=0;i<vect.size();i++){
	        	for(int j=0;j<vect[i].size();j++){
	          		insertWord(vect[i].substr(j));
	        	} 
	      	}
	      	//calling helper function 
	      	return patern(root,pattern);
		}
		
		
};


int main()
{
	Trie t;
	t.insertWord("and");
	t.insertWord("are");
	t.insertWord("dot");
	
	cout<<t.search("and")<<endl;
	t.removeWord("and");
	cout<<t.search("and")<<endl;
	
	vector<string> vect = {"anuj","asdf","edfr","aqws"};
	cout<<t.patternMatching(vect,"an")<<endl;
}
