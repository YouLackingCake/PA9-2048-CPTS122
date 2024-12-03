#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class ScoringStrategy
{
public:
    virtual int calculateScore(int tileValue) const = 0;//function for calculating score

    virtual ~ScoringStrategy() = default;//destructor
};

class ClassicScoring : public ScoringStrategy
{
public:
    int calculateScore(int tileValue) const override
    {
        return tileValue;
    }
};

class MultiplierScoring : public ScoringStrategy
{
public:
    int calculateScore(int tileValue) const override
    {
        return tileValue * 2;
    }
};

class ExponentialScoring : public ScoringStrategy
{
public:
    int calculateScore(int tileValue) const override
    {
        return tileValue * tileValue;
    }
};