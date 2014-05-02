int		fread_obj	args( ( void *parametr, FILE *fp, int use ) );
void		fwrite_obj	args( ( CHAR_DATA *ch, OBJ_DATA *obj, FILE *fp,
					int iNest, bool own ) );
char		*initial		args( ( const char *str ) );
int		load_char_obj	args( ( DESCRIPTOR_DATA *d, char *name ) );
CHAR_DATA	*nowa_postac	args( ( DESCRIPTOR_DATA *d, char *name ) ) __attribute__( ( warn_unused_result ) );
void		save_char_obj	args( ( CHAR_DATA *ch ) );
