#pragma once
#include <utility>

enum class TurfType
{
    Grass,
    Wood,
    Concrete
};

class FieldBase
{
    typedef std::pair<double, double> Dimension2D;

private:
    Dimension2D m_dimension;
    TurfType m_turfType;

public:
    virtual Dimension2D GetDimensions()
    {
        return m_dimension;
    }

    virtual TurfType GetTurfType()
    {
        return m_turfType;
    }

    virtual ~FieldBase() = 0;


};re