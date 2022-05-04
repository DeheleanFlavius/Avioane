/*
 * game.c
 *
 *  Created on: Apr 6, 2022
 *      Author: flavius.dehelean
 */
#include "game.h"
#include "logic.h"
#define M_RAND 10
#define M_COLOANA 10
#define M_MATRICE (M_RAND * M_COLOANA)
#define PLAYER_NAME "Flavius"
#define SIZE_CORD 2


uint8_t g_myId;
uint8_t g_PlayerIds [3];
uint8_t g_Bord[M_RAND][M_COLOANA] = {
		//0    1 	2	 3	  4	   5	6	 7	  8	   9
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //0
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //1
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //2
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //3
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //4
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //5
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //6
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //7
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }, //8
		{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }  //9

};

Player myself ={.id =5,.name=PLAYER_NAME,.playerState=STATUS_ALIVE,.score=0};
Player *playerPtr = &myself;


void gm_ReceiveMyID(const uint8_t *inData,  const size_t *inLen) {
	g_myId = inData[3];
}

size_t gm_SendName(uint8_t *payload) {
	memcpy(payload, playerPtr->name, sizeof(playerPtr->name));
	return sizeof(playerPtr->name);

}
size_t gm_SendBoard(uint8_t *payload) {
	logic();
	memcpy(payload, playerPtr->board, sizeof(playerPtr->board));
	return sizeof(playerPtr->board);

}
size_t gm_SendCoord(uint8_t *payload) {
	/*functie de trimitere a coordonatelor*/

	uint8_t Cordonates [3] = { 0x00, 0x02, 0x03 };
	memcpy(payload,Cordonates,sizeof(Cordonates));
	return sizeof(Cordonates);
}

void gm_ReceiveStartRound(const uint8_t *inData, const size_t *inLen){
}

void gm_ReceiveConfirmHit(const uint8_t *inData, const size_t *inLen){
}

void gm_ReceiveTargeted(const uint8_t *inData, const size_t *inLen){
}

void gm_ReceiveGameEnd(const uint8_t *inData, const size_t *inLen){
}


