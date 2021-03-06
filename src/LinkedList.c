#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
//#include "../inc/LinkedList.h"

/**
 *
 * @param this
 * @param nodeIndex
 * @return
 */
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
    LinkedList* this= NULL;
    this=(LinkedList*) malloc(sizeof(LinkedList));
    if(this!=NULL)
    {
    	this->size=0;
    	this->pFirstNode=NULL;
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
    int rtn = -1;
    if(this!=NULL)
    {
    	rtn = this->size;
    }
    return rtn;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	Node* pAuxNode;
	int posicion=0;
	int len=ll_len(this);
	if (this!=NULL && (nodeIndex>=0 && nodeIndex<len))
	{
		pAuxNode=this->pFirstNode;
		while(posicion!=nodeIndex)
		{
			pAuxNode=pAuxNode->pNextNode;
			posicion++;
		}
		pNode=pAuxNode;
	}
    return pNode;
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
    int returnAux = -1;
    int len = ll_len(this);

    Node* pNodeNuevo = (Node*) malloc(sizeof(Node));
    Node* pNodeAnterior;
    Node* pNodeSiguiente;

    if(this!=NULL && nodeIndex>=0 && nodeIndex<=len)
    {
    	pNodeNuevo->pElement=pElement;
    	pNodeNuevo->pNextNode=NULL;
    	returnAux=0;
    	if(nodeIndex==0)
    	{
    		pNodeNuevo->pNextNode=this->pFirstNode;
    		this->pFirstNode=pNodeNuevo;
    	}
    	/*else if(this->pFirstNode==NULL)
    	{
    		this->pFirstNode=pNodeNuevo;
    	}*/ else
    	{
    		pNodeAnterior=getNode(this, nodeIndex-1);
    		pNodeSiguiente=pNodeAnterior->pNextNode;
    		pNodeAnterior->pNextNode=pNodeNuevo;
    		pNodeNuevo->pNextNode=pNodeSiguiente;
    	}
    		this->size++;
    }
    return returnAux;
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
    int returnAux = -1;
    if(this != NULL)
    {
    	int nodeIndex=ll_len(this);
    	returnAux=addNode(this, nodeIndex, pElement);
    }
    return returnAux;
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
    void* returnAux = NULL;
    int len=ll_len(this);
    if(this!=NULL && index>=0 && index<len)
    {
    	Node* pNodeObtenido;
    	pNodeObtenido=getNode(this, index);
    	if(pNodeObtenido!=NULL)
    	{
    		returnAux=pNodeObtenido->pElement;
    	}
    }
    return returnAux;
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
    int len=ll_len(this);
    Node* pNodeBuscado;
    if(this!=NULL && index>=0 && index<len)
    {
    	pNodeBuscado=getNode(this, index);
    	pNodeBuscado->pElement=pElement;
    	returnAux=0;
    }

    return returnAux;
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
    int len=ll_len(this);
    Node* pNodeBuscado;
    Node* pNodeAnterior;
    if(this!=NULL && index>=0 && index<len)
    {
    	if(index==0)
    	{
    		pNodeBuscado=this->pFirstNode;
    		this->pFirstNode=pNodeBuscado->pNextNode;
    		free(pNodeBuscado);
    	} else
    	{
    		pNodeBuscado=getNode(this, index);
    		pNodeAnterior=getNode(this, index-1);
    		pNodeAnterior->pNextNode=pNodeBuscado->pNextNode;
    		free(pNodeBuscado);
    	}
    	this->size--;
    	returnAux=0;
    }
    return returnAux;
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
    int len=ll_len(this);

    if(this!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		returnAux=ll_remove(this,0);
    		if(returnAux==-1)
    		{
    			break;
    		}
    	}
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
    if(this!=NULL)
    {
    	ll_clear(this);
    	free(this);
    	returnAux=0;
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
    int len=ll_len(this);
    void* pAuxElement;
    if(this!=NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		pAuxElement= ll_get(this, i);
    		if(pAuxElement==pElement)
    		{
    			returnAux=i;
    			break;
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
    int len=ll_len(this);
    if(this!=NULL)
    {
    	returnAux=0;
    	if(len==0)
    	{
    		returnAux=1;
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
    int len=ll_len(this);
    if(this!=NULL && index>=0 && index<=len)
    {
    	returnAux=addNode(this, index, pElement);
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
    int len=ll_len(this);
    Node* pNodeBuscado;
    if(this!=NULL && index>=0 && index<len)
    {
    	pNodeBuscado=getNode(this, index);
    	returnAux=pNodeBuscado->pElement;
    	ll_remove(this, index);
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
    int index;
    if(this!=NULL)
    {
    	index=ll_indexOf(this, pElement);
    	returnAux=0;
    	if(index!=-1)
    	{
    		returnAux=1;
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
    int len1=ll_len(this);
    int len2=ll_len(this2);
    void* pAuxElement;

    if(this!=NULL && this2!=NULL)
    {
    	returnAux=0;
    	if(len2>0 && len1>0)
    	{
			for(int i=0;i<len2;i++)
			{
				pAuxElement=ll_get(this2, i);
				returnAux=ll_contains(this, pAuxElement);
				if(returnAux==0)
				{
					break;
				}
			}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    LinkedList* pNuevaLista=ll_newLinkedList();
    int len=ll_len(this);
    void* pNuevoElement;
    if(this!=NULL && pNuevaLista!=NULL)
    {
    	if((from>=0 && from<=len) && (to>from && to<=len))
    	{
    		for(int i=from;i<to;i++)
    		{
    			pNuevoElement=ll_get(this, i);
    			ll_add(pNuevaLista, pNuevoElement);
    		}
    		cloneArray=pNuevaLista;
    	}
    }
    return cloneArray;
}



/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    LinkedList* pNuevaLista=ll_newLinkedList();

    if(this!=NULL && pNuevaLista!=NULL)
    {
    	int len=ll_len(this);
    	pNuevaLista=ll_subList(this, 0, len);
    	cloneArray=pNuevaLista;
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
	int returnAux =-1;
	int len;
	void* pPrimerDato;
	void* pSegundoDato;
	int ordenamientoFuncion;
	void* pPivote;

	if(this!=NULL && pFunc!=NULL && (order==0 || order==1))
	{
		len=ll_len(this);
		for(int i=0;i<len-1;i++)
		{
			for(int j=i+1;j<len;j++)
			{
				pPrimerDato=ll_get(this,i);
				pSegundoDato=ll_get(this,j);
	            if(pPrimerDato!=NULL && pSegundoDato!=NULL)
	            {
	            	ordenamientoFuncion=pFunc(pPrimerDato,pSegundoDato);
	            	if(ordenamientoFuncion == -1 && order == 0)
	            	{
	            		pPivote=pPrimerDato;
	            		ll_set(this,i,pSegundoDato);
	            		ll_set(this,j,pPivote);
	            	}
	            	if(ordenamientoFuncion==1 && order ==1)
	            	{
	            		pPivote=pPrimerDato;
	            		ll_set(this,i,pSegundoDato);
	            		ll_set(this,j,pPivote);
	            	}
	            	returnAux=0;
	            }
			}
		}
	}
    return returnAux;
}
/**
 * @brief genera un listado con los elementos de una editorial especifica
 * @param this
 * @param fn
 * @return linkedlist
 */
LinkedList* ll_filter(LinkedList* this, int (*fn)(void*))
{
	LinkedList* ListaEditMinotauro=NULL;
	ListaEditMinotauro=ll_newLinkedList();
	int len=ll_len(this);
	void* pElementoBuscado;
	int corroboracion;
	if(this!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			pElementoBuscado=ll_get(this,i);
			if(pElementoBuscado!=NULL)
			{
				corroboracion=fn(pElementoBuscado);
				if(corroboracion == 1)
				{
					ll_add(ListaEditMinotauro, pElementoBuscado);
				}
			}
		}
	}
	return ListaEditMinotauro;
}
/***
 * @brief realiza un listado con descuento en ciertas editoriales
 * @param this
 * @param fn
 * @return linkedlist
 */
LinkedList* ll_map (LinkedList* this, void* (*fn)(void*))
{
	LinkedList* ListaConDescuestos=NULL;
	ListaConDescuestos=ll_clone(this);
	int len=ll_len(this);
	void* pElementoBuscado;
	void* pAuxiliar;
	if(this!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			pElementoBuscado=ll_get(this,i);
			if(pElementoBuscado!=NULL)
			{
				pAuxiliar=fn(pElementoBuscado);
				ll_set(ListaConDescuestos,i,pAuxiliar);
			}
		}
	}
	return ListaConDescuestos;
}
/***
 * @brief realiza un conteo de los elementos de la lista
 * @param this
 * @param fn
 * @param totalPearson
 * @return int
 */
int ll_count(LinkedList* this, int (*fn)(void*,float*),float* totalPearson)
{
	int rtn=-1;
	int len=ll_len(this);
	void* pElementoBuscado;
	int corroboracion;
	int contadorLibrosMas500=0;
	float precioTotalPearson=0;

	if(this!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			pElementoBuscado=ll_get(this,i);
			if(pElementoBuscado!=NULL)
			{
				corroboracion=fn(pElementoBuscado,&precioTotalPearson);
				if(corroboracion == 1)
				{
					contadorLibrosMas500++;
				}
				*totalPearson=precioTotalPearson;
			}
			rtn=contadorLibrosMas500;
		}
	}
	return rtn;
}
