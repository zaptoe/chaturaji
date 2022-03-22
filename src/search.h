#pragma once
#include <ctime>

enum Flag { UPPER, LOWER, EXACT };

class Search
{
  public:
    Search(Evaluation evaluation);
    Value go(std::time_t timeAllowed);
  private:
    Value search(Board board, Value alpha, Value beta, Depth depth, int ply = 1);
    Value qsearch(Board board, Value alpha, Value beta, int ply = 1);
};
