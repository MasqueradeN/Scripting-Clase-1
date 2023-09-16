require("LuaScenes")

MainMenu = {}
MainMenu.__index = MainMenu
setmetatable(MainMenu, {__index = LuaScenes})

function MainMenu:New()
 local this = LuaScenes:New()
 setmetatable(this, self)
 return this
end

function InitMenu()
	setFont()
	setBackGround()
end

function setFont()
	setFontFile("Howlimit.ttf")
end

function setBackGround()
	setBackgroundTexture("Menu.jpg")
end

function Update()
	print("Updating")
end

function Render()
	print("Rendering")
end


