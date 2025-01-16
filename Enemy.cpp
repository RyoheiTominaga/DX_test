#include "Enemy.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"
//#include"Object.h"
//class Object ob;
Enemy::Enemy() {
	X = 0;
	Y = 0;
	score = 0;
}
void Enemy::AddScore() {
	score++;
}
void Enemy::Move() {
	X = SCREEN_SIZE_X;
	//Y = ob.Y;
}
int Enemy::GetX() {
	return X;
}
int Enemy::GetY() {
	return Y;
}
void Enemy::GetScore(int X, int Y) {
	DrawFormatString(X, Y, GetColor(255, 255, 255), "Enemy:%3d", score);
}
//void Player::GetPlayerPoint() {
//	beforeX = X;
//	beforeY = Y;
//	GetMousePoint(&X, &Y);
//	X = 0;
//	if (Y > screen.Get_SizeY() - ob.SizeY) {
//		Y = screen.Get_SizeY() - ob.SizeY;
//	}
//	if (Y < 0) {
//		Y = 0;
//	}
//}