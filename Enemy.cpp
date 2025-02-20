#include "Enemy.h"
//#include"Object.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"

//class Object ob;//Ç»Ç∫Ç©ÉGÉâÅ[Ç™ãNÇ´ÇÈ
//Object ob1;
Enemy::Enemy() {
	X = SCREEN_SIZE_X;
	Y = 0;
	score = 0;
	moveMode = true;
	PlateHit = false;
}

void Enemy::GetScore(int X, int Y) {
	DrawFormatString(X, Y, GetColor(255, 255, 255), "Enemy:%3d", score);
	//DrawFormatString(500, 300, GetColor(255, 255, 255), "enemyOb:%3d,",ob1.X);
}
void Enemy::MakePlate() {
	int sizeX = PLATE_SIZE_X;
	int sizeY = PLATE_SIZE_Y;
	
	for (int i = 0;i < sizeX;++i) {
		for (int j = 0;j < sizeY;++j) {
			if (X == SCREEN_SIZE_X) {
				DrawPixel((X - sizeX) + i, Y + j, GetColor(255, 255, 255));
			}
			else {
				DrawPixel(X + i, Y + j, GetColor(255, 255, 255));
			}
		}
	}
}
void Enemy::MovePlate() {
	if (Y<=0) {
		moveMode = true;
	}
	else if (Y>=(SCREEN_SIZE_Y-PLATE_SIZE_Y)) {
		moveMode = false;
	}

	if (moveMode) {
		Y += 5;
	}
	else if (!moveMode) {
		Y -= 5;
	}
}
int Enemy::GetY() {
	return Y;
}
void Enemy::Play() {
	MakePlate();
	//MovePlate();
}
void Enemy::ScoreAdd() {
	score++;
}
void Enemy::circleSarch(int point) {
	Y = point;
}
