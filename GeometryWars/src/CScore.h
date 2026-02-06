#pragma once

#include"Component.h"

class CScore : public Component {
public:
	CScore();
	CScore(int scoreIn);
	int score = 100;

private:
};