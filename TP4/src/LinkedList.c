#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size=0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL; //Crea un puntero nodo auxiliar y lo pone en nulo

    int i; //Variable de control

    if(this != NULL) //Si el LinkedList es distinto de nulo
    {
        if(nodeIndex >= 0 && nodeIndex < ll_len(this)) //Si el indice es mayor o igual a cero y menor al tamaño del LinkedList
        {
            pNode = this->pFirstNode; //El puntero nodo ahora es el primer nodo del LinkedList

            if(pNode!=NULL) //Si el puntero nodo es distinto de nulo
            {
                for(i=0; i<ll_len(this); i++) //Desde cero, mientras la variable de control sea menor al tamaño del LinkedList, sumar 1
                {
                    if(i==nodeIndex) //Si la variable de control es igual al indice
                    {
                        break; //Interrumpir (salir del ciclo)
                    }
                    pNode = pNode->pNextNode; //El puntero nodo ahora es el siguiente nodo
                }
            }
        }
    }

    return pNode; //Devuelve el puntero nodo
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1; //Valor de error (por defecto) de variable de retorno

    Node* new_node=(Node*)malloc(sizeof(Node)); //Crea un nodo auxiliar de forma dinamica
    Node* old_node=NULL; //Crea un puntero nodo auxiliar y lo pone en nulo
    new_node->pElement=pElement; //Asigna el elemento argumento al elemento del nodo auxiliar creado dinamicamente

    if(this!=NULL && new_node!=NULL) //Si el LinkedList y el nodo auxiliar son distintos de nulo
    {
        if(nodeIndex>=0 && nodeIndex<=ll_len(this)) //Si el indice es mayor o igual a cero y menor o igual al tamaño del LinkedList
        {
            if(nodeIndex==0) //Si el indice es igual a cero
            {
                new_node->pNextNode=this->pFirstNode; //El nodo next del nodo auxiliar ahora es el primer nodo del LinkedList
                this->pFirstNode=new_node; //El primer nodo del LinkedList ahora es el nodo auxiliar
            }
            else
            {
                old_node=getNode(this, nodeIndex-1); //El puntero nodo auxiliar ahora es el resultado de explorar el LinkedList
                new_node->pNextNode=old_node->pNextNode; //El nodo next del nodo auxiliar ahora es el nodo next del puntero nodo auxiliar
                old_node->pNextNode=new_node; //El nodo next del puntero nodo auxiliar ahora es el nodo auxiliar
            }
            returnAux=0; //Valor de OK de variable de retorno
            this->size++; //Aumenta en 1 la posicion del LinkedList
        }
    }
    return returnAux; //Devuelve el valor de retorno
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1; //Valor de error (por defecto) de variable de retorno

    if(this != NULL) //Si el LinkedList es distinto de nulo
    {
        returnAux = addNode(this, this->size, pElement); //La variable de retorno agrega y enlaza un nuevo nodo al LinkedList
    }

    return returnAux; //Devuelve el valor de retorno
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL; //La variable de retorno ahora es nulo
    Node* new_node; //Crea un nodo auxiliar

    if(this != NULL) //Si el LinkedList es distinto de nulo
    {
        if(index>=0 && index<ll_len(this)) //Si el indice es mayor o igual a cero y tambien menor al tamaño del LinkedList
        {
            new_node = getNode(this, index); //El nodo auxiliar ahora es el resultado de la exploracion de la lista

            if(new_node != NULL) //Si el nodo auxiliar es distinto de nulo
            {
                returnAux = new_node->pElement; //El valor de la variable de retorno ahora es el elemento del nodo auxiliar
            }
        }
    }

    return returnAux; //Devuelve el valor de retorno
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* new_node;

    if(this != NULL)
    {
        if(index>=0 && index<ll_len(this))
        {
            new_node = getNode(this, index); //El nodo auxiliar ahora es el resultado de la exploracion de la lista
            if(new_node != NULL) //Si el nodo auxiliar es distinto de nulo
            {
                new_node->pElement = pElement; //El elemento del nodo auxiliar ahora es igual al elemento argumento
                returnAux = 0; //Valor de OK de la variable de retorno
            }
        }
    }

    return returnAux; //Devuelve el valor de retorno
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;

    Node* first_node; //Crea un primer nodo auxiliar
    Node* second_node; //Crea un segundo nodo auxiliar

    if(this != NULL)
    {
        if(index>=0 && index<this->size) //Si el indice es mayor o igual a cero y menor que el tamaño del LinkedList
        {
            returnAux = 0; //El valor de la variable de retorno ahora es igual a cero (OK)
            if(this->size == 1) //Si el tamaño del LinkedList es igual a uno
            {
                this->pFirstNode = NULL; //El primer nodo del LinkedList ahora es igual a nulo
                free(getNode(this, index)); //Al resultado de explorar la lista a traves del indice se le hace un free (libera memoria dinamicamente)
            }
            else if(index == 0) //Si el indice es igual a cero
            {
                first_node = getNode(this, index); //El primer nodo auxiliar ahora es el resultado de explorar la lista a traves del indice
                this->pFirstNode = first_node->pNextNode; //El primer nodo del Linkedlist ahora es igual al siguiente nodo del primer nodo auxiliar
                free(first_node);
            }
            else //Sino
            {
                first_node = getNode(this, index); //El primer nodo auxiliar ahora es el resultado de explorar la lista a traves del indice
                if(first_node != NULL) //Si el primer nodo auxiliar es distinto de nulo
                {
                    second_node = getNode(this, index - 1); //El segundo nodo auxiliar ahora es el resultado de explorar la lista a traves del indice menos uno (anterior)
                    second_node->pNextNode = first_node->pNextNode; //El nodo next del segundo nodo auxiliar ahora es el nodo next del primer nodo auxiliar
                    free(first_node); //Se le hace un free (liberar memoria) al primer nodo auxiliar
                }
            }
        }
        this->size--; //Reduce el tamaño del LinkedList en uno
    }

    return returnAux; //Devuelve el valor de retorno
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;

    int i;

    if(this != NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            ll_remove(this, i); //Elimina el elemento de la lista situado en el valor de la variable de control
        }
        returnAux = 0;
    }

    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_clear(this) == 0) //Si todos los elementos de la lista son borrados
        {
            free(this); //Se le hace un free al LinkedList (se libera dinamicamente)
            returnAux = 0;
        }
    }

    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    int i;

    Node* pNode = NULL;

    if(this != NULL)
    {
        for(i=0; i<ll_len(this); i++)
        {
            pNode = getNode(this, i); //El nodo auxiliar es igual al nodo obtenido el valor de la variable de control
            if(pNode->pElement == pElement) //Si el elemento del nodo auxiliar es igual al elemento argumento
            {
                returnAux = i; //El valor de retorno ahora es el valor de la variable de control
                break; //Interrumpe el ciclo
            }
        }
    }
    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_len(this) == 0) //Si el tamaño del LinkedList es igual a cero
        {
            returnAux = 1; //La lista esta vacia
        }
        else //Sino
        {
            returnAux = 0; //La lista no esta vacia
        }
    }

    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(index>=0 && index<=ll_len(this)) //Si el indice es mayor o igual a cero y menor o igual al tamaño del LinkedList
        {
            returnAux = addNode(this, index, pElement); //El valor de retorno ahora es igual al resultado de agregar el nodo en el indice indicado
        }
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;

    if(this != NULL)
    {
        if(index>=0 && index<=ll_len(this))
        {
            returnAux = ll_get(this, index); //El valor de retorno ahora es el resultado de obtener el elemento en el indice indicado
            ll_remove(this, index); //Elimina el elemento en el indice indicado
        }
    }

    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
        if(ll_indexOf(this, pElement) == -1) //Si el resultado de explorar la lista a traves del elemento argumento es nulo
        {
            returnAux = 0; //No contiene el elemento
        }
        else //Sino
        {
            returnAux = 1;  //Contiene el elemento
        }
    }

    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;

    int i;

    int counter = 0;

    void* pElementAux; //Crea un elemento auxiliar

    if(this != NULL && this2 != NULL) //Si la lista1 es distinta de nula y la lista2 tambien
    {
        returnAux = 0; //Valor de retorno para que los elementos de la lista2 no esten contenidos en la lista1

        if(ll_len(this) >= ll_len(this2)) //Si el  tamaño de la lista1 es mayor o igual que el tamaño de la lista2
        {
            for(i=0; i<ll_len(this2); i++) //Desde cero, mientras la variable de control sea menor al tamaño de la lista2, aumentar en uno
            {
                pElementAux = ll_get(this2, i); //El elemento auxiliar ahora es el elemento obtenido de la lista2 a traves de la variable de control
                if(ll_contains(this, pElementAux) == 1) //Si el elemento auxiliar esta contenido en la lista1
                {
                    counter++; //Aumenta en uno el contador auxiliar
                }
            }
            if(counter == ll_len(this)) //Si el contador auxiliar es igual al tamaño de la lista1
            {
                returnAux = 1; //Valor de retorno para que los elementos de la lista2 esten contenidos en la lista1
            }
        }
    }

    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param this LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL; //Crea una lista auxiliar y la iguala a nulo

    int i;

    int new_list = 0; //Crea un contador auxiliar de lista

    Node* pNode; //Crea un nodo auxiliar

    if(this != NULL)
    {
        if(from>=0 && from<=ll_len(this) && to>=0 && to<=ll_len(this)) //Si el indice inicial es mayor o igual que cero y menor o igual que el tamaño de la lista
        {
            //y el indice final es mayor o igual que cero y menor o igual al tamaño de la lista
            cloneArray = ll_newLinkedList(); //La lista auxiliar ahora es construida dinamicamente a traves del constructor
            for(i=from; i<to; i++) //Desde el indice inicial, mientras la variable de control sea menor al indice final, sumar uno
            {
                pNode = getNode(this, i); //El nodo auxiliar ahora es el resultado de obtener un nodo de la lista a traves de la variable de control
                if(pNode != NULL) //Si el nodo auxiliar es distinto de nulo
                {
                    addNode(cloneArray, new_list, pNode->pElement); //Agrega un nuevo nodo a la lista auxiliar
                    new_list++; //Aumenta en uno el contador auxiliar de lista
                }
            }
        }
    }

    return cloneArray; //Devuelve la lista auxiliar
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL; //Crea una lista auxiliar y la iguala a nulo

    if(this != NULL) //Si el LinkedList es distinto de nulo
    {
        cloneArray = ll_subList(this, 0, this->size); //La lista auxiliar ahora es una nueva lista LinkedList a traves de su tamaño
    }

    return cloneArray; //Retorna la nueva lista
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void*,void*), int order)
{
    int returnAux =-1; //Valor de retorno de error (por defecto)

    int i; //Variable de control

    int flag; //Variable bandera

    void* pElementA; //Crea un elemento auxiliar A
    void* pElementB; //Crea un elemento auxiliar B
    void* pElementAux; //Crea un elemento Auxiliar

    if(this != NULL) //Si la lista es distinta de nulo
    {
        if(pFunc != NULL) //Si la funcion argumento es distinta de nulo
        {
            if(order == 0 || order == 1) //Si el orden es descendente o es ascendente
            {
                if(ll_len(this) > 0) //Si el tamaño de la lista es mayor que cero
                {
                    do //Hacer
                    {
                        flag = 0; //La variable bandera ahora es cero
                        for(i=0; i<ll_len(this)-1; i++) //Desde cero, mientras la variable de control sea menor al tamaño de la lista menos uno, sumar uno
                        {
                            pElementA = ll_get(this, i); //El elemento auxiliar A ahora es el elemento obtenido de la lista a traves de la variable de control
                            pElementB = ll_get(this, i+1); //El elemento auxiliar B ahora es el elemento obtenido de la lista a traves de la variable de control mas uno
                            if((pFunc(pElementA, pElementB) < 0 && order == 0) || (pFunc(pElementA, pElementB) > 0 && order == 1))
                            {
                                //Si el resultado de la funcion argumento a traves de los elementos auxiliares es menor a cero y el orden es descendente o
                                //el resultado de la funcion argumento a traves de los elementos auxiliares es mayor a cero y el orden es ascendente
                                pElementAux = pElementA; //El elemento Auxiliar ahora es el elemento auxiliar A
                                ll_set(this, i, pElementB); //Cambia el elemento de la lista a traves de la variable de control por el elemento auxiliar B
                                ll_set(this, i+1, pElementAux); //Cambia el elemento de la lista a traves de la variable de control mas uno por el elemento Auxiliar
                                flag = 1; //La variable bandera ahora es uno
                            }
                            returnAux = 0; //Valor de OK de la variable de retorno
                        }
                    }
                    while(flag); //Mientras la variable bandera sea uno (verdadero)
                }
            }
        }
    }

    return returnAux;

}







LinkedList* ll_filter(LinkedList* this, int(*pFunc)(void*))
{
    int i; //Variable de control

    void* pElementAux; //Elemento auxiliar

    LinkedList* new_subList; //Lista auxiliar

    if(this != NULL) //Si la lista auxiliar argumento es distinta de nulo
    {
        if(*pFunc != NULL) //Si la funcion argumento es distinta de nulo
        {
            new_subList = ll_newLinkedList(); //La lista auxiliar ahora es construida dinamicamente a traves del constructor

            for(i=0; i<ll_len(this); i++) //Desde cero, mientras la variable de control sea menor al tamaño de la lista, sumar uno
            {
                pElementAux = ll_get(this, i); //El elemento auxiliar ahora es la obtencion del elemento de la lista a traves de la variable de control
                if(pFunc(pElementAux) == 1); //Si el resultado de la funcion argumento a traves del elemento auxiliar es OK
                {
                    ll_add(new_subList, pElementAux); //Agrega el elemento auxiliar a la lista auxiliar
                }
            }
        }
    }
    return new_subList; //Devuelve la lista auxiliar
}
