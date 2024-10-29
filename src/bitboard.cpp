#include "bitboard.h" //bitboard header file
#include <iostream> // for printing to the console

// define the global bitboard variables for piece positions
Bitboard whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
Bitboard blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
Bitboard whitePieces, blackPieces, allPieces;

// initializes all pieces to their starting positions on a chessboard
void init() {
    whitePawns   = 0x000000000000FF00; // 0xFF00 -> binary: 0000 0000 0000 0000 0000 0000 1111 1111
    whiteKnights = 0x0000000000000042; // 0x42 -> binary: 0000 0000 0000 0000 0000 0000 0100 0010
    whiteBishops = 0x0000000000000024; // 0x24 -> binary: 0000 0000 0000 0000 0000 0000 0010 0100
    whiteRooks   = 0x0000000000000081; // 0x81 -> binary: 0000 0000 0000 0000 0000 0000 1000 0001
    whiteQueens  = 0x0000000000000010; // 0x10 -> binary: 0000 0000 0000 0000 0000 0000 0001 0000
    whiteKing    = 0x0000000000000008; // 0x08 -> binary: 0000 0000 0000 0000 0000 0000 0000 1000

    blackPawns   = 0x00FF000000000000; // 0xFF00 shifted up -> binary: 0000 0000 1111 1111 0000 0000 0000 0000
    blackKnights = 0x4200000000000000; // 0x42 shifted up -> binary: 0100 0010 0000 0000 0000 0000 0000 0000
    blackBishops = 0x2400000000000000; // 0x24 shifted up -> binary: 0010 0100 0000 0000 0000 0000 0000 0000
    blackRooks   = 0x8100000000000000; // 0x81 shifted up -> binary: 1000 0001 0000 0000 0000 0000 0000 0000
    blackQueens  = 0x1000000000000000; // 0x10 shifted up -> binary: 0001 0000 0000 0000 0000 0000 0000 0000
    blackKing    = 0x0800000000000000; // 0x08 shifter up -> binary: 0000 1000 0000 0000 0000 0000 0000 0000

    //combine individual bitboards into white, black and all pieces bitboards
    whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
    blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
    allPieces = whitePieces | blackPieces;
}

// counts the number of 1 bits in a bitboard using a built in function
int popCount(Bitboard bitboard ) {
    return __builtin_popcountll(bitboard); // gcc/clang built-in function for counting bits in a 64-bit integer
}

// finds the index of the least significant 1 bit in a bitboard (needed for move gen)
int lsbIndex(Bitboard bitboard) {
    return __builtin_ctzll(bitboard); // gcc/clang function to count trailing zeros (lsb index)
}

// sets a bit at a specific square (0 to 63) on the bitboard
Bitboard setBit(int square) {
    return 1ULL << square; // shifts to the left by a 'square' positions to set that bit
}

// clears a bit at a specific square on a bitboard
Bitboard clearBit(Bitboard bitboard, int square) {
    return bitboard & ~(1ULL << square); // ANDs with a NOT mask to clear the specific bit
}

// prints a bitboard to the console in an 8x8 grid format for easier visualization
void printBitboard(Bitboard bitboard) {
    for (int rank = 7; rank >= 0; --rank) { // loop through ranks from top to bottom
        for (int file = 0; file < 8; ++file) { // loop through files from left to right
            int square = rank * 8 + file; // calculate the square index (0 to 63)
            std::cout << ((bitboard & (1ULL << square)) ? "1 " : "0 "); // print 1 for a set bit, 0 otherwise
        }
        std::cout << std::endl; // newline after each rank
    }
    std::cout << std::endl; // extra newline for separation
}