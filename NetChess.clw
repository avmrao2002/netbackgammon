; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CNetChessView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "NetChess.h"
LastPage=0

ClassCount=16
Class1=CNetChessApp
Class2=CNetChessDoc
Class3=CNetChessView
Class4=CMainFrame

ResourceCount=11
Resource1=IDD_DIALOG_SERVER_INFO
Class5=CAboutDlg
Class6=CServerSocket
Class7=CClientSocket
Resource2=IDD_DIALOG_PICK_PIECE
Class8=COptions
Resource3=IDD_DIALOG_PROPERTIES
Class9=CServerInfoDlg
Resource4=IDR_SHELL_MENU
Class10=CMessageSend
Resource5=IDR_MAINFRAME
Class11=CHistoryDlg
Class12=CMyColorDialog
Resource6=IDD_DIALOG_GAME_TYPE
Class13=CPickPieceDlg
Resource7=IDD_DIALOG_MESSAGE
Resource8=IDD_DIALOG_OPTIONS
Class14=CPropertiesDlg
Resource9=IDD_DIALOG_HISTORY
Class15=CGameTypeDlg
Resource10=IDD_ABOUTBOX
Class16=CHowToPlay
Resource11=IDD_DIALOG_HOWTOPLAY

[CLS:CNetChessApp]
Type=0
HeaderFile=NetChess.h
ImplementationFile=NetChess.cpp
Filter=N

[CLS:CNetChessDoc]
Type=0
HeaderFile=NetChessDoc.h
ImplementationFile=NetChessDoc.cpp
Filter=N

[CLS:CNetChessView]
Type=0
HeaderFile=NetChessView.h
ImplementationFile=NetChessView.cpp
Filter=C
LastObject=ID_EDIT_UNDO
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=AFX_ID_PREVIEW_CLOSE
BaseClass=CFrameWnd
VirtualFilter=fWC




[CLS:CAboutDlg]
Type=0
HeaderFile=NetChess.cpp
ImplementationFile=NetChess.cpp
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=5
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDOK,button,1342373889
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_APP_EXIT
Command3=ID_EDIT_OPTIONS
Command4=ID_EDIT_PROPERTIES
Command5=ID_EDIT_UNDO
Command6=ID_TOOLS_CLIENT
Command7=ID_TOOLS_SERVER
Command8=ID_TOOLS_DISCONNECT
Command9=ID_TOOLS_SENDMESSAGE
Command10=ID_VIEW_HIDE
Command11=ID_APP_ABOUT
Command12=ID_HELP_HOWTOPLAY
CommandCount=12

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_SAVEHISTORY
Command2=ID_TOOLS_CLIENT
Command3=ID_TOOLS_DISCONNECT
Command4=ID_TOOLS_SERVER
Command5=ID_EDIT_MOVEFIRST
Command6=ID_TOOLS_GAMETYPE
Command7=ID_VIEW_HIDE
Command8=ID_VIEW_HISTORY
Command9=ID_TOOLS_SENDMESSAGE
Command10=ID_FILE_NEW
Command11=ID_EDIT_OPTIONS
Command12=D_EDIT_PROPERTIES
Command13=ID_EDIT_CUT
Command14=ID_NEXT_PANE
Command15=ID_PREV_PANE
Command16=ID_EDIT_COPY
Command17=ID_EDIT_PASTE
Command18=ID_TOOLS_WHITEONTOP
Command19=ID_EDIT_CUT
Command20=ID_EDIT_UNDO
CommandCount=20

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_TOOLS_SENDMESSAGE
Command3=ID_EDIT_OPTIONS
Command4=ID_VIEW_HIDE
Command5=ID_TOOLS_SERVER
Command6=ID_TOOLS_CLIENT
Command7=ID_EDIT_UNDO
Command8=ID_TOOLS_DISCONNECT
Command9=ID_APP_ABOUT
Command10=AFX_ID_PREVIEW_CLOSE
Command11=AFX_ID_PREVIEW_CLOSE
Command12=AFX_ID_PREVIEW_CLOSE
Command13=AFX_ID_PREVIEW_CLOSE
Command14=AFX_ID_PREVIEW_CLOSE
Command15=AFX_ID_PREVIEW_CLOSE
Command16=AFX_ID_PREVIEW_CLOSE
Command17=AFX_ID_PREVIEW_CLOSE
Command18=AFX_ID_PREVIEW_CLOSE
Command19=AFX_ID_PREVIEW_CLOSE
CommandCount=19

[CLS:CServerSocket]
Type=0
HeaderFile=ServerSocket.h
ImplementationFile=ServerSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=CServerSocket
VirtualFilter=q

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=N
LastObject=ID_EDIT_UNDO
VirtualFilter=q

[DLG:IDD_DIALOG_OPTIONS]
Type=1
Class=COptions
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDC_CHECK_WHITE_ON_TOP,button,1073807363
Control3=IDC_BUTTON_WHITE_COLOR,button,1342242816
Control4=IDC_BUTTON_BLACK_COLOR,button,1342242816
Control5=IDC_STATIC_WHITE,static,1342308352
Control6=IDC_STATIC_BLACK,static,1342308352
Control7=IDC_STATIC,button,1342177287
Control8=IDC_STATIC,button,1342177287
Control9=IDC_BUTTON_WHITE_PIECE_COLOR,button,1342242816
Control10=IDC_BUTTON_BLACK_PIECE_COLOR,button,1342242816
Control11=IDC_STATIC_WHITE_PIECE_COLOR,static,1342308352
Control12=IDC_STATIC_BLACK_PIECE_COLOR,static,1342308352

[CLS:COptions]
Type=0
HeaderFile=Options.h
ImplementationFile=Options.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_BUTTON_BLACK_PIECE_COLOR
VirtualFilter=dWC

[DLG:IDD_DIALOG_SERVER_INFO]
Type=1
Class=CServerInfoDlg
ControlCount=8
Control1=IDC_IPADDRESS,SysIPAddress32,1073807360
Control2=IDC_EDIT_PORT_NUMBER,edit,1350631552
Control3=IDOK,button,1342242817
Control4=IDCANCEL,button,1342242816
Control5=IDC_STATIC_IP_ADDRESS,static,1073872896
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_NAME,edit,1350631552

[CLS:CServerInfoDlg]
Type=0
HeaderFile=ServerInfoDlg.h
ImplementationFile=ServerInfoDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CServerInfoDlg
VirtualFilter=dWC

[DLG:IDD_DIALOG_MESSAGE]
Type=1
Class=CMessageSend
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_EDIT_MESSAGE,edit,1352728580
Control4=IDC_EDIT_RECEIVE_MESSAGE,edit,1352730756

[CLS:CMessageSend]
Type=0
HeaderFile=MessageSend.h
ImplementationFile=MessageSend.cpp
BaseClass=CDialog
Filter=D
LastObject=CMessageSend
VirtualFilter=dWC

[DLG:IDD_DIALOG_HISTORY]
Type=1
Class=CHistoryDlg
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_HISTORY,edit,1352730692

[CLS:CHistoryDlg]
Type=0
HeaderFile=HistoryDlg.h
ImplementationFile=HistoryDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHistoryDlg

[CLS:CMyColorDialog]
Type=0
HeaderFile=MyColorDialog.h
ImplementationFile=MyColorDialog.cpp
BaseClass=CColorDialog
Filter=D
VirtualFilter=dWC
LastObject=CMyColorDialog

[DLG:IDD_DIALOG_PICK_PIECE]
Type=1
Class=CPickPieceDlg
ControlCount=8
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC_BITMAP_BLACK,static,1350570247
Control4=IDC_STATIC_BITMAP_BLACK_KING,static,1350570247
Control5=IDC_STATIC_BITMAP_WHITE,static,1350570247
Control6=IDC_STATIC_BITMAP_WHITE_KING,static,1350570247
Control7=IDC_STATIC_STATUS,static,1342308352
Control8=IDC_STATIC_EMPTY,static,1342181639

[CLS:CPickPieceDlg]
Type=0
HeaderFile=PickPieceDlg.h
ImplementationFile=PickPieceDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=AFX_ID_PREVIEW_CLOSE
VirtualFilter=dWC

[MNU:IDR_SHELL_MENU]
Type=1
Class=?
Command1=ID_SHELL_CLOSE
Command2=ID_SHELL_VIEW
CommandCount=2

[DLG:IDD_DIALOG_PROPERTIES]
Type=1
Class=CPropertiesDlg
ControlCount=3
Control1=IDOK,button,1342242817
Control2=IDC_STATIC_STATUS,static,1342308352
Control3=IDC_STATIC_CLIENT_STATUS,static,1342308352

[CLS:CPropertiesDlg]
Type=0
HeaderFile=PropertiesDlg.h
ImplementationFile=PropertiesDlg.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=AFX_ID_PREVIEW_CLOSE

[DLG:IDD_DIALOG_GAME_TYPE]
Type=1
Class=CGameTypeDlg
ControlCount=12
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_RADIO_AMERICAN,button,1342177289
Control4=IDC_RADIO_SPARSE,button,1342177289
Control5=IDC_RADIO_CROWDED,button,1342177289
Control6=IDC_RADIO_CHINESE8x8,button,1342177289
Control7=IDC_RADIO_CHINESE10x10,button,1342177289
Control8=IDC_RADIO_INTERNATIONAL,button,1342177289
Control9=IDC_RADIO_ITALIAN,button,1342177289
Control10=IDC_RADIO_POLISH,button,1342177289
Control11=IDC_RADIO_RUSSIAN,button,1342177289
Control12=IDC_STATIC,button,1342177287

[CLS:CGameTypeDlg]
Type=0
HeaderFile=GameTypeDlg1.h
ImplementationFile=GameTypeDlg1.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=IDC_RADIO_SPARSE

[DLG:IDD_DIALOG_HOWTOPLAY]
Type=1
Class=CHowToPlay
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_EDIT_STRING,edit,1352730692

[CLS:CHowToPlay]
Type=0
HeaderFile=HowToPlay.h
ImplementationFile=HowToPlay.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CHowToPlay

