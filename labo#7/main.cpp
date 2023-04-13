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
            i+=1;
        }
        if (tmp == '\0')
        {
            cout << "No se Encontro";
        }
        else
        {
            cout << "\nEl elemento es : " << tmp << "\nPosicion exacta: " << i << endl;
        }
    }
}
