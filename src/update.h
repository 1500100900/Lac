void	advance_level		args( ( CHAR_DATA *ch ) );
void	ban_update		args( ( void ) );
void	demote_level		args( ( CHAR_DATA *ch ) );
void	gain_condition		args( ( CHAR_DATA *ch, int iCond, int value ) );
void	gain_exp		args( ( CHAR_DATA *ch, int gain ) );
void	komunikaty_ustroju	args( ( CHAR_DATA *ch ) );
void	lv_hlp			args( ( CHAR_DATA *ch ) );
void	update_handler		args( ( void ) );
void	update_handler_before	args( ( void ) );
void	uzyj			args( ( CHAR_DATA *ch, int sn, const char *co ) );

extern	bool	delete_char;
extern	bool	delete_obj;
extern	bool	murder_char; /* Lam */
extern	int	pulse_point;
extern	int	pulse_point_max;

