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
	o_n = 0;
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
				//onRight = false;
				operator1();
			}
			else if ((Y >= e.GetY() && Y <= (e.GetY() + SizeY_Cube))) {
				plusX *= -1;
				//onRight = true;
				operator2();
				//operator--();
			}
			else {
				if (o_n==1) {
					e.operator++();
					e.score++;
				}
				else if(o_n==0) {
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
			if (o_n==0) {
				o_n = 0;
				plusX = 10 * -1;
				plusY = 5;//��Ń����_���ɂ���
			}
			else if(o_n==1){
				o_n = 1;
				plusX = 10;
				plusY = 5;//��Ń����_���ɂ���
			}
			
		}
	}
	
}
void Object::MakeCircle() {
	DrawCircle(X, Y, CircleSize, 0xFFFFFF, TRUE);
}
bool Object::HitY()//�ǂɂԂ������Ƃ��ɔ���
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