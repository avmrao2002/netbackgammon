#if !defined(AFX_MYCOLORDIALOG_H__ACE89F5E_BD4E_4D01_8E45_F45C65B0499C__INCLUDED_)
#define AFX_MYCOLORDIALOG_H__ACE89F5E_BD4E_4D01_8E45_F45C65B0499C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyColorDialog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyColorDialog dialog

class CMyColorDialog : public CColorDialog
{
	DECLARE_DYNAMIC(CMyColorDialog)

public:
	CMyColorDialog(COLORREF clrInit = 0, DWORD dwFlags = 0,
			CWnd* pParentWnd = NULL);
 
protected:
	//{{AFX_MSG(CMyColorDialog)
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYCOLORDIALOG_H__ACE89F5E_BD4E_4D01_8E45_F45C65B0499C__INCLUDED_)
