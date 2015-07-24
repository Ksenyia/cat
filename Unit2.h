//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
#include <Graphics.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TTimer *Timer1;
	TTimer *Timer2;
	TTimer *Timer3;
	TTimer *Timer4;
	TBitBtn *BitBtn1;
	TLabel *Label1;
	TTimer *Timer5;
	TImage *Image1;
	TTimer *Timer6;
	TTimer *Timer7;
	TTimer *Timer8;
	TTimer *Timer9;
	TLabel *Label2;
	TLabel *Label3;
	TBitBtn *BitBtn2;
	void __fastcall FormKeyPress(TObject *Sender, wchar_t &Key);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormKeyUp(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall Timer3Timer(TObject *Sender);
	void __fastcall Timer4Timer(TObject *Sender);
	void __fastcall BitBtn1Click(TObject *Sender);
	void __fastcall Timer7Timer(TObject *Sender);
	void __fastcall Timer8Timer(TObject *Sender);
	void __fastcall Timer5Timer(TObject *Sender);
	void __fastcall Timer6Timer(TObject *Sender);
	void __fastcall BitBtn2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
