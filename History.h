#if !defined(HISTORY_H)
#define HISTORY_H

class CHistory
{
private:	 
	 PIECE_SIDE m_piece_side;
	 PIECE_TYPE m_from_piece_type;
	 COLOR_TYPE m_from_color_type;
	 int m_from_pieceid;
	 int m_from_row_id;
	 int m_from_col_id;

	 PIECE_TYPE m_to_piece_type;
	 COLOR_TYPE m_to_color_type;
	 int m_to_pieceid;
	 int m_to_row_id;
	 int m_to_col_id;

	 PIECE_TYPE m_rm_piece_type;
	 COLOR_TYPE m_rm_color_type;
	 int m_rm_pieceid;
	 int m_rm_row_id;
	 int m_rm_col_id;
public:
	void SetHistory(PIECE_SIDE piece_side,PIECE_TYPE from_piece_type,
	 COLOR_TYPE from_color_type,
	 int from_pieceid,
	 int from_row_id,
	 int from_col_id, 
	 PIECE_TYPE to_piece_type,
	 COLOR_TYPE to_color_type,
	 int to_pieceid,
	 int to_row_id,
	 int to_col_id,

	 PIECE_TYPE m_rm_piece_type,
	 COLOR_TYPE m_rm_color_type,
	 int m_rm_pieceid,
	 int m_rm_row_id,
	 int m_rm_col_id);

	void GetHistory(PIECE_SIDE& piece_side,PIECE_TYPE &from_piece_type,
	 COLOR_TYPE &from_color_type,
	 int &from_pieceid,
	 int &from_row_id,
	 int &from_col_id, 
	 PIECE_TYPE &to_piece_type,
	 COLOR_TYPE &to_color_type,
	 int &to_pieceid,
	 int &to_row_id,
	 int &to_col_id,

	 PIECE_TYPE &m_rm_piece_type,
	 COLOR_TYPE &m_rm_color_type,
	 int &m_rm_pieceid,
	 int &m_rm_row_id,
	 int &m_rm_col_id);	 

protected:
};
#endif