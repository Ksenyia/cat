object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 393
  ClientWidth = 643
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Image1: TImage
    Left = 24
    Top = 88
    Width = 322
    Height = 257
  end
  object Button1: TButton
    Left = 80
    Top = 16
    Width = 75
    Height = 25
    Caption = 'Button1'
    TabOrder = 0
    OnClick = Button1Click
  end
  object Memo1: TMemo
    Left = 352
    Top = 18
    Width = 249
    Height = 129
    Lines.Strings = (
      'Memo1')
    TabOrder = 1
  end
  object MediaPlayer1: TMediaPlayer
    Left = 382
    Top = 304
    Width = 253
    Height = 30
    AutoEnable = False
    DoubleBuffered = False
    Display = MediaPlayer1
    FileName = 'D:\mus\'#1052#1077#1083#1100#1085#1080#1094#1072' - '#1058#1077#1073#1103' '#1078#1076#1072#1083#1072' '#1103'.mp3'
    ParentDoubleBuffered = False
    TabOrder = 2
  end
  object Timer1: TTimer
    OnTimer = Timer1Timer
    Left = 576
    Top = 248
  end
end
