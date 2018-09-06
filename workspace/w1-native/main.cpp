#include "rtttl_player.hpp"

const char * let_it_be = "Beatles Let It Be:d=4,o=5,b=100:16e6,8d6,c6,16e6,8g6,8a6,8g.6,16g6,8g6,8e6,16d6,8c6,16a,8g,e.6,p,8e6,16e6,8f.6,8e6,8e6,8d6,16p,16e6,16d6,8d6,2c.6";

class dummy_note_player : public note_player {
public:    
   void play( const note & n ) override {};   
};
 
int main( void ){	
   auto p = dummy_note_player();   
   rtttl_play( p, let_it_be );
}
