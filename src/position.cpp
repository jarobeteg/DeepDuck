#include <iostream>

#include "position.h"
#include "bitboard.h"
#include "types.h"

Position::Position() {
    Position::init();
}

// initializes the starting position of a chess game
void Position::init() {
    whitePawns   = Rank2;
    whiteKnights = Rank1 & (FileB | FileG);
    whiteBishops = Rank1 & (FileC | FileF);
    whiteRooks   = Rank1 & (FileA | FileH);
    whiteQueens  = Rank1 & FileD;
    whiteKing    = Rank1 & FileE;

    blackPawns   = Rank7;
    blackKnights = Rank8 & (FileB | FileG);
    blackBishops = Rank8 & (FileC | FileF);
    blackRooks   = Rank8 & (FileA | FileH);
    blackQueens  = Rank8 & FileD;
    blackKing    = Rank8 & FileE;

    whiteBB = whitePawns | whiteKnights | whiteBishops | whiteRooks | whiteQueens | whiteKing;
    blackBB = blackPawns | blackKnights | blackBishops | blackRooks | blackQueens | blackKing;
    occupiedBB = whiteBB | blackBB;

    whiteBBArray[0] = whitePawns;
    whiteBBArray[1] = whiteKnights;
    whiteBBArray[2] = whiteBishops;
    whiteBBArray[3] = whiteRooks;
    whiteBBArray[4] = whiteQueens;
    whiteBBArray[5] = whiteKing;

    blackBBArray[0] = blackPawns;
    blackBBArray[1] = blackKnights;
    blackBBArray[2] = blackBishops;
    blackBBArray[3] = blackRooks;
    blackBBArray[4] = blackQueens;
    blackBBArray[5] = blackKing;

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
    
    Position::printBitboard(occupiedBB);
}

// prints a bitboard to the console in an 8x8 grid format for easier visualization
void Position::printBitboard(Bitboard bitboard) {
    for (int rank = 7; rank >= 0; --rank) {
        for (int file = 0; file < 8; ++file) {
            int square = rank * 8 + file;
            long long position = (bitboard & (1ULL << square));
            char piece = Position::getPieceChar(position);
            std::cout << piece << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// returns the piece char for printBitboard
char Position::getPieceChar(uint64_t position) {
    for (int i = 0; i < 6; i++) {
        if (whiteBBArray[i] & position) return pieceChars[i];
        if (blackBBArray[i] & position) return pieceChars[i + 6];
    }
    return '0';
}