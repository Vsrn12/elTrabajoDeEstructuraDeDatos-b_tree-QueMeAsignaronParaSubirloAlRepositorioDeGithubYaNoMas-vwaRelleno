/*#include <iostream>
#include "b_tree.h"
using namespace std;

int main() {
  BTreeNode *root = NULL;

  insert(&root, 10);
  insert(&root, 1);
  insert(&root, 20);
  insert(&root, 30);
  insert(&root, 5);
  insert(&root, 40);
  insert(&root, 50);
  insert(&root, 60);
  
  printBTree(root);
  
  return 0;
}*/


#include "b_tree.h"
#include <iostream>

using namespace std;



int main() {
    BTreeNode *root = NULL;
    //string filename = "random_numbers_1000000.csv";

    const char *filename = "random_numbers_1000000.txt";  // Cambia esto por la ruta de tu archivo
    loadCSV(&root, filename);
    
    cout<<"FIN"<<endl;
    int opcion = -1;
    bool found = true;
    double key = 0.11;
    bool v1 = true;

    while(v1){
        cout<<"[0] salir"<<endl;
        cout<<"[1] insertar"<<endl;
        cout<<"[2] buscar"<<endl;
        cout<<"Ingresar opcion: ";
        cin>>opcion;
        switch(opcion){
            case 0:
                v1 = 0;
                break;
            case 1:
                cout<<"ingrese la llave a insertar: ";
                cin>>key;
                insert(&root, key);
                break;
            case 2:
                cout<<"ingrese la llave a buscar: ";
                cin>>key;    
                found = search(root, key);
                if(found)
                    cout<<"llave encontrada"<<endl;
                else
                    cout<<"llave no encontrada"<<endl;
                break;
          case 3 :
                printBTree(root);
            break;

            default:
                cout<<"opcion invalida"<<endl;
                v1 = 0;
                break;
        }
    }
    cout<<"wa"<<endl;
    return 0;
}