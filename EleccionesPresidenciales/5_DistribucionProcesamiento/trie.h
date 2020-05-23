#ifndef __TRIE_H__
#define __TRIE_H__

#include<iostream>

using namespace std;

struct TrieNode { 
	struct TrieNode *children[10]; 
	bool isEnd; 
}; 

struct TrieNode *getNode(void);
void insert(struct TrieNode *root, string key);
bool search(struct TrieNode *root, string key) ;


#endif