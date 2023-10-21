#define _CRT_SECURE_NO_WARNINGS
#define N 5000

#include <stdio.h>
#include <locale.h>

void mySkipLine() {
	char ch;
	while (scanf("%c", &ch))
		if (ch == '\n')
			break;	
}

int myBaceInput() {
	int inp;
	while (1)
	{	
		if (!scanf("%i", &inp) || inp <= 1 || inp > 36) {
			printf("\n!!����� ������ ���� 1 < n <= 36 � �������� �� ����!!\n��������� ���� ������� ���������: ");
			mySkipLine();
			continue;
		}
		break;
	}
	mySkipLine();
	return inp;
}

int myCharArrayInput(char str[], int strBuc, int endBuc, int strNum, int endNum) {
	int ln = 0;

	printf("������� �����: ");
	for (int i = 0; ; i++) {
		if (i >= N) {
			printf("\n!!��������� ���� ����� ������� �������!!");
			mySkipLine();
			return 0;
		}

		if (!scanf("%c", str + i)) {
			printf("\n!!����������� ����!!");
			mySkipLine();
			return 0;
		}

		if (str[i] == '\n')
			break;

		if (!((strBuc <= str[i] && str[i] <= endBuc) || (strNum <= str[i] && str[i] <= endNum))) {
			printf("\n!!����� ������ ������� �� ���� � ��������� ���� ����������� ��������!!");
			mySkipLine();
			return 0;
		}

		ln++;
	}

	return ln;
}

long long myPow(unsigned int num, unsigned int stepn) {
	long ret = 1;
	long retRem = 1;
	for (int i = 0; i < stepn; i++) {
		retRem = ret;
		ret *= num;
		if (ret < retRem)
			return -1;
	}
	return ret;
}

int main() {
	int bace, newBace, lnOld = 0, lnNew = 0;
	long long sumOld = 0, sumOldOldRem = 0;
	long long mnoch = 0, mnochRem = 0;
	char strtBuc = 'A', endBuc;
	char strtNum = '0', endNum;
	char str[N];

	setlocale(LC_ALL, "");

	printf("\n������� ������� ���������: ");
	bace = myBaceInput();
	endBuc = strtBuc + (bace - 11);
	endNum = strtNum - 1 + (bace <= 9 ? bace : 10);

	printf("������� ������� ������� ���������: ");
	newBace = myBaceInput();

	do {
		lnOld = myCharArrayInput(str, strtBuc, endBuc, strtNum, endNum);
	} while (!lnOld);

	for (int i = lnOld - 1; i >= 0; i--) {
		mnoch = myPow(bace, lnOld - i - 1);
		if (mnoch == -1) {
			printf("\n�� �������� �������� ������� ��������� ������� ����� �� �� ����������� ���������.");
			return 0;
		}

		sumOldOldRem = sumOld;
		if (strtBuc <= str[i] && str[i] <= endBuc)
			sumOld += (str[i] - (strtBuc - 10)) * mnoch;
		else
			sumOld += (str[i] - strtNum) * mnoch;

		if (sumOld < sumOldOldRem) {
			printf("\n�� �������� �������� ������� ��������� ������� ����� �� �� ����������� ���������.");
			return 0;
		}
	}

	if (sumOld == 0) {
		printf("\n0");
		return 0;
	}
	
	for (lnNew = 0; sumOld > 0; lnNew++)
	{
		if (lnNew >= N) {
			printf("\n��������� ���� ����� ������� �������. �� �������� �������� ������� ��������� ������� ����� �� �� ����������� �������.");
			return 0;
		}
		str[lnNew] = sumOld % newBace;
		sumOld /= newBace;
	}

	printf("\n");
	for (int i = lnNew - 1; i >= 0; i--) {
		if (str[i] < 10)
			printf("%i", str[i]);
		else
			printf("%c", 'A' - 10 + str[i]);
	}
}