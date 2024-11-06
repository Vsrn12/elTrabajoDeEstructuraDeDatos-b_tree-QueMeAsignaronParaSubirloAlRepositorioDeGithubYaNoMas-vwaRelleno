#include "b_tree.h"
using namespace std;

BTreeNode::BTreeNode() {
    num_keys = 0;
    is_leaf = true;
    for (int i = 0; i < MAX_KEYS + 1; i++) {
        children[i] = NULL;
    }
}

BTreeNode *createNode() {
    BTreeNode *newNode = (BTreeNode *)malloc(sizeof(BTreeNode));
    if (newNode == NULL) {
        cout<<"La asignación de memoria falló.\n";
        exit(1);
    }
    newNode->num_keys = 0;
    return newNode;
}

void insert(BTreeNode** root, double key) {
    if (*root == NULL) {
        *root = createNode();
        (*root)->keys[0] = key;
        (*root)->num_keys = 1;
        cout << "Insertado en raíz: " << key << endl;  // Mensaje de depuración
    } else {
        if ((*root)->num_keys == MAX_KEYS) {
            //cout << "Dividiendo nodo lleno..." << endl;  // Mensaje de depuración
            BTreeNode *newRoot = createNode();
            newRoot->children[0] = *root;
            splitChild(newRoot, 0);
            *root = newRoot;
        }
        insertNonFull(*root, key);
    }
}

void splitChild(BTreeNode* parent, int i) {
    BTreeNode* fullNode = parent->children[i];
    BTreeNode* newNode = createNode();
    newNode->num_keys = (MAX_KEYS) / 2 ; // Asumiendo que MAX_KEYS es impar

    // Mover la mitad de las claves al nuevo nodo
    for (int j = 0; j < newNode->num_keys; j++) {
        newNode->keys[j] = fullNode->keys[j + (MAX_KEYS / 2)];
    }

    // Mover los hijos del nodo lleno al nuevo nodo
    if (fullNode->children[0] != NULL) {
        for (int j = 0; j <= fullNode->num_keys; j++) {
            newNode->children[j] = fullNode->children[j + (MAX_KEYS / 2)-1];
        }
    }

    fullNode->num_keys = (MAX_KEYS / 2); // Reducir el número de claves en el nodo lleno

    // Insertar el nuevo nodo en el padre
    for (int j = parent->num_keys; j > i; j--) {
        parent->children[j + 1] = parent->children[j];
        
    }
    parent->children[i + 1] = newNode;

    for (int j = parent->num_keys - 1; j >= i; j--) {
        parent->keys[j + 1] = parent->keys[j];
    }
    parent->keys[i] = fullNode->keys[(MAX_KEYS / 2) - 1];
    fullNode->num_keys--;
    parent->num_keys++;
}

void insertNonFull(BTreeNode *node, double key) {
    int i = node->num_keys - 1;
    if (node->children[0] == NULL) {
        insertKey(node, key);
        return;
    }
    while (i >= 0 && node->keys[i] > key) {
        i--;
    }
    i++;
    if (node->children[i]->num_keys == MAX_KEYS) {
        splitChild(node, i);
        if (node->keys[i] < key) {
            i++;
        }
    }
    insertNonFull(node->children[i], key);
}

void insertKey(BTreeNode *node, double key) {
    int i = node->num_keys - 1;
    while (i >= 0 && node->keys[i] > key) {
        node->keys[i + 1] = node->keys[i];
        i--;
    }
    node->keys[i + 1] = key;
    node->num_keys++;
}

bool search(BTreeNode* root, double key) {
    if (root == NULL) {
        return false;
    }

    int i = 0;
    while (i < root->num_keys && key > root->keys[i]) {
        i++;
    }

    if (i < root->num_keys && root->keys[i] == key) {
        return true; 
    }

    if (root->children[i] != NULL){
        return false;
    }
    
    return search(root->children[i], key);
}
/*
void loadCSV(BTreeNode** root, const char *filename) {
    FILE *file = fopen(filename, "r");
    
    // Ignora la primera línea (encabezado)
    char buffer[1024];
    if (fgets(buffer, sizeof(buffer), file) == NULL) {
        // Maneja error al leer la línea 
        fclose(file);
        return;
    }

    int index;
    double key;
    while (fscanf(file, "%d,%lf", &index, &key) == 2) {
        insert(root, key);
    }

    fclose(file);
}*/
void loadCSV(BTreeNode **root, const char *filename) {
    ifstream file(filename);
    string line;

    // Ignorar la primera línea (cabecera)
    getline(file, line);

    // Leer cada línea del archivo
    while (getline(file, line)) {
        stringstream ss(line);
        string indexStr, numberStr;

        getline(ss, indexStr, ',');  // Leer el índice (ignorando)
        getline(ss, numberStr, ','); // Leer el número como cadena

        try {
            long double number = stod(numberStr); // Convertir a double
            insert(root, number);
        } catch (const invalid_argument& e) {
                cerr << "Error al convertir el número en la línea: " << line <<endl;
            }

        // Insertar la llave en el árbol B

    }

    file.close();
}

void printBTree(BTreeNode *node, int level) {
    if (node == nullptr) return;

    cout << string(level * 2, ' ') << "Node: ";
    for (int i = 0; i < node->num_keys; i++) {
        cout << node->keys[i] << " ";
    }
    cout << endl;

    for (int i = 0; i <= node->num_keys; i++) { 
        if (node->children[i] != nullptr) { 
            printBTree(node->children[i], level + 1);
        }
    }
}