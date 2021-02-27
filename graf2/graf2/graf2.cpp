#include "iostream"
#include <stdio.h>
#include <string.h> 
#include <dos.h>
#include "windows.h"
#include <conio.h>
#include <malloc.h>
#include <cstdio>
#include <string>
using namespace std;
typedef int* pInt;
void ojidanie() {
	printf("\n \n Ojidanie najatia luboi klavishi. \n");
	getch();
	system("cls");
}
void menu() {
	cout << " 1. Matrix smejnosti. \n";
	cout << " 2. Matrix intsendetnoti. \n";
	cout << " 3. Spisok smejnosti. \nPunkt: ";
}
void vvodms(pInt*& ms, int& n, int& ms_s) {  // ввод матрица смежности
	int i, y, u=1,l=0,a;
	cout << "\n Vvedite kol-vo vershin: ";  //кол-во вершин
	scanf("%d", &n);
	ms = new pInt[n];							//динамическое выделение памяти для матрицы смежности
	for (i = 0; i < n; i++)
		ms[i] = new int[n];
	for (i = 0; i < n; i++) {
	error:										// точка возврата на случай ошибок ниже
		if (u == 1) {
			system("cls");
			cout << " razdelenie probelom !! znachenia (0,1,2) \n \n ";
			printf("   ");
			for (y = 1; y < n + 1; y++)
				printf("%d ", y);
			u = 0;
			printf("\n");
		}
		printf("X%d  ", i + 1);
		for (a = 0; a < n; a++)
			cin >> ms[i][a];
		for (a = 0; a < n; a++)
			if (ms[i][a] != 0 && ms[i][a] != 1 && ms[i][a] != 2) {
				printf("Nedopustimie znachenia! (0,1,2)");
				ojidanie();
				u = 1;
				goto error;
			}
		for (a = 0; a < n; a++)
			if (a == i && ms[i][a] != 2 && ms[i][a] == 1) {
				printf("Kogda petlea pishem 2."); // проверка правельности написания когда петля
				ojidanie();
				u = 1;
				goto error;
			}
	}
	ms_s = 1; // матрица введена
	printf("Matrix smejnosti vvedena.");
}
void vvodmi(pInt*& mi, int& n,int &e, int& mi_s) {
	int i, o, u = 1, a, j, l;
	int b[2];
	char s[10];
	cout << "\n Vvedite kol-vo vershin: ";  //кол-во вершин
	scanf("%d", &n);
	cout << "\n Vvedite kol-vo dug: ";  //кол-во вершин
	scanf("%d", &e);
	mi = new pInt[e];							//динамическое выделение памяти для матрицы смежности
	for (i = 0; i < e; i++)
		mi[i] = new int[2];
	for (i = 0; i < e; i++) {
	error2:										// точка возврата на случай ошибок ниже
		if (u == 1) {
			cout << " Nomer vershini iz kotoroi nachinaetsea duga - nomer vershini v kotoroi zakanchivaetsea. Primer: 1-2 \n \n";
			u = 0;
		}
		printf("e%-2d   ", i + 1);
		scanf("%s", s);
		o = strlen(s);
		l = 0;
		b[0] = 0; b[1] = 0;
		for (j = 0; j < o; j++) {
			if (s[j] != '-') {
				a = s[j] - '0';
				b[l] = b[l] * 10 + a;
			} else l++;
		}
		for (j = 0; j < i; j++) {	// проверка на существование дуги в одну и в другую сторону
			if (mi[j][0] == b[0] && mi[j][1] == b[1]) { 
				printf("Duga uje sushestvuet\n"); 
				goto error2; 
			}
			else if (mi[j][1] == b[0] && mi[j][0] == b[1]) {
				printf("Duga v obratnoe napravlenie uje sushestvuet "); 
				goto error2; 
			}
		}  
		if (b[0] > 0 && b[0] <= n && b[1] > 0 && b[1] <= n ) {    // проверка првельности значении для вершин
			mi[i][0] = b[0];
			mi[i][1] = b[1];
		}
		else if (o > 5 || o < 3 ) {   // проверка количества значений для вершин
			printf("Nedostatochno znachenii!");
			ojidanie();
			u = 1;
			goto error2;
		}
		else {
			printf("Nedopustimie znachenia! (1 - %d)", n);
			ojidanie();
			u = 1;
			goto error2;
		}
	}
	mi_s = 1; // матрица введена
	printf("Matrix intsendetnoti vvedena.");
}
void vvodss(pInt*& ss, int& n, int& ss_s) {
	int i, j, o, a, b = 0, u = 1, l;
	int hoh = 0, f = 0;
	char s[255];
	int mas[100] = { 0 };
	cout << "\n Vvedite kol-vo vershin: ";  //кол-во вершин
	cin >> n;
	ss = new pInt[n];							//динамическое выделение памяти 
	for (i = 0; i < n; i++) {
		hoh = 0;
	error3:										// точка возврата на случай ошибок ниже
		if (u == 1) {
			system("cls");
			cout << "primer: 1-  1,2,0 \n \n ";
			cout << "Spisok smejnosti.\n";
			u = 0;
		}
		printf("%-2d  - ",i+1);
		cin >> s;
		//scanf("%s", s);
		o = strlen(s);
		//k = 1;
		if (s[o - 1] != '0') {   // проверка чтобы в конце было 0
			cout << "V kontse ',0' !! ";
			u = 1;
			goto error3;
		}
		for (l = 0; l < o - 1; l++)
			if( s[l]== ',')
				hoh++;
		f = 0;
		for (j = 0; j < o - 1; j++) {
			if (s[j] != ',') {
				a = 0;
				a = s[j] - '0';
				b = b * 10 + a;
			}
			if (s[j] == ',') {
				mas[f]=b;
				b = 0;
				f++;
			}
		}
		for (j = 0; j < hoh; j++) 
			if (mas[j] < -1 || mas[j] > n) { // проверка првельности значении для вершин
				cout << "Nedopustimie znachenia! (1-" << n << ")";
				ojidanie();
				u = 1;
				for (l = 0; l < hoh; l++)
					mas[l] = 0;
				goto error3;
			}
		ss[i] = new int[hoh + 1];
		ss[i][0] = hoh + 1;
		for (j = 0; j < hoh; j++)
		ss[i][j+1] = mas[j];
	}
	ss_s = 1; // матрица введена
	cout << "\nSpisok smejnosti  vveden. ";
}
void vivodms(pInt* ms, int n, int ms_s) {   // вывод матрицы смежности
	if (ms_s = 1)						// проверка сущ матрицы  !!! дописать проверку
		system("cls");
	printf(" Matrix smejnosti. \n");
	printf("      ");
	for (int i = 1; i < n + 1; i++)
		printf("X%-2d  ", i);
	for (int i = 0; i < n; i++) {
		printf("\nX%-2d    ", i + 1);
		for (int j = 0; j < n; j++)
			printf("%d    ", ms[i][j]);
	}
	printf("\n \n \n \n \n");
}
void vivodmi(pInt* mi, int n, int e, int mi_s) {
	if (mi_s == 1) {
		system("cls");
		printf(" Matrix intsendetnoti. \n");
		printf("     ");
		for (int i = 1; i < n + 1; i++)
			printf("X%-2d  ", i);
		for (int i = 0; i < e; i++) {
			printf("\ne%-2d  ", i + 1);
			for (int j = 0; j < n; j++) {
				if (mi[i][1] == mi[i][0] && mi[i][1] == j + 1) printf(" 2   ");
				else if (mi[i][0] == j + 1 && mi[i][1] != mi[i][0]) printf("-1   ");
				else if (mi[i][1] == j + 1 && mi[i][1] != mi[i][0]) printf(" 1   ");
				else printf(" 0   ");
			}
		}
		printf("\n \n \n \n \n");
	}
}
void vivodss(pInt* ss, int n, int ss_s) {
	int i, j;
	system("cls");
	cout << "Spisok smejnosti. \n";
	for ( i = 0; i < n; i++) {
		printf("%-2d - ",i+1);
		for ( j = 1; j < ss[i][0]; j++)
			cout << ss[i][j] << ",";
		cout << "0\n";
	}
	cout << "\n \n \n \n \n";
}
void izmsvmi(pInt* ms, int n, int ms_s, pInt*& mi, int& e, int& mi_s) {
	int k=0;
	e = 0;
	if (ms_s != 1) goto fail;					
	for (int i = 0; i < n ; i++)					// подсчёт дуг
		for (int j = 0; j < n; j++) 
			if (ms[i][j] == 1 || ms[i][j] == 2) e++;
	mi = new pInt[e];							//динамическое выделение памяти 
	for (int i = 0; i < e; i++)
		mi[i] = new int[2];
	for (int i = 0; i < n; i++)				// преобразование из м.с. в м.и. 
		for (int j = 0; j < n; j++)
			if (ms[i][j] == 1 || ms[i][j] == 2) {
				mi[k][0] = i+1; 
				mi[k][1] = j+1;
					k++;
			}
	mi_s = 1;
fail: printf(" ");
}
void izmsvss(pInt* ms, int n, int ms_s, pInt*& ss, int& ss_s) {
	int p,i,j,k;
	ss = new pInt[n];
	for (i = 0; i < n; i++) {
		p = 0;
		k = 1;
		for (j = 0; j < n; j++)
			if (ms[i][j] == 1 || ms[i][j] == 2)
				p++;
		ss[i] = new int[p + 1];
		ss[i][0] = p + 1;
		for (j = 0; j < n; j++) {
			if (ms[i][j] == 1 || ms[i][j] == 2) {
				ss[i][k] = j + 1;
				k++;
			}
		}
	}
	ss_s = 1;
}
void izssvms(pInt* ss, int n, int ss_s, pInt*& ms, int& ms_s) {
	int i, j, y;
	ms = new pInt[n];							//динамическое выделение памяти для матрицы смежности
	for (i = 0; i < n; i++)
		ms[i] = new int[n];
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			ms[i][j] = 0;
			for (y = 1; y < ss[i][0]; y++) {
				if (ss[i][y] == j + 1 && j == i) {
					ms[i][j] = 2;
				}
				else if (ss[i][y] == j + 1) {
					ms[i][j] = 1;
				}
			}
		}
	}
	ms_s = 1;
}
void izmivss(pInt* mi, int n, int e, int mi_s, pInt*& ms, int& ms_s) {
	int i, j, a, b;
	ms = new pInt[n];							//динамическое выделение памяти для матрицы смежности
	for (i = 0; i < n; i++)
		ms[i] = new int[n];
	for (i = 0; i < n; i++)				// заполнение нулями
		for (j = 0; j < n; j++)
			ms[i][j] = 0;
	for (i = 0; i < e; i++) {		// заполнение 1 и 2
		a = mi[i][0] - 1;
		b = mi[i][1] - 1;
		if (a == b) {
			ms[a][b] = 2;
		}
		else ms[a][b] = 1;
	}
	ms_s = 1;
}
int main(int argc, char* argv[])
{
	pInt* ss = nullptr;
	pInt* ms = nullptr;
	pInt* mi = nullptr;
	int ms_s = 0, mi_s = 0, ss_s = 0; 
	int c, r, v, n = 0, e = 0, l;
	prog:
	cout << " 		VVedite nomer iz menu: \n";
	cout << " 1. Vvod. \n 2. Vivod. \n 3. Vihod iz programii. \nPunkt: ";
	scanf("%d", &c);
	system("cls");
	switch (c)
	{
	case 1: {
		printf(" Vvod: \n");
		menu();
		scanf("%d", &r);
		if (ms_s == 1) {				// если матрица введена спросить  ввести новую или перейти в меню
		err:
			printf("Dannie uje vvedeni.\n");
			printf("Vvesti drugie?  1 -da   0 -net.\n");
			scanf("%d", &l);
			switch (l)
			{
			case 1: {
				ms_s = 0;
				mi_s = 0;
				ss_s = 0;
			}
			case 0: {
				printf("Vihod v menu.\n");
				ojidanie();
				goto prog;
			}
			default: goto err;
			}
		}
		switch (r)
		{
		case 1: { // ввод матрица смежности
			vvodms(ms, n, ms_s);
			ojidanie();
			goto prog;
		}
		case 2: {
			vvodmi(mi, n, e, mi_s);
			izmivss(mi, n, e, mi_s, ms, ms_s);
			ojidanie();
			goto prog;  //
		}
		case 3: {
			vvodss(ss, n, ss_s);
			izssvms(ss, n, ss_s, ms, ms_s);
			ojidanie();
			goto prog;
		}
		default: goto prog;
		}
	}
	case 2: {
		printf(" Vivod: \n");
		menu();
		scanf("%d", &v);
		switch (v)
		{
		case 1: {					
			vivodms(ms, n, ms_s);
			ojidanie();
			goto prog;
		}
		case 2: {
			if (mi_s != 1) izmsvmi(ms, n, ms_s, mi, e, mi_s);
			vivodmi(mi, n, e, mi_s);
			ojidanie();
			goto prog;
		}
		case 3: {
			if (ss_s != 1) izmsvss(ms,  n,  ms_s, ss, ss_s);
			vivodss(ss, n, ss_s);
			ojidanie();
			goto prog;
		}
		default: goto prog;
		}
	case 3: {
		exit(32);
	}
	default: goto prog;
	}
	}
}