#pragma once
class Enemy {
public:
	Enemy();
	void AddScore();
	void Move();
	int GetX();
	int GetY();
	void GetScore(int X, int Y);
private:
	int X;
	int Y;
	int score;
};