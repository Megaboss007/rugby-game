// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
  // TODO: unused parameters, remove these lines later
 
  // In C, static variables are kept between executions of the function
  // By construction, the attacker will never be in the INVALID_POSITION,
  // so this works to initialize the variable.
  static position_t previous_position = INVALID_POSITION;
  static direction_t best_direction = DIR_RIGHT;
  static position_t spypositiondfd = INVALID_POSITION;
  static int cont = 0;
  static bool up = false;
  static bool down = false;
  static bool stop = false;
  

  if (cont == 4) // Aqui pode ser utilizado um número aleatório
    spypositiondfd = get_spy_position(defender_spy);

  
if(cont>=4 && !stop) {

  if(spypositiondfd.i > attacker_position.i)   {
    best_direction = (direction_t) DIR_UP_LEFT;
    up = true;    
    }
  else {
    best_direction = (direction_t) DIR_DOWN_LEFT; 
    down = true;
    }
}
  else if (stop) {
  if(up)
  best_direction = (direction_t)  DIR_DOWN_RIGHT;
    else if (down) 
    best_direction = (direction_t)  DIR_UP_RIGHT;
  }

  if (equal_positions(attacker_position, previous_position) ) {
    if (up)
    best_direction = (direction_t)  DIR_DOWN_RIGHT;
    else if (down)
    best_direction = (direction_t)  DIR_UP_RIGHT;
    else
    best_direction = (direction_t) DIR_RIGHT;
    stop = true;
    up = false;
    down = false;
  } 


  previous_position = attacker_position;
  cont++;
  return best_direction;
}


/*----------------------------------------------------------------------------*/
