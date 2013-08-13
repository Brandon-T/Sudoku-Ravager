#ifndef PUZZLEALGORITHMS_HPP_INCLUDED
#define PUZZLEALGORITHMS_HPP_INCLUDED

#include <vector>
#include <algorithm>
#include "PuzzleInfo.hpp"

template<typename T>
inline bool InRange(T LowerBound, T UpperBound, T Value) {return ((LowerBound < Value) && (Value < UpperBound));}

void GetBoxIndex(int RowX, int RowY, int &BoxXIndex, int &BoxYIndex);

void GetCellPossibilities(int X, int Y, int PuzzleMatrix[9][9], std::vector<int> &CellInfo);

void FillUniqueCells(int PuzzleMatrix[9][9]);

void FillHiddenSingles(int Index, int PuzzleMatrix[9][9], bool Rows);

#endif // PUZZLEALGORITHMS_HPP_INCLUDED
