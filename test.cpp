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
//����̉ۑ�Ƃ��Ă�
void Game();
void LookScore();
void Sircle();
void EnemyMove();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	
	
	int flame = 0;//�t���[��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_SIZE_X,SCREEN_SIZE_Y, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[���͂����ďI��
	start = true;
	while (ProcessMessage() == 0) {
		ClearDrawScreen();//����ʂ�����
		//�N���X�����̍ۂɋC��t����_�Ƃ��ẮA�����̎��͎����ł��Ƃ�������
		//����ł����ƒ��˕Ԃ����߂̔��v���C���[�ƃG�l�~�[���ꂼ��Ŏ�������ׂ��݂����Ȃ���
		//����̉ۑ�Ƃ��Ă͑S�̂̍\�z
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
		ScreenFlip();//����ʂ�\��ʂɃR�s�[
		// WaitKey();
		flame++;
		

		//�N���X����������킯�킩��񂭂Ȃ���

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





