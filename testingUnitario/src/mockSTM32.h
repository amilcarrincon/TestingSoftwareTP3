#ifndef _MOCKSTM32_H_
#define _MOCKSTM32_H_

#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <time.h>

typedef uint16_t CAN_HandleTypeDef;

extern uint8_t canBufferTx[128];
extern uint8_t canBufferRx[128];

typedef enum 
{
	HAL_OK = 0,
	HAL_FAULT
}hal_state;

typedef enum 
{
  DISABLE = 0U, 
  ENABLE = 1U
} FunctionalState;

typedef struct
{
  uint32_t StdId;    
  uint32_t ExtId;    
  uint32_t IDE;      
  uint32_t RTR;     
  uint32_t DLC;      
  uint32_t Timestamp; 
  uint32_t FilterMatchIndex; 

} CAN_RxHeaderTypeDef;


typedef struct
{
  uint32_t StdId;  
  uint32_t ExtId; 
  uint32_t IDE;  
  uint32_t RTR;      
  uint32_t DLC;      
  FunctionalState TransmitGlobalTime; 

} CAN_TxHeaderTypeDef;


void HAL_CAN_AddTxMessage(CAN_HandleTypeDef *hcan, CAN_TxHeaderTypeDef *pHeader, uint8_t aData[], uint32_t *pTxMailbox);

void HAL_CAN_GetRxMessage(CAN_HandleTypeDef *hcan, uint32_t RxFifo, CAN_RxHeaderTypeDef *pHeader, uint8_t aData[]);

#endif