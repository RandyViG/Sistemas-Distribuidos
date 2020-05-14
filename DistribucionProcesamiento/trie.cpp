#include "trie.h"

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode( void ){ 
	struct TrieNode *pNode = new TrieNode; 
	pNode->isEnd = false; 
	for (int i = 0; i < 10; i++) 
		pNode->children[i] = NULL; 
	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert( struct TrieNode *root, string key ){ 
	struct TrieNode *pCrawl = root; 
	for (int i = 0; i < key.length(); i++) { 
		int index = key[i] - '0'; 
		if (!pCrawl->children[index]) 
			pCrawl->children[index] = getNode(); 
		pCrawl = pCrawl->children[index]; 
	} 
	// mark last node as leaf 
	pCrawl->isEnd = true; 
} 

// Returns true if key presents in trie, else false 
bool search( struct TrieNode *root, string key ) { 
	struct TrieNode *pCrawl = root; 
	for (int i = 0; i < key.length(); i++){ 
		int index = key[i] - '0'; 
		if (!pCrawl->children[index]) 
			return false; 
		pCrawl = pCrawl->children[index]; 
	} 
	return (pCrawl != NULL && pCrawl->isEnd); 
} 