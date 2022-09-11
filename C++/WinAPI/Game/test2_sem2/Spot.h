#pragma once
#include <windows.h>
#include<iostream>
struct Spot
{
	int x_;
	int y_;
	std::string figure;	
	Spot() = default;
	Spot(int x, int y) :x_(x), y_(y) {
		figure = "nothing";
	}

};