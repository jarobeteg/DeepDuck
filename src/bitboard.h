#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint> // for using uint64_t, a 64-bit integer type 

// define bitboard as an alias for uint64_t, to represent a chessboard as a 64-bit integer
typedef uint64_t Bitboard;

// declare bitboards for each piece type and color (using extern to avoid multiple definitions)
extern Bitboard whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
extern Bitboard blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
extern Bitboard whitePieces, blackPieces, allPieces;

// initializes all piece positions for the start of the game
void init();

// prints the board in a human readable format (for debugging at the moment)
void printBitboard(Bitboard bitboard);

// counts the number of 1 bits in a bitboard (number of pieces of a bitboard)
int popCount(Bitboard bitboard);

// finds the index of the least significant 1 bit (needed for move gen)
int lsbIndex(Bitboard bitboard);

// sets a bit in a specific square of a bitboard
Bitboard setBit(int square);

// clears a bit in a specific square of a bitboard
Bitboard clearBit(Bitboard bitboard, int square);

#endif