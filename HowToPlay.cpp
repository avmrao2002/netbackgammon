// HowToPlay.cpp : implementation file
//

#include "stdafx.h"
#include "NetChess.h"
#include "HowToPlay.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CHowToPlay dialog


CHowToPlay::CHowToPlay(CWnd* pParent /*=NULL*/)
	: CDialog(CHowToPlay::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHowToPlay)
	m_edit_string = _T("");
	//}}AFX_DATA_INIT
}


void CHowToPlay::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHowToPlay)
	DDX_Text(pDX, IDC_EDIT_STRING, m_edit_string);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CHowToPlay, CDialog)
	//{{AFX_MSG_MAP(CHowToPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHowToPlay message handlers

BOOL CHowToPlay::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
		
m_edit_string = "\t\t\tHOW TO PLAY Net Backgammon\r\n\tNetBackgammon is Backgammon game which can be played between two players on the same "
"board or over LAN, intranet using TCP/IP communication. Backgammon game is played on board "
"between two players. The board consists of 24 points or narrow triangles alternate in color"
"(Choose the triangle color from Edit->Options)."
" These points are kept in four quadrants. These quadrants are called player's home board and "
"outer board and opponent's home board and outer board. The home board and outer board are "
"Separated by bar.  The points are numbers starting from 1 to 24 from home board. Each player "
"has 15 checkers of his color choice(Select the color from Edit-Properties).\r\nThe initial arrangement "
" of NetBackgammon is automatically arranged as: two on each player's twenty-four point, "
"five on each player's thirteen point, three on each player's eight point, and five on each "
"player's six point.\r\n"
"The object of the game is to move all the checkers to his own home and bear them off.\r\n\r\n"
"Note: doubling is not supported in this game.\r\n\r\n"
"Rules of the game:\r\n"
"Click on the dice(Red cubes on the right side of the board). Move the balls based on the "
"dice numbers and click Send. Double click on the checker will move the checker based on the "
" dice number.\r\n"
"1. A checker may be moved to open point, one that is not occupied by two or more opposing checkers\r\n"
"2. A player must move both numbers if it is possible\r\n\r\n"
"Hitting:\r\n"
"A point occupied by a single checker of either color is called a blot. If an opposing checker "
"lands on a blot, the blot is hit and placed on the bar.\r\nAny time a player has one or more "
"checkers on the bar, first obligation is to enter those checker(s) into the opposing home "
" board. A checker is entered by moving it to an open point corresponding to one of the numbers "
" on the dice/double clicking on it. If no move is possible, then player losses his turn and "
"click on Send for other player to play\r\n\r\n"
"Bearing off:\r\nOnce a player has moved all of his fifteen checkers into his home board, he may " 
"commence bearing off. A player bears off a checker by rolling a number that corresponds to "
" the point on which the checker resides, and then removing that checker from the board. "
"Thus, rolling a 4 permits the player to remove a checker from the fourth point.\r\n\r\n"
"How to start:\r\n"
"To start the game, each player starts the game on their machine. Those who want to play with "
"White should run as server(Tools->Server) and other should connect(Tools->Client) to the "
" server. Only one connection accepted in the server. Once the connection is established(check "
" the connection by clicking on Edit->Properties) "
"White starts the game by clicking on the dice cubes(immediately dice data will be reflected on "
"both boards) and move the checkers based on the numbers. "
"After the moves(first dice number and second dice number moves) are done, Click on Send. "
"Checker moves will be reflected on both the boards. "
"Players turn will be displayed on the status bar.\r\n\r\n"
"\r\nOther features are:-----\r\n"
"\"File->New\" A new game will be started by cleaning the running game.\r\n"
"\"Edit->Option\" can be used to change the color of the board squares and checkers.\r\n"
"\"Edit->Properties\" will display the current connection status of the game.\r\n"
"\"Edit->Undo\" Undo the last one or two move(s).Undo can be done before submitting the move. Once the move is submitted,you can not undo the move.\r\n"
"\"Tools->SendMessage\" can be used to send instant message to the other player.\r\n"
"\"Tools->Disconnect\" disconnects from the network game.\r\n"
"\"View->Hide\" will hide the current board and an icon will be placed in the system tray. "
"To activate the game again, click on NetBackgammon icon in the system tray, the hidden board "
" will be activated\r\n\r\n"
"Whenever there is a move, a message or any other action, an icon will be toggled in the system tray. "
"On clicking on icon in system tray, the hidden game will be displayed.\r\n\r\n"
"This software is aimed at for playing NetBackgammon game between two players over network or on the same board.\r\n\r\n"
"Enjoy the free game!!!";

UpdateData(FALSE);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
