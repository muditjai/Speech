#pragma once
#include <memory>
#include <vector>

class Shape
{
    int x, y;
public:
    Shape(int x, int y);
    Shape(const Shape& other) = default;
};

template <typename T>
class WeightMatrix
{
    std::vector<std::vector<T>> weights;
    std::vector<T> bias;
    Shape shape;

public:
    WeightMatrix(std::vector<std::vector<T>> weights, std::vector<T> bias, Shape s);
};

template <typename T>
class Activation
{
public:
    virtual std::vector<T> applyActivation(std::vector<T> input) = 0;
};

template <typename T>
class ReluActivation : Activation<T>
{
    virtual std::vector<T> applyActivation(std::vector<T> input) override
    {
        return std::vector<T>();
    }
};