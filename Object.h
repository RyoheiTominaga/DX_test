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
	bool onRight;//�{�[�����E�����֍s���Ȃ�true plusX�����Ȃ�true
	bool on;//false:�~�܂� true ����
private:
	int CircleSize;//�{�[���̑傫��
	int plusX;//�{�[���̉��ړ��̑��x
	int plusY;//�{�[���̏c�ړ��̑��x
	int startX;//�X�^�[�g�n�_
	int startY;//�X�^�[�g�n�_
	void CricleMoveChangeY();
	void MakeCircle();
	void MoveCircle();
public://�{�[���̍��W�֘A
	int X;//�{�[����X���W
	int Y;//�{�[����Y���W

};