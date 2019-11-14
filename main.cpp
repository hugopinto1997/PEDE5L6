#include <iostream>
#include <cstdlib>
using namespace std;

struct Lista{
    int dato;
    Lista *sig;
};

struct Arbol{
    int dato;
    Arbol *izq;
    Arbol *der;
};


//FUNCIONES RELACIONADAS CON LA LISTA

void mostrarLista(Lista *pInicio){
    if(pInicio!=NULL){
        cout<<pInicio->dato<<"->";
        mostrarLista(pInicio->sig);
    }else{
        cout<<"NULL";
    }
}

Lista *crearNodoLista(int valor){
    Lista *nuevoNodo = new Lista();
    nuevoNodo->dato = valor;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
}

void insertarLista(Lista *&pInicio, Lista *&nuevo){
    if(pInicio==NULL){
        pInicio=nuevo;
    }else{
        insertarLista(pInicio->sig, nuevo);
    }
}



//FUNCIONES RELACIONADAS CON EL BST

void mostrarArbolPreOrder(Arbol *raiz){
    if(raiz!=NULL){
        cout<<raiz->dato<<" - ";
        mostrarArbolPreOrder(raiz->izq);
        mostrarArbolPreOrder(raiz->der);
    }
}

Arbol *crearNodoArbol(int valor){
    Arbol *nuevo = new Arbol();
    nuevo->dato = valor;
    nuevo->izq = nuevo->der = NULL;
    return nuevo;
}

void llenarArbol(Arbol *&raiz, Arbol *&nuevo){
    if(raiz==NULL){
        raiz = nuevo;
    }
    else if (nuevo->dato < raiz->dato){
        if(raiz->izq != NULL){
            llenarArbol(raiz->izq, nuevo);
        }else{
            raiz->izq = nuevo;
        }
    }
    else if (nuevo->dato > raiz->dato){
        if(raiz->der != NULL){
            llenarArbol(raiz->der, nuevo);
        }else{
            raiz->der = nuevo;
        }
    }
}



//FUNCIONES QUE INVOLUCRAN AMBOS LISTA Y BST

void llenarArbolConLista(Lista *pInicio, Arbol *&raiz){
    if(pInicio != NULL){
        Arbol *nuevo = crearNodoArbol(pInicio->dato);
        llenarArbol(raiz, nuevo);
        llenarArbolConLista(pInicio->sig,raiz);
    }
}

int main() {
    //este arreglo contendra los numeros de la lista
    int arreglo[] = {3,5,1,0,2,4,10};
    Lista *pInicio = NULL;
    Lista *aux = NULL;

    Arbol *raiz = NULL;

    for (int i = 0; i < sizeof(arreglo)/ sizeof(*arreglo); ++i) {
        aux = crearNodoLista(arreglo[i]);
        insertarLista(pInicio,aux);
    }
    cout<<"La lista ingresada es: ";
    mostrarLista(pInicio);

    llenarArbolConLista(pInicio,raiz);
    cout<<endl<<"El BST: ";
    mostrarArbolPreOrder(raiz);

    return 0;
}