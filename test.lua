local t = {11, 22, 33, you = "one", me = "two"}

local mt = {__index = print}

t.you