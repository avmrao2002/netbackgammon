#include "stdafx.h"
#include "History.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

void CHistory::SetHistory(
	 PIECE_SIDE piece_side,
	 PIECE_TYPE from_piece_type,
	 COLOR_TYPE from_color_type,
	 int from_pieceid,
	 int from_row_id,
	 int from_col_id, 
	 PIECE_TYPE to_piece_type,
	 COLOR_TYPE to_color_type,
	 int to_pieceid,
	 int to_row_id,
	 int to_col_id,
	 PIECE_TYPE rm_piece_type,
	 COLOR_TYPE rm_color_type,
	 int rm_pieceid,
	 int rm_row_id,
	 int rm_col_id)

{
	m_piece_side = piece_side;
	m_from_piece_type = from_piece_type;
	m_from_color_type=from_color_type;
	m_from_pieceid=from_pieceid;
	m_from_row_id=from_row_id;
	m_from_col_id=from_col_id;
	m_to_piece_type=to_piece_type;
	m_to_color_type=to_color_type;
	m_to_pieceid=to_pieceid;
	m_to_row_id=to_row_id;
	m_to_col_id=to_col_id;

	m_rm_piece_type = rm_piece_type;
	m_rm_color_type = rm_color_type;
	m_rm_pieceid = rm_pieceid;
	m_rm_row_id = rm_row_id;
	m_rm_col_id = rm_col_id;
}

void CHistory::GetHistory(
	PIECE_SIDE &piece_side,
	PIECE_TYPE &from_piece_type,
	 COLOR_TYPE &from_color_type,
	 int &from_pieceid,
	 int &from_row_id,
	 int &from_col_id, 
	 PIECE_TYPE &to_piece_type,
	 COLOR_TYPE &to_color_type,
	 int &to_pieceid,
	 int &to_row_id,
	 int &to_col_id,
	 PIECE_TYPE &rm_piece_type,
	 COLOR_TYPE &rm_color_type,
	 int &rm_pieceid,
	 int &rm_row_id,
	 int &rm_col_id)
{
	piece_side = m_piece_side;
	from_piece_type = m_from_piece_type;
	from_color_type=m_from_color_type;
	from_pieceid=m_from_pieceid;
	from_row_id=m_from_row_id;
	from_col_id=m_from_col_id;
	to_piece_type=m_to_piece_type;
	to_color_type=m_to_color_type;
	to_pieceid=m_to_pieceid;
	to_row_id=m_to_row_id;
	to_col_id=m_to_col_id;
	rm_piece_type = m_rm_piece_type;
	rm_color_type = m_rm_color_type;
	rm_pieceid = m_rm_pieceid;
	rm_row_id = m_rm_row_id;
	rm_col_id = m_rm_col_id;
}