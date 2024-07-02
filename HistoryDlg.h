#if !defined(AFX_HISTORYDLG_H__A9E5EDCE_7D85_4046_99DB_2BC85DA7C950__INCLUDED_)
#define AFX_HISTORYDLG_H__A9E5EDCE_7D85_4046_99DB_2BC85DA7C950__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// HistoryDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CHistoryDlg dialog
#include "History.h"
class CHistoryDlg : public CDialog
{
// Construction
	CHistory *m_History;
	int m_iHistory;
public:
	CHistoryDlg(CWnd* pParent = NULL);   // standard constructor
	CHistoryDlg(CWnd* pParent,CHistory*,int,int );   // standard constructor

// Dialog Data
	//{{AFX_DATA(CHistoryDlg)
	enum { IDD = IDD_DIALOG_HISTORY };
	CString	m_edit_history;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHistoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CHistoryDlg)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HISTORYDLG_H__A9E5EDCE_7D85_4046_99DB_2BC85DA7C950__INCLUDED_)
