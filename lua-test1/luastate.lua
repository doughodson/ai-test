-- Override Lua Print()
local print = function (x)
  print("Lua: "..x)
end

local a1 = LuaState()

if a1:isAlive() then
  print("Alive")
else
  print("Dead")
end


print("End of Script")
