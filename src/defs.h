#pragma once
#include <limits>
#include <string>
#include "thread.h"
#include "board.h"
#include "evaluation.h"
#include "search.h"

const int INF = std::numeric_limits<int>::max();

enum BoardSize { SMALL, LARGE };
enum Color { RED, BLUE, YELLOW, GREEN };
enum PieceType { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING };
enum Variants { REGULAR, ANTICHESS, NCHECK, ATOMIC };

typedef int Depth;
typedef int Value;

struct Move {
  int from;
  int to;
  int bit;
};

struct Entry {
  Value score;
  Depth depth;
  Flag flag;
};
