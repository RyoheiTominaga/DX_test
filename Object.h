#pragma once
class Object {
public:
	Object();
	int o_n;//0or1
	void MakeCube(int X, int Y);//cubeの作成
	void MakeCircle();
	int GetSizeX_Cube();
	int GetSizeY_Cube();
	void CircleMove();//ボールの動き
	bool HitY();
	bool HitX();
	bool onRight;//ボールが右にあるかないか
	bool on;//true:止まる false 動く
	Object& operator++() {
		++o_n;
		return *this;
	}
	Object& operator--() {
		--o_n;
		return *this;
	}
	Object& operator2() {
		o_n = 0;
			return *this;
	}
	Object& operator1() {
		o_n = 1;
		return *this;
	}
	//~Object();
private:
	int SizeX_Cube;//跳ね返すためのキューブの大きさX
	int SizeY_Cube;//跳ね返すためのキューブの大きさY


private:
	int CircleSize;//ボールの大きさ
	int plusX;//ボールの横移動の速度
	int plusY;//ボールの縦移動の速度
	

public://ボールの座標関連
	int X;//ボールのX座標
	int Y;//ボールのY座標
	
};