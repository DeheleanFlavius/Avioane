/*
 * ServerFile.h
 *
 *  Created on: Mar 30, 2022
 *      Author: alexandru.borbilau
 */

#ifndef INC_SERVER_H_
#define INC_SERVER_H_

#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include "stm32g0xx_hal.h"
#include "game.h"
//#include "logic.h"

typedef enum {
	/*
	 * Status flags for when we want to return our functions. It's made to be similar with HAL_UART_RECEIVE/TRANSMIT returns
	 */
	STATUS_OK = 0x00,
	STATUS_ERROR = 0x01,
	STATUS_BUSY = 0x02,
	STATUS_TIMEOUT = 0x03
} StatusFlag;

typedef enum {
	/*
	 * Message types we know the server will be using with which we can communicate
	 */
	RECEIVE_MY_ID = 0x00,
	RECEIVE_ROUND_START = 0x01,
	RECEIVE_CONFIRM_HIT = 0x02,
	RECEIVE_TARGETED = 0x03,
	RECEIVE_GAME_END = 0x04,
	SEND_NAME = 0x05,
	SEND_BOARD = 0x06,
	SEND_COORD = 0x07,
	SEND_OK = 0xEE,
	SEND_NOT_OK = 0xFF
} MessageType;

/*
 * Here we loop around until we receive a message from the server which we save in a buffer
 * uart - the type of connection UART/USART
 * inData - the buffer where we save the message we receive
 * inLen - the variable where we store the length of the received message
 * timeout - how much time we wait for each byte received, if this time passes it's going to result in a timeout
 * Returns a StatusFlag type message OK/FAIL/ERROR/TIMEOUT
 */
StatusFlag srv_ReceiveMessage(UART_HandleTypeDef *uart, uint8_t *inData,
		size_t *inLen, uint32_t timeout);

/*
 * Here we create the message we transmit back to the server
 * uart - the type of connection UART/USART
 * outData - the buffer that we use to store the message that we will transmit
 * outLen - the variable where we store the length of the message we will transmit back to the server
 * inData - the last message we received from the server, we use this in some functions where we want to store the payload we receive
 * 			we also use this for the first byte which shows us the type of message we need to transmit back to the server
 * inLen - length of the message we received from the server
 * timeout - how much time we wait for each byte to be transmitted, results in timeout if this passes
 * Returns a StatusFlag type message OK/FAIL/ERROR/TIMEOUT
 */
StatusFlag srv_TransmitMessage(UART_HandleTypeDef *uart, uint8_t *outData,
		size_t *outLen, uint8_t *inData, const size_t *inLen, uint32_t timeout);

/*
 * The function we use to check for the CRC (last number in the buffer) in the given buffer - 1
 * data - the buffer we want to get the CRC for
 * buffLen - the length of the buffer we give as argument
 * Returns the CRC
 */
uint8_t srv_GetCRC(uint8_t *data, size_t bufflen);

#endif /* INC_SERVER_H_ */
