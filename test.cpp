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
	
	int flame = 0;//フレーム
	SetDrawScreen(DX_SCREEN_BACK);//描画先を裏画面に
	ChangeWindowMode(TRUE);//非全画面にセット
	SetGraphMode(SCREEN_SIZE_X,SCREEN_SIZE_Y, 32);//画面サイズ指定
	SetOutApplicationLogValidFlag(FALSE);//log.txtを生成しないように設定
	if (DxLib_Init() == 1) { return -1; }//初期化に失敗時にエラーをはかせて終了

	while (ProcessMessage() == 0) {
		ClearDrawScreen();//裏画面を消す
		
		ob.MakeCube(p.GetPX(), p.GetPY());
		ob.MakeCube(e.GetX(),e.GetY());
		ob.MakeCircle();
		ob.CircleMove();
		p.GetScore(200, 100);
		e.GetScore(800, 100);
		DrawFormatString(400, 300, GetColor(255, 255, 255), "E%3d,P%3d", e.score, p.score);
		DrawFormatString(600, 300, GetColor(255, 255, 255), "onright:", ob.onRight);
		ScreenFlip();//裏画面を表画面にコピー
		// WaitKey();
		flame++;
		

		//クラス分けしたらわけわからんくなった

	}
	DxLib_End();
	return 0;

}




