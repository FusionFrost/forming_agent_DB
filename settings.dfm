object Setting: TSetting
  Left = 0
  Top = 0
  Caption = 'Settings'
  ClientHeight = 473
  ClientWidth = 538
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
    Width = 521
    Height = 133
    Caption = 'Pdf to TxT convector'
    TabOrder = 0
    object Label1: TLabel
      Left = 16
      Top = 24
      Width = 144
      Height = 13
      Caption = #1059#1082#1072#1078#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1086' pdfconvert'
    end
    object Label4: TLabel
      Left = 16
      Top = 77
      Width = 44
      Height = 13
      Caption = #1050#1086#1084#1072#1085#1076#1072
    end
    object Pdf2TxtButton: TButton
      Left = 480
      Top = 48
      Width = 38
      Height = 25
      Caption = '...'
      TabOrder = 0
      OnClick = Pdf2TxtButtonClick
    end
    object PDF2TXTEdit: TEdit
      Left = 16
      Top = 50
      Width = 458
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object Edit1: TEdit
      Left = 16
      Top = 96
      Width = 458
      Height = 21
      TabOrder = 2
      Text = 'inputpath /to outputpath'
    end
  end
  object Button2: TButton
    Left = 455
    Top = 439
    Width = 75
    Height = 25
    Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100
    TabOrder = 1
    OnClick = Button2Click
  end
  object GroupBox2: TGroupBox
    Left = 8
    Top = 299
    Width = 522
    Height = 134
    Caption = '7zip'
    TabOrder = 2
    object Label2: TLabel
      Left = 16
      Top = 24
      Width = 168
      Height = 13
      Caption = #1059#1082#1072#1078#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1099' 7zip'
    end
    object Label6: TLabel
      Left = 24
      Top = 80
      Width = 44
      Height = 13
      Caption = #1050#1086#1084#1072#1085#1076#1072
    end
    object SevenZipButton: TButton
      Left = 477
      Top = 56
      Width = 38
      Height = 25
      Caption = '...'
      TabOrder = 0
      OnClick = SevenZipButtonClick
    end
    object SEVENZIPEdit: TEdit
      Left = 16
      Top = 56
      Width = 455
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object Edit3: TEdit
      Left = 16
      Top = 99
      Width = 455
      Height = 21
      TabOrder = 2
      Text = 'inputpath -o outputpath'
    end
  end
  object GroupBox3: TGroupBox
    Left = 8
    Top = 147
    Width = 522
    Height = 134
    Caption = 'Winrar'
    TabOrder = 3
    object Label3: TLabel
      Left = 16
      Top = 16
      Width = 184
      Height = 13
      Caption = #1059#1082#1072#1078#1080#1090#1077' '#1087#1091#1090#1100' '#1076#1086' '#1087#1088#1086#1075#1088#1072#1084#1084#1099'  Winrar'
    end
    object Label5: TLabel
      Left = 16
      Top = 75
      Width = 44
      Height = 13
      Caption = #1050#1086#1084#1072#1085#1076#1072
    end
    object WinrarButton: TButton
      Left = 477
      Top = 48
      Width = 38
      Height = 25
      Caption = '...'
      TabOrder = 0
      OnClick = WinrarButtonClick
    end
    object WINRAREdit: TEdit
      Left = 16
      Top = 48
      Width = 455
      Height = 21
      ReadOnly = True
      TabOrder = 1
    end
    object Edit2: TEdit
      Left = 16
      Top = 99
      Width = 455
      Height = 21
      TabOrder = 2
      Text = 'inputpath -o -x outputpath'
    end
  end
  object OpenTextFileDialog1: TOpenTextFileDialog
    Left = 496
    Top = 16
  end
end
