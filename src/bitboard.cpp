#include "bitboard.h"
#include <cstdint>
#include <iostream>

Bitboard whitePawns, whiteKnights, whiteBishops, whiteRooks, whiteQueens, whiteKing;
Bitboard blackPawns, blackKnights, blackBishops, blackRooks, blackQueens, blackKing;
Bitboard whitePieces, blackPieces, allPieces;
uint64_t whitePiecesArray[6], blackPiecesArray[6];
char pieceChars[12];

void init() {
    whitePawns   = 0x000000000000FF00; // 0xFF00 -> binary: 0000 0000 0000 0000 0000 0000 1111 1111
    whiteKnights = 0x0000000000000042; // 0x42 -> binary: 0000 0000 0000 0000 0000 0000 0100 0010
    whiteBishops = 0x0000000000000024; // 0x24 -> binary: 0000 0000 0000 0000 0000 0000 0010 0100
    whiteRooks   = 0x0000000000000081; // 0x81 -> binary: 0000 0000 0000 0000 0000 0000 1000 0001
    whiteQueens  = 0x0000000000000008; // 0x08 -> binary: 0000 0000 0000 0000 0000 0000 0001 0000
    whiteKing    = 0x0000000000000010; // 0x10 -> binary: 0000 0000 0000 0000 0000 0000 0000 1000

    blackPawns   = 0x00FF000000000000; // 0xFF00 shifted up -> binary: 0000 0000 1111 1111 0000 0000 0000 0000
    blackKnights = 0x4200000000000000; // 0x42 shifted up -> binary: 0100 0010 0000 0000 0000 0000 0000 0000
    blackBishops = 0x2400000000000000; // 0x24 shifted up -> binary: 0010 0100 0000 0000 0000 0000 0000 0000
    blackRooks   = 0x8100000000000000; // 0x81 shifted up -> binary: 1000 0001 0000 0000 0000 0000 0000 0000
    blackQueens  = 0x0800000000000000; // 0x08 shifted up -> binary: 0001 0000 0000 0000 0000 0000 0000 0000
    blackKing    = 0x1000000000000000; // 0x10 shifter up -> binary: 0000 1000 0000 0000 0000 0000 0000 0000

    whitePieces = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
    blackPieces = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
    allPieces = whitePieces | blackPieces;

    whitePiecesArray[0] = whitePawns;
    whitePiecesArray[1] = whiteKnights;
    whitePiecesArray[2] = whiteBishops;
    whitePiecesArray[3] = whiteRooks;
    whitePiecesArray[4] = whiteQueens;
    whitePiecesArray[5] = whiteKing;

    blackPiecesArray[0] = blackPawns;
    blackPiecesArray[1] = blackKnights;
    blackPiecesArray[2] = blackBishops;
    blackPiecesArray[3] = blackRooks;
    blackPiecesArray[4] = blackQueens;
    blackPiecesArray[5] = blackKing;

    pieceChars[0] = 'P';
    pieceChars[1] = 'N';
    pieceChars[2] = 'B';
    pieceChars[3] = 'R';
    pieceChars[4] = 'Q';
    pieceChars[5] = 'K';

    pieceChars[6] = 'p';
    pieceChars[7] = 'n';
    pieceChars[8] = 'b';
    pieceChars[9] = 'r';
    pieceChars[10] = 'q';
    pieceChars[11] = 'k';
}

// counts the number of 1 bits in a bitboard using a built in function
int popCount(Bitboard bitboard ) {
    return __builtin_popcountll(bitboard);
}

// finds the index of the least significant 1 bit in a bitboard (needed for move gen)
int lsbIndex(Bitboard bitboard) {
    return __builtin_ctzll(bitboard);
}

// sets a bit at a specific square (0 to 63) on the bitboard
Bitboard setBit(int square) {
    return 1ULL << square;
}

// clears a bit at a specific square on a bitboard
Bitboard clearBit(Bitboard bitboard, int square) {
    return bitboard & ~(1ULL << square);
}

// prints a bitboard to the console in an 8x8 grid format for easier visualization
void printBitboard(Bitboard bitboard) {
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file < 8; ++file) {
            int square = rank * 8 + file;
            long long position = (bitboard & (1ULL << square));
            char piece = getPieceChar(position);
            std::cout << piece << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// returns the piece char for printBitboard
char getPieceChar(uint64_t position) {
    for (int i = 0; i < 6; i++) {
        if (whitePiecesArray[i] & position) return pieceChars[i];
        if (blackPiecesArray[i] & position) return pieceChars[i + 6];
    }
    return '0';
}