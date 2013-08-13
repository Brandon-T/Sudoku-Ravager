#include <windows.h>
#include <iostream>
#include "PuzzleInfo.hpp"
#include "PuzzleAlgorithms.hpp"

using namespace std;

int Matrix[9][9];

void Solve(int PuzzleMatrix[9][9])
{
    FillUniqueCells(PuzzleMatrix);

    for (int I = 0; I < 9; ++I)
    {
        FillHiddenSingles(I, PuzzleMatrix, true);
    }

    for (int I = 0; I < 9; ++I)
    {
        FillHiddenSingles(I, PuzzleMatrix, false);
    }
}

void SolveAllPuzzles(std::string PuzzlePath)
{
    int Count = 0;
    std::vector<int> Puzzles;
    for (int I = 1; I < 51; ++I)
    {
        std::cout<<"\n\nPuzzle: "<<I<<"\n\n";
        ReadPuzzle(PuzzlePath + ToString(I) + ".hpp", ", ", Matrix);

        for (int I = 0; I < 10; ++I)
            Solve(Matrix);

        PrintPuzzle(Matrix);
        if (PuzzleSolved(Matrix)) ++Count;
        else Puzzles.push_back(I);
    }

    std::cout<<"Failed: "<<Puzzles<<std::endl;
    std::cout<<"Solved: "<<Count<<" Puzzles!"<<std::endl;
}

int main()
{
    CreatePuzzles("C:/Users/Brandon/Desktop/C++/SudokuSolver/Sudoku.txt", "C:/Users/Brandon/Desktop/C++/SudokuSolver/Puzzles/");
    SolveAllPuzzles("C:/Users/Brandon/Desktop/C++/SudokuSolver/Puzzles/");
    std::cin.get();
    return 0;

    /*ReadPuzzle("C:/Users/Brandon/Desktop/SudokuSolver/Puzzles/6.hpp", ", ", Matrix);

    for (int I = 0; I < 10 && !PuzzleSolved(Matrix); ++I)
    {
        Solve(Matrix);
    }

    PrintPuzzle(Matrix);

    //Move(0, 21);
    return 0;*/
}
