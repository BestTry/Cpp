#pragma once
#include "pch.h"
#include <iostream>								// std::cout, cin
#include <string>
#include "Date.h"
#include <locale>								// std::locale, std::tolower
#include <utility>

using namespace std;

class MiscFunc
{
public:
	MiscFunc();
	~MiscFunc();

	string dispUserFctn(int);
	bool chkUserAffrmResps();
	char toLowerChar(char);




};

