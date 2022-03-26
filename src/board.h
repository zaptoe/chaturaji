#pragma once
#include <array>

enum Color : int {
  RED    = 1,
  BLUE   = 2,
  YELLOW = 3,
  GREEN  = 4
};

struct Move {
  int from;
  int to;
  int bit;
};

const int EMPTY = 0;

enum Piece : int {
  RED_PAWN    = 1,
  BLUE_PAWN   = 2,
  YELLOW_PAWN = 3,
  GREEN_PAWN  = 4,
  KNIGHT      = 5,
  BISHOP      = 6,
  ROOK        = 7,
  QUEEN       = 8,
  KING        = 9
};

class Board {
  public:
    Color colorToMove = Color::RED;
    std::array<int, 256> pieces;
    std::array<int, 256> board;
    std::array<int, 5> partners = { 0, 3, 4, 1, 2 };
    std::array<int, 8> directions = {
      1, -1, 16, -16, 15, -15, 17, -17
    };
    std::array<std::array<int, 8>, 10> offsets = {{
      {  0,   0,   0,   0,  0,  0,  0,   0  },
      { -16, -17, -15,  0,  0,  0,  0,   0  },
      {  1,   17, -15,  0,  0,  0,  0,   0  },
      {  16,  17,  15,  0,  0,  0,  0,   0  },
      { -1,  -17,  15,  0,  0,  0,  0,   0  },
      { -18, -33, -31, -14, 18, 33, 31,  14 },
      { -17, -15,  17,  15, 0,  0,  0,   0  },
      { -16,  1,   16, -1,  0,  0,  0,   0  },
      { -17, -16, -15,  1,  17, 16, 15, -1  },
      { -17, -16, -15,  1,  17, 16, 15, -1  }
    }};
    std::array<int, 10> offsetsNum = {
      0, 3, 3, 3, 3, 8, 4, 4, 8, 8,
    };
    bool attacksSquare(int fromSq);
    bool isOpponentsPiece(int toSq, bool onlySliders = false);
};
