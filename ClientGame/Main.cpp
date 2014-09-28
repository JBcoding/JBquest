#include "stdafx.h"
#include "Player.h"


int main(int argc, char* argv[])
{
	// get things going
	//  optional parameters:
	//		int windowWidth			default: 1024
	//		int windowHeight		default: 768
	//		std::string windowName	default: "Angel Engine"
	//		bool antiAliasing		default: false
	//		bool fullScreen			default: false
	//		bool resizable			default: false
	theWorld.Initialize(1024, 768, "JBquest", false, true, false);
	
	//adds the default grid so you can more easily place Actors
	theWorld.Add(new GridActor(), -1);
	
	//YOUR GAME SETUP CODE HERE
	
	theWorld.SetupPhysics();
	theWorld.GetPhysicsWorld().SetGravity(b2Vec2(0, -10));
	
	
	Player *Mathias = new Player(Vector2(0, 2), "Mathias");
	
	theWorld.Add(Mathias);

	///////////////GROUND//////////////////
	PhysicsActor *Ground = new PhysicsActor();
	Ground->SetPosition(0.0f, -11.0f);
	Ground->SetSize(30.0f, 5.0f);
	Ground->SetColor(0.0f, 1.0f, 0.0f);
	Ground->SetDensity(0.0f);
	Ground->SetFriction(0.1f);
	Ground->SetRotation(45);
	Ground->InitPhysics();
	theWorld.Add(Ground);
	///////////////////////////////////////

	// do all your setup first, because this function won't return until you're exiting
	theWorld.StartGame();
	
	// any cleanup can go here
	theWorld.Destroy();
	
	return 0;
}
