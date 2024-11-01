#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>

// define bitboard as an alias for uint64_t, to represent a chessboard as a 64-bit integer
typedef uint64_t Bitboard;

extern Bitboard whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
extern Bitboard blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
extern Bitboard whitePieces, blackPieces, allPieces;
extern uint64_t whitePiecesArray[6], blackPiecesArray[6];
extern char pieceChars[12];

// initializes all piece positions for the start of the game
void init();

// prints the board in a human readable format (for debugging at the moment)
void printBitboard(Bitboard bitboard);

// returns a char for the printBitboard to represent each piece with a char
char getPieceChar(uint64_t position);

// counts the number of 1 bits in a bitboard (number of pieces of a bitboard)
int popCount(Bitboard bitboard);

// finds the index of the least significant 1 bit (needed for move gen)
int lsbIndex(Bitboard bitboard);

// sets a bit in a specific square of a bitboard
Bitboard setBit(int square);

// clears a bit in a specific square of a bitboard
Bitboard clearBit(Bitboard bitboard, int square);

#endif