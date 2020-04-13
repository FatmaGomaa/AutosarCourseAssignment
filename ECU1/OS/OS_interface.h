/******************************/
/* Author  : Moustafa Ghareeb */
/* Version : V1.0             */
/* Date    : 07-04-2020       */
/******************************/

#ifndef OS_INTERFACE_H_
#define OS_INTERFACE_H_

#define TASK_ACCESSIBLE	1
#define TASK_TERMINATED	0

#define OS_TICK_TIME_US	1000
#define Max_Task_number 2

void RTOS_START(void);
void RTOS_CreateTask(u32 Copy_first_delay, u32 Copy_periodicity, u8 Copy_Task_Status, void (*Copy_task_function)(void));
void RTOS_SuspendTask(u8 task_id);
void RTOS_ResumeTask(u8 task_id);

#endif /* RTOS_INTERFACE_H_ */
