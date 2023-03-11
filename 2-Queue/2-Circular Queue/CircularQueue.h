/*****************************************************/
/****** Author 	: Mayar Saber 				    ******/
/****** SWC		: DataStructures-Circular Queue ******/
/****** Version : 01		  				    ******/
/*****************************************************/

#ifndef		_CIRCULARQUEUE_H
#define		_CIRCULARQUEUE_H

#define		CIRCULAR_QUEUE_MAX_SIZE		5
#define		CIRCULAR_QUEUE_DUMMYDATA	65536

typedef  struct
{
	s32  CircularQueue_s32Head;
	s32  CircularQueue_s32Tail;
	u32  CircularQueue_A32QueueArray[CIRCULAR_QUEUE_MAX_SIZE];
	
}CircularQueueStruct;


typedef  enum
{
	Queue_FULL,
	Queue_NFULL,
	Queue_Empty,
	Queue_NEmpty
	
}QueueStateEnum;

/*Helper Functions - Private Functions - Local Functions*/
static	ErrorState_t  	 CircularQueue_voidInit		(CircularQueueStruct * Copy_QueuePointer);
static	ErrorState_t     CircularQueue_IsFullCheck  (CircularQueueStruct * Copy_QueuePointer , QueueStateEnum * Copy_QueueState);

ErrorState_t  	 CircularQueue_IsEmptyCheck (CircularQueueStruct * Copy_QueuePointer , QueueStateEnum * Copy_QueueState);
ErrorState_t     CircularQueue_EnqueueData  (CircularQueueStruct * Copy_QueuePointer , u32 Copy_u32EnteredData);
ErrorState_t  	 CircularQueue_DisplayData  (CircularQueueStruct * Copy_QueuePointer);
ErrorState_t     CircularQueue_DequeueData  (CircularQueueStruct * Copy_QueuePointer , u32 * Copy_pu32ReturnedData);

#endif