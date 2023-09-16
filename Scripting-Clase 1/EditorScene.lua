require("Scenes")

EditorSceneLua = {}
EditorSceneLua.__index = EditorSceneLua
setmetatable(EditorSceneLua, {__index = Scenes})

function EditorScene:New()
 local this = Scenes:New()
 setmetatable(this, self)
 return this
end

function setFont()
	setFontFile("Howlimit.ttf")
end

function setBackGround()
	setBackGroundFile("file.jpg")
end

function Update()
	
end

function Render()
	
end