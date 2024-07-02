// NetChessView.h : interface of the CNetChessView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
#define AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ChessBoard.h"
#include "Options.h"
#include "History.h"

class CNetChessView : public CView
{
	int i;//for 2005 compliant
	bool m_mouseMoveFlag;
	CRect m_moveRect;
	CPoint m_point;
	CAsyncSocket *m_pClientSocket;
	CAsyncSocket *m_pServerSocket;
	CDialog *m_ChatDlg;
	bool m_LetterFlag;
	bool m_NumberFlag;
	bool m_white_on_top;	 
	COLOR_TYPE m_player_turn;
	int m_topHistory;
	int m_squareWidth;
	int m_sendButtonClickedFlag;
	int m_level;
	GAME_TYPE m_GameType;
	int m_diceBitmapId;
	int m_diceBitmapId1;
	CPoint m_bearindex;
	int m_diceClickFlag;
	int countBalls(int,int);
	int m_lastDiceMove1;	
	int m_lastDiceMove2;	
	CString m_whoAmI;
	CString m_myname;
protected: // create from serialization only
	CNetChessView();
	DECLARE_DYNCREATE(CNetChessView)
	CChessBoard cb[30][20];
	//int m_balls[30]
	CHistory  m_History[MAXHISTORY];
	int m_iHistory; 

// Attributes
public:
	bool m_timerFlag;	 
	COptions m_optDlg;
	char m_moveInfo[10][100];
	int m_moveLength[10];
	int m_moveIndex;
	void DrawBoard();
	CNetChessDoc* GetDocument();
	void SetClientSocket(CAsyncSocket*);
	void SetData(char* data, int length);
	void SendSockData(unsigned char *data,int length);
	bool CheckValidMove(int,int,int&,int&);
	void KillTimerEvent();
	void OnEditRedoAction();
	void OnEditUndoAction();
	CAsyncSocket* GetClientSocket();
	void Initialize();
	int GetBitmapId(int piece_id);
	void SetPaneText(int paneno,CString str);
	void ShowTrayIcon(DWORD message,int icon,int input);
	CPoint getOffsetPoint();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNetChessView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CNetChessView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNetChessView)
	afx_msg void OnEditOptions();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnToolsClient();
	afx_msg void OnToolsServer();
	afx_msg void OnToolsSendmessage();
	afx_msg void OnFileOpen();
	afx_msg void OnFileSave();
	afx_msg void OnViewLetter();
	afx_msg void OnUpdateViewLetter(CCmdUI* pCmdUI);
	afx_msg void OnViewNumber();
	afx_msg void OnUpdateViewNumber(CCmdUI* pCmdUI);
	afx_msg void OnFileSavehistory();
	afx_msg void OnEditUndo();
	afx_msg void OnEditRedo();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnUpdateToolsServer(CCmdUI* pCmdUI);
	afx_msg void OnUpdateToolsClient(CCmdUI* pCmdUI);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFileNew();
	afx_msg void OnViewHistory();
	afx_msg void OnToolsWhiteontop();
	afx_msg void OnEditMovefirst();
	afx_msg void OnEditMovelast();
	afx_msg void OnHelpHowtoplay();
	afx_msg void OnToolsDisconnect();
	afx_msg void OnEditProperties();
	afx_msg void OnToolsGametype();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
	LRESULT OnMessageColorData(WPARAM wParam,LPARAM lParam);
	void OnLButtonDownAction(UINT nFlags, CPoint point);
	void OnLButtonUpAction(UINT nFlags, CPoint point);
	void OnMouseMoveAction(UINT nFlags, CPoint point);
	void OnFileNewAction();
	bool allBallsAreInHome();

};

#ifndef _DEBUG  // debug version in NetChessView.cpp
inline CNetChessDoc* CNetChessView::GetDocument()
   { return (CNetChessDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NETCHESSVIEW_H__5A680802_7FFF_40BB_B3DF_22486247A285__INCLUDED_)
