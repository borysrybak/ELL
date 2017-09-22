//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Project:  Embedded Learning Library (ELL)
//  File:     DebugNetUtils.cpp (debugNet)
//  Authors:  Chuck Jacobs
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#include "VectorStats.h"

#include <algorithm>
//
// VectorStats class
//
template <typename ValueType>
VectorStats::VectorStats(const std::vector<ValueType>& vec)
{
    if (vec.size() == 0)
    {
        _valid = false;
        return;
    }

    // compute basic stats
    _min = static_cast<double>(vec[0]);
    _max = static_cast<double>(vec[0]);
    double sum = 0;
    for (auto x : vec)
    {
        double d = static_cast<double>(x);
        _min = std::min(_min, d);
        _max = std::max(_max, d);
        sum += d;
    }
    _mean = sum / vec.size();

    double sumDiffMeanSq = 0;
    for (auto x : vec)
    {
        auto diff = x - _mean;
        sumDiffMeanSq += diff * diff;
    }
    _variance = sumDiffMeanSq / vec.size();
    _stdDev = std::sqrt(_variance);
    _size = vec.size();
    _valid = true;
}

template <typename ValueType>
double VectorStats::Diff(const std::vector<ValueType>& vec1, const std::vector<ValueType>& vec2)
{
    ValueType error = 0;
    for (size_t i = 0, len1 = vec1.size(), len2 = vec2.size(); i < len1 || i < len2; i++)
    {
        if (i < len1 && i < len2)
        {
            ValueType e = vec1[i];
            ValueType f = vec2[i];
            if (e != f)
            {
                error += fabs(e - f);
            }
        }
        else if (i < len1)
        {
            ValueType e = vec1[i];
            error += fabs(e);
        }
        else if (i < len2)
        {
            ValueType f = vec2[i];
            error += fabs(f);
        }
    }
    return error;
}

template <typename ValueType>
std::vector<ValueType> Subtract(const std::vector<ValueType>& vec1, const std::vector<ValueType>& vec2)
{
    auto size1 = vec1.size();    
    auto size2 = vec2.size();
    assert(size1 == size2); // require this for now
    auto maxSize = std::max(size1, size2);
    std::vector<ValueType> result(maxSize);
    for(size_t index = 0; index < maxSize; ++index)
    {
        auto val1 = index < size1 ? vec1[index] : 0;
        auto val2 = index < size2 ? vec2[index] : 0;
        result[index] = val1 - val2;
    }

    return result;
}

template <typename ValueType>
std::vector<ValueType> Abs(const std::vector<ValueType>& vec)
{
    std::vector<ValueType> result(vec.size());
    for(size_t index = 0; index < vec.size(); ++index)
    {
        result[index] = std::fabs(vec[index]);
    }

    return result;
}