#pragma once
class Sets
{
	int *set; // - ������ � ���������� ���������
	int size; // - ������ �������
public:
	Sets(); // - ����������� �� ���������
	Sets(int n); // - �����������
	~Sets(); // - ����������
	void Create(int); // - �������� ������������ �� ����� �������
	void Merge(int, int);// - �����������
	int Search(int);// - �����
	void Print();
	int Get(int);
};

