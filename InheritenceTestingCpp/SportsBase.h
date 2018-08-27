#pragma once

class SportsBase
{
public:
    virtual int GetNumTeams() = 0;
    virtual Field GetField() = 0;
};