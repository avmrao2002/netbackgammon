// PropertiesDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "PropertiesDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg dialog


CPropertiesDlg::CPropertiesDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPropertiesDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPropertiesDlg)
	m_Static_Client_Status = _T("");
	m_Static_Status = _T("");
	//}}AFX_DATA_INIT
}


void CPropertiesDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPropertiesDlg)
	DDX_Text(pDX, IDC_STATIC_CLIENT_STATUS, m_Static_Client_Status);
	DDX_Text(pDX, IDC_STATIC_STATUS, m_Static_Status);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPropertiesDlg, CDialog)
	//{{AFX_MSG_MAP(CPropertiesDlg)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPropertiesDlg message handlers
void CPropertiesDlg::SetInfo(int type,CString ipaddr,int port,int serverport)
{
	m_type = type;
	m_ipaddress = ipaddr;
	m_port = port;
	m_serverport = serverport;
	if(type == -1)
	{
		m_Static_Status = "Not running as client/server";
		m_Static_Client_Status = " ";
	}
	else if(type == SERVER)
	{
		CString str;
		str.Format("Running as Server, listening on %d",m_serverport);
		m_Static_Status=str;		 
		if(m_port == 0)
		{
			m_Static_Client_Status = "Not connected to client";
		}
		else
		{
			CString str;
			str.Format("Connected from %s",ipaddr.GetBuffer(0)); 
			m_Static_Client_Status = str;
		}
	}
	else if(type == CLIENT)
	{
		m_Static_Status = "Running as Client";
		CString str;
		str.Format("Connected to %s on %d",ipaddr.GetBuffer(0),port);
		m_Static_Client_Status = str;
	}
	//UpdateData(TRUE);
	 
}
