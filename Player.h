#pragma once
class Player {
public:
	Player();
	int GetPX();//X
	int GetPY();//Y
	Player& operator++() {
		++score;
		return *this;
	}
	void GetScore(int X,int Y);
	int score;//�|�C���g
private:
	int X;
	int Y;
	
};