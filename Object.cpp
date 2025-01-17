#include"Object.h"
#include"Player.h"
#include"Enemy.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"

class Player p;

class Enemy e;
Object::Object(){
	
	onRight = false;
	SizeX_Cube = 10;
	SizeY_Cube = 100;
	plusX = 10;
	plusY = 7;
	CircleSize = 10;
	X = 0;
	Y = 0;
	on = false;
}
void Object::MakeCube(int X,int Y) {
	 //&p;
	for (int i = 0;i <SizeX_Cube;++i) {
		for (int j = 0;j < SizeY_Cube;++j) {
			if (X == SCREEN_SIZE_X) {
				DrawPixel((X-SizeX_Cube) + i, Y + j, GetColor(255, 255, 255));
			}
			else {
				DrawPixel(X + i, Y + j, GetColor(255, 255, 255));
			}
		}
	}
}
int  Object::GetSizeX_Cube() {
	return SizeX_Cube;
};
int Object::GetSizeY_Cube() {
	return SizeY_Cube;
};
void Object::CircleMove() {
	
	if (!on) {
		X += plusX;
		Y += plusY;
		if (HitY()) {
			plusY *= -1;
		}
		if (HitX()) {
			if ((Y >= p.GetPY()) && (Y <= (p.GetPY() + SizeY_Cube))) {
				plusX *= -1;
				onRight = false;
			}
			else if ((Y >= e.GetY() && Y <= (e.GetY() + SizeY_Cube))) {
				plusX *= -1;
				onRight = true;
			}
			else {
				if (onRight) {
					e.operator++();
					e.score++;
				}
				else {
					p.operator++();
					p.score++;
				}
				on = true;
				DrawFormatString(20, 100, GetColor(255, 255, 255), "");
				plusX = 0;
				plusY = 0;
				X = (SCREEN_SIZE_X / 2);
				Y = (SCREEN_SIZE_Y / 2);
				
			}
		}
	}
	else if (on) {
		
		if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
			on = false;
			if (onRight) {
				plusX = 10 * -1;
				plusY = 5;//Œã‚Åƒ‰ƒ“ƒ_ƒ€‚É‚·‚é
			}
			else {
				plusX = 10;
				plusY = 5;//Œã‚Åƒ‰ƒ“ƒ_ƒ€‚É‚·‚é
			}
			
		}
	}
	
}
void Object::MakeCircle() {
	DrawCircle(X, Y, CircleSize, 0xFFFFFF, TRUE);
}
bool Object::HitY()//•Ç‚É‚Ô‚Â‚©‚Á‚½‚Æ‚«‚É”½ŽË
{
	if (Y < 0+CircleSize) {
		Y = CircleSize;
		return true;
	}
	else if (Y >SCREEN_SIZE_Y-CircleSize) {
		Y = SCREEN_SIZE_Y-CircleSize;

		return true;
	}
	else {
		return false;
	}
}
bool Object::HitX() {

	if (X < 0 + (SizeX_Cube + CircleSize) ) {
		X = (SizeX_Cube + CircleSize);
		return true;
	}
	else if (X > SCREEN_SIZE_X - (SizeX_Cube + CircleSize))
	{
		X = SCREEN_SIZE_X - (SizeX_Cube + CircleSize);
			return true;
	}
	else{
	
		return false;
	}
	//if (Y >= p.GetPY() && Y <= mouseY + ob.GetSizeY_Cube() && X<0 + ob.GetSizeX_Cube()) {
		//	//X = cubeSizeX;
		//	plusX *= -1;
		//}
}