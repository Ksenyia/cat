//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <iostream>
#include <math.h>
#include <string.h>
#include <string.h>




#include "Unit2.h"
  using namespace std;
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
int k=0,W;
String s;
Graphics::TBitmap  *kadr=new Graphics::TBitmap();
int num[3]={2,3,4};
int a[20][20]={
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,0,0,2,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,0,0,2,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
0,0,0,0,0,0,0,0,0,1,0,3,0,0,0,0,0,0,0,1,
0,0,0,0,2,0,0,0,0,0,0,3,0,0,0,0,0,0,0,1,
0,0,0,0,2,3,3,0,0,0,4,4,0,3,0,4,4,0,5,1,
1,1,3,3,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
0,0,1,1,1,0,1,0,0,0,0,0,0,1,0,0,0,0,0,0,
0,0,0,0,0,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
1,0,0,0,0,1,1,0,0,1,1,0,0,2,0,0,0,0,0,1,
1,0,0,1,1,0,0,1,1,1,1,0,0,2,0,0,0,0,0,1,
1,0,0,0,0,0,0,0,1,1,1,0,0,0,0,4,4,0,0,1,
1,0,1,1,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,1,
1,0,0,0,1,1,0,0,0,1,1,0,0,0,0,0,0,0,0,1,
1,1,1,0,0,1,1,0,0,0,0,0,0,0,0,1,1,0,0,1,
1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,};
class IntNumber
{
   //int field, kol_mn;
		TRect Pr_ris1;
		TRect *Pr;
 void  x_rsl(); //количество цифр числа
		int y_rsl();
int A[20][20];
	public:
		int w;
		int h;
		int x0;
		int y0;
		IntNumber(TRect fi) {Pr_ris1=fi;} //конструктор класса
		TRect ris(){return Pr_ris1;}	//получение значения числа
		bool peres(int a, int b);	//проверка на простоту
		int x_ris(); //количество цифр числа
		int y_ris(); //переворот числа



		void razlog(int &x0,int prost[]); //разложение числа на простые множители
		~IntNumber(){delete [] Pr;} // деструктор класса
};
void IntNumber::x_rsl()
{
	A[20][20]=a[20][20];
		for (int i = 0; i < 20; i++)
			 for (int j = 0; j < 20; j++)
              for (int i1 = 0; i1 < 3; i1++)
{
 if((num[i1]==A[i][j])&&((num[i1]==A[i+1][j])||(num[i1]==A[i][j+1]))&&(k==0)){
  x_rs[]=(i+1)*W;

 }


}
return x_rs[];
}
bool IntNumber::peres(int a, int b)
{
	if ((x_rsl>=a)&&(x_rsl<=a+w)&&(y_rsl>=b)&&(y_rsl<=b+h))
		return true;
	else
		return false;
}

int IntNumber::kol_numbers()
{
	int i=0;
	int s=field;
	while (s>0)
	{
		i++;
		s/=10;
	}
	return i;
}

int IntNumber::perevorot()
{
	int x=0;
	int s=field;
	while (s>=1)
	{
	  x=x*10+s % 10;
      s/=10;
	}
	return x;
}

//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{


}
//---------------------------------------------------------------------------
void __fastcall TForm2::Button1Click(TObject *Sender)
{
	   kadr -> LoadFromFile("APLANE.BMP");
	   kadr -> Transparent = true;
	   w = kadr -> Width;
	   h = kadr -> Height;
	   Pr_kadr = Bounds (0, 0, w, h);
	   x = - w;
	   y = 20;
	   fon -> Width = w;
	   fon -> Height =h;
	   Pr_fon = Bounds (x, y, w, h);
	   fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);

}
//---------------------------------------------------------------------------
void __fastcall TForm2::Timer1Timer(TObject *Sender)
{
	 Image1 -> Canvas -> CopyRect(Pr_fon, fon -> Canvas, Pr_kadr);
	 x++;
	 if (x > Image1 -> Width)
		x = -w;
	 Pr_fon = Bounds (x, y, w, h);
	 fon -> Canvas -> CopyRect(Pr_kadr, Image1 -> Canvas, Pr_fon);
     Image1 -> Canvas -> Draw(x, y, kadr);

}
//---------------------------------------------------------------------------
