/***************************************************/
/****** Author 	: Mayar Saber 				  ******/
/****** SWC		: DataStructures-Linear Queue ******/
/****** Version : 01		  				  ******/
/***************************************************/
#include	<stdio.h>

/*LIB*/
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"
#include	"ERROR_STATE.h"

/*Linear Queue*/
#include	"LinearQueue.h"

void LinearQueue_voidInit(LinearQueueStruct * Copy_pLinearQueue)
{
	u8 Local_u8Counter = 0;
	for(Local_u8Counter = 0 ; Local_u8Counter < LINEAR_QUEUE_MAX_SIZE ; Local_u8Counter++)
	{
		Copy_pLinearQueue -> LinearQueue_Au32QueueArray[Local_u8Counter] = 0;
	}
	
	Copy_pLinearQueue -> LinearQueue_s32Head = -1;
	Copy_pLinearQueue -> LinearQueue_s32Tail = -1;
}

/***********************************************************************************************************************/

LinearQueueState_t	LinearQueue_QueueFullCheck(LinearQueueStruct * Copy_pLinearQueue)
{
	LinearQueueState_t  LocalState = QUEUE_NFULL;
	
	if((Copy_pLinearQueue -> LinearQueue_s32Tail) == (LINEAR_QUEUE_MAX_SIZE - 1))
	{
		LocalState = QUEUE_FULL;
	}

	return LocalState;
}

/***********************************************************************************************************************/

LinearQueueState_t	LinearQueue_QueueEmptyCheck(LinearQueueStruct * Copy_pLinearQueue)
{
	LinearQueueState_t  LocalState = QUEUE_NEMPTY;
	
	if((((Copy_pLinearQueue -> LinearQueue_s32Head) == -1) && ((Copy_pLinearQueue -> LinearQueue_s32Tail) == -1)) || ((Copy_pLinearQueue -> LinearQueue_s32Head) > (Copy_pLinearQueue -> LinearQueue_s32Tail)))
	{
		LocalState = QUEUE_EMPTY;
	}
	
	return LocalState;
}

/***********************************************************************************************************************/

ErrorState_t   LinearQueue_EnqueueData(LinearQueueStruct * Copy_pLinearQueue , u32 copy_u32InputData)
{
	ErrorState_t  Local_Function_State = RET_OK;
	
	if(Copy_pLinearQueue != NULL)
	{
		/*Check if the queue is full*/
		if(LinearQueue_QueueFullCheck(Copy_pLinearQueue) == QUEUE_FULL)
		{
			printf("The queue is full, %d isn't added\n", copy_u32InputData);
			Local_Function_State = RET_NOK;
		}
		
		/*Check if the queue is empty*/
		else if(LinearQueue_QueueEmptyCheck(Copy_pLinearQueue) == QUEUE_EMPTY)
		{
			Copy_pLinearQueue -> LinearQueue_s32Head = 0;
			Copy_pLinearQueue -> LinearQueue_s32Tail = 0;
			Copy_pLinearQueue -> LinearQueue_Au32QueueArray[Copy_pLinearQueue -> LinearQueue_s32Tail] = copy_u32InputData;
		}
		
		/*If it's not empty neither full*/
		else
		{
			Copy_pLinearQueue -> LinearQueue_s32Tail++;
			Copy_pLinearQueue -> LinearQueue_Au32QueueArray[Copy_pLinearQueue -> LinearQueue_s32Tail] = copy_u32InputData;
		}
	}
	
	else
	{
		//printf("Error: a NULL address has been sent to this function...\n");
		Local_Function_State = RET_NULL_PTR;
	}
	
	return Local_Function_State;
}

/***********************************************************************************************************************/

ErrorState_t   LinearQueue_DisplayData(LinearQueueStruct * Copy_pLinearQueue)
{
	ErrorState_t  Local_Function_State = RET_OK;
		
	u8 Local_u8Counter = 0;
	
	if(Copy_pLinearQueue != NULL)
	{
		/*Check if the queue is empty -- To avoid displaying a garbage value*/
		if(LinearQueue_QueueEmptyCheck(Copy_pLinearQueue) == QUEUE_EMPTY)
		{
			printf("Sorry, there is no data to display\n");
			Local_Function_State = RET_NOK;
		}
		
		else
		{
			printf("the content of the queue is : \n");
			
			for(Local_u8Counter = Copy_pLinearQueue -> LinearQueue_s32Head ; Local_u8Counter <= Copy_pLinearQueue -> LinearQueue_s32Tail ; Local_u8Counter++)
			{
				printf("Queue[%d] = %d\n", Local_u8Counter , Copy_pLinearQueue -> LinearQueue_Au32QueueArray[Local_u8Counter]);
			}
		}
	}
	
	else
	{
		Local_Function_State = RET_NULL_PTR;
	}
	
	return Local_Function_State;
}

/********************************************************/

ErrorState_t	LinearQueue_DequeueData(LinearQueueStruct * Copy_pLinearQueue , u32 * Copy_pu32ReturnedData)
{
	ErrorState_t	Local_FunctionState = RET_OK;
	if((Copy_pLinearQueue != NULL) && (Copy_pu32ReturnedData != NULL))
	{
		*Copy_pu32ReturnedData = LinearQueue_DummyData;
		
		if(LinearQueue_QueueEmptyCheck(Copy_pLinearQueue) == QUEUE_EMPTY)
		{
			printf("There is no data to display\n");
			Local_FunctionState = RET_NOK;
		}
		else
		{
			*Copy_pu32ReturnedData = Copy_pLinearQueue -> LinearQueue_Au32QueueArray[Copy_pLinearQueue -> LinearQueue_s32Head];
			Copy_pLinearQueue -> LinearQueue_Au32QueueArray[Copy_pLinearQueue -> LinearQueue_s32Head] = 0;
			if((Copy_pLinearQueue -> LinearQueue_s32Head) < LINEAR_QUEUE_MAX_SIZE - 1)
			{
				Copy_pLinearQueue -> LinearQueue_s32Head++;
			}
			else if((Copy_pLinearQueue -> LinearQueue_s32Head) == LINEAR_QUEUE_MAX_SIZE - 1)
			{
					Copy_pLinearQueue -> LinearQueue_s32Head = -1;
					Copy_pLinearQueue -> LinearQueue_s32Tail = -1;
			}
			
		}
	}
	else
	{
		//printf("Error: a NULL address has been sent to this function...\n");
		Local_FunctionState = RET_NULL_PTR;
	}
	
	return Local_FunctionState;
}