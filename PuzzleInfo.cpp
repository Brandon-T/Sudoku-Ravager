#include "PuzzleInfo.hpp"

void Move(short X, short Y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{X, Y});
}

void FormatPuzzle(std::string FilePath, std::string CurrentDelimiter, std::string PuzzleDelimiter)
{
    std::string Line = std::string();
    std::vector<std::string> Lines;
    std::fstream File(FilePath.c_str(), std::ios::in);

    while(std::getline(File, Line))
    {
        if (Line.find(", ") == std::string::npos)
        {
            Lines.push_back(JoinStrings(SplitString(Line, CurrentDelimiter), PuzzleDelimiter) + "\n");
        }
    }
    File.close();

    if (!Lines.empty())
    {
        File.open(FilePath.c_str(), std::ios::out);
        for (auto it = Lines.begin(); it != Lines.end(); ++it)
        {
            File.write(it->c_str(), it->size());
        }
        File.close();
    }
}

void CreatePuzzles(std::string ProjectEulerFile, std::string PuzzleFolder)
{
    std::fstream File(ProjectEulerFile.c_str(), std::ios::in);
    if (File.is_open())
    {
        int I = 0, J = 10;
        std::string Line;
        std::vector<std::string> Lines;

        while (std::getline(File, Line))
        {
            if (--J == 0)
            {
                Lines.push_back(Line);
                std::fstream Output(PuzzleFolder + "/" + ToString(++I) + ".hpp", std::ios::out);
                if (Output.is_open())
                {
                    for (auto it = Lines.begin(); it != Lines.end(); ++it)
                        Output.write(it->c_str(), it->size());
                    Output.close();
                    FormatPuzzle(PuzzleFolder + "/" + ToString(I) + ".hpp", std::string(), ", ");
                }
                Lines.clear();
                J = 10;
            }
            else if (J != 9)
                Lines.push_back(Line + "\n");
        }
        File.close();
    }
}

void ReadPuzzle(const std::string &FilePath, std::string Delimiter, int Matrix[9][9])
{
    std::string Line = std::string();
    std::vector<std::vector<std::string>> Lines;
    std::fstream File(FilePath.c_str(), std::ios::in);

    while(std::getline(File, Line))
    {
        Lines.push_back(SplitString(Line, Delimiter));
    }
    File.close();

    for (int I = 0; I < 9; ++I)
    {
        for (int J = 0; J < 9; ++J)
        {
            Matrix[J][I] = ToNumber<int>(Lines[I][J]);
        }
    }
}

bool PuzzleSolved(int PuzzleMatrix[9][9])
{
    for (int I = 0; I < 9; ++I)
    {
        for (int J = 0; J < 9; ++J)
        {
            if (PuzzleMatrix[J][I] == 0)
                return false;
        }
    }
    return true;
}

void ReadRowLine(int Index, int PuzzleMatrix[9][9], int LineMatrix[9])
{
    for (int I = 0; I < 9; ++I)
    {
        LineMatrix[I] = PuzzleMatrix[I][Index];
    }
}

void ReadColumnLine(int Index, int PuzzleMatrix[9][9], int LineMatrix[9])
{
    for (int I = 0; I < 9; ++I)
    {
        LineMatrix[I] = PuzzleMatrix[Index][I];
    }
}

void ReadRow(int Index, int PuzzleMatrix[9][9], int RowMatrix[3][9])
{
    Index *= 3;

    for (int I = Index; I < Index + 3; ++I)
    {
        for (int J = 0; J < 9; ++J)
        {
            RowMatrix[J][I] = PuzzleMatrix[J][I];
        }
    }
}

void ReadColumn(int Index, int PuzzleMatrix[9][9], int ColumnMatrix[9][3])
{
    Index *= 3;

    for (int I = 0; I < 9; ++I)
    {
        for (int J = Index; J < Index + 3; ++J)
        {
            ColumnMatrix[J][I] = PuzzleMatrix[J][I];
        }
    }
}

void ReadBox(int RowIndex, int ColumnIndex, int PuzzleMatrix[9][9], int Box[3][3])
{
    RowIndex *= 3;
    ColumnIndex *= 3;

    for (int C = 0, I = ColumnIndex; I < ColumnIndex + 3; ++C, ++I)
    {
        for (int R = 0, J = RowIndex; J < RowIndex + 3; ++R, ++J)
        {
            Box[R][C] = PuzzleMatrix[J][I];
        }
    }
}

void PrintPuzzle(int Matrix[9][9], char BlankCharacter)
{
    for (int I = 0; I < 9; ++I)
    {
        for (int J = 0; J < 9; ++J)
        {
            if (J == 3 || J == 6)
            {
                std::cout<<"|  ";
            }

            if (Matrix[J][I] == 0)
                std::cout<<BlankCharacter<<"  ";
            else
                std::cout<<Matrix[J][I]<<"  ";
        }

        std::cout<<std::endl;
        if (I != 8)
        {
            std::cout<<"\t |\t     |\n";
        }

        if (I == 2 || I == 5)
        {
            std::cout<<"--------- ----------- ---------";
            std::cout<<std::endl;
            std::cout<<"\t |\t     |\n";
        }
    }
}

void PrintRowLine(int RowLine[9], char BlankCharacter)
{
    for (int I = 0; I < 9; ++I)
    {
        if (RowLine[I] == 0)
            std::cout<<BlankCharacter<<' ';
        else
            std::cout<<RowLine[I]<<' ';
    }
}

void PrintColumnLine(int ColumnLine[9], char BlankCharacter)
{
    for (int I = 0; I < 9; ++I)
    {
        if (ColumnLine[I] == 0)
            std::cout<<BlankCharacter<<std::endl;
        else
            std::cout<<ColumnLine[I]<<std::endl;
    }
}

void PrintRowMatrix(int RowMatrix[3][9], char BlankCharacter)
{
    for (int I = 0; I < 3; ++I)
    {
        for (int J = 0; J < 9; ++J)
        {
            if (RowMatrix[J][I] == 0)
                std::cout<<BlankCharacter<<" ";
            else
                std::cout<<RowMatrix[J][I]<<" ";
        }
        std::cout<<std::endl;
    }
}

void PrintColumnMatrix(int ColumnMatrix[9][3], char BlankCharacter)
{
    for (int I = 0; I < 9; ++I)
    {
        for (int J = 0; J < 3; ++J)
        {
            if (ColumnMatrix[J][I] == 0)
                std::cout<<BlankCharacter<<' ';
            else
                std::cout<<ColumnMatrix[J][I]<<' ';
        }
        std::cout<<std::endl;
    }
}

void PrintBoxMatrix(int BoxMatrix[3][3], char BlankCharacter)
{
    for (int I = 0; I < 3; ++I)
    {
        for (int J = 0; J < 3; ++J)
        {
            if (BoxMatrix[J][I] == 0)
                std::cout<<BlankCharacter<<' ';
            else
                std::cout<<BoxMatrix[J][I]<<' ';
        }
        std::cout<<std::endl;
    }
}
