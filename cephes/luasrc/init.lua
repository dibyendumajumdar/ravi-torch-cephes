require 'torch'
local tcephes = require 'tcephes'
cephes = {}
for k,v in pairs(tcephes) do cephes[k] = v end

-- Error handling with soft wrapping of all functions
torch.include('cephes', 'error_handling.lua')
torch.include('cephes', 'limits.lua')
torch.include('cephes', 'bessel.lua')
torch.include('cephes', 'misc.lua')

return cephes

