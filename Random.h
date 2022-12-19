#pragma once
#ifndef RandomDefine
#define RandomDefine

class Random
{
private:
	int seed1, seed2;

public:
	//������ �������������
	void initialize(void)
	{
		seed1 = 3797;
		seed2 = 2119;
	}

	void init(int s1, int s2)
	{
		seed1 = s1;
		seed2 = s2;
	}
	//������ �������
	float randReal(void);
	unsigned nextintBetween(int low, int high);
};
#endif

