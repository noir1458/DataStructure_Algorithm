#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ALPHABET_SIZE 26  // Assuming only lowercase English letters

typedef struct TrieNode {
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;  // True if the node represents the end of a word
} TrieNode;

// Function to create a new trie node
TrieNode* createNode() {
    TrieNode* pNode = (TrieNode*)malloc(sizeof(TrieNode));
    if (pNode) {
        pNode->isEndOfWord = false;
        for (int i = 0; i < ALPHABET_SIZE; i++) {
            pNode->children[i] = NULL;
        }
    }
    return pNode;
}

// Function to insert a word into the trie
void Insert(TrieNode* root, const char* key) {
    TrieNode* crawler = root;
    while (*key) {
        /*
        TODO: write a traversal on the key for inserting nodes in tree





        */
        key++;
    }
    crawler->isEndOfWord = true;
}

// Function to search a word in the trie
bool search(TrieNode* root, const char* key) {
    TrieNode* crawler = root;
    while (*key) {
        /*
        TODO: write a traversal on the key for searching nodes in tree





        */
        key++;
    }
    return (crawler != NULL && crawler->isEndOfWord);
}
bool isEmpty(TrieNode* root) {
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

bool deleteHelper(TrieNode* root, const char* key, int depth) {
    if (!root) {
        return false;
    }

    // If last character of key is being processed
    if (*key == '\0') {
        if (root->isEndOfWord) {
            root->isEndOfWord = false;
            // If root does not have any children (its not prefix of any other word)
            if (isEmpty(root)) {
                return true; // Delete the node
            }
            return false; // Do not delete the node
        }
    }
    else {
        int index = *key - 'a';
        if (root->children[index]) {
            /*
            TODO: write a traversal on the key for searching nodes and deleting
            Hint: recersive solutions are always in handy




            */
        }
    }
    return false;
}

void Delete(TrieNode* root, const char* key) {
    if (root != NULL && *key && search(root, key)) {
        deleteHelper(root, key, 0);
    }
    else {
        printf("Cannot delete '%s': Word not found in Trie.\n", key);
    }
}

void modify(TrieNode* root, const char* oldKey, const char* newKey) {
    Delete(root, oldKey);
    Insert(root, newKey);
}
void suggestions(TrieNode* root, const char* currentPrefix) {
    if (root->isEndOfWord) {
        printf("%s\n", currentPrefix);
    }

    if (isEmpty(root)) {
        return;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (root->children[i]) {
            /*
            TODO: write a traversal on the prefix for searching nodes and completing
            Hint: recersive solutions are always in handy




            */
        }
    }
}

void autoComplete(TrieNode* root, const char* prefix) {
    TrieNode* crawler = root;
    for (int i = 0; prefix[i] && crawler; i++) {
        int index = prefix[i] - 'a';
        crawler = crawler->children[index];
    }

    if (crawler) {
        suggestions(crawler, prefix);
    }
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    TrieNode* root = createNode(); // Initialize the Trie

    // Predefined words to insert into the Trie
    char* wordsToInsert[] = { "apple", "app", "application", "apricot", "banana",
                             "berry", "blueberry", "blackberry", "banana", "balm", "ba"};
    int n = sizeof(wordsToInsert) / sizeof(wordsToInsert[0]);

    // Inserting words into the Trie
    for (int i = 0; i < n; i++) {
        Insert(root, wordsToInsert[i]);
        printf("Inserted: %s\n", wordsToInsert[i]);
    }
	/*
	Inserted: apple
	Inserted: app
	Inserted: application
	Inserted: apricot
	Inserted: banana
	Inserted: berry
	Inserted: blueberry
	Inserted: blackberry
	Inserted: banana
	Inserted: balm
	Inserted: ba
	*/
	
    // Perform an autocomplete on 'app'
    printf("Autocomplete results for 'app':\n");
    autoComplete(root, "app");
	/*
	Autocomplete results for 'app':
	app
	apple
	application
	*/
	
    // Perform an autocomplete on 'ba'
    printf("Autocomplete results for 'ba':\n");
    autoComplete(root, "ba");
	/*
	Autocomplete results for 'ba':
	ba
	balm
	banana
	*/
	
    // Modifying 'banana' to 'bandana'
    modify(root, "banana", "bandana");
    printf("Modified 'banana' to 'bandana'.\n");

    // Perform an autocomplete on 'ba'
    printf("Autocomplete results for 'ba':\n");
    autoComplete(root, "ba");
	/*
	Autocomplete results for 'ba':
	ba
	balm
	bandana
	*/
	
    // Cleaning up the Trie
    for (int i = 0; i < n; i++) {
        Delete(root, wordsToInsert[i]);
    }
    Delete(root, "bandana");  // Deleting the modified word
	/*
	Cannot delete 'banana': Word not found in Trie.
	Cannot delete 'banana': Word not found in Trie.
	*/


    return 0;
}
