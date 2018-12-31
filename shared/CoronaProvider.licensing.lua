local Provider = require "CoronaProvider"

local Class = Provider:newClass( "CoronaProvider.licensing" )

-- Default implementations
local function defaultFunction()
	print( "WARNING: The 'licensing' library is not available on this platform." )
end

Class.isStub = true
Class.init = defaultFunction
Class.verify = defaultFunction

-- Return an instance
return Class
