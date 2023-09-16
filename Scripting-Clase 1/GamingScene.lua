require("LuaScenes")

GamingScene = {}
GamingScene.__index = GamingScene
setmetatable(GamingScene, {__index = LuaScenes})

function InitGaming()
    InitFont()
    InitBGTexture()
end

function InitFont()
    setGamingFont("Howlimit.ttf")
end
function InitBGTexture()
    setBackgroundTexture("Galaxy.png")
end

function GamingScene:New()
 local this = LuaScenes:New()
 setmetatable(this, self)
 return this
end

function Update()

end

function Render()
	print("Gaming Scene render")
end

