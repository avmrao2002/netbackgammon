// ServerInfoDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "ServerInfoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CServerInfoDlg dialog


CServerInfoDlg::CServerInfoDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CServerInfoDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CServerInfoDlg)
	m_port_nunber = 55555;
	m_name = _T("WHITE");
	//}}AFX_DATA_INIT
	UpdateData(FALSE);
}
CServerInfoDlg::CServerInfoDlg(CWnd* pParent /*=NULL*/,int type)
	: CDialog(CServerInfoDlg::IDD, pParent)
{
	m_port_nunber = 55555;	 
	m_type = type;
}


void CServerInfoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CServerInfoDlg)
	DDX_Control(pDX, IDC_IPADDRESS, m_ipaddress);
	DDX_Text(pDX, IDC_EDIT_PORT_NUMBER, m_port_nunber);
	DDV_MinMaxInt(pDX, m_port_nunber, 1, 65535);
	DDX_Text(pDX, IDC_NAME, m_name);
	DDV_MaxChars(pDX, m_name, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CServerInfoDlg, CDialog)
	//{{AFX_MSG_MAP(CServerInfoDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CServerInfoDlg message handlers

void CServerInfoDlg::OnOK() 
{
	UpdateData(TRUE);
	CString str;
	BYTE b1,b2,b3,b4;
	m_ipaddress.GetAddress(b1,b2,b3,b4);
	m_strIPAddress.Format("%u.%u.%u.%u",b1,b2,b3,b4);
	if(m_name.IsEmpty() !=0)
	{
		AfxMessageBox("Enter name");
		return;
	}
	  	
	CDialog::OnOK();
}

BOOL CServerInfoDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	if(m_type == CLIENT)
	{
		CWnd* wnd = GetDlgItem(IDC_IPADDRESS);
		wnd->ShowWindow(SW_SHOW);
			wnd = GetDlgItem(IDC_STATIC_IP_ADDRESS);
		wnd->ShowWindow(SW_SHOW);
	}
	m_ipaddress.SetAddress(127,0,0,1);
	m_name = _T("WHITE");
	UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
