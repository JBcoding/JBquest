#include "stdafx.h"
#include "Player.h"

Player::Player(Vector2 StartingPosition, String Name) {
	theTuning.SetFloat("PlayerMaxSpeed", 12);

	SetName(Name);

	SetPosition(StartingPosition);
	SetSize(3.0f, 5.0f);
	SetColor(1, 1, 1, 1);
	ClearSpriteInfo();
	std::cout << SetSprite("Resources/Images/Mathias_Standing.png", 0, GL_CLAMP, GL_NEAREST);

	
	SetDensity(0.8f);
	SetFriction(0.0f);
	SetRestitution(0.02f);
	SetFixedRotation(true);
	SetShapeType(PhysicsActor::SHAPETYPE_BOX);
	InitPhysics();
}

void Player::Update(float dt)
{
	float maxVel = theTuning.GetFloat("PlayerMaxSpeed");

	float xVector = 0.0f;
	if (theController.IsConnected())
	{
		xVector = theController.GetLeftThumbVec2().X;
	}
	if (theInput.IsKeyDown(ANGEL_KEY_RIGHTARROW))
	{
		xVector = 1.0f;
	}
	if (theInput.IsKeyDown(ANGEL_KEY_LEFTARROW))
	{
		xVector = -1.0f;
	}
	if (theInput.IsKeyDown(ANGEL_KEY_LEFTARROW) && theInput.IsKeyDown(ANGEL_KEY_RIGHTARROW))
	{
		xVector = 0.0f;
	}

	float desiredVelocity = xVector * maxVel;
	float velocityChange = desiredVelocity - GetBody()->GetLinearVelocity().x;
	float impulse = GetBody()->GetMass() * velocityChange;
	this->ApplyLinearImpulse(Vector2(impulse, 0), Vector2());
}

int Player::getDamage(){
	return 8; // 8 Is my lucky number, and this is my last day, so fuck it
}

unsigned int Player::getHealth() {
	return Health;
}
void Player::setHealth(unsigned int NewHealth) {
	Health = NewHealth;
}
float Player::getSpeed() {
	return Speed;
}
void Player::setSpeed(float NewSpeed) {
	Speed = NewSpeed;
}
float Player::getJumpHeight() {
	return JumpHeight;
}
void Player::setJumpHeight(float NewJumpHeight) {
	JumpHeight = NewJumpHeight;
}
unsigned short Player::getLevel() {
	return Level;
}
void Player::setLevel(unsigned short NewLevel) {
	Level = NewLevel;
}