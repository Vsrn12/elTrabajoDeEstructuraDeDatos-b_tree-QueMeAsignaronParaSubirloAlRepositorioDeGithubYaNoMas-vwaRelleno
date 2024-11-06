
#ifndef B_TREE_H
#define B_TREE_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <sstream>
#include <fstream>
#include <string>
using namespace std;
#define MAX_KEYS 4

class BTreeNode {
public:
    int num_keys;
    double keys[MAX_KEYS];
    BTreeNode *children[MAX_KEYS + 1];
    bool is_leaf;

    BTreeNode();
};

BTreeNode *createNode();
void insert(BTreeNode* *root, double key);
void splitChild(BTreeNode *parent, int index);
void insertNonFull(BTreeNode *node, double key);
void insertKey(BTreeNode *node, double key);
bool search(BTreeNode* root, double key);
void printBTree(BTreeNode *node, int level = 0);
void loadCSV(BTreeNode **root, const char *filename);

#endif // B_TREE_H
