#include"Object.h"
#include"Player.h"
#include"Enemy.h"
#include"Define.h"
#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"
Player player;
Object::Object(){
	
	
	plusX = 10;
	plusY = 7;
	CircleSize = 10;
	startX = SCREEN_SIZE_X / 2;
	startY = SCREEN_SIZE_Y / 2;
	X = startX;
	Y = startY;
	on = false;
	if (plusX < 0) {
		onRight = false;
	}
	else {
		onRight = true;
	}
	
}
Object::~Object() {

}
bool Object::OnGet() {

	return on;
}
void Object::Start() {
	on = true;
	
}
void Object::CricleMoveChangeX() {
	plusX *= -1;
	if (plusX < 0) {
		onRight = false;
	}
	else {
		onRight = true;
	}
}
void Object::CricleMoveChangeY() {
	plusY *= -1;
}
void Object::MoveCircle() {
	
	if (on && (X<0 || X>SCREEN_SIZE_X)){
		on=false;
		X = startX;
		Y = startY;
		plusY = 7;
	}

	if (on) {
		X += plusX;
		Y += plusY;
	}
	
	if (Y <= 0 || Y >= SCREEN_SIZE_Y) {
		CricleMoveChangeY();
	}

}

void Object::MakeCircle() {
	DrawCircle(X, Y, CircleSize, 0xFFFFFF, TRUE);
}
void Object::CircleManager() {
	MakeCircle();
	MoveCircle();
}
void Object:: CircleAngle(int num) {
	plusY += num;
}
