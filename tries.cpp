#include<bits/stdc++.h>
using namespace std;
#define CHARSET 256
class TrieNode{
    public:
    bool isWord;
    TrieNode * children[256];
    TrieNode(){
    this->isWord=false;
    for(int i = 0;i<CHARSET;i++){
        this->children[i] = NULL;
    }
    }
};
class Trie{
    TrieNode * root;
    bool isLeafNode(TrieNode* crawler){
        for(int i = 0;i<CHARSET;i++){
            if(crawler->children[i]!=NULL){
                return false;
            }
        }
        return true;
    }
    public:
    Trie(){
        this->root = new TrieNode();
    }
    void insert(const string &str){
        TrieNode * crawler = this->root;
        for(int i = 0;i<CHARSET;i++){
            if(crawler->children[int(str[i])] == NULL){
                crawler->children[int(str[i])] = new TrieNode();
            }
            crawler = crawler->children[int(str[i])];
        }
        crawler->isWord = true;
    }
     bool search(const string &str){
        TrieNode * crawler = this->root;
        for(int i = 0;i<CHARSET;i++){
            if(crawler->children[int(str[i])] == NULL){
                return false;
            }
            crawler = crawler->children[int(str[i])];
        }
       return crawler->isWord ;
    }
    bool remove(TrieNode* crawler, const string & word, int curr,const int len){
        if(crawler==NULL) return false;
        if(curr==len) {
            crawler->isWord = false;
            return (isLeafNode(crawler));
            
        }else{
            if(remove(crawler->children[(word[curr])], word, curr+1, len)){
                delete crawler->children[(word[curr])];
                return (crawler->isWord && isLeafNode(crawler)) ;
                
            }
        }
    }
    void remove(const string &word){
        TrieNode * crawler = this->root;
        remove(crawler, word, 0,word.size());
        
    }
};
int main(){
    Trie t;
    t.insert("apple");
   cout<< t.search("apple");
    return 0;
}
