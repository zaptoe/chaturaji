#pragma once

struct Entry {
  Value score;
  Depth depth;
  Flag flag;
};

class Evaluation
{
  public:
	Value getEval(Board board, Move lastMove);
};
