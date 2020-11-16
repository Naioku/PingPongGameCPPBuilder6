object Form2: TForm2
  Left = 596
  Top = 221
  BorderStyle = bsToolWindow
  Caption = 'Game Rules'
  ClientHeight = 708
  ClientWidth = 762
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'MS Sans Serif'
  Font.Style = []
  OldCreateOrder = False
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object background: TShape
    Left = 0
    Top = 0
    Width = 762
    Height = 708
    Align = alClient
    Brush.Color = clGray
  end
  object Label1: TLabel
    Left = 312
    Top = 72
    Width = 136
    Height = 27
    Caption = 'Game Rules'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label2: TLabel
    Left = 56
    Top = 120
    Width = 136
    Height = 27
    Caption = 'Game Rules'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label3: TLabel
    Left = 88
    Top = 504
    Width = 231
    Height = 27
    Caption = 'Left Player controls:'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label4: TLabel
    Left = 384
    Top = 504
    Width = 165
    Height = 27
    Caption = 'W -> move up,'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label5: TLabel
    Left = 88
    Top = 568
    Width = 243
    Height = 27
    Caption = 'Right Player controls:'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label6: TLabel
    Left = 384
    Top = 568
    Width = 246
    Height = 27
    Caption = 'Up arrow -> move up,'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label7: TLabel
    Left = 384
    Top = 600
    Width = 307
    Height = 27
    Caption = 'Down arrow -> move down'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label8: TLabel
    Left = 384
    Top = 536
    Width = 188
    Height = 27
    Caption = 'S -> move down'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label9: TLabel
    Left = 88
    Top = 416
    Width = 288
    Height = 27
    Caption = 'Win contidion: 2 sets won'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object Label10: TLabel
    Left = 88
    Top = 456
    Width = 206
    Height = 27
    Caption = 'Points in 1 set: 10'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -27
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    Transparent = True
  end
  object startButton: TButton
    Left = 272
    Top = 648
    Width = 209
    Height = 41
    Caption = 'Ok. I'#39've got it!'
    Font.Charset = EASTEUROPE_CHARSET
    Font.Color = clWhite
    Font.Height = -23
    Font.Name = 'MS UI Gothic'
    Font.Style = []
    ParentFont = False
    TabOrder = 0
    OnClick = startButtonClick
  end
end
