/*
Se Testea las HAL del protocolo CAN, enviando y recibiendo caracteres y 
bytes mediante el Canal 1 CAN de la placa Nucleo STM32F429zi
*/

#include "unity.h"
#include "CANdriver.h"
#include "mockSTM32.h"

/** Test
 *  1) Inicializa protocolo CAN
 *  2) Transmitr un byte
 *  3) Recibir un byte
 *  4) Transmitiendo caracteres
 *  5) Recibiendo caracteres
 */

CAN_HandleTypeDef hcan1 = 0xf;
CAN_TxHeaderTypeDef canTxHeader;
CAN_RxHeaderTypeDef canRxHeader;
uint8_t canBufferTx[128] = "";
uint8_t canBufferRx[128] = "";


// 1)Inicializa protocolo CAN
void test_InitCan()
{
    CANInit(&hcan1, &canTxHeader, &canRxHeader);

    TEST_ASSERT_EQUAL_UINT32(0, canTxHeader.DLC);
    TEST_ASSERT_EQUAL_UINT32(0, canRxHeader.DLC);
}

// 2) Transmitir un byte con protocolo CAN
void test_CanTransmittByte()
{
    uint8_t byte[] = "A";
    canTx(&hcan1, &canTxHeader, byte);
    TEST_ASSERT_EQUAL_STRING(byte, canBufferTx);
}

// 3) Recibir un byte con protocolo CAN
void test_CanReceiveByte()
{
    uint8_t BufferRx_temp[255];
    strcpy(canBufferRx, "b");
    canRx(&hcan1, &canRxHeader, BufferRx_temp);
    TEST_ASSERT_EQUAL_STRING(canBufferRx, BufferRx_temp);
}

// 4) Transmitiendo caracteres con protocolo CAN
void test_transmision_un_string()
{
    uint8_t string[] = "Conectando";
    canTx(&hcan1, &canTxHeader, string);
    TEST_ASSERT_EQUAL_STRING(string, canBufferTx);
}

// 5) Recibiendo caracteres con protocolo CAN
void test_recepcion_un_string()
{
    uint8_t BufferRx_temp[255];
    strcpy(canBufferRx, "Conectado");
    canRx(&hcan1, &canRxHeader, BufferRx_temp);
    TEST_ASSERT_EQUAL_STRING(canBufferRx, BufferRx_temp);
}