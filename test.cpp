#include"DxLib.h"
#include"DxDataTypeWin.h"
#include"DxFunctionWin.h"
#include"DxCompileConfig.h"
#include"DxDataType.h"
#include"Object.h"
#include"Player.h"
#include"Define.h"
#include"Enemy.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	class Enemy e;
	class Object ob;
	class Player p;
	
	int flame = 0;//�t���[��
	SetDrawScreen(DX_SCREEN_BACK);//�`���𗠉�ʂ�
	ChangeWindowMode(TRUE);//��S��ʂɃZ�b�g
	SetGraphMode(SCREEN_SIZE_X,SCREEN_SIZE_Y, 32);//��ʃT�C�Y�w��
	SetOutApplicationLogValidFlag(FALSE);//log.txt�𐶐����Ȃ��悤�ɐݒ�
	if (DxLib_Init() == 1) { return -1; }//�������Ɏ��s���ɃG���[���͂����ďI��

	while (ProcessMessage() == 0) {
		ClearDrawScreen();//����ʂ�����
		
		ob.MakeCube(p.GetPX(), p.GetPY());
		ob.MakeCube(e.GetX(),e.GetY());
		ob.MakeCircle();
		ob.CircleMove();
		p.GetScore(200, 100);
		e.GetScore(800, 100);
		DrawFormatString(400, 300, GetColor(255, 255, 255), "E%3d,P%3d", e.score, p.score);
		DrawFormatString(600, 300, GetColor(255, 255, 255), "onright:", ob.onRight);
		ScreenFlip();//����ʂ�\��ʂɃR�s�[
		// WaitKey();
		flame++;
		

		//�N���X����������킯�킩��񂭂Ȃ���

	}
	DxLib_End();
	return 0;

}




