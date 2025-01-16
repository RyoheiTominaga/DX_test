#pragma once
class Player {
public:
	Player();
	int GetPX();//X
	int GetPY();//Y
	void AddScore();
	void GetScore(int X,int Y);
private:
	int X;
	int Y;
	int score;//ƒ|ƒCƒ“ƒg
};