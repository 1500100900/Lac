bool		load_mobprogs		args ( ( FILE* fp ) );
bool   		mprog_read_programs	args ( ( FILE* fp, void *param,
						int gdzie ) );
char		*mprog_type_to_name	args( ( int type, int gdzie ) );

extern struct progi_type progi[ 4 ][ 26 ];
