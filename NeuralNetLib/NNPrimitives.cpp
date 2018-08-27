#include "stdafx.h"
#include "NNPrimitives.h"

Shape::Shape(int x, int y): x{ x }, y{ y }
{

}

template <typename T>
WeightMatrix<T>::WeightMatrix(std::vector<std::vector<T>> weights, std::vector<T> bias, Shape s): weights{weights}, bias{bias}, shape{s}
{

}

template class WeightMatrix<int>;
template class WeightMatrix<float>;
template class WeightMatrix<double>;