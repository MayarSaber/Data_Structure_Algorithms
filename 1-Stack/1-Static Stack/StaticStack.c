/***************************************************/
/****** Author 	: Mayar Saber 				  ******/
/****** SWC		: DataStructures-Static Stack ******/
/****** Version : 01		  				  ******/
/***************************************************/
#include	<stdio.h>

/*LIB*/
#include	"STD_TYPES.h"
#include	"BIT_MATH.h"

/*StaticStack*/
#include	"StaticStack.h"

void StaticStack_voidInit(StaticStackStruct * Copy_pStaticStackStruct)
{
	u8 Local_u8Counter;
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_pStaticStackStruct != NULL)
	{
		for(Local_u8Counter = 0 ; Local_u8Counter < StaticStack_MaxSize ; Local_u8Counter++)
		{
			Copy_pStaticStackStruct -> StaticStack_Au32StackArray[Local_u8Counter] = 0;
		}
		
		Copy_pStaticStackStruct -> StaticStack_32Head = 0;
	}
	
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
}

/*********************************************************************************************************/

u8 StaticStack_u8PushToStack(StaticStackStruct * Copy_pStaticStackStruct , u32 Copy_u32Data)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	
	if(Copy_pStaticStackStruct != NULL)
	{
		if((Copy_pStaticStackStruct -> StaticStack_32Head) < StaticStack_MaxSize)
		{
			Copy_pStaticStackStruct -> StaticStack_Au32StackArray[Copy_pStaticStackStruct -> StaticStack_32Head] = Copy_u32Data;
			Copy_pStaticStackStruct -> StaticStack_32Head++;
		}
		else
		{
			printf("Sorry, the stack is full and %d isn't added to the stack\n",Copy_u32Data);
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

/*********************************************************************************************************/

u8 StaticStack_u8PopFromStack (StaticStackStruct * Copy_pStaticStackStruct , u32 * Copy_u32ReturnedData)
{
	u8 Local_u8ErrorState = STD_TYPES_OK;
	if((Copy_pStaticStackStruct != NULL)&&(Copy_u32ReturnedData != NULL))
	{
		if((Copy_pStaticStackStruct -> StaticStack_32Head) > 0 )		//Stack isn't empty
		{
			Copy_pStaticStackStruct -> StaticStack_32Head--;
			*Copy_u32ReturnedData = Copy_pStaticStackStruct-> StaticStack_Au32StackArray[Copy_pStaticStackStruct -> StaticStack_32Head];
			Copy_pStaticStackStruct-> StaticStack_Au32StackArray[Copy_pStaticStackStruct -> StaticStack_32Head] = 0;
		}
		
		else
		{
			printf("The stack is empty\n");
			*Copy_u32ReturnedData = StaticStack_DummyData;
			Local_u8ErrorState = STD_TYPES_NOK;
		}
	}
	else
	{
		Local_u8ErrorState = STD_TYPES_NOK;
	}
	
	return Local_u8ErrorState;
}

