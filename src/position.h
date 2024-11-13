#ifndef POSITION_H
#define POSITION_H

#include <cstdint>

#include "bitboard.h"
#include "types.h"

// stores previous states of the chessboard to allow undo moves etc.
struct StateInfo {};

// this class stores information about the board representation
// pieces, who to move, castles info etc.
// this also make moves and undo moves etc.
class Position {
    public:
    Position();
    void init();
    void reset();
    void makeMove();
    void undoMove();
    void printBitboard(Bitboard bitboard);
    char getPieceChar(uint64_t position);

    private:
    Bitboard whitePawns, blackPawns;
    Bitboard whiteKnights, blackKnights;
    Bitboard whiteBishops, blackBishops;
    Bitboard whiteRooks, blackRooks;
    Bitboard whiteQueens, blackQueens;
    Bitboard whiteKing, blackKing;

    Bitboard whiteBB, blackBB, occupiedBB, emptyBB;
    Bitboard whiteBBArray[6], blackBBArray[6];
    char pieceChars[12];
};

#endif