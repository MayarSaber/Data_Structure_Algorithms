/**********************************************************/
/****** Author 	: Mayar Saber 				         ******/
/****** SWC		: DataStructures-Singly Linked Lists ******/
/****** Version : 01		  				         ******/
/**********************************************************/

#include	"SinglyLinkedList.h"

ErrorState_t  SinglyLinkedList_CreateList(SinglyLinkedList_List * *Copy_ReturnedBaseAddress)
{
	ErrorState_t	Local_FunctionState = RET_OK;
	
	SinglyLinkedList_List * Local_PtrToListBaseAddress = NULL;
	
	if(Copy_ReturnedBaseAddress != NULL)
	{
		    /*Creating the list using DMA*/
		Local_PtrToListBaseAddress = (SinglyLinkedList_List*)malloc(sizeof(SinglyLinkedList_List));
		
		if(Local_PtrToListBaseAddress != NULL)
		{
			/*Initialte the values of list size and first node*/
			Local_PtrToListBaseAddress -> SinglyLinkedList_u32ListSize = 0;
			Local_PtrToListBaseAddress -> SinglyLinkedList_pHead = NULL;
			
			/*Return the base address of the node*/
			*Copy_ReturnedBaseAddress = Local_PtrToListBaseAddress;
		}
		
		else	/*malloc failed*/
		{
			Local_FunctionState = RET_NULL_PTR;
		}
	}
	
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_EmptyListCheck(SinglyLinkedList_List *Copy_ptrList , ListState_t *Copy_ListState)
{
	ErrorState_t Local_FunctionState = RET_OK;
	
	if((Copy_ptrList != NULL) && (Copy_ListState != NULL))
	{
		if(((Copy_ptrList -> SinglyLinkedList_u32ListSize) == 0)&&((Copy_ptrList -> SinglyLinkedList_pHead) == NULL))
		{
			*Copy_ListState = List_Empty;
		}
		
		else
		{
			*Copy_ListState = List_NEmpty;
		}
	}
	
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_AddNodeToFront (SinglyLinkedList_List *Copy_ptrList , u32 Copy_u32NodeValue)
{
	ErrorState_t  Local_FunctionState = RET_OK;
	
	if(Copy_ptrList != NULL)
	{
		/*Create a pointer of the node struct type*/
		SinglyLinkedList_Node * Local_PtrToNodeBaseAddress = NULL;
		
		/*Create the node dynamically and save the returned base address to the created pointer after casting*/
		Local_PtrToNodeBaseAddress = (SinglyLinkedList_Node *)malloc(sizeof(SinglyLinkedList_Node));
		
		/*Check if the DMA process was successful*/
		if(Local_PtrToNodeBaseAddress != NULL)
		{
			/*Pass the address of the head in the LIST to the address of the next node in the node*/
			Local_PtrToNodeBaseAddress -> SinglyLinkedList_pNextNode = Copy_ptrList -> SinglyLinkedList_pHead;
			
			/*Set the address of the first node in the LIST to be the base address of the created node*/
			Copy_ptrList -> SinglyLinkedList_pHead = Local_PtrToNodeBaseAddress;
			
			/*Set the value of the node from the input parameter to the function*/
			Local_PtrToNodeBaseAddress -> SinglyLinkedList_u32NodeValue = Copy_u32NodeValue;
			
			/*Increase the size parameter in the LIST by one*/
			Copy_ptrList -> SinglyLinkedList_u32ListSize++;
		}
		
		else
		{
			/*If malloc() failed to create the node*/
			Local_FunctionState = RET_NULL_PTR;
		}
	}
	
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
		
	
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_RemoveNodeFromTheFront (SinglyLinkedList_List *Copy_ptrList , u32 * Copy_u32ReturnedValue)
{
	ErrorState_t  Local_FunctionState = RET_OK;
	ListState_t   Local_EmptyCheck;
	
	if((Copy_ptrList != NULL) && (Copy_u32ReturnedValue != NULL))
	{
		/*Check if the list is empty*/
		SinglyLinkedList_EmptyListCheck(Copy_ptrList , &Local_EmptyCheck);
		
		if(Local_EmptyCheck == List_Empty)
		{
			Local_FunctionState = RET_NOK;
			printf("Error: THe list is empty:\n");
			*Copy_u32ReturnedValue = SINGLYLINKEDLIST_DUMMYVALUE;
		}
		
		else
		{
			/*Get the address of the node from the list head*/
			SinglyLinkedList_Node * Local_ptrToNode = Copy_ptrList -> SinglyLinkedList_pHead;
			
			/*Return the value from the node*/
			*Copy_u32ReturnedValue = Local_ptrToNode -> SinglyLinkedList_u32NodeValue;
			
			/*Assign the value in the node pointer next, to the list head*/
			Copy_ptrList -> SinglyLinkedList_pHead = Local_ptrToNode -> SinglyLinkedList_pNextNode;
			
			/*free the size of the node we want to remove*/
			free(Local_ptrToNode);
			
			/*Decrease the size in he list*/
			Copy_ptrList -> SinglyLinkedList_u32ListSize--; 
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_AddNodeToEnd (SinglyLinkedList_List *Copy_ptrList , u32 Copy_u32NodeValue)
{
	ErrorState_t  Local_FunctionState = RET_OK;
	ListState_t   Local_EmptyCheck;
	
	if(Copy_ptrList != NULL)
	{
		/*Create a pointer of the node struct type*/
		SinglyLinkedList_Node * Local_PtrToNodeBaseAddress = NULL;
		
		/*Create the node dynamically and save the returned base address to the created pointer after casting*/
		Local_PtrToNodeBaseAddress = (SinglyLinkedList_Node *)malloc(sizeof(SinglyLinkedList_Node));
		
		/*Check if the DMA process was successful*/
		if(Local_PtrToNodeBaseAddress != NULL)
		{
			SinglyLinkedList_EmptyListCheck(Copy_ptrList , &Local_EmptyCheck);
						
			/*Set the value of the node*/
			Local_PtrToNodeBaseAddress -> SinglyLinkedList_u32NodeValue = Copy_u32NodeValue;
			
			/*Assign the next node pointer in the node to be NULL*/
			Local_PtrToNodeBaseAddress -> SinglyLinkedList_pNextNode = NULL;
				
			if(Local_EmptyCheck == List_Empty)
			{
				/*Assign the address of the created node to the list->Head*/
				Copy_ptrList -> SinglyLinkedList_pHead = Local_PtrToNodeBaseAddress;

				/*Increase the size of the list by one*/
				Copy_ptrList -> SinglyLinkedList_u32ListSize++;

			}
			
			else
			{
				/////*Get the address of the last node*/
				////SinglyLinkedList_Node * Local_PtrToLastNodeBaseAddress = (Copy_ptrList -> SinglyLinkedList_pHead) + (Copy_ptrList -> SinglyLinkedList_u32ListSize -1);
				////
				/////*Assign the address of the new base node to the next pointer of the last node*/
				////Local_PtrToLastNodeBaseAddress -> SinglyLinkedList_pNextNode = Local_PtrToNodeBaseAddress;
				////
				/////*Assign the next pointer of the new node to NULL*/
				////Local_PtrToNodeBaseAddress -> SinglyLinkedList_pNextNode = NULL;
				////
				/////*Assign the value of the new node from the input data*/
				////Local_PtrToNodeBaseAddress -> SinglyLinkedList_u32NodeValue = Copy_u32NodeValue;
				////
				/////*Increase the size by one*/
				////Copy_ptrList -> SinglyLinkedList_u32ListSize++;
				
				/**Create a pointer to get the address of the current final node**/
				SinglyLinkedList_Node * TempPtr = Copy_ptrList -> SinglyLinkedList_pHead;
				while((TempPtr -> SinglyLinkedList_pNextNode) != NULL)
				{
					TempPtr = TempPtr -> SinglyLinkedList_pNextNode;
				}
				
				/**After getting the address of the final node -> set it's next pointer to the address of the newly created node**/
				TempPtr -> SinglyLinkedList_pNextNode = Local_PtrToNodeBaseAddress;
				
				/**Increase the size of the list by one**/
				Copy_ptrList -> SinglyLinkedList_u32ListSize++;
			}
		}
		else
		{
			Local_FunctionState = RET_NULL_PTR;
		}
	}
	
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_RemoveNodeFromTheEnd(SinglyLinkedList_List *Copy_ptrList , u32 * Copy_u32ReturnedValue)
{
	ErrorState_t  Local_FunctionState = RET_OK;
	ListState_t  Local_EmptyCheck;
	
	SinglyLinkedList_Node * Local_ptrToLastNode = NULL;
	SinglyLinkedList_Node * Local_ptrToBeforeLastNode = NULL;
	
	if((Copy_ptrList != NULL) && (Copy_u32ReturnedValue != NULL))
	{
		SinglyLinkedList_EmptyListCheck(Copy_ptrList , &Local_EmptyCheck);
		
		if(Local_EmptyCheck == List_Empty)
		{
			printf("Error: The list is already empty, there is no data to be returned...\n");
			Local_FunctionState = RET_NOK;
			*Copy_u32ReturnedValue = SINGLYLINKEDLIST_DUMMYVALUE;
		}
		
		else if(Copy_ptrList -> SinglyLinkedList_pHead -> SinglyLinkedList_pNextNode != NULL)
		{
			Local_ptrToLastNode = Copy_ptrList -> SinglyLinkedList_pHead;
			Local_ptrToBeforeLastNode = Copy_ptrList -> SinglyLinkedList_pHead;
			
			while((Local_ptrToLastNode -> SinglyLinkedList_pNextNode) != NULL)
			{
				Local_ptrToLastNode = Local_ptrToLastNode -> SinglyLinkedList_pNextNode;
			}
			
			while((Local_ptrToBeforeLastNode -> SinglyLinkedList_pNextNode -> SinglyLinkedList_pNextNode) != NULL)
			{
				Local_ptrToBeforeLastNode = Local_ptrToBeforeLastNode -> SinglyLinkedList_pNextNode;
			}
			
			
			*Copy_u32ReturnedValue = Local_ptrToLastNode -> SinglyLinkedList_u32NodeValue;
			
			free(Local_ptrToLastNode);
			Local_ptrToBeforeLastNode -> SinglyLinkedList_pNextNode = NULL;
			Copy_ptrList -> SinglyLinkedList_u32ListSize--;
		}
		
		else
		{
			Local_ptrToLastNode = Copy_ptrList -> SinglyLinkedList_pHead;
			*Copy_u32ReturnedValue = Local_ptrToLastNode -> SinglyLinkedList_u32NodeValue;
			free(Local_ptrToLastNode);
			Copy_ptrList -> SinglyLinkedList_pHead = NULL;
			Copy_ptrList -> SinglyLinkedList_u32ListSize--;
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_AddNodeAtAnyPosition (SinglyLinkedList_List *Copy_ptrList , u32 Copy_u32NodeValue , u32 Copy_u32Position)
{
	
	ErrorState_t Local_FunctionState = RET_OK;
	
	/*Create a pointer to hold the address of the required position*/
	SinglyLinkedList_Node * Local_PositionptrTemp = NULL;
	
	/*Create a pointer to hold the address of the following position*/
	SinglyLinkedList_Node * Local_FollowingptrTemp = NULL;
	
	/*Create a counter to get to the required position*/
	u8 Local_u8Counter = 1;
	
	if((Copy_ptrList != NULL) && ((Copy_u32Position <= (Copy_ptrList -> SinglyLinkedList_u32ListSize)) && (Copy_u32Position > 0)))
	{
		/*Create a pointer to the new node*/
		SinglyLinkedList_Node * Local_PtrToNodeBaseAddress = (SinglyLinkedList_Node*)malloc(sizeof(SinglyLinkedList_Node));
		
		if(Local_PtrToNodeBaseAddress != NULL) //If the malloc function was successful
		{
			/*Add the value of the new node*/
			Local_PtrToNodeBaseAddress -> SinglyLinkedList_u32NodeValue = Copy_u32NodeValue;
			
			/*Hold the first node address in the temp pointer*/
			Local_PositionptrTemp = Copy_ptrList -> SinglyLinkedList_pHead;
			
			if(Copy_u32Position != 1)
			{
				while(Local_u8Counter < Copy_u32Position -1) //Move using the temp pointer till the right position
				{
					Local_PositionptrTemp = Local_PositionptrTemp -> SinglyLinkedList_pNextNode;
					Local_u8Counter++;
				}
				
				/*Following pointer will hold the following position*/
				Local_FollowingptrTemp = Local_PositionptrTemp -> SinglyLinkedList_pNextNode;
				
				/*set the next node value of the previous node*/
				Local_PositionptrTemp ->SinglyLinkedList_pNextNode = Local_PtrToNodeBaseAddress;
				
				/*set the next node value of the new node*/
				Local_PtrToNodeBaseAddress -> SinglyLinkedList_pNextNode = Local_FollowingptrTemp;
				
				/*Increase the size of the list*/
				Copy_ptrList -> SinglyLinkedList_u32ListSize++;
			}
			
			else
			{
				Copy_ptrList -> SinglyLinkedList_pHead = Local_PtrToNodeBaseAddress;
				
				Local_PtrToNodeBaseAddress -> SinglyLinkedList_pNextNode = Local_PositionptrTemp;
				
				Copy_ptrList -> SinglyLinkedList_u32ListSize++;
			}
		}
		
		else
		{
			Local_FunctionState = RET_NULL_PTR;
		}
	}
	else
	{
		printf("Error: The position you sent to function isn't applicable or you sent a NULL pointer, %d isn't added\n",Copy_u32NodeValue);
		Local_FunctionState = RET_NOK;
	}
	
	return Local_FunctionState;
}

/***********************************************************************************************/

ErrorState_t  SinglyLinkedList_RemoveNodeFromAnyPosition (SinglyLinkedList_List *Copy_ptrList , u32 * Copy_u32ReturnedValue , u32 Copy_u32Position)
{
	ErrorState_t  Local_FunctionState = RET_OK;
	
	if((Copy_ptrList != NULL) && (Copy_u32ReturnedValue != NULL))
	{
		
	}
	
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
}

