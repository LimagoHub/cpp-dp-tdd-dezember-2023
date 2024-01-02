//
// Created by JoachimWagner on 02.01.2024.
//

#pragma once


class Dependency {
public:
    virtual ~Dependency()=default;
    virtual int foo(int x) const =0;
};
