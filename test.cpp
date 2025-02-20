#pragma once

#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"
#include"Player.h"
#include"Define.h"
#include"Enemy.h"
#include"Object.h"
Enemy e;
Player p;
Object ob;
bool one = true;
bool test = false;
bool start=false;
//今後の課題としては
void Game();
void LookScore();
void Sircle();
void EnemyMove();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	
	int flame = 0;//フレーム
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(SCREEN_SIZE_X,SCREEN_SIZE_Y, 32);//画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE);//log.txtを生成しないように設定
	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーをはかせて終了
	start = true;
	while (ProcessMessage() == 0) {
		ClearDrawScreen();//裏画面を消す
		//クラス分けの際に気を付ける点としては、自分の事は自分でやるということ
		//今回でいうと跳ね返すための板もプレイヤーとエネミーそれぞれで持たせるべきみたいなかんじ
		//今後の課題としては全体の構築
		if (CheckHitKey(KEY_INPUT_SPACE) != 0) {
			ob.Start();
			if (!start) {
				if (ob.onRight) {
					p.ScoreAdd();
				}
				else {
					e.ScoreAdd();
				}
			}
			start = true;
		}
		DrawFormatString(400, 300, GetColor(255, 255, 255), "start:%3d,", start);
		Game();
		ScreenFlip();//裏画面を表画面にコピー
		// WaitKey();
		flame++;
		

		//クラス分けしたらわけわからんくなった

	}
	DxLib_End();
	return 0;

}
void Game() {
	
	e.Play();
	p.Play();
	ob.CircleManager();
	LookScore();
	Sircle();
	/*DrawFormatString(700, 300, GetColor(255, 255, 255), "X:%3d,", ob.X);
	DrawFormatString(800, 400, GetColor(255, 255, 255), "test:%3d,", test);*/
	if (ob.onRight && ob.X > (SCREEN_SIZE_X - 200)&&one) {
		EnemyMove();
		one = false;
	}
	if (!ob.on) {
		one = true;
		start = false;
	}
}
void LookScore() {
	p.GetScore(200, 100);
	e.GetScore(800, 100);
}
void Sircle() {
	if ((ob.X <= PLATE_SIZE_X) || (ob.X >= (SCREEN_SIZE_X - PLATE_SIZE_X))) {
		test = true;
		if (ob.onRight) {
			if (ob.Y > e.GetY() && ob.Y < (e.GetY() + PLATE_SIZE_Y)) {
				ob.CricleMoveChangeX();
				int num = rand() % 3;
				ob.CircleAngle(num);
				one = true;
			}
		}
		else if (!ob.onRight) {
			if (ob.Y > p.GetY() && ob.Y < (p.GetY() + PLATE_SIZE_Y)) {
				ob.CricleMoveChangeX();
				int num = rand() % 3;
				ob.CircleAngle(num);
			}
		}
	}
}
void EnemyMove() {
	int point = rand()%2+1;
	if (point ==1) {
		e.circleSarch((ob.Y + PLATE_SIZE_Y/2));
	}
	else {
		e.circleSarch((ob.Y-PLATE_SIZE_Y/2));
	}
	
}





