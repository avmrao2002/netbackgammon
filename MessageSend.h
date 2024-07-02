#if !defined(AFX_MESSAGESEND_H__08C3FB4D_9E1E_4AF9_951F_7ED1033E3B16__INCLUDED_)
#define AFX_MESSAGESEND_H__08C3FB4D_9E1E_4AF9_951F_7ED1033E3B16__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MessageSend.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMessageSend dialog

class CMessageSend : public CDialog
{
// Construction
public:
	CMessageSend(CWnd* pParent = NULL);
	CString m_name;
	void SetReceiveData(char* data);
	// standard constructor
// Dialog Data
	//{{AFX_DATA(CMessageSend)
	enum { IDD = IDD_DIALOG_MESSAGE };
	CString	m_edit_message;
	CString	m_edit_receive_message;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageSend)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMessageSend)
	virtual void OnOK();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGESEND_H__08C3FB4D_9E1E_4AF9_951F_7ED1033E3B16__INCLUDED_)
