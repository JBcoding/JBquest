

class Player : public PhysicsActor
{
public:
	Player(Vector2 StartingPosition, String Name);

	int getDamage();
	void Update(float dt);

	unsigned int getHealth();
	void setHealth(unsigned int NewHealth);
	float getSpeed();
	void setSpeed(float NewSpeed);
	float getJumpHeight();
	void setJumpHeight(float NewJumpHeight);
	unsigned short getLevel();
	void setLevel(unsigned short NewLevel);

private:
	unsigned int Health;
	float Speed;
	float JumpHeight;
	unsigned short Level;
};