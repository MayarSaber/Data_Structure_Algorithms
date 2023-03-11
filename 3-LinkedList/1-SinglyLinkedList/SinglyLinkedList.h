/**********************************************************/
/****** Author 	: Mayar Saber 				         ******/
/****** SWC		: DataStructures-Singly Linked Lists ******/
/****** Version : 01		  				         ******/
/**********************************************************/

#include	"STD_TYPES.h"
#include	"ERROR_STATE.h"

#include	<stdio.h>
#include    <stdlib.h>

#define		SINGLYLINKEDLIST_DUMMYVALUE		 65563


typedef	 struct node
{
	u32 		  SinglyLinkedList_u32NodeValue;
	struct node * SinglyLinkedList_pNextNode;		/*IMP*/
	
}SinglyLinkedList_Node;


typedef	struct
{
	u32 				   SinglyLinkedList_u32ListSize;
	SinglyLinkedList_Node * SinglyLinkedList_pHead;
	
}SinglyLinkedList_List;


typedef enum
{
	List_Empty,
	List_NEmpty
	
}ListState_t;


ErrorState_t    SinglyLinkedList_CreateList	 		       (SinglyLinkedList_List * *Copy_ReturnedBaseAddress);
ErrorState_t  	SinglyLinkedList_EmptyListCheck 		   (SinglyLinkedList_List *Copy_ptrList , ListState_t *Copy_ListState);
ErrorState_t  	SinglyLinkedList_AddNodeToFront		       (SinglyLinkedList_List *Copy_ptrList , u32 Copy_u32NodeValue);
ErrorState_t    SinglyLinkedList_RemoveNodeFromTheFront    (SinglyLinkedList_List *Copy_ptrList , u32 * Copy_u32ReturnedValue);
ErrorState_t  	SinglyLinkedList_AddNodeToEnd 			   (SinglyLinkedList_List *Copy_ptrList , u32 Copy_u32NodeValue);
ErrorState_t    SinglyLinkedList_RemoveNodeFromTheEnd      (SinglyLinkedList_List *Copy_ptrList , u32 * Copy_u32ReturnedValue);
ErrorState_t  	SinglyLinkedList_AddNodeAtAnyPosition      (SinglyLinkedList_List *Copy_ptrList , u32 Copy_u32NodeValue , u32 Copy_u32Position);
ErrorState_t    SinglyLinkedList_RemoveNodeFromAnyPosition (SinglyLinkedList_List *Copy_ptrList , u32 * Copy_u32ReturnedValue , u32 Copy_u32Position);


