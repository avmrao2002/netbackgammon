#if !defined(AFX_SERVERINFODLG_H__B788EE7D_4FA2_4627_AF12_8580AAF2C52B__INCLUDED_)
#define AFX_SERVERINFODLG_H__B788EE7D_4FA2_4627_AF12_8580AAF2C52B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ServerInfoDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CServerInfoDlg dialog

class CServerInfoDlg : public CDialog
{
// Construction
	int m_type; 
public:
	CServerInfoDlg(CWnd* pParent = NULL);   // standard constructor
	CServerInfoDlg(CWnd* pParent ,int type);   // standard constructor
	CString m_strIPAddress;

// Dialog Data
	//{{AFX_DATA(CServerInfoDlg)
	enum { IDD = IDD_DIALOG_SERVER_INFO };
	CIPAddressCtrl	m_ipaddress;
	int		m_port_nunber;
	CString	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CServerInfoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CServerInfoDlg)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SERVERINFODLG_H__B788EE7D_4FA2_4627_AF12_8580AAF2C52B__INCLUDED_)
