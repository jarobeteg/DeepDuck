#ifndef TYPES_H
#define TYPES_H

#include <cstdint>

using Bitboard = uint64_t;

enum Color { 
    WHITE, 
    BLACK, 
    
    COLOR_NB = 2 
    };

enum Piece {
    W_PAWN, W_KNIGHT, W_BISHOP, W_ROOK, W_QUEEN, W_KING,
    B_PAWN, B_KNIGHT, B_BISHOP, B_ROOK, B_QUEEN, B_KING,
    PIECE_NONE,
    
    PIECE_NB = 12
};

enum Square : int {
    A1, B1, C1, D1, E1, F1, G1, H1,
    A2, B2, C2, D2, E2, F2, G2, H2,
    A3, B3, C3, D3, E3, F3, G3, H3,
    A4, B4, C4, D4, E4, F4, G4, H4,
    A5, B5, C5, D5, E5, F5, G5, H5,
    A6, B6, C6, D6, E6, F6, G6, H6,
    A7, B7, C7, D7, E7, F7, G7, H7,
    A8, B8, C8, D8, E8, F8, G8, H8,
    SQUARE_NONE,

    SQUARE_NB = 64
};

// a move is stored in 16 bits
// bit 0-5 is for the source square (0-63)
// bit 6-11 is for the destination square (0-63)
// bit 12-13 is for promotion piece type
// bit 14-15 is for special moves like promotion, en passant and castling
class Move {
    public:
    Move() = default;
    // construsctor to initialize from raw data
    constexpr explicit Move(std::uint16_t d) : 
        data(d) {}
    
    // constructor to initialize from source and destination squares
    constexpr Move(Square from, Square to, int promotionType = 0, int specialMove = 0) : 
        data((specialMove << 14) | (promotionType << 12) | (to << 6) | from) {}

    // getters
    constexpr Square from_sq() const { return Square(data & 0x3F); }
    constexpr Square to_sq() const { return Square((data >> 6) & 0x3F); }
    constexpr int promotion_type() const { return ((data >> 12) & 0x3); }
    constexpr int special_move() const { return ((data >> 14) & 0x3); }

    // raw data
    constexpr std::uint16_t raw() const { return data; }

    // comparison operators
    constexpr bool operator==(const Move& m) const { return data == m.data; }
    constexpr bool operator!=(const Move& m) const { return data != m.data; }

    protected:
    std::uint16_t data;
};

#endif