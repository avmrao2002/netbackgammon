#if !defined(AFX_PROPERTIESDLG_H__A4F0CA57_1857_4A27_B407_510D24DE80D8__INCLUDED_)
#define AFX_PROPERTIESDLG_H__A4F0CA57_1857_4A27_B407_510D24DE80D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// PropertiesDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg dialog

class CPropertiesDlg : public CDialog
{
// Construction
	int m_type;
	CString m_ipaddress;
	int m_port;
	int m_serverport;
public:
	CPropertiesDlg(CWnd* pParent = NULL);   // standard constructor
	void SetInfo(int type,CString ipaddr,int port,int serverport);
// Dialog Data
	//{{AFX_DATA(CPropertiesDlg)
	enum { IDD = IDD_DIALOG_PROPERTIES };
	CString	m_Static_Client_Status;
	CString	m_Static_Status;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertiesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CPropertiesDlg)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTIESDLG_H__A4F0CA57_1857_4A27_B407_510D24DE80D8__INCLUDED_)
