#ifndef BITBOARD_H
#define BITBOARD_H

#include <cstdint>

#include "types.h"

// define bitboard as an alias for uint64_t, to represent a chessboard as a 64-bit integer
constexpr Bitboard FileA = 0x0101010101010101ULL;
constexpr Bitboard FileB = FileA << 1;
constexpr Bitboard FileC = FileA << 2;
constexpr Bitboard FileD = FileA << 3;
constexpr Bitboard FileE = FileA << 4;
constexpr Bitboard FileF = FileA << 5;
constexpr Bitboard FileG = FileA << 6;
constexpr Bitboard FileH = FileA << 7;

constexpr Bitboard Rank1 = 0xFF;
constexpr Bitboard Rank2 = Rank1 << (8 * 1);
constexpr Bitboard Rank3 = Rank1 << (8 * 2);
constexpr Bitboard Rank4 = Rank1 << (8 * 3);
constexpr Bitboard Rank5 = Rank1 << (8 * 4);
constexpr Bitboard Rank6 = Rank1 << (8 * 5);
constexpr Bitboard Rank7 = Rank1 << (8 * 6);
constexpr Bitboard Rank8 = Rank1 << (8 * 7);

// counts the number of 1 bits in a bitboard (number of pieces of a bitboard)
int popCount(Bitboard bitboard);

// finds the index of the least significant 1 bit (needed for move gen)
int lsbIndex(Bitboard bitboard);

// sets a bit in a specific square of a bitboard
Bitboard setBit(uint64_t square);

// clears a bit in a specific square of a bitboard
Bitboard clearBit(Bitboard bitboard, uint64_t square);

#endif