require("Entity")

Player = {}
Player.__index = Player

function Player:New(num)
	local this =
	{
		base = Entity:New(num)
	}
	setmetatable(this,self)
	return this
end

function InitPlayer()
	InitSprite()
	SetPosition()
	SetSpeed()
end
function InitSprite()
	SetPlayerSprite("pixil-frame-0 (5).png")
end

function SetPosition()
	SetPlayerPosition(200,200)
end

function SetSpeed()
	PlayerSpeed(10)
end