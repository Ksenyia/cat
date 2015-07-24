//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "stdio.h"

int a[20][20];  // размер карты 20*20 клеток
int x=30,y=30;
int live=0;

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
 switch(Key)
 {
  case VK_LEFT :        /// кнопка влево
  if(a[x/30-1][y/30]!=1)
  {
  if(a[x/30-1][y/30]==2) { a[x/30-1][y/30]=0; live++; } // если нашли аптечко прибавилась жизнь
  x-=30;
  }
  break;

  case VK_UP :       /// кнопка вверх
  if(a[x/30][y/30-1]!=1)
  {
  if(a[x/30][y/30-1]==2) { a[x/30][y/30-1]=0; live++; } // если нашли аптечко прибавилась жизнь
  y-=30;
  }
  break;

  case VK_RIGHT :  /// кнопка вправо
  if(a[x/30+1][y/30]!=1)
  {
   if(a[x/30+1][y/30]==2) {a[x/30+1][y/30]=0; live++; }  // если нашли аптечко прибавилась жизнь
   x+=30;
  }
  break;

  case VK_DOWN :   /// кнопка вниз
  if(a[x/30][y/30+1]!=1)
  {
   if(a[x/30][y/30+1]==2) {a[x/30][y/30+1]=0; live++; } // если нашли аптечко прибавилась жизнь
   y+=30;
  }
  break;

 }
 FormPaint(Sender);
         
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormPaint(TObject *Sender)
{
   for(int i=0;i<20;i++)
   {
   for(int j=0;j<20;j++)
   {
    switch(a[i][j])
    {
      case 0 : Form1->Canvas->Brush->Color=clGreen; break;
      case 1 : Form1->Canvas->Brush->Color=clRed; break;
      case 2 : Form1->Canvas->Brush->Color=clYellow; break;
    }
    Form1->Canvas->Rectangle(i*30,j*30,i*30+30,j*30+30);  // 30 = размер клетки в пиксел€х
   }
   }
   Form1->Canvas->Ellipse(x,y,x+30,y+30);  // рисуем кругл€шок
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
  FILE *f;
  if(f=fopen((ExtractFilePath(Application->ExeName) + "map.txt").c_str(),"r"))
  {
   for(int i=0;i<20;i++)
   {
   for(int j=0;j<21;j++)  // на единицу больше из-за символа конца строки
   {
    char t=fgetc(f);
    switch(t)
    {
    case '0' : a[i][j]=0; break;  // 48 - код символа 0
    case '1' : a[i][j]=1; break;  // 49 - код символа 1
    case '2' : a[i][j]=2; break;  // 50 - код символа 2
    }
   }
   }
   }
}
//---------------------------------------------------------------------------
