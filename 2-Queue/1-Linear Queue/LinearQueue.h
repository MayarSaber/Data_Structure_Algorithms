/***************************************************/
/****** Author 	: Mayar Saber 				  ******/
/****** SWC		: DataStructures-Linear Queue ******/
/****** Version : 01		  				  ******/
/***************************************************/

#ifndef		LINEAR_QUEUE_H
#define		LINEAR_QUEUE_H


#define		LINEAR_QUEUE_MAX_SIZE		5
#define		LinearQueue_DummyData		65536


typedef enum
{
	QUEUE_EMPTY,
	QUEUE_NEMPTY,
	QUEUE_FULL,
	QUEUE_NFULL
	
}LinearQueueState_t;


typedef struct
{
	s32 LinearQueue_s32Head;
	s32 LinearQueue_s32Tail;
	u32 LinearQueue_Au32QueueArray[LINEAR_QUEUE_MAX_SIZE];
	
}LinearQueueStruct;


void				LinearQueue_voidInit		(LinearQueueStruct * Copy_pLinearQueue);
LinearQueueState_t	LinearQueue_QueueFullCheck	(LinearQueueStruct * Copy_pLinearQueue);
LinearQueueState_t	LinearQueue_QueueEmptyCheck	(LinearQueueStruct * Copy_pLinearQueue);
ErrorState_t  		LinearQueue_EnqueueData		(LinearQueueStruct * Copy_pLinearQueue , u32 copy_u32InputData);
ErrorState_t  		LinearQueue_DisplayData		(LinearQueueStruct * Copy_pLinearQueue);
ErrorState_t		LinearQueue_DequeueData		(LinearQueueStruct * Copy_pLinearQueue , u32 * Copy_pu32ReturnedData);


#endif