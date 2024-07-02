#if !defined(AFX_OPTIONS_H__7DFB9D71_1840_4BB6_8452_C5E968A37A72__INCLUDED_)
#define AFX_OPTIONS_H__7DFB9D71_1840_4BB6_8452_C5E968A37A72__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Options.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// COptions dialog

class COptions : public CDialog
{
// Construction
	 
public:
	COptions(CWnd* pParent = NULL);   // standard constructor
	COLORREF m_crefWhiteColor;
	COLORREF m_crefBlackColor;
	COLORREF m_crefBlackPieceColor;
	COLORREF m_crefWhitePieceColor;
	bool m_whiteClrDlg;
	bool m_blackClrDlg;
	int m_pieceType;
	void SetColor(COLORREF cr);
	 

// Dialog Data
	//{{AFX_DATA(COptions)
	enum { IDD = IDD_DIALOG_OPTIONS };
	BOOL	m_check_white_on_top;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(COptions)
	afx_msg void OnButtonBlackColor();
	afx_msg void OnButtonWhiteColor();
	virtual BOOL OnInitDialog();
	afx_msg void OnCheckWhiteOnTop();
	virtual void OnOK();
	afx_msg void OnStaticPieceType1();
	afx_msg void OnStaticPieceType2();
	afx_msg void OnStaticPieceType3();
	afx_msg void OnButtonWhitePieceColor();
	afx_msg void OnStaticBlackPieceColor();
	afx_msg void OnButtonBlackPieceColor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPTIONS_H__7DFB9D71_1840_4BB6_8452_C5E968A37A72__INCLUDED_)
