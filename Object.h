#pragma once
class Object {
public:
	Object();
	int o_n;//0or1
	void MakeCube(int X, int Y);//cube�̍쐬
	void MakeCircle();
	int GetSizeX_Cube();
	int GetSizeY_Cube();
	void CircleMove();//�{�[���̓���
	bool HitY();
	bool HitX();
	bool onRight;//�{�[�����E�ɂ��邩�Ȃ���
	bool on;//true:�~�܂� false ����
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
	int SizeX_Cube;//���˕Ԃ����߂̃L���[�u�̑傫��X
	int SizeY_Cube;//���˕Ԃ����߂̃L���[�u�̑傫��Y


private:
	int CircleSize;//�{�[���̑傫��
	int plusX;//�{�[���̉��ړ��̑��x
	int plusY;//�{�[���̏c�ړ��̑��x
	

public://�{�[���̍��W�֘A
	int X;//�{�[����X���W
	int Y;//�{�[����Y���W
	
};