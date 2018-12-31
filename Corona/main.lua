local licensing = require "licensing"

local providerName = "google"

licensing.init( providerName )

local function listener( event )
	print( event )
end

licensing.verify( listener )
