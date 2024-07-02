// MyColorDialog.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "MyColorDialog.h"
#include "NetChessDoc.h"
#include "NetChessView.h"
 

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyColorDialog

IMPLEMENT_DYNAMIC(CMyColorDialog, CColorDialog)

CMyColorDialog::CMyColorDialog(COLORREF clrInit, DWORD dwFlags, CWnd* pParentWnd) :
	CColorDialog(clrInit, dwFlags, pParentWnd)
{
}


BEGIN_MESSAGE_MAP(CMyColorDialog, CColorDialog)
	//{{AFX_MSG_MAP(CMyColorDialog)
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


void CMyColorDialog::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default 
	 	 
	CColorDialog::OnLButtonUp(nFlags, point);
}

void CMyColorDialog::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	
	CColorDialog::OnLButtonDown(nFlags, point);
}
