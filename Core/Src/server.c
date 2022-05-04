/*
 * ServerMain.c
 *
 *  Created on: Mar 30, 2022
 *      Author: alexandru.borbilau
 */

#include "server.h"

StatusFlag srv_ReceiveMessage(UART_HandleTypeDef *uart, uint8_t *inData,
		size_t *inLen, uint32_t timeout) {
	/*
	 * Here we loop around until we receive a message from the server which we save in a buffer
	 * uart - the type of connection UART/USART
	 * inData - the buffer where we save the message we receive
	 * inLen - the variable where we store the length of the received message
	 * timeout - how much time we wait for each byte received, if this time passes it's going to result in a timeout
	 * Returns a StatusFlag type message OK/FAIL/ERROR/TIMEOUT
	 */
	while (HAL_OK != HAL_UART_Receive(uart, inData, 3, timeout)) {

	}
	*inLen = 3 + ((inData[2] << 8 | inData[1]) + 1);
	return (StatusFlag) HAL_UART_Receive(uart, &(inData[3]), *inLen - 3,
			timeout);
}

StatusFlag srv_TransmitMessage(UART_HandleTypeDef *uart, uint8_t *outData,
		size_t *outLen, uint8_t *inData, const size_t *inLen, uint32_t timeout) {
	/*
	 * Here we create the message we transmit back to the server
	 * uart - the type of connection UART/USART
	 * outData - the buffer that we use to store the message that we will transmit
	 * outLen - the variable where we store the length of the message we will transmit back to the server
	 * inData - the last message we received from the server, we use this in some functions where we want to store the payload we receive
	 * 			we also use this for the first byte which shows us the type of message we need to transmit back to the server
	 * timeout - how much time we wait for each byte to be transmitted, results in timeout if this passes
	 * Returns a StatusFlag type message OK/FAIL/ERROR/TIMEOUT
	 */
	size_t payloadLen = 0x00;
	MessageType msgTransmitType = (MessageType) inData[0];

	switch (msgTransmitType) {

	case RECEIVE_ROUND_START:
		gm_ReceiveStartRound(inData, inLen);
		msgTransmitType = SEND_OK; //Send back OK
		break;

	case RECEIVE_CONFIRM_HIT:
		gm_ReceiveConfirmHit(inData, inLen);
		msgTransmitType = SEND_OK;
		break;

	case RECEIVE_TARGETED:
		gm_ReceiveTargeted(inData, inLen);
		msgTransmitType = SEND_OK;
		break;

	case RECEIVE_MY_ID:
		gm_ReceiveMyID(inData, inLen);
		msgTransmitType = SEND_OK;
		break;

	case RECEIVE_GAME_END:
		gm_ReceiveGameEnd(inData, inLen);
		msgTransmitType = SEND_OK;
		break;

	case SEND_COORD:
		payloadLen = gm_SendCoord(&(outData[3]));
		//msgTransmitType = SEND_COORD; //Commented out because we don't need it, just here to understand
		break;

	case SEND_NAME:
		payloadLen = gm_SendName(&(outData[3]));
		//msgTransmitType = SEND_NAME;
		break;

	case SEND_BOARD:
		payloadLen = gm_SendBoard(&(outData[3]));
		//msgTransmitType = SEND_BOARD;
		break;

	default:
		msgTransmitType = SEND_NOT_OK; //If every case fails it means something went wrong
		break;
	}

	*outLen = 3 + payloadLen + 1;
	outData[0] = msgTransmitType;
	outData[1] = (uint8_t) payloadLen;
	outData[2] = (uint8_t) (payloadLen >> 8);
	outData[3 + payloadLen] = srv_GetCRC(outData, *outLen - 1);

	return (StatusFlag) HAL_UART_Transmit(uart, (uint8_t*) outData, *outLen,
			100);
}

uint8_t srv_GetCRC(uint8_t *data, size_t buffLen) {
	/*
	 * The function we use to check for the CRC (last number in the buffer) in the given buffer - 1
	 * data - the buffer we want to get the CRC for
	 * buffLen - the length of the buffer we give as argument
	 * Returns the CRC
	 */
	uint8_t crc = 0x00;
	for (uint8_t i = 0; i < buffLen; i++) {
		crc ^= data[i];
	}

	return crc;
}
