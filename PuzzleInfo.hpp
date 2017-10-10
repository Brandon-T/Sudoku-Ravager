#ifndef PUZZLEINFO_HPP_INCLUDED
#define PUZZLEINFO_HPP_INCLUDED

#include <iostream>
#include <vector>
#include <fstream>
#include "Manipulation.hpp"

void Move(short X, short Y);

void FormatPuzzle(std::string FilePath, std::string CurrentDelimiter, std::string PuzzleDelimiter);

void CreatePuzzles(std::string ProjectEulerFile, std::string PuzzleFolder);

void ReadPuzzle(const std::string &FilePath, std::string Delimiter, int Matrix[9][9]);

bool PuzzleSolved(int PuzzleMatrix[9][9]);

void ReadRowLine(int Index, int PuzzleMatrix[9][9], int LineMatrix[9]);

void ReadColumnLine(int Index, int PuzzleMatrix[9][9], int LineMatrix[9]);

void ReadRow(int Index, int PuzzleMatrix[9][9], int RowMatrix[3][9]);

void ReadColumn(int Index, int PuzzleMatrix[9][9], int ColumnMatrix[9][3]);

void ReadBox(int RowIndex, int ColumnIndex, int PuzzleMatrix[9][9], int Box[3][3]);

void PrintPuzzle(int Matrix[9][9], char BlankCharacter = '.');

void PrintRowLine(int RowLine[9], char BlankCharacter = '.');

void PrintColumnLine(int ColumnLine[9], char BlankCharacter = '.');

void PrintRowMatrix(int RowMatrix[3][9], char BlankCharacter = '.');

void PrintColumnMatrix(int ColumnMatrix[9][3], char BlankCharacter = '.');

void PrintBoxMatrix(int BoxMatrix[3][3], char BlankCharacter = '.');

#endif // PUZZLEINFO_HPP_INCLUDED
