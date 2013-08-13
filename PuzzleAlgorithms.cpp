#include "PuzzleAlgorithms.hpp"

void GetBoxIndex(int RowX, int RowY, int &BoxXIndex, int &BoxYIndex)
{
    if (RowX < 3) {BoxXIndex = 0;}
    else if (InRange(2, 6, RowX)) {BoxXIndex = 1;}
    else if (InRange(5, 9, RowX)) {BoxXIndex = 2;}

    if (RowY < 3) {BoxYIndex = 0;}
    else if (InRange(2, 6, RowY)) {BoxYIndex = 1;}
    else if (InRange(5, 9, RowY)) {BoxYIndex = 2;}
}

void GetCellPossibilities(int X, int Y, int PuzzleMatrix[9][9], std::vector<int> &CellInfo)
{
    if (PuzzleMatrix[X][Y] != 0) return;

    std::vector<int> Data;
    int BoxMatrix[3][3] = {{0}};
    int RowLineMatrix[9] = {0};
    int ColumnLineMatrix[9] = {0};
    int RowBoxIndex = 0, ColumnBoxIndex = 0;
    GetBoxIndex(X, Y, RowBoxIndex, ColumnBoxIndex);

    ReadRowLine(Y, PuzzleMatrix, RowLineMatrix);
    ReadColumnLine(X, PuzzleMatrix, ColumnLineMatrix);
    ReadBox(RowBoxIndex, ColumnBoxIndex, PuzzleMatrix, BoxMatrix);

    for (int I = 0; I < 9; ++I)
    {
        if (BoxMatrix[I / 3][I % 3] != 0) Data.push_back(BoxMatrix[I / 3][I % 3]);
        if (RowLineMatrix[I] != 0) Data.push_back(RowLineMatrix[I]);
        if (ColumnLineMatrix[I] != 0) Data.push_back(ColumnLineMatrix[I]);
    }

    std::sort(Data.begin(), Data.end());
    Data.erase(std::unique(Data.begin(), Data.end()), Data.end());

    for (int I = 1, J = 0; I < 10; ++I, ++J)
    {
        if (std::find(Data.begin(), Data.end(), I) == Data.end())
        {
            CellInfo.push_back(I);
        }
    }
}

void FillUniqueCells(int PuzzleMatrix[9][9])
{
    for (int I = 0; I < 9; ++I)
    {
        for (int J = 0; J < 9; ++J)
        {
            std::vector<int> CellInfo;
            GetCellPossibilities(J, I, PuzzleMatrix, CellInfo);

            if (CellInfo.size() == 1)
            {
                PuzzleMatrix[J][I] = CellInfo[0];
            }
        }
    }
}

void FillHiddenSingles(int Index, int PuzzleMatrix[9][9], bool Rows)
{
    std::vector<int> Data;
    std::vector<std::vector<int>> Possibilities;

    for (int I = 0; I < 9; ++I)
    {
        Possibilities.push_back(std::vector<int>());
        if (Rows)
        {
            GetCellPossibilities(I, Index, PuzzleMatrix, Possibilities.back());
        }
        else
        {
            GetCellPossibilities(Index, I, PuzzleMatrix, Possibilities.back());
        }
        Data.insert(Data.end(), Possibilities.back().begin(), Possibilities.back().end());
    }

    for (auto it = Data.begin(); it != Data.end(); ++it)
    {
        if (std::count(Data.begin(), Data.end(), *it) == 1)
        {
            int I = 0;
            for (auto jt = Possibilities.begin(); jt != Possibilities.end(); ++jt, ++I)
            {
                if (std::find(jt->begin(), jt->end(), *it) != jt->end())
                {
                    if (Rows)
                    {
                        PuzzleMatrix[I][Index] = *it;
                    }
                    else
                    {
                        PuzzleMatrix[Index][I] = *it;
                    }
                }
            }
        }
    }
}
