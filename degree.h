#pragma once
#ifndef DEGREE_H
#define DEGREE_H
#include <string>
#include <map>
using namespace std;

enum DegreeProgram
{
    SECURITY,
    NETWORK,
    SOFTWARE
};
static const std::string degreeProgramList[] = {"Security", "Network", "Software"};

DegreeProgram getPrgFromStr(string prgInStr)
{
    if (prgInStr == degreeProgramList[0])
    {
        return SECURITY;
    }
    else if (prgInStr == degreeProgramList[1])
    {
        return NETWORK;
    }
    else // If invalid program is given, this will fail. For simplicity, I did not implement error handling.
    {
        return SOFTWARE;
    }
}

#endif