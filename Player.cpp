#include "Player.h"
#include "Object.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"
class Object ob;
Player::Player() {
	X = 0;
	Y = 0;
	score = 0;
}
int Player:: GetPX() {
	GetMousePoint(&X, &Y);
	X = 0;
	return X;
};
int Player::GetPY() {
	GetMousePoint(&X, &Y);
	if (Y > (SCREEN_SIZE_Y - ob.GetSizeY_Cube()))
	{
		Y = SCREEN_SIZE_Y - ob.GetSizeY_Cube();
	}
	if (Y < 0) {
		Y = 0;
	}
	return Y;
};
void Player::AddScore() {
	score++;
}
void Player::GetScore(int X,int Y) {
	DrawFormatString(X, Y, GetColor(255, 255, 255), "Player:%3d",score);
}