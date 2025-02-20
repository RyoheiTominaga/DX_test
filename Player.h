#pragma once


class Player {
	

public:
	Player();
	~Player();
	Player& operator++() {
		++score;
		return *this;
	}
	bool PlateHit;
	void ScoreAdd();
	void GetScore(int X,int Y);
	int GetY();
	int score;//ƒ|ƒCƒ“ƒg
	void Play();
private:
	int X;
	int Y;
	void PlateManegement();
};