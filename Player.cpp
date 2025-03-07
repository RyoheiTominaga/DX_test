#include "Player.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"

//class Object *ob;
//前方宣言など見直しと勉強のし直しが必要
Player::Player() {
	X = 0;
	Y = 0;
	score = 0;
	PlateHit = false;
}
Player::~Player() {

}

void Player::PlateManegement() {
	//DrawFormatString(200, 300, GetColor(255, 255, 255), "playerOb:%3d,", ob->X);
	GetMousePoint(&X, &Y);
	X = 0;
	if (Y < 0)Y = 0;//移動制限(上)
	else if (Y > SCREEN_SIZE_Y-PLATE_SIZE_Y)Y = SCREEN_SIZE_Y-PLATE_SIZE_Y;//移動制限(下)
	int sizeX = PLATE_SIZE_X;
	int sizeY = PLATE_SIZE_Y;
		for (int i = 0;i < sizeX;++i) //描画
		{
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

void Player::GetScore(int X,int Y) {
	DrawFormatString(X, Y, GetColor(255, 255, 255), "Player:%3d",score);
}
int Player::GetY() {
	return Y;
}
void Player::Play() {
	PlateManegement();
}
void Player::ScoreAdd() {
	score++;
}
