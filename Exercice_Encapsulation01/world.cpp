#include <iostream>
#include "world.h"

#include "entity.h"
#include "vector2.h"
#include "player.h"
#include "mob.h"
#include "breakableObject.h"
#include "staticObject.h"

// Pour avoir le type de class spécifique à une variable lors de l'affichage
// --> dynamic_cast
#include <typeinfo> 


World::World(){

}

void World::Init() {
	//Creation des entités

	std::cout << "---- --- -- - Initialisation du Monde - -- --- ----" << std::endl;
	Entity* staticObject = new StaticObject(2, 3);
	Entity* breakableObject = new BreakableObject(2, 2, 1, 1);
	Entity* mob = new Mob(0, 0, 20, 20, 1, Vector2(0, 0));
	Entity* player = new Player(4, 4, 10, 10, 3, Vector2(4, 4));

	ptr_Entitys.push_back(staticObject);
	ptr_Entitys.push_back(breakableObject);
	ptr_Entitys.push_back(mob);
	ptr_Entitys.push_back(player);
}

//Fonction pour vérifier si la création des entitys s'ajoute bien dans ptr_Entitys
//void World::Display_Ptr()
//{
//	for (Entity* entityCreate : ptr_Entitys)
//	{
//		Vector2 position = entityCreate->GetPosition();
//		std::cout << typeid(*entityCreate).name() << " at position : (" << position.GetX()
//			<< ", " << position.GetY() << ")" << std::endl;
//	}
//}




bool World::Step()
{
	//Pas d'ennemi = 1
	bool noEnemies = true;
	//On parcour la variable ptr_Entitys selon les Entity créer
	for (Entity* createEntity : ptr_Entitys)
	{
		//Si il existe une Class:mob ou une Class:breakableObject
		if (dynamic_cast<Mob*>(createEntity) || dynamic_cast<BreakableObject*>(createEntity)) 
		{
			//Vérifie également si ils ont toujours des points de vie
			if (dynamic_cast<Alive*>(createEntity)->GetActualHP() > 0) 
			{
				//Si y'en a avec des HP, il y a donc des ennemies
				noEnemies = false;
			}
			else
			{
				//Il existe bien ces types, mais qu'ils n'ont pas de HP
				//Pour l'instant on ne gère pas la destruction de l'objet    <---------------------------- Ligne d'amélioration
				noEnemies = true;
			}
		}
	}

	//Si il n'y a pas d'ennemi, on affiche la fin de la simulation
	if (noEnemies)
	{
		//std::cout << "---- --- -- -Simulation Finished- -- --- ----" << std::endl;
		//On retourne false pour dire que la simulation est bien finis et sortir de la boucle while du main()
		return false;
	}

	//pour les informations dans ptr_Entitys
	for (Entity* createEntity : ptr_Entitys)
	{
		//Recherche  un type Mob dans le pointeur
		if (Mob* _mob = dynamic_cast<Mob*>(createEntity))
		{
			//prend en compte la vitesse du mob
			float _mobSpeed = _mob->GetVitesse();

			//déroule la liste des entity une nouvelle fois a la recherche d'un cible
			for (Entity* target : ptr_Entitys)
			{
				//cherche un BreakableObject dans la liste des entity
				if (BreakableObject* _targetBreakableObject = dynamic_cast<BreakableObject*>(target))
				{
					//cherche si ces HP superieur à 0
					if (_targetBreakableObject->GetActualHP() > 0)
					{
						//Cherche a prendre ces pointeurs de position de la cible, on veut agir directement sur la position
						//Ne pas faire de copie des positions X et Y
						Vector2* breakableObjectPositionPtr = _targetBreakableObject->GetPosition();
						float targetX = breakableObjectPositionPtr->GetX();
						float targetY = breakableObjectPositionPtr->GetY();

						//Même chose pour le mob
						Vector2* mobPositionPtr = _mob->GetPosition();
						float mobX = mobPositionPtr->GetX();
						float mobY = mobPositionPtr->GetY();

						//Difference entre position mob et de la cible
						float deltaX = targetX - mobX;
						float deltaY = targetY - mobY;

						//Mouvement de deplacement basique, ne prend pas en compte superposition/obstacle    <---Ligne d'amélioration
						//Calcul distance en X et Y entre mob et la cible
						// si distance de X plus grand que Y
						//on se deplacera alors en X
						if (std::abs(deltaX) > std::abs(deltaY))
						{
							//Si la difference et positif, alors on avance sur X
							if (deltaX > 0)
							{
								_mob->Deplacement(_mobSpeed, 0);
							}
							//Si la difference et negatif, alors on recule sur X
							else 
							{
								_mob->Deplacement(- _mobSpeed, 0); 
							}
						}
						//Si distance Y plus petit ou egale à X
						//on se deplace alors sur Y
						else 
						{
							if (deltaY > 0) 
							{
								//distance positif -> on avance sur Y
								_mob->Deplacement(0, _mobSpeed); 
							}
							else 
							{
								//distance negatif -> on recule sur Y
								_mob->Deplacement(0, -_mobSpeed);
							}
						}

						//Verification de la portee d'attaque
						//Dans le programme tout le monde attaque avec une portée de 1   <------------------------Ligne d'amélioration
						
						//Verifie la distance entre mob et la cible en prenant la valeur absolue
						//Si la distance absolue de X et de Y inférieur ou = 1
						if (abs(deltaX) <= 1 && abs(deltaY) <= 1)
						{
							//creer le pointeur point de vie de la cible
							Alive* targetAlive = dynamic_cast<Alive*>(_targetBreakableObject);
							_mob->Attack(targetAlive);
						}
					}
				}
			}
		}

		//Cherche le type Player dans la liste d'entity
		if (Player* _player = dynamic_cast<Player*>(createEntity))
		{
			float _playerSpeed = _player->GetVitesse();

			//créer la variable target, qui parcour chaque entity ajouter dans ptr_Entitys
			for (Entity* target : ptr_Entitys)
			{
				//si une entity correspond au type mob
				if (Mob* _mob = dynamic_cast<Mob*>(target))
				{
					//si il est encore en vie
					if (_mob->GetActualHP() > 0)
					{
						//même logique qu'avec mob et sa cible 
						// possible de rajouter dans Deplacement() de AMovable	<------------------------------------Ligne d'amélioration
						//Que tout les enfants heriteront
						Vector2* mobPositionPtr = _mob->GetPosition();
						float targetX = mobPositionPtr->GetX();
						float targetY = mobPositionPtr->GetY();

						Vector2* playerPositionPtr = _player->GetPosition();
						float playerX = playerPositionPtr->GetX();
						float playerY = playerPositionPtr->GetY();

						float deltaX = targetX - playerX;
						float deltaY = targetY - playerY;

						if (std::abs(deltaX) > std::abs(deltaY))
						{
							if (deltaX > 0)
							{
								_player->Deplacement(_playerSpeed, 0);
							}
							else
							{
								_player->Deplacement(-_playerSpeed, 0);
							}
						}
						else
						{
							if (deltaY > 0)
							{
								_player->Deplacement(0, _playerSpeed);
							}
							else
							{
								_player->Deplacement(0, -_playerSpeed);
							}
						}

						//Verification de la portee d'attaque
						//Dans le programme tout le monde attaque avec une portée de 1
						if (abs(playerX - targetX) <= 1 && abs(playerY - targetY) <= 1)
						{
							Alive* targetAlive = dynamic_cast<Alive*>(_mob);
							_player->Attack(targetAlive);
						}
					}
				}
			}
		}
		
	}
	//Simulation pas terminer, retourne true pour continuer la boucle while de main()
	// Faire une vérification des HP des entity
	// obliger de refaire un tour pour voir si les entitys sont morte ou non  <---------------------------------Ligne d'Amelioration 
	return true;
}
