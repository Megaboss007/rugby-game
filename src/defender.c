// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"


// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter


/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
  // TODO: unused parameters, remove these lines later
  
// In C, static variables are kept between executions of the function
  // By construction, the attacker will never be in the INVALID_POSITION,
  // so this works to initialize the variable.
 
  static position_t previous_position = INVALID_POSITION;
  static position_t spypositionatk = INVALID_POSITION;
  
  static direction_t best_direction = DIR_UP;
  static direction_t directionaux= DIR_DOWN;
  static direction_t directionaux2= DIR_UP;
  static int cont = 0; 

if(cont == 10) // Pode ser utilizado um número aleatório
  spypositionatk  = get_spy_position(attacker_spy);
   if(get_spy_number_uses(attacker_spy) != 0){
   if(spypositionatk.i > defender_position.i)   
    best_direction = (direction_t) DIR_DOWN;
  else if (spypositionatk.i < defender_position.i)
    best_direction = (direction_t) DIR_UP;
  else best_direction = (direction_t) DIR_STAY;
   }
  if (equal_positions(defender_position, previous_position)) {
   best_direction = directionaux;
   directionaux = directionaux2;
   directionaux2 = best_direction; 
  }     
  previous_position = defender_position;
  cont++;
  return best_direction;

}

/*----------------------------------------------------------------------------*/
