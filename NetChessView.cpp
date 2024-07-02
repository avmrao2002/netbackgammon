// NetChessView.cpp : implementation of the CNetChessView class
//

#include "stdafx.h"
#include "NetChess.h"
#include "Options.h"
#include "ChessBoard.h"
#include "ServerInfoDlg.h"
#include "ServerSocket.h"
#include "ClientSocket.h"
#include "MessageSend.h"
#include "History.h"
#include "HistoryDlg.h"
#include "PropertiesDlg.h"
#include "MainFrm.h"

#include "NetChessDoc.h"
#include "NetChessView.h"
#include "HowToPlay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
void writeMessage(char *str,...)
{
#ifdef _DEBUG
	char arr[9999];
	va_list va;     
    va_start(va,str);
    vsprintf(arr,str,va);       
	FILE* fp=fopen(".\\data.dat","a+");
	if(fp!=NULL)
	{
		fprintf(fp,"%s\n",arr);
		fclose(fp);
	}
#endif
}
/////////////////////////////////////////////////////////////////////////////
// CNetChessView

IMPLEMENT_DYNCREATE(CNetChessView, CView)

BEGIN_MESSAGE_MAP(CNetChessView, CView)
	//{{AFX_MSG_MAP(CNetChessView)
	ON_COMMAND(ID_EDIT_OPTIONS, OnEditOptions)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_COMMAND(ID_TOOLS_CLIENT, OnToolsClient)
	ON_COMMAND(ID_TOOLS_SERVER, OnToolsServer)
	ON_COMMAND(ID_TOOLS_SENDMESSAGE, OnToolsSendmessage)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_FILE_SAVE, OnFileSave)
	ON_COMMAND(ID_VIEW_LETTER, OnViewLetter)
	ON_UPDATE_COMMAND_UI(ID_VIEW_LETTER, OnUpdateViewLetter)
	ON_COMMAND(ID_VIEW_NUMBER, OnViewNumber)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NUMBER, OnUpdateViewNumber)
	ON_COMMAND(ID_FILE_SAVEHISTORY, OnFileSavehistory)
	ON_COMMAND(ID_EDIT_UNDO, OnEditUndo)
	ON_COMMAND(ID_EDIT_REDO, OnEditRedo)
	ON_WM_RBUTTONDOWN()
	ON_UPDATE_COMMAND_UI(ID_TOOLS_SERVER, OnUpdateToolsServer)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_CLIENT, OnUpdateToolsClient)
	ON_WM_TIMER()
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_VIEW_HISTORY, OnViewHistory)
	ON_COMMAND(ID_TOOLS_WHITEONTOP, OnToolsWhiteontop)
	ON_COMMAND(ID_EDIT_MOVEFIRST, OnEditMovefirst)
	ON_COMMAND(ID_EDIT_MOVELAST, OnEditMovelast)
	ON_COMMAND(ID_HELP_HOWTOPLAY, OnHelpHowtoplay)
	ON_COMMAND(ID_TOOLS_DISCONNECT, OnToolsDisconnect)
	ON_COMMAND(D_EDIT_PROPERTIES, OnEditProperties)
	ON_COMMAND(ID_TOOLS_GAMETYPE, OnToolsGametype)
	ON_COMMAND(ID_EDIT_PROPERTIES, OnEditProperties)
	ON_WM_LBUTTONDBLCLK()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
	ON_MESSAGE(ID_MY_MESSAGE_COLORDATA,OnMessageColorData)
END_MESSAGE_MAP()

int checkExisting(int n, int *arr, int rand)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i] == rand)
			return 1;
	}
	return 0;
}

int getExisting(int n,int* arr, int* data)
{	 
	int foundFlag = 0; 	 	 
	for(int i=0;i<n;i++)
	{		 
		if(data[i] == 0) continue;
 		for(int j =0;j<n;j++)
		{
 			if(arr[j]==0)
			{
			 			 
				return data[i];
			}
				
			if(arr[j] == data[i])
			{				 
				foundFlag = 1;
				break;
			}
		}
		if(foundFlag == 0)
		{	 			 
			return data[i];
		}
	}
 	return -1;
}
int getRandom(int num)
{
	SYSTEMTIME st;
	::GetSystemTime(&st);
    int value = (st.wMilliseconds % num)+ 1;
	return value;
	
	/*srand( (unsigned)time( NULL ) );
	int data[100];
	for(int i=0;i<100;i++)
	{
		data[i] = i+1;
	}

	for(i=0;i<100;i++)
	{
		arr[i]=0;
	}
	int trycount = 0;
	for(i=0;i<num;i++)
	{
			 
			int rnd = (rand() % ((num)+1));
 			if( rnd == 0 || checkExisting(num,arr,rnd) == 1)
			{//try once again
				if(trycount==1000)
				{
					int retdata = getExisting(num,arr,data);
					if(retdata < 0)
					{
						return;
					}
					else
					{
						trycount = 0;
						arr[i] = retdata;
					}
				}
				else
				{
					trycount++;
					i--;
				}
				 
			}
			else
			{
				trycount=0;
				arr[i] = rnd;
			}
	} */
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView construction/destruction

CNetChessView::CNetChessView()
{
	// TODO: add construction code here
	m_pClientSocket = NULL;
	m_pServerSocket = NULL;
	m_ChatDlg = NULL;		
	Initialize();	
	m_whoAmI = "WHITE";
}

CNetChessView::~CNetChessView()
{
}

BOOL CNetChessView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView drawing

void CNetChessView::OnDraw(CDC* pDC)
{
	CNetChessDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	DrawBoard();
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView printing

BOOL CNetChessView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CNetChessView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CNetChessView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CNetChessView diagnostics

#ifdef _DEBUG
void CNetChessView::AssertValid() const
{
	CView::AssertValid();
}

void CNetChessView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CNetChessDoc* CNetChessView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CNetChessDoc)));
	return (CNetChessDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CNetChessView message handlers

void CNetChessView::OnEditOptions() 
{
	m_optDlg.DoModal();	 
	DrawBoard();
}

void CNetChessView::DrawBoard()
{
	CClientDC dc(this);	
 
	CBitmap localbmp;
	localbmp.LoadBitmap(IDB_BITMAP_BASE);
	//BITMAP bp={0,1000,490,3000,1,24,0x00000000};
	//localbmp.CreateBitmapIndirect(&bp);

	CDC ldc;
	ldc.CreateCompatibleDC(&dc);
	ldc.SelectObject(&localbmp); 
	COLORREF cr(RGB(20,140,17));	 
	//COLORREF cr(RGB(74,220,88));	 
	//ldc.SetBkColor(cr);
	CBrush brush(cr);
	COLORREF blackcr(RGB(0,0,0));	 
	CBrush blackbrush(blackcr);
	ldc.SelectObject(brush);
	CRect crect;
	GetClientRect(&crect);
	 
 
	ldc.FillRect(&crect,&brush);
	COLORREF bkcrRef;
	 
	//CRect crect = cb[3][3].GetRect();
	COLORREF redcr(RGB(255,0,0));

	CBrush redbrush;
	redbrush.CreateSolidBrush(redcr);
	
	COLORREF redbluecr(RGB(255,0,255));
	CBrush redbluebrush;
	redbluebrush.CreateSolidBrush(redbluecr);

	CBrush* pbrush = ldc.SelectObject(&redbluebrush);

	ldc.Rectangle(crect.left + 6, crect.top + 4,
		crect.right - 122, crect.bottom - 4);

	 
	COLORREF bluecr(RGB(150,236,252));
	CBrush bluebrush;
	bluebrush.CreateSolidBrush(bluecr);

	COLORREF greencr(RGB(0,255,0));
	CBrush greenbrush;
	greenbrush.CreateSolidBrush(greencr);

	ldc.SelectObject(bluebrush);

	ldc.Rectangle(crect.left +21, crect.top +21,
		crect.right - 135, crect.bottom -21);

	pbrush =  ldc.SelectObject(&redbluebrush);
	
		
    CPen pen(PS_NULL,0,RGB(0,0,0));
	CPen *orgpen = ldc.SelectObject(&pen);
	COLORREF c1 =  m_optDlg.m_crefWhiteColor;
	COLORREF c2 =  m_optDlg.m_crefBlackColor;

	for(int i = 0; i< m_level ; i++)
	{
		if (i == 6) 
		{
			CRect rect1 = cb[0][i].GetRect();
			CRect rect2 = cb[13-1][i].GetRect();
			CRect rect3(rect1.left,rect1.top,rect2.right,rect2.bottom);
			//COLORREF cr(RGB(0,0,0));
			//CBrush brush(cr);
			ldc.FillRect(&rect3,&brush);
			continue;
		}
	    CRect rect = cb[0][i].GetRect();
		CRect rect1 = cb[4][i].GetRect();
		POINT pt[4] = {
						{rect.left,rect.top},
						{rect.right, rect.top},
						{rect1.left+15, rect1.bottom},
						{rect.left,rect.top}
						};
						
		if(i < 13)
		{
			CBrush brush(c1);	
			CRgn rgn;
			rgn.CreatePolygonRgn(pt,4,ALTERNATE);
			COLORREF cr(RGB(0,255,0));
			ldc.Polygon(pt,4);
			ldc.FillRgn(&rgn,&brush);
			ldc.FrameRgn(&rgn,&blackbrush,1,0);

			CRect rect2 = cb[13-1][i].GetRect();
			CRect rect3 = cb[13-5][i].GetRect();
			POINT pt1[4] = {
							{rect2.left,rect2.bottom},
							{rect2.right, rect2.bottom},
							{rect3.left+15, rect3.top},
							{rect2.left,rect2.bottom}
							};
							
			CBrush brush1(c2);	
			CRgn rgn1;
			rgn1.CreatePolygonRgn(pt1,4,ALTERNATE);
			COLORREF cr1(RGB(0,0,255));
			ldc.Polygon(pt1,4);
			ldc.FillRgn(&rgn1,&brush1);
			ldc.FrameRgn(&rgn1,&blackbrush,1,0);
			COLORREF temp = c1;
			c1 = c2;
			c2= temp;	
		}
	}

	ldc.SelectObject(orgpen);

	for(i = 0; i < m_level; i++)
	{
		for( int j = 0; j < m_level; j++)
		{
			CRect rect = cb[i][j].GetRect();			
			if(cb[i][j].GetPieceType() != BLANK && cb[i][j].GetPieceState() != PIECE_MOVING)
			{
				int piece_id;
				COLOR_TYPE  piece_color;
				PIECE_TYPE  piece_type;
				STATE piece_state;
				cb[i][j].GetPieceData(piece_id,piece_color,piece_type,piece_state);
				if(piece_id <= 0)
				{
					break;
				}
			
				CRect rect1(rect.left,rect.top,rect.right,rect.bottom);
				//ldc.Ellipse(rect1);
				CRgn rgn;						 
				rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
				switch(piece_id)
				{
					case CHECKERS_WHITE:
						{
							CBrush brush(m_optDlg.m_crefWhitePieceColor);
							ldc.FillRgn(&rgn,&brush );						 
							ldc.FrameRgn(&rgn,&brush,1,1);
						}
						break; 

					case CHECKERS_BLACK:	
						{
							CBrush brush(m_optDlg.m_crefBlackPieceColor);
							ldc.FillRgn(&rgn,&brush);						 
							ldc.FrameRgn(&rgn,&brush,1,1);
						}
						break; 			
				}
			}			
		}			
	}

	for(i=0;i<13;i++)
	{
		ldc.SetBkColor(redbluecr);
		int j = i;
		if(i == 6) continue;
		if(i > 6)
		{
			j = i-1;
		}
		CString str1;
		CString str2;
		str1.Format("%d",13+j);
		str2.Format("%d", 12-j);
		if(m_whoAmI == "BLACK")
		{
			ldc.TextOut(m_squareWidth * (i+1)+5,5,str1);
			ldc.TextOut(m_squareWidth * (i+1)+5,crect.bottom - 21, str2);
		}
		else
		{
			ldc.TextOut(m_squareWidth * (i+1)+5,crect.bottom - 21, str1);
			ldc.TextOut(m_squareWidth * (i+1)+5,5,str2);
		}
	}
	COLORREF textcolor(RGB(255,255,255));
	COLORREF backcr(RGB(20,140,17));	 
	ldc.SetBkColor(backcr);
	ldc.SetTextColor(textcolor);
	ldc.TextOut(470,25,"Click on dice");

	CDC ldc1;
	CBitmap localbmp1;

	localbmp1.LoadBitmap(IDB_DICE + m_diceBitmapId);
	ldc1.CreateCompatibleDC(&ldc);
	ldc1.SelectObject(&localbmp1); 
	ldc.BitBlt(470,50,50,50,&ldc1,0,0,SRCCOPY);
  
	CDC ldc2;
	CBitmap localbmp2;

	localbmp2.LoadBitmap(IDB_DICE + m_diceBitmapId1);
	ldc2.CreateCompatibleDC(&ldc);
	ldc2.SelectObject(&localbmp2); 
	ldc.BitBlt(510,50,50,50,&ldc2,0,0,SRCCOPY);
	CString str;
	str.Format("%d       %d",m_diceBitmapId,m_diceBitmapId1);
	ldc.TextOut(490,90,str);	
	str.Format("%d       %d",m_lastDiceMove1,m_lastDiceMove2);
	ldc.TextOut(490,120,str);	
	if(m_sendButtonClickedFlag == 1)
	{
		ldc.SelectObject(bluebrush);
		ldc.SetBkColor(bluecr);
	}
	else
	{
		ldc.SelectObject(redbluebrush);
		ldc.SetBkColor(redbluecr);
	}
	ldc.RoundRect(450,430,550,455,10,10);
	ldc.TextOut(480,435,"Send");

	COLORREF cr1(RGB(255,255,255));
	ldc.SetBkColor(cr1);

	if(m_mouseMoveFlag == true)
	{
		CRect rect = m_moveRect;
		int piece_id;
		ldc.SetBkColor(bkcrRef);
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[m_point.x][m_point.y].GetPieceData(piece_id,piece_color,piece_type,piece_state);
		if(piece_id < 0)
		{
			dc.BitBlt(0,0,600,700,&ldc,0,0,SRCCOPY);  
			return;
		}
		CRect rect1(rect.left+10,rect.top+10,rect.right-10,rect.bottom-10);
		//ldc.Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);
		switch(piece_id)
		{
			case CHECKERS_WHITE:
				{
					CBrush brush(m_optDlg.m_crefWhitePieceColor);
					ldc.FillRgn(&rgn,&brush );						 
					ldc.FrameRgn(&rgn,&brush,1,1);
				}
				break; 

			case CHECKERS_BLACK:	
				{
					CBrush brush(m_optDlg.m_crefBlackPieceColor);
					ldc.FillRgn(&rgn,&brush);						 
					ldc.FrameRgn(&rgn,&brush,1,1);
				}
				break; 			
		}		
	}
	dc.BitBlt(0,0,600,700,&ldc,0,0,SRCCOPY);

}
void CNetChessView::Initialize()
{
	m_mouseMoveFlag = false;
	m_moveRect =0;
	m_sendButtonClickedFlag = 0;	
	m_player_turn = WHITE;	
	m_timerFlag = false;
	m_squareWidth = 30;
	m_level = 18;
	m_GameType = AMERICAN; 		
	m_timerFlag = false;	
	m_diceBitmapId = 0;
	m_diceBitmapId1 = 0;
	m_point.x = m_point.y = -1;
	m_bearindex.x =3;
	m_bearindex.y =14;
	for(int i=0;i<10;i++)
	{
		m_moveLength[i] =0;
		memset(m_moveInfo,'\0',100);
	}
	m_moveIndex = -1;
	m_diceClickFlag = 0;
	m_lastDiceMove1 = 0;
	m_lastDiceMove2 = 0;
}

int CNetChessView::GetBitmapId(int piece_id)
{
	return -1;
}
void CNetChessView::OnInitialUpdate() 
{
	CView::OnInitialUpdate();	 

	if(m_ChatDlg == NULL)
	{
		m_ChatDlg = new CMessageSend();
		m_ChatDlg->Create(IDD_DIALOG_MESSAGE,this);		
	}
	int xstart,ystart;
	xstart = 30;
	ystart = 30;
	 
	int x,y=ystart;
	for ( int i = 0; i < m_level; i++)
	{
		x = xstart;
		for( int j = 0; j < m_level; j++)
		{
			CRect rect(x,y, x+ m_squareWidth, y+m_squareWidth);

			cb[i][j].SetRect(rect);
			cb[i][j].SetPieceType(BLANK);			 
			cb[i][j].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
			 
			x += m_squareWidth;
		}
		y += m_squareWidth;
	}
	COLOR_TYPE typex = BLACK;
	 
	for(i = 0; i< m_level; i++)
	{
		if(typex == WHITE)
			typex = BLACK;
		else
			typex = WHITE;
		COLOR_TYPE type = typex;
		for(int j=0; j < m_level; j++)
		{
			
			cb[i][j].SetColorType(type);
			if(type == WHITE)
				type = BLACK;
			else
				type = WHITE;
		}
	}	 	 

	for(int j = 0; j < 5 ;j ++)
	{
		cb[j][0].SetPieceData(CHECKERS_BLACK,BLACK,NORMAL,PIECE_NOT_MOVING);
		cb[13-j-1][0].SetPieceData(CHECKERS_WHITE,WHITE,NORMAL,PIECE_NOT_MOVING);
		cb[j][7].SetPieceData(CHECKERS_WHITE,WHITE,NORMAL,PIECE_NOT_MOVING);
		cb[13-j-1][7].SetPieceData(CHECKERS_BLACK,BLACK,NORMAL,PIECE_NOT_MOVING);		
	}
	for(int j=0;j<3;j++)
	{
		cb[j][4].SetPieceData(CHECKERS_WHITE,WHITE,NORMAL,PIECE_NOT_MOVING);
		cb[13-j-1][4].SetPieceData(CHECKERS_BLACK,BLACK,NORMAL,PIECE_NOT_MOVING);
        if(j != 2)
		{
			cb[j][12].SetPieceData(CHECKERS_BLACK,BLACK,NORMAL,PIECE_NOT_MOVING);
			cb[13-j-1][12].SetPieceData(CHECKERS_WHITE,WHITE,NORMAL,PIECE_NOT_MOVING);		
		}
	}
	int count = -4;
	for(int j=17;j>=0;j--)
	{
		if(j==6)
		{
			/*for (int i=0;i<18;i++)
			{
				cb[i][6].SetIndex();
				cb[6][i].SetIndex(50);
			}*/
			continue;
		}
		for (int i=12;i>6;i--)
		{
			cb[i][j].SetIndex(count);
			cb[12-i][j].SetIndex(25-count);
		}
		count++;
	}
	for(i=0;i<18;i++)
	{
		cb[i][6].SetIndex(cb[i][13].GetIndex());
	}
	
/*	for(i=0;i<18;i++)
	{
		for(j=0;j<18;j++)
			writeMessage("%d %d %d",i,j,cb[i][j].GetIndex());
	}*/
}

void CNetChessView::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	writeMessage("OnLButtonDown");
	OnLButtonDownAction(nFlags,point);	 
 	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	writeMessage("OnLbuttonUp");
	OnLButtonUpAction(nFlags,point);	 
	CView::OnLButtonUp(nFlags, point);
}

void CNetChessView::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default	 
	OnMouseMoveAction(nFlags,point);
	CView::OnMouseMove(nFlags, point);
}

void CNetChessView::OnToolsClient() 
{
	// TODO: Add your command handler code here
	if(m_pServerSocket != NULL)
	{
		AfxMessageBox("Running as Server, cannot run as client");
		return;
	}
	if(m_pClientSocket != NULL)
	{
		AfxMessageBox("Already running as client");
		return;
	}
	Initialize();
	OnInitialUpdate();
	DrawBoard();

	CServerInfoDlg dlg(this,CLIENT);
	if(dlg.DoModal()==IDOK)
	{
		m_player_turn = WHITE;
		SetPaneText(4,"WHITE");
		m_myname = dlg.m_name;
		((CMessageSend*)m_ChatDlg)->m_name = m_myname;
		m_whoAmI= "BLACK";
		SetPaneText(2,m_whoAmI);		
		m_pClientSocket = new CClientSocket();
		CString str;
		((CClientSocket*)m_pClientSocket)->SetInfo(dlg.m_strIPAddress, dlg.m_port_nunber);
		m_pClientSocket->Create();
		m_pClientSocket->Connect(dlg.m_strIPAddress, dlg.m_port_nunber) !=0  || GetLastError();
	}		
}

void CNetChessView::OnToolsServer() 
{
	// TODO: Add your command handler code here
	if(m_pServerSocket != NULL)
	{
		AfxMessageBox("Already running as server");
		return;
	}
	if(m_pClientSocket != NULL)
	{
		AfxMessageBox("Already running as client");
		return;
	}
	Initialize();
	OnInitialUpdate();
	DrawBoard();
	
	CServerInfoDlg dlg(this,SERVER);
	if(dlg.DoModal()==IDOK)
	{
		m_pServerSocket = new CServerSocket();
		((CServerSocket*)m_pServerSocket)->SetInfo(dlg.m_port_nunber);
		((CServerSocket*)m_pServerSocket)->CreateServer(dlg.m_port_nunber);		 
		m_player_turn = WHITE;	 
		SetPaneText(4,"WHITE");
		((CMessageSend*)m_ChatDlg)->m_name = dlg.m_name;
		m_whoAmI = "WHITE";
		SetPaneText(2,m_whoAmI);
		m_myname = dlg.m_name;
	}
}
void CNetChessView::SetClientSocket(CAsyncSocket* sock)
{
	Initialize();
	OnInitialUpdate();
	DrawBoard();

	m_pClientSocket = sock;
}

CAsyncSocket* CNetChessView::GetClientSocket()
{	 
	return m_pClientSocket;
}
void CNetChessView::SetData(char* data,int length)
{
	switch(data[0])
	{
		case MOVE:
			{	
				writeMessage("received move command");
				int piece_id;
				COLOR_TYPE  piece_color;
				PIECE_TYPE  piece_type;
				STATE piece_state;
				int to_piece_id;
				int rm_piece_id;
				
				cb[data[2]][data[3]].GetPieceData(piece_id,piece_color,piece_type,piece_state);
				
				cb[data[2]][data[3]].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);					 
				cb[data[10]][data[11]].SetPieceData(piece_id,piece_color,piece_type,piece_state);
				memcpy(&rm_piece_id,&data[20],4);
				if(rm_piece_id != -1)
				{
					cb[data[18]][data[19]].SetPieceData(rm_piece_id,(COLOR_TYPE)data[24],(PIECE_TYPE)data[25],PIECE_NOT_MOVING);
					writeMessage("blot piece id not null rm_piece_id %d",rm_piece_id);
					writeMessage("data 18 %d data 19 %d data 24 %d data 25 %d",data[18],data[19],data[24],data[25]);
				}
				writeMessage("from x %d from y%d to x %d to y %d",data[2],data[3],data[10],data[11]);				
				m_sendButtonClickedFlag = 0;
				m_diceClickFlag = 0;
				m_lastDiceMove1 = 0;
				m_lastDiceMove2 = 0;
				m_diceBitmapId = 0;
				m_diceBitmapId1 = 0;				
				DrawBoard();
				
				ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);					
				KillTimer(SHELL_ICON_TIMER_EVENT_ID);
				SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
				m_timerFlag = true;
			}
				break;

			case BEAROFF:
			{	
				writeMessage("received bearoff command");
				int piece_id;
				COLOR_TYPE  piece_color;
				PIECE_TYPE  piece_type;
				STATE piece_state;
				int to_piece_id;
				int rm_piece_id;
				
				cb[data[2]][data[3]].GetPieceData(piece_id,piece_color,piece_type,piece_state);
				
				cb[data[2]][data[3]].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);					 
				cb[data[10]][data[11]].SetPieceData(piece_id,piece_color,piece_type,piece_state);
				m_bearindex.x = data[10];
				m_bearindex.y = data[11];
				
				writeMessage("from x %d from y%d to x %d to y %d",data[2],data[3],data[10],data[11]);				
				m_sendButtonClickedFlag = 0;
				m_diceClickFlag = 0;
				m_lastDiceMove1 = 0;
				m_lastDiceMove2 = 0;
				m_diceBitmapId = 0;
				m_diceBitmapId1 = 0;
				DrawBoard();				
				ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);					
				KillTimer(SHELL_ICON_TIMER_EVENT_ID);
				SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
				m_timerFlag = true;
			}
			break;

			case YOURTURN:
				m_player_turn = m_player_turn == WHITE ? BLACK : WHITE;
				SetPaneText(4,m_player_turn == WHITE ? "WHITE" : "BLACK");
				m_moveIndex = -1;
				m_sendButtonClickedFlag = 0;
				m_diceClickFlag = 0;
				m_lastDiceMove1 = 0;
				m_lastDiceMove2 = 0;
				m_diceBitmapId = 0;
				m_diceBitmapId1 = 0;
				DrawBoard();
				break;
			case DICEROLL:
			{	
				writeMessage("received DICEROLL move command");
				
				int id,id1;
				
				memcpy(&id, &data[1],4); 
				memcpy(&id1,&data[5],4);
				m_diceBitmapId = id;
				m_diceBitmapId1 = id1;
				
				DrawBoard();
				ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);	
				
				KillTimer(SHELL_ICON_TIMER_EVENT_ID);
				SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
				m_timerFlag = true;
			}
			break;
		case TEXT:
			{	
				((CMessageSend*)m_ChatDlg)->SetReceiveData(&data[1]);	
				DrawBoard();
				ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);					
				KillTimer(SHELL_ICON_TIMER_EVENT_ID);
				SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
				m_timerFlag = true;				 
			}
			break;
	 
		case FILEDATA:
						
			break;
		case UNDO:
				{
					OnEditUndoAction();
					ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);	
					DrawBoard();
					KillTimer(SHELL_ICON_TIMER_EVENT_ID);
					m_timerFlag = true;
					SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
				}
			break;
		case REDO:
				{
					OnEditRedoAction();
					ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);						
					DrawBoard();
					KillTimer(SHELL_ICON_TIMER_EVENT_ID);
					m_timerFlag = true;
					SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
				}
			break;
		case NEWGAME:
				{
					ShowTrayIcon(NIM_ADD,IDR_MAINFRAME,0);					
					DrawBoard();
					KillTimer(SHELL_ICON_TIMER_EVENT_ID);
					m_timerFlag = true;
					SetTimer(SHELL_ICON_TIMER_EVENT_ID,1000,NULL);
					AfxMessageBox("Your opponent has requested for new game");
					OnFileNewAction();
					writeMessage("received new game request");
				}
				break;
		case SYNC:
	
			break;
		case NOTACCEPTED:
				AfxMessageBox("server not accepted for playing the game");
				break;
		default:
			break;
	}
 
}
void CNetChessView::SendSockData(unsigned char *data,int length)
{
	char clength[5];	 
	memcpy(clength,&length,4);
	if(m_pClientSocket != NULL)
	{	 
		m_pClientSocket->Send(clength,4);	 
		m_pClientSocket->Send(data,length);	 	
	}
}

void CNetChessView::OnToolsSendmessage() 
{
	if(m_pClientSocket != NULL)
	{	 
		m_ChatDlg->ShowWindow(SW_SHOW);	
	}
	else
	{
		AfxMessageBox("Not connected to network");
	}
}

void CNetChessView::OnFileOpen() 
{
	
}

void CNetChessView::OnFileSave() 
{
	
}


void CNetChessView::OnViewLetter() 
{
	// TODO: Add your command handler code here
	if(m_LetterFlag == false)
	{	 
		m_LetterFlag = true;
	}
	else
	{	 
		m_LetterFlag = false;
	}
	DrawBoard(); 
}

void CNetChessView::OnUpdateViewLetter(CCmdUI* pCmdUI) 
{

}

void CNetChessView::OnViewNumber() 
{

}

void CNetChessView::OnUpdateViewNumber(CCmdUI* pCmdUI) 
{

}
LRESULT CNetChessView::OnMessageColorData(WPARAM wParam,LPARAM lParam)
{	 
	DrawBoard();
	return 0;
}


void CNetChessView::OnFileSavehistory() 
{

}
bool CNetChessView::CheckValidMove(int i,int j, int& rmx,int& rmy)
{
	writeMessage("CheckValidMove i %d j %d x %d y %d",i,j,m_point.x,m_point.y);
	if(m_lastDiceMove1 != 0 && m_lastDiceMove2 != 0)
	{
		writeMessage("Both moves are done");
		return false;
	}
	PIECE_TYPE from_piece_type;
	COLOR_TYPE from_piece_color;
	int from_pieceid;
	STATE from_piece_state;
	cb[m_point.x][m_point.y].GetPieceData(from_pieceid,from_piece_color,from_piece_type,from_piece_state);
	int m_fromindex,m_toindex;
	 	
	PIECE_TYPE to_piece_type;
	COLOR_TYPE to_piece_color;
	int to_pieceid;
	STATE to_piece_state;
	cb[j][j].GetPieceData(to_pieceid,to_piece_color,to_piece_type,to_piece_state);
	m_toindex = cb[i][j].GetIndex();
	m_fromindex = cb[m_point.x][m_point.y].GetIndex();
	//check balls in blot
	for(int k=0;k<13 && m_point.y != 6;k++)
	{
		if(cb[k][6].GetPieceId() != -1 && cb[k][6].GetPieceId() == from_pieceid)
		{
			writeMessage("blot bar not empty");
			return false;
		}
	}		
	writeMessage("from index %d to index %d",m_fromindex,m_toindex);
	int icountBalls = countBalls(i,j); 
	writeMessage("from index %d to index %d, icount balls %d, target base pieceid %d frompieceid %d",
		m_fromindex,m_toindex,icountBalls,cb[i<6?0:12][j].GetPieceId(),from_pieceid);
	if(	(icountBalls == 0 || icountBalls == 1) 	|| 
	    (icountBalls > 1 && from_pieceid == cb[i<6?0:12][j].GetPieceId())
	  )
	{
		if(icountBalls == 1 && from_pieceid != cb[i<6?0:12][j].GetPieceId())
		{
			writeMessage("from pieceid %d,new pieceid %d,i %d",
				from_pieceid, cb[i<6?0:12][j].GetPieceId(),i<6?0:12);
			rmx = i<6?0:12;
			rmy = j;
			writeMessage("rmx %d rmd %d",rmx,rmy);
		}
		if(from_pieceid == CHECKERS_BLACK)
		{
			int diff = abs(m_fromindex - m_toindex);				
			writeMessage("m_bitmapPieceId %d m_bitmapPiceId1, %d diff %d",
				m_diceBitmapId, m_diceBitmapId1,diff);

			if( m_fromindex > m_toindex 			&& 
				(diff == m_diceBitmapId|| diff == m_diceBitmapId1))
			{
				(m_lastDiceMove1 != 0 ? m_lastDiceMove2 : m_lastDiceMove1) = diff;
				writeMessage("condition is true, is valid move lastDiceMove1 %d lastDiceMove2 %d",m_lastDiceMove1,m_lastDiceMove2);
				return true;
			}
			else 
			{
				writeMessage("not valid move");
				return false;
			}
		}
		else
		{
			int diff = abs(m_toindex - m_fromindex);
			writeMessage("m_bitmapPieceId %d m_bitmapPiceId1, %d diff %d",
			m_diceBitmapId, m_diceBitmapId1,diff);			
			if(	m_fromindex < m_toindex &&
				(diff == m_diceBitmapId|| diff == m_diceBitmapId1))
			{			   
			   (m_lastDiceMove1 != 0 ? m_lastDiceMove2 : m_lastDiceMove1) = diff;
			   writeMessage("condition is true, is valid move lastDiceMove1 %d lastDiceMove2 %d",m_lastDiceMove1,m_lastDiceMove2);
			   return true;
			}
			else 
			{
				writeMessage("not valid move");
				return false;
			}
		}
	}
	writeMessage("base condition failed");
	return false;
}
int CNetChessView::countBalls(int i,int j)
{
	int count = 0;
	if(i > 6)
	{
		for(int k=7;k<13;k++)
		{
			if(cb[k][j].GetPieceId() > 0) count++;
		}
	}
	else
	{
		for(int k=0;k<6;k++)
		{
			if(cb[k][j].GetPieceId() > 0) count++;
		}
	}
	return count;
}
void CNetChessView::OnLButtonDownAction(UINT nFlags, CPoint point) 
{
	writeMessage("OnLButtonDownAction");
	// TODO: Add your message handler code here and/or call default
	if(((m_player_turn ==WHITE && m_pServerSocket == NULL) || (m_player_turn == BLACK && m_pServerSocket != NULL)) && !(m_pServerSocket == NULL && m_pClientSocket == NULL))
	{
		writeMessage("OnLButtoncondition true %d %d %d",m_player_turn,m_pServerSocket,m_pClientSocket);
		return;
	}
	CRect diceRect1(470,50,510,90);
	CRect diceRect2(510,50,560,90); 

	ShowTrayIcon(NIM_DELETE,IDR_MAINFRAME,0);	
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;

	if( m_diceClickFlag == 0 && (diceRect1.PtInRect(point) || diceRect2.PtInRect(point)))
	{		
		m_diceBitmapId = getRandom(6);
		Sleep(7);
		m_diceBitmapId1 = getRandom(6);
		m_point.x = m_point.y = -1;
		writeMessage("%d %d",m_diceBitmapId,m_diceBitmapId1);
		char data[100];							 
		int k=0;
		data[k++] = DICEROLL;				
		memcpy(&data[k],&m_diceBitmapId,4);
		k+=4;
		memcpy(&data[k],&m_diceBitmapId1,4);
		k+=4;
		SendSockData((unsigned char*)data,k);
		DrawBoard();
		CView::OnLButtonDown(nFlags, point);
		m_diceClickFlag = 1;
		return;
	}
	
	CRect RoundRect(450,430,550,450);
	if(RoundRect.PtInRect(point) && m_diceClickFlag == 1)
	{
		//send the move
		m_sendButtonClickedFlag = 1;		
		DrawBoard();
		return;
	}
	for(int i = 0; i < 18; i++)
	{
		for( int j = 0; j < 18; j++)
		{
			CRgn rgn;
			CRect rect = cb[i][j].GetRect();
		
			rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);
			if(rgn.PtInRegion(point) && m_player_turn == cb[i][j].GetPieceColor())
			{	
				if(i<=6)
				{
					if(cb[i+1][j].GetPieceId() != -1)
						return;
				}
				else if(i > 6)
				{
					if(cb[i-1][j].GetPieceId() != -1)
						return;
				}
				m_point.x = i; m_point.y = j;
				cb[i][j].SetPieceState(PIECE_MOVING);
			 	m_mouseMoveFlag = true;
				return;	 
			}

		}		
	}	
	
	DrawBoard();
	CView::OnLButtonDown(nFlags, point);
}

void CNetChessView::OnLButtonUpAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	//send the data if clicked on round rect
	writeMessage("Onlbutton action");
	CRect RoundRect(450,430,550,450);
	if(RoundRect.PtInRect(point) && m_sendButtonClickedFlag == 1)
	{
		//send the move		
		writeMessage("in send button");
		for(int i=0;i<=m_moveIndex;i++)
		{
			SendSockData((unsigned char*)m_moveInfo[i],m_moveLength[i]);
			memset(m_moveInfo[i],'\0',m_moveLength[i]);			
		}
		char data = YOURTURN;
		SendSockData((unsigned char*)&data,1);
		m_player_turn = m_player_turn == WHITE ? BLACK : WHITE;
		SetPaneText(4,m_player_turn == WHITE ? "WHITE" : "BLACK");
		m_moveIndex = -1;
		m_sendButtonClickedFlag = 0;
		m_diceClickFlag = 0;
		m_lastDiceMove1 = 0;
		m_lastDiceMove2 = 0;
		m_diceBitmapId = 0;
		m_diceBitmapId1 = 0;
		DrawBoard();
	}
	m_sendButtonClickedFlag = 0;
	
	
	if(m_mouseMoveFlag == false)
	{	 
		writeMessage("m_mouseMoveFlag is false");
		return;
	}	
	m_mouseMoveFlag = false;
	m_moveRect =0;
	//CRect diceRect1(275,200,315,240);
	//CRect diceRect2(325,200,365,240);
	
	cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);
	//check that the the balls are beared off
	CRect lefttop=cb[0][14].GetRect(),rightbottom=cb[17][17].GetRect();
	CRect bearect(lefttop.left,lefttop.top,rightbottom.right,rightbottom.bottom);
	if(bearect.PtInRect(point))
	{
		if(allBallsAreInHome() == false)
		{
			DrawBoard();
			return;
		}
		int piece_id;
		COLOR_TYPE  piece_color;
		PIECE_TYPE  piece_type;
		STATE piece_state;
		cb[m_point.x][m_point.y].GetPieceData(piece_id,piece_color,piece_type,piece_state);		
		//dont allow if the checker is not in their home
		if((piece_id == CHECKERS_WHITE && cb[m_point.x][m_point.y].GetIndex() < 19) ||
		   (piece_id == CHECKERS_BLACK && cb[m_point.x][m_point.y].GetIndex() > 6))
		{
			writeMessage("checker is not in home %d",cb[m_point.x][m_point.y].GetIndex());
			DrawBoard();
			return;
		}		
		int index = cb[m_point.x][m_point.y].GetIndex();
		writeMessage("bearing the ball with index %d piece_id",index,piece_id);
		if(piece_id == CHECKERS_WHITE)
		{
			writeMessage("white checkers");
			index = 25 - index;
			if(m_lastDiceMove1 == 0)
			{
				writeMessage("lastdice ball 1 is zero");
				if(index == m_diceBitmapId)
				{
					writeMessage("Index matched to first bitmapid");
					m_lastDiceMove1 = m_diceBitmapId;
				}
				else if(index == m_diceBitmapId1)
				{
					writeMessage("Index matched to second bitmapid");
					m_lastDiceMove1 = m_diceBitmapId1;
				}
				else 
				{
					writeMessage("index doesnot match to any dice values");
					DrawBoard();
					return;
				}
			}
			else if(m_lastDiceMove2 == 0)
			{
				writeMessage("last dice ball1 not zero, lastdice ball 2 is zero");
				if(index == m_diceBitmapId)
				{
					writeMessage("Index matched m_diceBitmapid");
					m_lastDiceMove2 = m_diceBitmapId;
				}
				else if(index == m_diceBitmapId1)
				{
					writeMessage("Index matched m_diceBitmapid1");
					m_lastDiceMove2 = m_diceBitmapId1;
				}
				else
				{
					writeMessage("Index does not match to any value");
					DrawBoard();
					return;
				}
			}
			else 
			{
				writeMessage("both moves are done");
				return;		
			}
		}
		else
		{			
			writeMessage("BLACK_CHEKERS, index %d",index);
			if(m_lastDiceMove1 == 0)
			{
				writeMessage("lastdicemove1 0");
				if(index == m_diceBitmapId)
				{
					writeMessage("index matched to first value");
					m_lastDiceMove1 = m_diceBitmapId;
				}
				else if(index == m_diceBitmapId1)
				{
					writeMessage("index matched to second value");
					m_lastDiceMove1 = m_diceBitmapId1;
				}
				else 
				{
					writeMessage("index does not matched to any bitmap");
					DrawBoard();
					return;
				}
			}
			else if(m_lastDiceMove2 == 0)
			{
				writeMessage("lastdicemove1 is not zero and lastdicemove is zero");
				if(index == m_diceBitmapId)
				{
					writeMessage("index matched to first bitmap");
					m_lastDiceMove2 = m_diceBitmapId;
				}
				else if(index == m_diceBitmapId1)
				{
					writeMessage("index matched to second bitmap");
					m_lastDiceMove2 = m_diceBitmapId1;
				}
				else 
				{
					writeMessage("index does not match to any one");
					DrawBoard();
					return;
				}
			}
			else 
			{
				writeMessage("invalid piece id");
				DrawBoard();
				return;		
			}
		}
		writeMessage("send message to other player");
		m_bearindex.x++;
		if(m_bearindex.x == 13)
		{
			m_bearindex.x = 4;
			m_bearindex.y++;
		}
		cb[m_bearindex.x][m_bearindex.y].SetPieceData(piece_id,piece_color,piece_type,piece_state);		
		char data[100];							 
		int k=0;
		data[k++] = BEAROFF;
		data[k++] = m_white_on_top;
		data[k++] = (char)m_point.x;
		data[k++] = (char)m_point.y;
		memcpy(&data[k],&piece_id,4);
		k+=4;
		data[k++] = piece_color;
		data[k++] = piece_type;
		data[k++] = m_bearindex.x;
		data[k++] = m_bearindex.y;
		int topieceid = -1;
		memcpy(&data[k],&topieceid,4);
		k+=4;
		data[k++] = NONE;
		data[k++] = BLANK;
		data[k++] = 0;
		data[k++] = 0;
		int rm_piece_id = -1;
		memcpy(&data[k],&rm_piece_id,4);
		k+=4;
		data[k++] = NONE;
		data[k++] = BLANK;
		memcpy(&data[k],&m_topHistory,4);
		k+=4;
		m_moveIndex++;
		m_moveLength[m_moveIndex] = k;
		memcpy(m_moveInfo[m_moveIndex],data,k);												 
		cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);		
		m_point.x = m_point.y = -1;
		DrawBoard();	 
		return;
	}
	writeMessage("after bear off the balls");
    for(int i = 0; i < m_level; i++)
	{
		if(i == 6) continue;
		for( int j = 0; j < m_level; j++)
		{	
			if(j == 6) continue;
			if(cb[i][j].GetPieceId() == -1)
			{
				CRgn rgn;
				CRect rect1 = cb[i>6?7:0][j].GetRect();
				CRect rect2 = cb[i>6?12:5][j].GetRect();
				CRect rect(rect1.left,rect1.top,rect2.right,rect2.bottom);
				rgn.CreateEllipticRgn(rect.left, rect.top, rect.right, rect.bottom);	
				if(rgn.PtInRegion(point)&& rect != cb[m_point.x][m_point.y].GetRect())
				{						
					int piece_id;
					COLOR_TYPE  piece_color;
					PIECE_TYPE  piece_type;
					STATE piece_state;
					int to_piece_id;
					COLOR_TYPE  to_piece_color;
					PIECE_TYPE  to_piece_type;
					STATE to_piece_state;
					int rm_piece_id=-1;
					COLOR_TYPE  rm_piece_color=NONE;
					PIECE_TYPE  rm_piece_type=BLANK;
					STATE rm_piece_state=PIECE_NOT_MOVING;
					cb[m_point.x][m_point.y].GetPieceData(piece_id,piece_color,piece_type,piece_state);
					cb[i][j].GetPieceData(to_piece_id,to_piece_color,to_piece_type,to_piece_state);
					cb[m_point.x][m_point.y].SetPieceState(PIECE_NOT_MOVING);
					if(piece_color == to_piece_color)
					{
						m_point.x = m_point.y = -1;
						DrawBoard();
						return;
					}
					int rmx=-1,rmy=-1;
					writeMessage("before valid %d %d %d %d",i,j,rmx,rmy);
					if(CheckValidMove(i,j,rmx,rmy) == true)
					{
						writeMessage("after valid %d %d %d %d",i,j,rmx,rmy);
						if(i <=6 )
						{
							for(int k=0; k <= i;k++)
							{
								if(cb[k][j].GetPieceId() == -1)
								{
									i = k;
									break;
								}
							}
						}
						else
						{
							for(int k=13-1 ; k >= i;k --)
							{
								if(cb[k][j].GetPieceId() == -1)
								{
									i = k;
									break;
								}
							}
						}
						writeMessage("after valid1 %d %d %d %d",i,j,rmx,rmy);
						int ii=0;
						if(rmx != -1)
						{
							writeMessage("rmx not -1, after valid %d %d %d %d",i,j,rmx,rmy);
							cb[rmx][rmy].GetPieceData(rm_piece_id,rm_piece_color,rm_piece_type,rm_piece_state);					 
							i=rmx;
							j=rmy;
							int k =0;
							//cb[rmx][rmy].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);
							if(rm_piece_id == CHECKERS_WHITE)
							{
								for(k = 12;k > 6;k--)
								{
									if(cb[k][6].GetPieceId() == -1)
									{
										cb[k][6].SetPieceData(rm_piece_id,rm_piece_color,rm_piece_type,rm_piece_state);					 
										writeMessage("removed ball is put in blot position");
										break;
									}
								}
							}
							else
							{
								for(k = 0;k<6;k++)
								{
									if(cb[k][6].GetPieceId() == -1)
									{
										cb[k][6].SetPieceData(rm_piece_id,rm_piece_color,rm_piece_type,rm_piece_state);					 
										writeMessage("removed ball is put in blot position");
										break;
									}
								}
							}
							ii = k;
						}
						writeMessage("rmx -1 is over,after valid %d %d %d %d",i,j,rmx,rmy);						
						cb[i][j].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);
						cb[m_point.x][m_point.y].SetPieceType(BLANK);
						cb[m_point.x][m_point.y].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
						//Store move info

						char data[100];							 
						int k=0;
						data[k++] = MOVE;
						data[k++] = m_white_on_top;
						data[k++] = m_point.x;
						data[k++] = m_point.y;
						memcpy(&data[k],&piece_id,4);
						k+=4;
						data[k++] = piece_color;
						data[k++] = piece_type;
						data[k++] = i;
						data[k++] = j;
						memcpy(&data[k],&to_piece_id,4);
						k+=4;
						data[k++] = to_piece_color;
						data[k++] = to_piece_type;
						data[k++] = ii;
						data[k++] = 6;
						memcpy(&data[k],&rm_piece_id,4);
						k+=4;
						data[k++] = rm_piece_color;
						data[k++] = rm_piece_type;
						memcpy(&data[k],&m_topHistory,4);
						k+=4;
						m_moveIndex++;
						m_moveLength[m_moveIndex] = k;
						memcpy(m_moveInfo[m_moveIndex],data,k);												 
						m_point.x = m_point.y = -1;
					}
					DrawBoard();
					return;
				}
			}
		}
	}
	m_point.x = m_point.y = -1;
	DrawBoard();	 
}

void CNetChessView::OnMouseMoveAction(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_mouseMoveFlag == false)
		return;	 
	 
	CRect rect( point.x -25, point.y - 25, point.x + 25, point.y + 25);				  
	m_moveRect = rect;	 
	DrawBoard();	 
}

void CNetChessView::OnEditUndo() 
{
	// TODO: Add your command handler code here
	OnEditUndoAction();
	OnEditUndoAction();
	m_lastDiceMove1 = 0;
	m_lastDiceMove2 = 0;
	DrawBoard();
}
void CNetChessView::OnEditUndoAction()
{
	if(m_moveIndex < 0)
		return;
	int piece_id;
	COLOR_TYPE  piece_color;
	PIECE_TYPE  piece_type;
	STATE piece_state;

	int to_piece_id;
	COLOR_TYPE  to_piece_color;
	PIECE_TYPE  to_piece_type;
	STATE to_piece_state;

	int rm_piece_id=-1;
	COLOR_TYPE  rm_piece_color=NONE;
	PIECE_TYPE  rm_piece_type=BLANK;
	STATE rm_piece_state=PIECE_NOT_MOVING;
	int fromx,fromy,tox,toy,blotx,bloty;
	char data[100];
	memcpy(data,&m_moveInfo[m_moveIndex],m_moveLength[m_moveIndex]);
	int k = 0;
	int type;
	type = data[k++]; //MOVE or BEAROFF
	k++; //m_white_on_top
	fromx = data[k++];
	fromy = data[k++];
	memcpy(&piece_id,&data[k],4);
	k+=4;
	piece_color = (COLOR_TYPE)data[k++];
	piece_type = (PIECE_TYPE)data[k++];
	tox = data[k++];
	toy = data[k++];
	memcpy(&to_piece_id, &data[k],4);
	k+=4;
	to_piece_color = (COLOR_TYPE)data[k++];
	to_piece_type = (PIECE_TYPE)data[k++];
	blotx = data[k++];
	bloty = data[k++];
	if(type == BEAROFF)
	{
		m_bearindex.x--;
		if(m_bearindex.x == 3 && m_bearindex.y != 13)
		{
			m_bearindex.x = 12;
			m_bearindex.y--;
		}
	}
	memcpy(&rm_piece_id, &data[k],4);
	k+=4;
	rm_piece_color = (COLOR_TYPE)data[k++];
	rm_piece_type = (PIECE_TYPE)data[k++];
	int temp;//history,obsolete
	memcpy(&temp, &data[k],4);
	k+=4;
	cb[fromx][fromy].SetPieceData(piece_id,piece_color,piece_type,PIECE_NOT_MOVING);
	cb[tox][toy].SetPieceData(to_piece_id,to_piece_color,to_piece_type,PIECE_NOT_MOVING);
	if(rm_piece_id != -1)
	{
		cb[tox][toy].SetPieceData(rm_piece_id,rm_piece_color,rm_piece_type,PIECE_NOT_MOVING);
		cb[blotx][bloty].SetPieceData(-1,NONE,BLANK,PIECE_NOT_MOVING);
	}
	m_moveIndex--;	
}

void CNetChessView::OnEditRedo() 
{
	// TODO: Add your command handler code here	 	 
	OnEditRedoAction();

}

void CNetChessView::OnEditRedoAction()
{

}
void CNetChessView::OnRButtonDown(UINT nFlags, CPoint point) 
{
	
	CView::OnRButtonDown(nFlags, point);
}

void CNetChessView::OnUpdateToolsServer(CCmdUI* pCmdUI) 
{
	
}

void CNetChessView::OnUpdateToolsClient(CCmdUI* pCmdUI) 
{

}

void CNetChessView::OnPrint(CDC* pDC, CPrintInfo* pInfo) 
{
	// TODO: Add your specialized code here and/or call the base class
	DrawBoard();
	CView::OnPrint(pDC, pInfo);
}

void CNetChessView::OnTimer(UINT nIDEvent) 
{
	static int state=1;	 
	switch(nIDEvent)
	{
		case SHELL_ICON_TIMER_EVENT_ID:

			{			
				
				if(state == 1)
				{					
					ShowTrayIcon(NIM_MODIFY,IDR_MAINFRAME,0);					
					state = 0;
				}
				else
				{
					ShowTrayIcon(NIM_MODIFY,IDI_ICON_MAINFRAME_OPPOSITE,0);					
					state = 1;					
				}
			}
			break;
		default:
			break;
		 
	}
	CView::OnTimer(nIDEvent);
}
void CNetChessView::KillTimerEvent()
{
	 
	KillTimer(SHELL_ICON_TIMER_EVENT_ID);
	m_timerFlag = false;
}

void CNetChessView::OnFileNew() 
{
	OnFileNewAction(); 
	unsigned char data=NEWGAME;
	SendSockData(&data,1);
	 
}
void CNetChessView::OnFileNewAction()
{
	Initialize();
	OnInitialUpdate();
	DrawBoard();	

}

void CNetChessView::OnViewHistory() 
{

}

void CNetChessView::OnToolsWhiteontop() 
{

}

 

void CNetChessView::OnEditMovefirst() 
{
	// TODO: Add your command handler code here

}

void CNetChessView::OnEditMovelast() 
{

}

void CNetChessView::OnHelpHowtoplay() 
{
	//AfxMessageBox(helpMsg);

	CHowToPlay dlg;	
	dlg.DoModal();
	// TODO: Add your command handler code here
	
}

void CNetChessView::OnToolsDisconnect() 
{
	// TODO: Add your command handler code here
	 
	if(m_pClientSocket == NULL)
	{
		AfxMessageBox("Not connected to network");
		if(m_pServerSocket != NULL)
		{
			if(AfxMessageBox("Are you sure, you want to disconnect",MB_YESNO)==IDYES)
			{
				delete m_pServerSocket;
				m_pServerSocket = NULL;
			}
		}
		return;
	}
	if(m_pClientSocket != NULL)
	{ 
		if(AfxMessageBox("Are you sure, you want to disconnect",MB_YESNO)==IDYES)
		{
			m_pClientSocket->ShutDown(2);
			m_pClientSocket->Close();
			delete m_pClientSocket;
			m_pClientSocket = NULL; 
			DrawBoard();
		}
	}
}

void CNetChessView::OnEditProperties() 
{
	// TODO: Add your command handler code here
	CPropertiesDlg dlg(this);
	if(m_pServerSocket != NULL)
	{
		if(m_pClientSocket != NULL)
		{
			CString ipaddr;int port;
			((CClientSocket*)m_pClientSocket)->GetInfo(ipaddr,port);
			dlg.SetInfo(SERVER,ipaddr,port,((CServerSocket*)m_pServerSocket)->m_portnumber);
		}
		else
		{
			dlg.SetInfo(SERVER," ",0,((CServerSocket*)m_pServerSocket)->m_portnumber);			 
		}
	}
	else if(m_pClientSocket != NULL)
	{
		CString ipaddr;int port;
		((CClientSocket*)m_pClientSocket)->GetInfo(ipaddr,port);
		dlg.SetInfo(CLIENT,ipaddr,port,0);
	}
	else
	{
		dlg.SetInfo(-1,"",0,0);
	}
//dlg.UpdateData(FALSE);
	dlg.DoModal();	
}

void CNetChessView::OnToolsGametype() 
{

}
void CNetChessView::SetPaneText(int paneno,CString str)
{
	((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->m_wndStatusBar.SetPaneText(paneno,str);
}
void CNetChessView::ShowTrayIcon(DWORD message,int icon,int input)
{
		((CMainFrame*)((CNetChessApp*)AfxGetApp())->m_pMainWnd)->ShowTrayIcon(message,icon,input);
}

void CNetChessView::OnLButtonDblClk(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default
	writeMessage("OnLButtonDblClk");
	OnLButtonDownAction(nFlags,point);
	CPoint pt = getOffsetPoint();
	OnLButtonUpAction(nFlags,pt);
	CView::OnLButtonDblClk(nFlags, point);
}
CPoint CNetChessView::getOffsetPoint()
{
	if(m_mouseMoveFlag == false)
	{	 
		return 0;
	}
	writeMessage("getting offset on double button click");
	int index = cb[m_point.x][m_point.y].GetIndex();
	int pieceid = cb[m_point.x][m_point.y].GetPieceId();
	writeMessage("index and pieceid = %d %d",index,pieceid);
	writeMessage("lastdiceMoveid1 %d lastdicemoveid2 %d",
		m_lastDiceMove1,m_lastDiceMove2);
	if(pieceid == CHECKERS_WHITE)
	{
		writeMessage("CHECKERS_WHITE");
		if(m_lastDiceMove1 == 0)
		{
			writeMessage("lastDiceMove1 is zero, m_lastDiceMove1 %d,m_lastDiceMove2 %d m_diceBitmap1 %d m_diceBitmap2 %d",
				m_lastDiceMove1,m_lastDiceMove2,m_diceBitmapId,m_diceBitmapId1);			
			index = index + m_diceBitmapId;
			
		}
		else 
		{
			writeMessage("lastDiceMove1 is not zero, m_lastDiceMove1 %d,m_lastDiceMove2 %d m_diceBitmap1 %d m_diceBitmap2 %d",
				m_lastDiceMove1,m_lastDiceMove2,m_diceBitmapId,m_diceBitmapId1);
			if(m_lastDiceMove1 == m_diceBitmapId)
			{
				writeMessage("adding dice bitmap1");
				index = index + m_diceBitmapId1;
			}
			else
			{
				writeMessage("adding dice bitmap");
				index = index + m_diceBitmapId;
			}
		}
	}
	else
	{
		writeMessage("CHECKERS_BLACK");
		if(m_lastDiceMove1 == 0)
		{
			writeMessage("lastDiceMove1 is zero, m_lastDiceMove1 %d,m_lastDiceMove2 %d m_diceBitmap1 %d m_diceBitmap2 %d",
				m_lastDiceMove1,m_lastDiceMove2,m_diceBitmapId,m_diceBitmapId1);
			index = index - m_diceBitmapId;
			
		}
		else 
		{
			if(m_lastDiceMove1 == m_diceBitmapId)
			{
				writeMessage("sub dice bitmap1");
				index = index - m_diceBitmapId1;
			}
			else
			{
				writeMessage("sub dice bitmap");
				index = index - m_diceBitmapId;
			}
		}		
	}
	writeMessage("new index and pieceid = %d %d",index,pieceid);
	for(int j=0;j<13;j++)
	{
		if(j == 6) continue;
		if(cb[0][j].GetIndex() == index)
		{
			CRect rect = cb[0][j].GetRect();
			CPoint pt(rect.left + 10,rect.top + 10);
			writeMessage("found the index %d %d",0,j);
			return pt;
		}
		if(cb[12][j].GetIndex() == index)
		{
			CRect rect = cb[12][j].GetRect();
			CPoint pt(rect.left + 10,rect.top + 10);
			writeMessage("found the index %d %d",0,j);
			return pt;
		}
	}
	writeMessage("not matched");

	return 0;
}
bool CNetChessView::allBallsAreInHome()
{
	int pieceid = cb[m_point.x][m_point.y].GetPieceId();
	if(pieceid == CHECKERS_WHITE)
	{
		for(int i=0;i<13;i++)
		{
			for(int j=0;j<13;j++)
			{
				if(i < 6 && j > 6) continue;
				if(cb[i][j].GetPieceId() == pieceid)
				{
					writeMessage("ball at %d %d not in home",i,j);
					return false;
				}
			}
		}
	}
	else if (pieceid == CHECKERS_BLACK)
	{
		for(int i=0;i<13;i++)
		{
			for(int j=0;j<13;j++)
			{
				if(i > 6 && j > 6) continue;
				if(cb[i][j].GetPieceId() == pieceid)
				{
					writeMessage("ball at %d %d not in home",i,j);
					return false;
				}
			}
		}
	}
	writeMessage("all balls are in home");
	return true;
}
