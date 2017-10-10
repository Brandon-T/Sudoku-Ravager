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

        if (PuzzleSolved(Matrix))
        {
            PrintPuzzle(Matrix);
            ++Count;
        }
        else
        {
            if (BruteForce(0, 0, Matrix))
            {
                PrintPuzzle(Matrix);
                ++Count;
            }
            else
            {
                PrintPuzzle(Matrix);
                Puzzles.push_back(I);
            }
        }
    }

    if (Puzzles.size())
    {
        std::cout<<"Failed: "<<Puzzles<<std::endl;
        std::cout<<"Solved: "<<Count<<" Puzzles!"<<std::endl;
    }
    else
    {
        std::cout<<"Solved: "<<Count<<" Puzzles!"<<std::endl;
    }
}

int main()
{
    CreatePuzzles("/users/brandonanthony/Desktop/Sudoku/Sudoku/Sudoku.txt", "/users/brandonanthony/Desktop/Sudoku/Sudoku/Puzzles/");
    SolveAllPuzzles("/users/brandonanthony/Desktop/Sudoku/Sudoku/Puzzles/");
    std::cin.get();
    return 0;

//    ReadPuzzle("/users/brandonanthony/Desktop/Sudoku/Sudoku/Puzzles/6.hpp", ", ", Matrix);
//
//    for (int I = 0; I < 10 && !PuzzleSolved(Matrix); ++I)
//    {
//        Solve(Matrix);
//    }
//
//    if (!PuzzleSolved(Matrix))
//    {
//        BruteForce(0, 0, Matrix);
//    }
//
//    PrintPuzzle(Matrix);
//    return 0;
}
