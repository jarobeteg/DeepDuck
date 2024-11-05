#include <cstdint>

#include "bitboard.h"

// counts the number of 1 bits in a bitboard using a built in function
int popCount(Bitboard bitboard ) {
    return __builtin_popcountll(bitboard);
}

// finds the index of the least significant 1 bit in a bitboard (needed for move gen)
int lsbIndex(Bitboard bitboard) {
    return __builtin_ctzll(bitboard);
}

// sets a bit at a specific square (0 to 63) on the bitboard
Bitboard setBit(uint64_t square) {
    return 1ULL << lsbIndex(square);
}

// clears a bit at a specific square on a bitboard
Bitboard clearBit(Bitboard bitboard, uint64_t square) {
    return bitboard & ~(1ULL << lsbIndex(square));
}