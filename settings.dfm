object Setting: TSetting
  Left = 0
  Top = 0
  Caption = 'Settings'
  ClientHeight = 337
  ClientWidth = 631
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
    object Pdf2TxtButton: TButton
      Left = 16
      Top = 48
      Width = 161
      Height = 25
      Caption = #1055#1091#1090#1100
      TabOrder = 0
      OnClick = Pdf2TxtButtonClick
    end
  end
  object Button2: TButton
    Left = 542
    Top = 304
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox2: TGroupBox
    Left = 207
    Top = 8
    Width = 193
    Height = 113
    Caption = '7zip'
    TabOrder = 2
    object Label2: TLabel
      Left = 16
      Top = 24
      Width = 168
      Height = 13
      Caption = #1059#1082#1072#1078#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' 7zip'
    end
    object SevenZipButton: TButton
      Left = 16
      Top = 48
      Width = 161
      Height = 25
      Caption = #1055#1091#1090#1100
      TabOrder = 0
      OnClick = SevenZipButtonClick
    end
  end
  object GroupBox3: TGroupBox
    Left = 406
    Top = 8
    Width = 211
    Height = 113
    Caption = 'Winrar'
    TabOrder = 3
    object Label3: TLabel
      Left = 16
      Top = 24
      Width = 184
      Height = 13
      Caption = #1059#1082#1072#1078#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'  Winrar'
    end
    object WinrarButton: TButton
      Left = 16
      Top = 48
      Width = 177
      Height = 25
      Caption = #1055#1091#1090#1100
      TabOrder = 0
      OnClick = WinrarButtonClick
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 552
    Top = 232
  end
end
