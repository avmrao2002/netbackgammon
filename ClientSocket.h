#if !defined(AFX_CLIENTSOCKET_H__C28E3041_4F98_49FF_873C_C2EA2D6B592C__INCLUDED_)
#define AFX_CLIENTSOCKET_H__C28E3041_4F98_49FF_873C_C2EA2D6B592C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CAsyncSocket
{
// Attributes
	int m_length;
public:
	CString m_ipaddress;
	int m_port;
// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();
	void SetInfo(CString ipaddr,int port);
	void GetInfo(CString &ipaddr,int & port);
 

// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnClose(int nErrorCode);
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	virtual int Receive(void* lpBuf, int nBufLen, int nFlags = 0);
	virtual int Send(const void* lpBuf, int nBufLen, int nFlags = 0);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__C28E3041_4F98_49FF_873C_C2EA2D6B592C__INCLUDED_)
