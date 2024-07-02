// PickPieceDlg.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "PickPieceDlg.h"
#include "NetChessDoc.h"
#include "NetChessView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPickPieceDlg dialog


CPickPieceDlg::CPickPieceDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPickPieceDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPickPieceDlg)
	m_static_status = _T("Selected nothing");
	//}}AFX_DATA_INIT

	m_piecked_piece = -1;
	m_piece_type = BLANK;
	m_piece_color = NONE;
}


void CPickPieceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPickPieceDlg)
	DDX_Text(pDX, IDC_STATIC_STATUS, m_static_status);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CPickPieceDlg, CDialog)
	//{{AFX_MSG_MAP(CPickPieceDlg)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_BLACK, OnStaticBitmapBlack)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_BLACK_KING, OnStaticBitmapBlackKing)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_WHITE, OnStaticBitmapWhite)
	ON_BN_CLICKED(IDC_STATIC_BITMAP_WHITE_KING, OnStaticBitmapWhiteKing)
	ON_BN_CLICKED(IDC_STATIC_EMPTY, OnStaticEmpty)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPickPieceDlg message handlers

/*void CPickPieceDlg::OnStaticBishopBlack() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = BISHOP_BLACK;
	m_piece_type = BISHOP;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Bishop";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBishopWhite() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = BISHOP_WHITE;
	m_piece_type = BISHOP;
	m_piece_color = WHITE;
	m_static_status ="Selected White Bishop";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBitmapKnight() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = KNIGHT_WHITE;	
	m_piece_type = KNIGHT;
	m_piece_color = WHITE;
	m_static_status ="Selected White Knight";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticKingBlack() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = KING_BLACK;
	m_piece_type = KING;
	m_piece_color = BLACK;
	m_static_status ="Selected King Black";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticKingWhite() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = KING_WHITE;
	m_piece_type = KING;
	m_piece_color = WHITE;
	m_static_status ="Selected White King";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticKnightBlack() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = KNIGHT_BLACK;
	m_piece_type = KNIGHT;
	m_piece_color = BLACK;
	m_static_status ="Selected White Knight";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticPawnBlack() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = PAWN_BLACK;
	m_piece_type = PAWN;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Pawn";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticPawnWhite() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = PAWN_WHITE;
	m_piece_type = PAWN;
	m_piece_color = WHITE;
	m_static_status ="Selected White Pawn";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticQueenBlack() 
{
	// TODO: Add your control notification handler code here
	//m_piecked_piece = QUEEN_BLACK;
	m_piece_type = QUEEN;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Queen";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticQueenWhite() 
{
	// TODO: Add your control notification handler code here
//	m_piecked_piece = QUEEN_WHITE;
	m_piece_type = QUEEN;
	m_piece_color = WHITE;
	m_static_status ="Selected White Queen";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticRootBlack() 
{
	// TODO: Add your control notification handler code here
//	m_piecked_piece = ROOK_BLACK;
	m_piece_type = ROOK;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Rook";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticRootWhite() 
{
	// TODO: Add your control notification handler code here
//	m_piecked_piece = ROOK_WHITE;
	m_piece_type = ROOK;
	m_piece_color = WHITE;
	m_static_status ="Selected White Rook";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticEmpty() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = -1;
	m_piece_type = BLANK;
	m_piece_color = NONE;
	m_static_status ="Selected Blank";
	UpdateData(FALSE);
}*/

void CPickPieceDlg::OnStaticBitmapBlack() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = CHECKERS_BLACK;
	m_piece_type = NORMAL;
	m_piece_color = BLACK;
	m_static_status ="Selected Black Checker";
	UpdateData(FALSE);
	
}

void CPickPieceDlg::OnStaticBitmapBlackKing() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = CHECKERS_BLACK_KING;
	m_piece_type = KING;
	m_piece_color = BLACK;
	m_static_status ="Selected Black King";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBitmapWhite() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = CHECKERS_WHITE;
	m_piece_type = NORMAL;
	m_piece_color = WHITE;
	m_static_status ="Selected White checker";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticBitmapWhiteKing() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = CHECKERS_WHITE_KING;
	m_piece_type = KING;
	m_piece_color = WHITE;
	m_static_status ="Selected White King";
	UpdateData(FALSE);
}

void CPickPieceDlg::OnStaticEmpty() 
{
	// TODO: Add your control notification handler code here
	m_piecked_piece = -1;
	m_piece_type = BLANK;
	m_piece_color = NONE;
	m_static_status ="Selected Blank";
	UpdateData(FALSE);	
}

BOOL CPickPieceDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	 
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CPickPieceDlg::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_BLACK);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);
		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefBlackPieceColor);								 
		pdc->FillRgn(&rgn,&brush );
		pwnd->ReleaseDC(pdc);
		UpdateData(FALSE);
	}
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_BLACK_KING);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);
		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefBlackPieceColor);								 
		pdc->FillRgn(&rgn,&brush );		 
		POINT pt[6] = {
							{rect.left+15,rect.top+20},
							{rect.right -15, rect.top+20},
							{rect.left+15, rect.bottom - 15},
							{rect.left + 25,rect.top +15},
							{rect.right-15,rect.bottom-15},
							{rect.left+15,rect.top+20}};
 		pdc->Polyline(pt,6); 
		pwnd->ReleaseDC(pdc);

		UpdateData(FALSE);
	}
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_WHITE);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefWhitePieceColor);								 
		pdc->SetBkColor(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefWhitePieceColor);
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);

		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		 
		pdc->FillRgn(&rgn,&brush );
		pwnd->ReleaseDC(pdc);
		UpdateData(FALSE);
	}
	{
 		CWnd *pwnd = GetDlgItem(IDC_STATIC_BITMAP_WHITE_KING);
		CRect rect;
		pwnd->GetClientRect(rect);
		CDC *pdc = pwnd->GetDC();
		CRect rect1(rect.left+5,rect.top+5,rect.right-5,rect.bottom-5);
		pdc->Ellipse(rect1);
		CRgn rgn;						 
		rgn.CreateEllipticRgn(rect1.left, rect1.top, rect1.right, rect1.bottom);	
		CBrush brush(((CNetChessView*)((CFrameWnd*)AfxGetApp()->m_pMainWnd)->GetActiveView())->m_optDlg.m_crefWhitePieceColor);								 
		pdc->FillRgn(&rgn,&brush );		 
		POINT pt[6] = {
							{rect.left+15,rect.top+20},
							{rect.right -15, rect.top+20},
							{rect.left+15, rect.bottom - 15},
							{rect.left + 25,rect.top +15},
							{rect.right-15,rect.bottom-15},
							{rect.left+15,rect.top+20}};
 		pdc->Polyline(pt,6); 
		pwnd->ReleaseDC(pdc);

		UpdateData(FALSE);
	}

	// TODO: Add your message handler code here
	
	// Do not call CDialog::OnPaint() for painting messages
}
