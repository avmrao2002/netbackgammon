#if !defined(AFX_GAMETYPEDLG_H__F2602C68_028E_4459_AFE9_624A7461E9E7__INCLUDED_)
#define AFX_GAMETYPEDLG_H__F2602C68_028E_4459_AFE9_624A7461E9E7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// GameTypeDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CGameTypeDlg dialog

class CGameTypeDlg : public CDialog
{
// Construction
public:
	CGameTypeDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CGameTypeDlg)
	enum { IDD = IDD_DIALOG_GAME_TYPE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameTypeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CGameTypeDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMETYPEDLG_H__F2602C68_028E_4459_AFE9_624A7461E9E7__INCLUDED_)
