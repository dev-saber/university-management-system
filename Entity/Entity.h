#pragma once
#include <iostream>
using namespace std;
#include "../utils.cpp"

class Entity
{

    template <class V, class I>
    friend optional<V> find(vector<V>, I);
    template <class V, class I>
    friend bool deleteByID(vector<V>& vector, I id);

protected:
    int id;
    string label;

public:
    static int idd;
    Entity();
    Entity(string);
    Entity(Entity &);
    int getId();
    void setLabel(string);
    void display();
};
