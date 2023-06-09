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
void add(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon, char value);
void searchCola(ptrNodoCola ptrA, char value);
char removeElement(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon);
int countElement(ptrNodoCola ptrA);
void deleteElementAllOrNot(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon, int cant);

void instruction(void);

// Laboratorio #7
int main()
{
    ptrNodoCola ptrHead = NULL;
    ptrNodoCola ptrTalon = NULL;
    int op;
    char element;
    instruction();
    cout << "Que desea realizar? ";
    cin >> op;

    while (op != 6)
    {
        system("clear");
        switch (op)
        {
        case 1:
            cout << "Introduzca un caracter : ";
            cin >> element;
            add(&ptrHead, &ptrTalon, element);
            printCola(ptrHead);
            break;
        case 2:
            printCola(ptrHead);
            break;
        case 3:
            cout << "Introduzca un caracter : ";
            cin >> element;
            searchCola(ptrHead, element);
            break;
        case 4:
            element = removeElement(&ptrHead, &ptrTalon);
            cout << "\n\nElemento removido! -> " << element << endl;
            cout << "Elementos Restantes -> \n";
            printCola(ptrHead);
            break;
        case 5:
            int x;
            cout << "Introduzca un caracter : ";
            cin >> x;
            deleteElementAllOrNot(&ptrHead, &ptrTalon, x);
            break;
        default:
            cout << "Eleccion no Valida";
            break;
        }
        instruction();
        cout << "Que desea realizar? \n\n";

        cin >> op;
    }

    cout << "fin app\n\n";

    return 0;
}

void instruction(void)
{
    cout << "Introduzca su eleccion \n";
    cout << "1.- Ingresar a la cola\n";
    cout << "2.- Mostrar Cola\n";
    cout << "3.- Buscar Elemento en la cola\n";
    cout << "4.- Eliminar 1re. Elemento\n";
    cout << "5.- Elimniar # de Elementos\n";
    cout << "6.- Salir\n";
}

int isEmpty(ptrNodoCola ptrHead)
{
    return ptrHead == NULL;
}

void add(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon, char value)
{
    if (isdigit(value))
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
    else
    {

        cout << "\nNO es un digito!\n";
    }
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

        cout << "NULL\n\n";
    }
}

void searchCola(ptrNodoCola ptrA, char value)
{
    if (isEmpty(ptrA))
    {
        cout << "\nLa lista esta vacia!\n";
    }
    else
    {
        char tmp;
        int i = 1;
        while (ptrA != NULL)
        {

            if (value == ptrA->dato)
            {
                tmp = ptrA->dato;
                break;
            }
            ptrA = ptrA->ptr_S;
            i += 1;
        }
        if (tmp == '\0')
        {
            cout << "No se Encontro " << endl
                 << endl;
        }
        else
        {
            cout << "\nEl elemento es : " << tmp << "\nPosicion exacta: " << i << endl
                 << endl;
        }
    }
}

char removeElement(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon)
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

int countElement(ptrNodoCola ptrA)
{
    int i = 0;
    while (ptrA != NULL)
    {
        ptrA = ptrA->ptr_S;
        i += 1;
    }
    return i;
}

void deleteElementAllOrNot(ptrNodoCola *ptrHead, ptrNodoCola *ptrTalon, int cant)
{
    int elements = countElement(*ptrHead); // contar los elementos en la cola
    if (elements == 0)
    {
        cout << "La cola esta vacia" << endl;
        return;
    }
    if (cant <= 0 || cant >= 16)
    {
        cout << "La cantidad debe ser mayor que 0 o menor a 15" << endl;
        return;
    }
    if (cant > elements)
    {
        cant = elements;
        cout << "Se eliminara toda la cola que tiene " << elements << " elementos" << endl;
    }
    for (int i = 0; i < cant; i++)
    {
        char eliminado = removeElement(ptrHead, ptrTalon); // eliminar un elemento de la cola
    }
    printCola(*ptrHead);
}
