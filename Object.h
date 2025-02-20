#pragma once
class Object {
public:
	Object();
	~Object();
	
	void Start();
	void CricleMoveChangeX();
	void CircleManager();
	void CircleAngle(int num);
	bool OnGet();
	bool onRight;//ボールが右向きへ行くならtrue plusXが正ならtrue
	bool on;//false:止まる true 動く
private:
	int CircleSize;//ボールの大きさ
	int plusX;//ボールの横移動の速度
	int plusY;//ボールの縦移動の速度
	int startX;//スタート地点
	int startY;//スタート地点
	void CricleMoveChangeY();
	void MakeCircle();
	void MoveCircle();
public://ボールの座標関連
	int X;//ボールのX座標
	int Y;//ボールのY座標

};