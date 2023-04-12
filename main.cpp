#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct nodoCola
{
    char dato;
    struct nodoCola *ptr_S;
};

typedef struct nodoCola NodoCola;
typedef NodoCola *ptrNodoCola;

void printCola(ptrNodoCola ptrA);
int isEmpty(ptrNodoCola ptrHead);
char remove(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon);
void add(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon, char value);
void instruction(void);

int main()
{
    ptrNodoCola ptrHead = NULL;
    ptrNodoCola ptrTalon = NULL;
    int op;
    char element;
    instruction();
    cout << "Que desea realizar? ";
    cin >> op;

    while (op != 3)
    {
        switch (op)
        {
        case 1:
            cout << "Introduzca un caracter : ";
            cin >> element;
            add(&ptrHead, &ptrTalon, element);
            printCola(ptrHead);
            break;

        case 2:
            if (!isEmpty(ptrHead))
            {
                element = remove(&ptrHead, &ptrTalon);
                cout << "Se desenfilo " << element;
            }
            printCola(ptrHead);
            break;
        case 3:
            cout << "\nAdios!!\n\n";
            break;

        default:
            cout << "Eleccion no Valida";
            break;
        }
        cout << "?";
        cin >> op;
    }

    cout << "fin app";

    return 0;
}

void instruction(void)
{
    cout << "Introduzca su eleccion \n";
    cout << "1.- Ingresar un elemento\n";
    cout << "2.- Eliminar un elemento\n";
    cout << "3.- Salir\n";
}

int isEmpty(ptrNodoCola ptrHead)
{
    return ptrHead == NULL;
}

void add(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon, char value)
{
    ptrNodoCola ptrNew;
    ptrNew = (NodoCola *)malloc(sizeof(NodoCola));
    if (ptrNew != NULL)
    {
        ptrNew->dato = value;
        ptrNew->ptr_S = NULL;

        if (isEmpty(*ptrHead))
        {
            *ptrHead = ptrNew;
        }
        else
        {
            (*ptrTalon)->ptr_S = ptrNew;
        }

        *ptrTalon = ptrNew;
    }
    else
    {
        cout << "no se incerto " << value << "No hay memoria disponible";
    }
}

char remove(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon)
{
    char value;
    ptrNodoCola tempPtr;
    value = (*ptrHead)->dato;
    tempPtr = *ptrHead;
    *ptrHead = (*ptrHead)->ptr_S;

    if (*ptrHead == NULL)
    {
        *ptrTalon = NULL;
    }

    free(tempPtr);
    return value;
}

void printCola(ptrNodoCola ptrA)
{
    if (ptrA == NULL)
    {
        cout << "la cola esta vacia!" << endl
             << endl;
    }
    else
    {
        cout << "la cola es : \n";
        while (ptrA != NULL)
        {
            cout << ptrA->dato << " -> ";
            ptrA = ptrA->ptr_S;
        }

        cout << "NULL";
    }
}
