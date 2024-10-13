#include <iostream>

#include "vector2.h"
#include "staticObject.h"
#include "breakableObject.h"
#include "mob.h"
#include "player.h"
#include "world.h"


int main()
{
	World _world;

	std::cout << " -- - -- - -- - -- - -- - -- - -- - -- - -- - --"
		<< std::endl
		<< " ---- --- -- - Initialisation World- -- --- ----"
		<< std::endl << std::endl;

	_world.Init(); 
	//_world.display_ptr();

	std::cout << " -- - -- - -- - -- - -- - -- - -- - -- - -- - --"
		<< std::endl
		<< " ---- --- -- - Start Simulation - -- --- ----"
		<< std::endl << std::endl;

	int turn = 1;  

	//crer une boucle infinie jusqu'a que le Step() sort False
	while (true)
	{
		std::cout << std::endl << "-- - -- - -- - -- - -- - -- - -- - -- - -- - --"
			<<std::endl <<" ----> Turn: " << turn << std::endl;

		if (!_world.Step())
		{
			break;
		}

		//Si boucle 'infnie', pause après 10tours
		/*if (turn == 10)
		{ 
			system("pause");
		}*/
		turn++;
	}

	std::cout << " -- - -- - -- - -- - -- - -- - -- - -- - -- - --"
		<< std::endl
		<< "---- --- -- - Simulation Finished after " << turn << " turns. - -- --- ----" << std::endl;
	return 0;
}



