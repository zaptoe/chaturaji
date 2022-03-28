#include <array>
#include <vector>
#include "defs.h"

std::vector<Move> Board::generateValidMoves(Color color) {
  std::vector<Move> validMoves;
  std::vector<Move> moves;
  
  for (const int& validMove : moves) {
    if (Board::causesCheck(validMove)) {
      validMoves.push_back(validmove);
    }
  }
  return validMoves;
}

bool Board::inCheck() {
  int kingLocation = Board::kingLocations[Board::colorToMove];
  return Board::attacksSquare(kingLocation);
}

bool Board::attacksSquare(int fromSq) {
  int toSq = fromSq;
  int next = toSq + 17;
  if ((Board::pieces[next] == Piece::RED_PAWN || Board::pieces[next] == Piece::GREEN_PAWN)
    && Board::isOpponentsPiece(next)) {
    return true;
  }
  next = toSq + 15;
  if ((Board::pieces[next] == Piece::RED_PAWN || Board::pieces[next] == Piece::BLUE_PAWN)
    && Board::isOpponentsPiece(next)) {
    return true;
  }
  int next = toSq - 17;
  if ((Board::pieces[next] == Piece::YELLOW_PAWN || Board::pieces[next] == Piece::BLUE_PAWN)
    && Board::isOpponentsPiece(next)) {
    return true;
  }
  int next = toSq - 15;
  if ((Board::pieces[next] == Piece::YELLOW_PAWN || Board::pieces[next] == Piece::GREEN_PAWN)
    && Board::isOpponentsPiece(next)) {
    return true;
  }
  for (const int& knightOffset : Board::offsets[Piece::KNIGHT]) {
    if (knightOffset == 0) {
      break;
    }
    toSq = toSq + knightOffset;
    if (Board::pieces[toSq] == Piece::KNIGHT && Board::isOpponentsPiece(toSq)) {
        return true;
    }
  }
  for (const int& direction : Board::directions) {
    int increment = Rays::rayVector[direction];
    for (toSq = fromSq + increment; Board::board[toSq] == EMPTY; toSq += increment);
    if (Board::isOpponentsPiece(toSq, true, true, increment)) {
      return true;
    }
  }
  return false;
}

bool Board::isOpponentsPiece(int toSq, bool onlySliders = false, bool matchPieceType = false, int increment = 0) {
  if (onlySliders) {
    if (!matchPieceType) {
      if ((Board::board[toSq] != Board::colorToMove
        && Board::board[toSq] != Board::partners[Board::colorToMove])
        && (Board::pieces[toSq] == Piece::BISHOP
        || Board::pieces[toSq] == Piece::ROOK
        || Board::pieces[toSq] == Piece::QUEEN)) {
        return true;
      }
    } else if ((Board::board[toSq] != Board::colorToMove
      && Board::board[toSq] != Board::partners[Board::colorToMove])) {
      if ((abs(increment == 16)
        || abs(increment) == 1)
        && (Board::pieces[toSq] == Piece::ROOK
        || Board::pieces[toSq] == Piece::QUEEN)) {
        return true;
      } else if ((abs(increment == 15)
        || abs(increment) == 17)
        && (Board::pieces[toSq] == Piece::BISHOP
        || Board::pieces[toSq] == Piece::QUEEN)) {
        return true;
      }
    }
  } else if ((Board::board[toSq] != Board::colorToMove
    && Board::board[toSq] != Board::partners[Board::colorToMove])
    && Board::pieces[toSq] != EMPTY) {
    return true;
  }
  return false;
}
