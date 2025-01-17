#pragma once
class Enemy {
public:
	Enemy();
	Enemy& operator++() {
		++score;
		return *this;
	}
	int GetX();
	int GetY();
	void GetScore(int X, int Y);
	int score;
private:
	int X;
	int Y;
	
};