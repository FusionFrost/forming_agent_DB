object frmMain: TfrmMain
  Left = 0
  Top = 0
  Caption = 'OpenZip'
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
  object Button1: TButton
    Left = 8
    Top = 8
    Width = 137
    Height = 25
    Caption = #1042#1099#1073#1086#1088' '#1076#1080#1088#1077#1082#1090#1086#1088#1080#1080
    TabOrder = 0
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 160
    Top = 8
    Width = 225
    Height = 25
    Caption = #1050#1091#1076#1072' '#1087#1086#1083#1086#1078#1080#1090#1100' '#1088#1072#1089#1087#1072#1082#1086#1074#1072#1085#1085#1099#1077' '#1092#1072#1081#1083#1099
    TabOrder = 1
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 8
    Top = 56
    Width = 75
    Height = 25
    Caption = #1074#1099#1087#1086#1083#1085#1080#1090#1100
    TabOrder = 2
    OnClick = Button3Click
  end
  object OpenDialog1: TOpenDialog
    Left = 488
    Top = 16
  end
end