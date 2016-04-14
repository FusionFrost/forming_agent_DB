object Setting: TSetting
  Left = 0
  Top = 0
  Caption = 'Settings'
  ClientHeight = 337
  ClientWidth = 527
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object GroupBox1: TGroupBox
    Left = 8
    Top = 8
    Width = 193
    Height = 113
    Caption = 'Pdf to TxT convector'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 144
      Height = 13
      Caption = #1059#1082#1072#1078#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1086' pdfconvert'
    end
    object Button1: TButton
      Left = 16
      Top = 48
      Width = 161
      Height = 25
      Caption = #1055#1091#1090#1100' '#1076#1086' '#1082#1086#1085#1074#1077#1082#1090#1086#1088#1072
      TabOrder = 0
      OnClick = Button1Click
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 480
    Top = 288
  end
end
