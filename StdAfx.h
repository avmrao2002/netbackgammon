// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_)
#define AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers

#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT
#define MY_MESSAGE_SHELLNOTIFY WM_USER + 1
#include <afxsock.h>		// MFC socket extensions

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.
enum COLOR_TYPE {NONE,BLACK,WHITE};
enum PIECE_SIDE {TOP,BOTTOM};
//enum PIECE_TYPE {BLANK,PAWN,ROOK,KNIGHT,BISHOP,QUEEN,KING,}; 
enum PIECE_TYPE {BLANK,NORMAL,KING}; 
enum ACTION {MOVE,DICEROLL,YOURTURN,BEAROFF,TEXT,FILEDATA,MOVING,UNDO,REDO,NEWGAME,SYNC,NOTACCEPTED};
enum STATE {PIECE_MOVING,PIECE_NOT_MOVING};
enum GAME_TYPE {NOGAME,AMERICAN,CROWDED, SPARSE,CHINESE8x8,CHINESE10x10,INTERNATIONAL,ITALIAN,POLISH,RUSSIAN};
#define CLIENT 1
#define SERVER 2
#define MAXHISTORY 400
#define ID_MY_MESSAGE_COLORDATA WM_USER + 1
#define SHELL_ICON_TIMER_EVENT_ID 1000

#define CHECKERS_WHITE			1
#define CHECKERS_BLACK			2
#define CHECKERS_WHITE_KING		3
#define CHECKERS_BLACK_KING		4
 
#endif // !defined(AFX_STDAFX_H__7D203266_2EAA_41DB_B721_EEF4C52B849A__INCLUDED_)
