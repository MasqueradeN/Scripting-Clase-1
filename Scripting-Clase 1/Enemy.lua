require("Entity")

Enemy = {}
Enemy.__index = Enemy

function Enemy:New(num)
	local this =
	{
		base = Entity:New(num)
	}
	setmetatable(this,self)
	return this
end

function InitEnemy()
	InitSprite()
	SetPosition()
	SetSpeed()
end
function InitSprite()
	SetEnemySprite("thumb.jpg")
end

function SetPosition()
	SetEnemyPosition(20,20)
end

function SetSpeed()
	EnemySpeed(1.5)
end