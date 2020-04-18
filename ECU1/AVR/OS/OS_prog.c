/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 07-04-2020       */
/******************************/

#include "../LIB/STD_TYPES/STD_TYPES.h"
#include "../LIB/BIT_MATH/BIT_MATH.h"

#include "TIMER0.h"

#include "OS_interface.h"

typedef struct Task{
	u32	first_delay;
	u32	periodicity;
	u8 Task_Status;
	void (*Task_function) (void);
}Task;

void (*Taskfunction) (void);

Task RTOS_Tasks[Max_Task_number];

static void RTOS_Scheduler(void);

static u8 Task_number = 0;

void RTOS_START(void)
{
	TIMER0_Init();
	TIMER0_SetCallBack(RTOS_Scheduler);
	TIMER0_SetTimeus(OS_TICK_TIME_US);
}

void RTOS_SuspendTask(u8 task_id)
{
	RTOS_Tasks[task_id].Task_Status = TASK_TERMINATED;
}

void RTOS_ResumeTask(u8 task_id)
{
	RTOS_Tasks[task_id].Task_Status = TASK_ACCESSIBLE;
}

void RTOS_CreateTask(u32 Copy_first_delay, u32 Copy_periodicity, u8 Copy_Task_Status, void (*Copy_task_function)(void))
{
	RTOS_Tasks[Task_number].first_delay = Copy_first_delay;
	RTOS_Tasks[Task_number].periodicity = Copy_periodicity;
	RTOS_Tasks[Task_number].Task_Status = Copy_Task_Status;
	RTOS_Tasks[Task_number].Task_function = Copy_task_function;
	Task_number++;
}

static void RTOS_Scheduler()
{
	u8 task_order;
	for	(task_order = 0; task_order < Max_Task_number; task_order++)
	{
		if(RTOS_Tasks[task_order].Task_Status == TASK_ACCESSIBLE)
		{
			if(RTOS_Tasks[task_order].first_delay == 0)
			{
				RTOS_Tasks[task_order].Task_function();
				RTOS_Tasks[task_order].first_delay = RTOS_Tasks[task_order].periodicity;
			}
			else
			{}
			RTOS_Tasks[task_order].first_delay--;
		}
		else
		{}
	}
}
