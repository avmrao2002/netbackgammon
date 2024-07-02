#if !defined(AFX_HOWTOPLAY_H__D85915AB_77E9_4FDA_AA84_E66A515EAAC4__INCLUDED_)
#define AFX_HOWTOPLAY_H__D85915AB_77E9_4FDA_AA84_E66A515EAAC4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HowToPlay.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHowToPlay dialog

class CHowToPlay : public CDialog
{
// Construction
public:
	CHowToPlay(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHowToPlay)
	enum { IDD = IDD_DIALOG_HOWTOPLAY };
	CString	m_edit_string;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHowToPlay)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHowToPlay)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOWTOPLAY_H__D85915AB_77E9_4FDA_AA84_E66A515EAAC4__INCLUDED_)
