#pragma once
class Enemy {
public:
	Enemy();
	Enemy& operator++() {
		++score;
		return *this;
	}
	void circleSarch(int point);
	void Play();
	void GetScore(int X, int Y);
	bool PlateHit;
	int score;
	int GetY();
	void ScoreAdd();
private:
	int X;
	int Y;
	bool moveMode;
	void MakePlate();
	void MovePlate();

};
