DECLARE_DO_FUN(	do_hunt		); /* z Wurma */

void	auto_hunt	args( ( CHAR_DATA *ch ) );
int	find_path	args( ( ROOM_INDEX_DATA *from, ROOM_INDEX_DATA *to,
				int max_depth, bool same_area,
				bool through_doors ) );
void	hunt_victim	args( ( CHAR_DATA *ch ) );
