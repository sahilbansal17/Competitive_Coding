/*
  https://github.com/sahilbansal17/Competitive_Coding/

  Name: Anil Khatri (@imkaka)
  Email-Id: anil.soccer.khatri@gmail.com

*/

// Huffman Coding => It is a lossless data Compression algorithm. (https://en.wikipedia.org/wiki/Huffman_coding)
// The idea is to assign variable-length codes to input characters based on frequency of crossponding character,
// The most frequent character gets the smallest code and the least frequent character gets the largest code.
// It is considered as Optimum Prefix Code (for more => https://en.wikipedia.org/wiki/Prefix_code)


/* Implementation =>
   1. Building a Huffman Tree from input Characters

      -> Create a leaf node for each unique character and build a min heap(priority_queue) of all leaf nodes
      -> Extract two nodes with the minimum frequency from the min heap.
      -> Create a new node with frequency equal to the sum of the two nodes frequencies. Make the first extracted node as its left child 
         and the other extracted node as its right child. Add this node to the min heap. (Greedy Step)
      -> Repeat 2,3 until the heap contains only one node.(root).

   2. Traversing the Huffman Tree

      -> Maintain a Auxliary array, write 0 while moving to left child and 1 when right child,Print array when we are at leaf node.

   Example =>

    |Char| a | b |  c  | d  |  e | f|
    |----|---|---|-----|----|----|--|
    |Freq| 4 | 20|  26 | 30 | 32 |45|

    1. Huffman Tree (Min Heap)
                 
                       (157)              <= root
                    0/       \1
                  (62)        (95)
                0/    \1     0/    \1
             (30)    (32)  (45)    (50)
                                 0/   \1
                              (24)  (26)
                            0/   \1    
                          (4)  (20)

    2. Huffman Coding 
     
     |Char| a    | b   |  c   | d  |  e | f  |
     |----|------|-----|------|----|----|----|
     |Code| 1100 | 1101| 111  | 00 | 01 | 10 |
                    
*/


#include<iostream>
#include<queue>
#include<vector>

using namespace std;


struct Data{

  char carr;
  unsigned freq;
};
// A Huffman tree
struct HeapNode {
 
    char _carr;
    unsigned _freq;
    HeapNode *left, *right;
 
    HeapNode(char _carr, unsigned _freq)
    {
        left = right = NULL;
        this->_carr = _carr;
        this->_freq = _freq;
    }
};
 
// Print Huffman Code
void printHuffmanCodes(HeapNode* root, string str)
{
 
    if (!root)
        return;
 
    if (root->_carr != 'I')
        cout << root->_carr << ": " << str << "\n";
 
    printHuffmanCodes(root->left, str + "0");
    printHuffmanCodes(root->right, str + "1");
}


// For comparison of Nodes
struct comp{
    bool operator()(HeapNode* l, HeapNode* r)
    {
        return (l->_freq > r->_freq);
    }
};

//Building Huffman Tree
void HuffmanCodes(Data input [], int size)
{
      HeapNode *left, *right, *top;
 
    //Create min Heap and Insert _curr of input
    priority_queue<HeapNode*, vector<HeapNode*>, comp> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(new HeapNode(input[i].carr, input[i].freq));
 
    // Till Size !=1
    while (minHeap.size() != 1) {
 
        // Extract the top two
        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
        
        // Create new internal Node adding two freq and left and right child as Discussed
        // 'I' is for Internal Node 
        top = new HeapNode('I', left->_freq + right->_freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
 
    // Print Huffman codes using
    printHuffmanCodes(minHeap.top(), "");
}
 

int main(){
  int n;
  cout << "Please Enter Number of Characters: ";
  cin >> n;
  
  // data to store char and freq
  Data input[n];
  cout<< endl<<"Enter Character then Frequency with space in B/w:"<<endl;
  for(int i=0;i<n;i++){
      
      cin >> input[i].carr >> input[i].freq;
  }

  HuffmanCodes(input,n);

  return 0;
}

//Time Complexity => O(NlogN)    ->N is input unique char as exatract_Min() is called 2*(n-1) times where n are nodes
//                                 & extract_Min() take O(logN) so Overall O(NlogN)
//Space Complexity => O(N)       -> Storing Data.