/*****************************************************/
/****** Author 	: Mayar Saber 				    ******/
/****** SWC		: DataStructures-Circular Queue ******/
/****** Version : 01		  				    ******/
/*****************************************************/
#include	<stdio.h>

/*LIB*/
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include	"ERROR_STATE.h"

/*Circular Queue*/
#include	"CircularQueue.h"


ErrorState_t  CircularQueue_voidInit(CircularQueueStruct * Copy_QueuePointer)
{
	ErrorState_t   Local_FunctionState = RET_OK;
	u8 Local_u8Counter = 0;
	if(Copy_QueuePointer != NULL)
	{
		for(Local_u8Counter = 0 ; Local_u8Counter < CIRCULAR_QUEUE_MAX_SIZE ; Local_u8Counter++)
		{
			Copy_QueuePointer -> CircularQueue_A32QueueArray[Local_u8Counter] = 0;
		}
		
		Copy_QueuePointer -> CircularQueue_s32Head = -1;
		Copy_QueuePointer -> CircularQueue_s32Tail = -1;
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}

/*********************************************************************************************/

ErrorState_t  CircularQueue_IsFullCheck(CircularQueueStruct * Copy_QueuePointer , QueueStateEnum * Copy_QueueState)
{
	ErrorState_t  Local_FunctionState = RET_OK;
	
	if((Copy_QueuePointer != NULL) && (Copy_QueueState != NULL))
	{
		*Copy_QueueState = Queue_NFULL;
		
		if(((Copy_QueuePointer -> CircularQueue_s32Head) == ((Copy_QueuePointer -> CircularQueue_s32Tail)+1)) || (((Copy_QueuePointer -> CircularQueue_s32Tail) == (CIRCULAR_QUEUE_MAX_SIZE - 1)) && ((Copy_QueuePointer -> CircularQueue_s32Head) == 0)))
		{
			*Copy_QueueState = Queue_FULL;
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}

/*********************************************************************************************/

ErrorState_t  CircularQueue_IsEmptyCheck(CircularQueueStruct * Copy_QueuePointer , QueueStateEnum * Copy_QueueState)
{
	ErrorState_t  Local_FunctionState = RET_OK;

	if((Copy_QueuePointer != NULL) && (Copy_QueueState != NULL))
	{
		*Copy_QueueState = Queue_NEmpty;
		
		if(((Copy_QueuePointer -> CircularQueue_s32Head) == -1) && ((Copy_QueuePointer -> CircularQueue_s32Tail) == -1))
		{
			*Copy_QueueState = Queue_Empty;
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	return Local_FunctionState;
}

/*********************************************************************************************/

ErrorState_t  CircularQueue_EnqueueData(CircularQueueStruct * Copy_QueuePointer , u32 Copy_u32EnteredData)
{
	ErrorState_t 	Local_FunctionState = RET_OK;
	QueueStateEnum	Local_QueueState;
	
	if(Copy_QueuePointer != NULL)
	{
		CircularQueue_IsFullCheck(Copy_QueuePointer , &Local_QueueState);
		
		if(Local_QueueState == Queue_FULL)
		{
			printf("Sorry, the queue is full, %d isn't added...\n", Copy_u32EnteredData);
			Local_FunctionState = RET_NOK;
		}
		
		else if(Local_QueueState == Queue_Empty)
		{
			Copy_QueuePointer -> CircularQueue_s32Head = 0;
			Copy_QueuePointer -> CircularQueue_s32Tail = 0;
			
			Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Tail] = Copy_u32EnteredData;
		}
		
		else if((Copy_QueuePointer -> CircularQueue_s32Tail) == (CIRCULAR_QUEUE_MAX_SIZE - 1))
		{
			Copy_QueuePointer -> CircularQueue_s32Tail = 0;
			Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Tail] = Copy_u32EnteredData;
		}
		
		else
		{
			Copy_QueuePointer -> CircularQueue_s32Tail++;
			Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Tail] = Copy_u32EnteredData;
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}

/*********************************************************************************************/

ErrorState_t  CircularQueue_DisplayData(CircularQueueStruct * Copy_QueuePointer)
{
	ErrorState_t    Local_FunctionState = RET_OK;
	QueueStateEnum  Local_QueueState;
	u8 Local_u8Counter = 0;
	
	if(Copy_QueuePointer != NULL)
	{
		CircularQueue_IsEmptyCheck(Copy_QueuePointer , &Local_QueueState);
		
		if(Local_QueueState == Queue_Empty)
		{
			printf("Sorry, there's no data to be displayed...\n");
			Local_FunctionState = RET_NOK;
		}
		
		else if(((Copy_QueuePointer -> CircularQueue_s32Head) == (CIRCULAR_QUEUE_MAX_SIZE - 1)) && ((Copy_QueuePointer -> CircularQueue_s32Tail) != (CIRCULAR_QUEUE_MAX_SIZE - 1)))
		{
			printf("The contents of the queue are : \n");
			printf("CircularQueue[%d] = %d\n", (CIRCULAR_QUEUE_MAX_SIZE - 1) , Copy_QueuePointer -> CircularQueue_A32QueueArray[(CIRCULAR_QUEUE_MAX_SIZE - 1)]);
			for(Local_u8Counter = 0 ; Local_u8Counter <= Copy_QueuePointer -> CircularQueue_s32Tail ; Local_u8Counter++)
			{
				printf("CircularQueue[%d] = %d\n", Local_u8Counter, Copy_QueuePointer -> CircularQueue_A32QueueArray[Local_u8Counter]);
			}
		}
		
		else
		{
			printf("The contents of the queue are : \n");
			for(Local_u8Counter = Copy_QueuePointer -> CircularQueue_s32Head ; Local_u8Counter <= Copy_QueuePointer -> CircularQueue_s32Tail ; Local_u8Counter++)
			{
				printf("CircularQueue[%d] = %d\n", Local_u8Counter, Copy_QueuePointer -> CircularQueue_A32QueueArray[Local_u8Counter]);
			}
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}

/*********************************************************************************************/

ErrorState_t  CircularQueue_DequeueData(CircularQueueStruct * Copy_QueuePointer , u32 * Copy_pu32ReturnedData)
{
	ErrorState_t    Local_FunctionState = RET_OK;
	QueueStateEnum  Local_QueueState;
	if((Copy_QueuePointer != NULL) && (Copy_pu32ReturnedData != NULL))
	{
		CircularQueue_IsEmptyCheck(Copy_QueuePointer , &Local_QueueState);
		
		if(Local_QueueState == Queue_Empty)
		{
			printf("Sorry, there's no data to be returned...\n");
			*Copy_pu32ReturnedData = CIRCULAR_QUEUE_DUMMYDATA;
			Local_FunctionState = RET_NOK;
		}
		
		/*Handeled in another condition...*/
		//else if(((Copy_QueuePointer -> CircularQueue_s32Head) == (CIRCULAR_QUEUE_MAX_SIZE - 1)) && ((Copy_QueuePointer -> CircularQueue_s32Tail) == (CIRCULAR_QUEUE_MAX_SIZE - 1)))
		//{
		//	*Copy_pu32ReturnedData = Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Head];
		//	Copy_QueuePointer -> CircularQueue_s32Head = -1;
		//	Copy_QueuePointer -> CircularQueue_s32Tail = -1;
		//}
		
		else if(((Copy_QueuePointer -> CircularQueue_s32Head) == (CIRCULAR_QUEUE_MAX_SIZE - 1)) && ((Copy_QueuePointer -> CircularQueue_s32Tail) != (CIRCULAR_QUEUE_MAX_SIZE - 1)))
		{
			*Copy_pu32ReturnedData = Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Head];
			Copy_QueuePointer -> CircularQueue_s32Head = 0;
		}
		
		else if((Copy_QueuePointer -> CircularQueue_s32Head) == (Copy_QueuePointer -> CircularQueue_s32Tail))
		{
			*Copy_pu32ReturnedData = Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Head];
			Copy_QueuePointer -> CircularQueue_s32Head = -1;
			Copy_QueuePointer -> CircularQueue_s32Tail = -1;
		}
		
		else
		{
			*Copy_pu32ReturnedData = Copy_QueuePointer -> CircularQueue_A32QueueArray[Copy_QueuePointer -> CircularQueue_s32Head];
			Copy_QueuePointer -> CircularQueue_s32Head++;
		}
	}
	else
	{
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}