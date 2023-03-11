/***************************************************/
/****** Author 	: Mayar Saber 				  ******/
/****** SWC		: DataStructures-Static Stack ******/
/****** Version : 01		  				  ******/
/***************************************************/

#ifndef		STATICSTACK_H
#define		STATICSTACK_H

#define		StaticStack_MaxSize		5
#define		StaticStack_DummyData	65535

typedef struct
{
	u32 StaticStack_Au32StackArray[StaticStack_MaxSize];
	u32 StaticStack_32Head;
	
}StaticStackStruct;


void StaticStack_voidInit       (StaticStackStruct * Copy_pStaticStackStruct);
u8   StaticStack_u8PushToStack  (StaticStackStruct * Copy_pStaticStackStruct , u32 Copy_u32Data);
u8   StaticStack_u8PopFromStack (StaticStackStruct * Copy_pStaticStackStruct , u32 * Copy_u32ReturnedData);


#endif

