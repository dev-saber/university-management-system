#pragma once
#include <iostream>
using namespace std;
#include <algorithm>
#include <optional>

template <class V, class I>
optional<V> find(vector<V> vector, I id)
{
    auto it = find_if(vector.begin(), vector.end(), [id](const V &obj)
                      { return obj->id == id; });
    if (it != vector.end())
    {

        return *it;
    }
    else
    {
        return nullopt;
    }
};

template <class V, class I>
bool deleteByID(vector<V> &vector, I id)
{
    auto it = find_if(vector.begin(), vector.end(), [id](const V &obj)
                      { return obj->id == id; });
    if (it != vector.end())
    {

        vector.erase(it);
        return true;
    }
    return false;
};

string weekDays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
