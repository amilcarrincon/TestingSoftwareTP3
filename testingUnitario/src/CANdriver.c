#include "CANdriver.h"
#include "mockSTM32.h"

void CANInit(CAN_HandleTypeDef *pcan, CAN_TxHeaderTypeDef *TxHeader, CAN_RxHeaderTypeDef *RxHeader)
{
	TxHeader->DLC = 0;
	TxHeader->ExtId = 0;
	TxHeader->IDE = 0;
	TxHeader->RTR = 0;
	TxHeader->StdId = 0;
	TxHeader->TransmitGlobalTime = ENABLE;

	RxHeader->DLC = 0;
	TxHeader->ExtId = 0;
	TxHeader->IDE = 0;
	TxHeader->RTR = 0;
	TxHeader->StdId = 0;
	TxHeader->TransmitGlobalTime = ENABLE;
}

void canTx(CAN_HandleTypeDef *pcan, CAN_TxHeaderTypeDef *pHeader, uint8_t *message)
{
	uint32_t TxMailbox = 0;
	uint32_t *pTxMailbox = &TxMailbox;
	HAL_CAN_AddTxMessage(pcan, pHeader, message, pTxMailbox);
}

void canRx(CAN_HandleTypeDef *pcan, CAN_RxHeaderTypeDef *pHeader, uint8_t *buffer)
{
	uint32_t RxFifo = 0;
	HAL_CAN_GetRxMessage(pcan, RxFifo, pHeader, buffer);
}