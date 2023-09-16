Entity = {}
Entity.__index = Entity

function Entity:New(num)
	local this =
	{
		myNum = num
	}
	setmetatable(this,self)
	return this
end

function Entity:print()
	print("Entity")
end


function Entity:InitSprite(_texture)
end

function Entity:SetPosition(_x, _y)
	
end
