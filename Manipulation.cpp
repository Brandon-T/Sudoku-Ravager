#include "Manipulation.hpp"

std::string JoinStrings(std::vector<std::string> StringsToJoin, std::string Delimiter)
{
    std::string Result;
    for (std::size_t I = 0; I < StringsToJoin.size() - 1; ++I)
        Result += StringsToJoin[I] + Delimiter;

    Result += StringsToJoin[StringsToJoin.size() - 1];
    return Result;
}

std::vector<std::string> SplitString(std::string StringToSplit, std::string Delimiter)
{
    std::vector<std::string> Result;
    if (Delimiter == std::string())
    {
        for (std::string::iterator it = StringToSplit.begin(); it != StringToSplit.end(); ++it)
        {
            std::string Character = std::string();
            Character += *it;
            Result.push_back(Character);
        }
    }
    else
    {
        std::size_t Pos = StringToSplit.find_first_of(Delimiter);
        while(Pos != std::string::npos)
        {
            if(Pos > 0)
            {
                Result.push_back(StringToSplit.substr(0, Pos));
            }
            StringToSplit = StringToSplit.substr(Pos + 1);
            Pos = StringToSplit.find_first_of(Delimiter);
        }

        if(StringToSplit.length() > 0)
        {
            Result.push_back(StringToSplit);
        }
    }
    return Result;
}
