#include "Enemy.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"
#include"Object.h"
//class Object ob;//‚È‚º‚©ƒGƒ‰[‚ª‹N‚«‚é
Enemy::Enemy() {
	X = 0;
	Y = 0;
	score = 0;
}
int Enemy::GetX() {
	X = SCREEN_SIZE_X;
	return X;
}
int Enemy::GetY() {
	//Y = ob.Y;
	return Y;
}
void Enemy::GetScore(int X, int Y) {
	DrawFormatString(X, Y, GetColor(255, 255, 255), "Enemy:%3d", score);
}
