/*
 * game.h
 *
 *  Created on: Apr 6, 2022
 *      Author: alexandru.borbilau
 */

#ifndef INC_GAME_H_
#define INC_GAME_H_

#include "server.h"

typedef enum {
	//The state of the player. ALIVE = 1, DEAD = 0
	STATUS_DEAD = 0x00,
	STATUS_ALIVE = 0x01
} PlayerStatus;

typedef struct {
	//Player struct where we keep the info for the players in the game
	uint8_t id; //Player ID
	uint8_t name[20]; //Player name char 0-255
	PlayerStatus playerState; //Player status ALIVE = 1, DEAD = 0
	uint8_t score; //Player score
	uint8_t board[10][10];
} Player;

extern Player *playerPtr;

/*
 * Fill payload with our name and we say the length of the payload which should be 20 because (Name + empty until 20)
 * payload - the memory address for the place where our payload starts in the buffer Position[3]
 * 			 an array of uint8_t
 * Returns the size of the payload
 */
size_t gm_SendName(uint8_t *payload);

/*
 * Fill payload with our board, and the length of the payload which should be 100 (10 * 10)
 * payload - memory address for the place where our payload starts in the buffer Position[3]
 * 			 array of uint8_t
 * Returns the size of the payload
 */
size_t gm_SendBoard(uint8_t *payload);

/*
 * Fill payload with coordinates, and the length of the payload, payload is filled with
 * [0] - targeted player ID
 * [1] - targeted row Position 0-9
 * [2] - targeted column position 0-9
 * payload example: { 01, 04, 05 }
 * payload - memory address for the place where our payload starts in the buffer Position[3]
 * 			 array of uint8_t
 * Returns the size of the payload
 */
size_t gm_SendCoord(uint8_t *payload);

/*
 * Receives a message from the server with my ID
 * inData - array of uint8_t with the message received from the server, payload starts at Position[3]
 * inLen - length of the incoming message so we know how much to process in the buffer
 */
void gm_ReceiveMyID(const uint8_t *inData,  const size_t *inLen);

/*
 * Receives a message from the server with:
 * [3] + [4] - bytes for current round number (ushort)
 * [5] - P1 ID
 * [6-26] - P1 Name
 * [27] - P2 ID
 * [28 - 48] - P2 Name
 * [49] - P3 ID
 * [50 - 70] - P4 Name
 * ++ for other players
 * inData - Memory address for the incoming message, payload starts at Position[3]
 * 			Stores the IDs and status for the players found in the payload
 * inLen - length of the incoming message so we know how much to process in the buffer
 */
void gm_ReceiveStartRound(const uint8_t *inData, const size_t *inLen);

/*
 * Receives a message from the server with the result based on what our sent coordinates did. (HIT = 1/MISS = 0)
 * inData - Memory address from the incoming message, payload starts at Position[3]
 * inLen - length of the incoming message so we know how much to process in the buffer
 */
void gm_ReceiveConfirmHit(const uint8_t *inData, const size_t *inLen);

/*
 * Receives a message from the server when we're targeted by a player. (HIT = 1/MISS = 0)
 * inData - Memory address from the incoming message, payload starts at Position[3]
 * inLen - length of the incoming message so we know how much to process in the buffer
 */
void gm_ReceiveTargeted(const uint8_t *inData, const size_t *inLen);

/*
 * Receives a message from the server with the results for the end of the game
 * inData - Memory address from the incoming message, payload starts at Position[3]
 * inLen - length of the incoming message so we know how much to process in the buffer
 */
void gm_ReceiveMyID(const uint8_t *inData, const size_t *inLen);

void gm_ReceiveGameEnd(const uint8_t *inData, const size_t *inLen);

#endif /* INC_GAME_H_ */
