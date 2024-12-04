/*****************************************************************
* Programmers: Carson CLary, Kyla Jones, Lily Hirano, Kendall Reid
* Class: CptS 122, Fall 2024;
* Programming Assignment: PA9
* Date:12/04/2024
* Description: 2048 game using SFML. Header for scoring classes
*****************************************************************/

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