#pragma once

#include <iostream>

struct Vertex
{
    float x;
    float y;
    float z;

    template <int N> static int get_array_len(Vertex (&arr)[N])
    {
        return N;
    }

    template <int N> static int get_array_size(Vertex (&arr)[N])
    {
        return sizeof(Vertex) * N;
    }

    template <typename T> static constexpr int num_members = sizeof(T) / sizeof(float);
};