#ifndef MANIPULATION_HPP_INCLUDED
#define MANIPULATION_HPP_INCLUDED

#include <vector>
#include <sstream>

template <typename T>
T ToNumber(const std::string &Text) {std::istringstream SS(Text); T Result; return (SS >> Result ? Result : 0);}

template<typename T>
inline std::string ToString(T Type){std::stringstream SS; SS<<Type; return SS.str();}

template<typename T>
std::ostream& operator << (std::ostream& Stream, const std::vector<T>& VectorToPrint)
{
    if (VectorToPrint.size() > 1)
    {
        for (std::size_t I = 0; I < VectorToPrint.size() - 1; ++I)
        {
            Stream<<VectorToPrint[I]<<", ";
        }
    }

    if (!VectorToPrint.empty())
    {
        Stream<<VectorToPrint.back();
    }
    return Stream;
}

std::string JoinStrings(std::vector<std::string> StringsToJoin, std::string Delimiter);

std::vector<std::string> SplitString(std::string StringToSplit, std::string Delimiter);

#endif // MANIPULATION_HPP_INCLUDED
